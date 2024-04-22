#ifndef WATERDROPLET_H
#define WATERDROPLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>


/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * class water droplet creates a object that mimics rain
*/

class game1scene; // Forward declaration to avoid circular dependency

class waterDroplet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit waterDroplet(game1scene* scene, QGraphicsPixmapItem* parent = nullptr);

signals:
    void score_water(); // Emitted when the water droplet scores by colliding with a bucket
    void missed_droplets(); // Emitted when the water droplet is missed
    void gameOver(); // Emitted when the game over condition is met

public slots:
    void move_droplet(); // Slot that handles the movement and game logic for the droplet

private:
    QTimer* timer_drop; // Timer for controlling the movement interval of the droplet
    game1scene* gameScene; // Pointer to the game scene for accessing game state and properties

    int calculateSpeedBasedOnGameMode(); // Calculates the droplet's speed based on the game's difficulty level
};

#endif // WATERDROPLET_H
