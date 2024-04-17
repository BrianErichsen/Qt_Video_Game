#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsScene>
#include "bucket.h"
#include "waterdroplet.h"

/*Author: Brian Erichsen Fagundes
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * game1Scene class represents a QGraphicsScene object
*/

class game1scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game1scene();
};

#endif // GAME1SCENE_H
