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
    timer_drop->start(50); // Starts timer with a faster rate
}

// Method that moves droplets
void waterDroplet::move_droplet() {
    // Start with base speed adjusted for game mode
    int base_speed = calculateSpeedBasedOnGameMode();
    // Optional: if the game's end condition is met, stop the game
    if (gameScene->getMissedDroplets() >= 5 || gameScene->getScore() >= 150) {
        emit gameOver(); // Notify game scene of the game over state
        return;
    }

    // If droplet is within screen then move droplet
    if (scene() && pos().y() < scene()->height()) {
        setPos(x(), y() + base_speed);
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
    } else { // Remove droplet if it is out of window
        emit missed_droplets(); // Notify of missed droplet
        scene()->removeItem(this);
        delete this;
    }
}

// Calculate droplet speed based on game difficulty
int waterDroplet::calculateSpeedBasedOnGameMode() {
    int difficulty_factor = gameScene->getDifficulty();
    int base_speed = 5 + 5 * difficulty_factor; // Increase speed with difficulty level
    return base_speed;
}
