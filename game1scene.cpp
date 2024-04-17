#include "game1scene.h"
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>

/*Author: Brian Erichsen Fagundes
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * class game part 1 scene implementation
*/

game1scene::game1scene() {
    //loads back ground into scene and scale it
    setBackgroundBrush(QBrush(QImage(":/resources/background.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0, 0, 908, 510);
    //creates instance of bucket
    bucket* bucket_item = new bucket();
    bucket_item->setPos(400, 365);//sets it's initial position
    addItem(bucket_item);//adds item into scene

    //creates appropriate number of water droplets
    for (int i = 0; i < 16; ++i) {
        waterDroplet* water_droplets = new waterDroplet();
        int rand_number_x = QRandomGenerator::global()->bounded(890);
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

