#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsScene>
#include "bucket.h"
#include "waterdroplet.h"

/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * game1Scene class represents a QGraphicsScene object
*/


class game1scene : public QGraphicsScene
{
    Q_OBJECT
private:
    QGraphicsTextItem* droplet_count;
    QGraphicsTextItem* score_count;
    QGraphicsTextItem* missed_count;
    int score;
    int collectedDroplets;
    int missedDroplets;

public:
    explicit game1scene(QGraphicsScene* parent = nullptr);
    int getCollectedDroplets();
    int getScore();
    int getMissedDroplets();


public slots:
    void updateScore();
    void updateMissedDroplet();
};

#endif // GAME1SCENE_H
