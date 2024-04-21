#include "waterdroplet.h"
#include <QGraphicsScene>
#include "bucket.h"
#include "game1scene.h"



/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * Implementation of waterDroplet class
*/
//public constructor
waterDroplet::waterDroplet(game1scene* scene, QGraphicsPixmapItem* parent) :
    QGraphicsPixmapItem(parent), gameScene(scene)
{

    //loads image from given path and sets its scale
    setPixmap(QPixmap("://resources/water.gif").scaled(30, 30));
    //creates and defines timer
    timer_drop = new QTimer(this);
    //connects move droplet method to timer
    connect(timer_drop, &QTimer::timeout, this, &waterDroplet::move_droplet);
    timer_drop->start(1000);//starts timer at 1 second mark
}

//method that moves droplets
void waterDroplet::move_droplet() {
    //start with base speed
    int base_speed = 10;
    //the speed is calculated based on number of collected droplets; one factor up each 5 collected droplets
    int droplet_speed = base_speed * (gameScene->getCollectedDroplets() / 5 + 1 );
    //sets a limit of max 16 * base speed
    droplet_speed = qMin(droplet_speed, 16 * base_speed);
    //optional for now --
    if (gameScene->getMissedDroplets() >= 5 || gameScene->getScore() >= 150) {
        scene()->removeItem(this);
        delete this;
        return;
    }
    //if pos is within screen then move droplet
    if (scene() && pos().y() < scene()->height()) {
        setPos(x(), y() + droplet_speed);
        //checkes for collision
        QList<QGraphicsItem*> colliding_items = collidingItems();
        //iterate through all collisions
        for (int i = 0; i < colliding_items.size(); ++i) {
            //if same type where bucket is then remove droplet and returns
            if (typeid(*(colliding_items[i])) == typeid(bucket)) {
                emit score_water();
                scene()->removeItem(this);
                delete this;
                return;//returns so we prevent further movement
            }
        }
    } else { // here removes droplet if it is out of window
        //emit triggers the signal missed droplet to be sent to slot on game1scene class
        emit missed_droplets();
        scene()->removeItem(this);
        delete this;
    }
}
