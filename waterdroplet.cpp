#include "waterDroplet.h"
#include <QGraphicsScene>
#include "bucket.h"
#include "game1scene.h"

/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * Implementation of waterDroplet class
*/

// Constructor
waterDroplet::waterDroplet(game1scene* scene, QGraphicsPixmapItem* parent) :
        QGraphicsPixmapItem(parent), gameScene(scene)
{
    // Load image from given path and set its scale
    setPixmap(QPixmap("://resources/water.gif").scaled(30, 30));
    // Create and define timer
    timer_drop = new QTimer(this);
    // Connect move_droplet method to timer
    connect(timer_drop, &QTimer::timeout, this, &waterDroplet::move_droplet);
    timer_drop->start(150); // Starts timer with a faster rate
}
/*I've moved the logic to check if it leaves the window to the beginning of the movement logic.
 * This way, if a droplet would leave the window after moving, it gets deleted before the actual movement occurs.
This adjustment reduces the need for additional checks on the droplet's position after each movement,
 improving the efficiency and responsiveness of the method*/

// Method that moves droplets
void waterDroplet::move_droplet() {
    int base_speed = calculateSpeedBasedOnGameMode();

    // Check if droplet is already out of the window before moving it
    if (scene() && pos().y() + base_speed >= scene()->height()) {
        emit missed_droplets(); // Notify of missed droplet
        scene()->removeItem(this);
        delete this;
        return; // Exit early to avoid further processing
    }

    // Proceed with normal movement
    int droplet_speed = base_speed * (gameScene->getCollectedDroplets() / 5 + 1);
    droplet_speed = qMin(droplet_speed, 16 * base_speed);

    // Check game end conditions
    if (gameScene->getMissedDroplets() >= 5 || gameScene->getScore() >= 150) {
        emit gameOver(); // Notify game scene of the game over state
        return;
    }

    // Move the droplet
    setPos(x(), y() + droplet_speed);

    // Check for collisions
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (auto& item : colliding_items) {
        if (typeid(*item) == typeid(bucket)) {
            emit score_water(); // Notify of score change
            scene()->removeItem(this);
            delete this;
            return; // Prevent further movement
        }
    }
}



// Calculate droplet speed based on game difficulty using exponential growth
int waterDroplet::calculateSpeedBasedOnGameMode() {
    int difficulty_factor = gameScene->getDifficulty();
    int base_speed = 15 * pow(2, difficulty_factor - 1); // Exponential increase in speed with difficulty level
    return base_speed;
}
