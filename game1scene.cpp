#include "game1scene.h"
#include <QtCore/QCoreApplication> //
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include "waterdroplet.h"

/*Author: Brian Erichsen Fagundes
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * class game part 1 scene implementation
*/

game1scene::game1scene( QGraphicsScene* parent) :
    QGraphicsScene(parent)
{
    //loads back ground into scene and scale it
    setBackgroundBrush(QBrush(QImage(":/resources/background.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0, 0, 908, 510);
    //creates instance of bucket
    bucket* bucket_item = new bucket();
    bucket_item->setPos(400, 365);//sets it's initial position
    addItem(bucket_item);//adds item into scene
    score = 0;
    collectedDroplets = 0;
    //-------------------
    droplet_count = new QGraphicsTextItem();
    droplet_count->setHtml("<font color='blue' size='5'>Collected Droplets: </font>" + QString("<font color='red' size='5'>%1</font>").arg(collectedDroplets) + "</font");
    droplet_count->setPos(10, 120);
    addItem(droplet_count);
    //-------------------
    score_count = new QGraphicsTextItem();
    score_count->setHtml("<font color='red' size='5'>Score: </font>" + QString("<font color='red' size='5'>%1</font>").arg(score) + "</font");
    score_count->setPos(10, 100);
    addItem(score_count);


    //creates appropriate number of water droplets --16
    for (int i = 0; i < 75; ++i) {
        waterDroplet* water_droplets = new waterDroplet();
        connect(water_droplets, &waterDroplet::score_water, this, &game1scene::updateScore);

        int rand_number_x = QRandomGenerator::global()->bounded(860);
        int rand_number_y = QRandomGenerator::global()->bounded(150);
        //making sure that no droplet is out of reach from bucket
        water_droplets->setPos(rand_number_x + 10, 75 + rand_number_y);
        addItem(water_droplets);
    }
    //creates appropriate number of clouds up on the screen
    for (int i = 0; i < 7; ++i) {
        QGraphicsPixmapItem* clouds = new QGraphicsPixmapItem();
        clouds->setPixmap(QPixmap("://resources/cloud.png").scaled(125, 100));
        clouds->setPos(750 - i * 120, 0);
        addItem(clouds);
    }
}

void game1scene::updateScore() {
    collectedDroplets++;
    score += 5;
    //we can change design for something better
    droplet_count->setHtml("<font color='blue' size='5'>Collected Droplets: </font>" + QString("<font color='blue' size='5'>%1</font>").arg(collectedDroplets) + "</font");
    score_count->setHtml("<font color='red' size='5'>Score: </font>" + QString("<font color='red' size='5'>%1</font>").arg(score) + "</font");
}


