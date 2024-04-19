#ifndef WATERDROPLET_H
#define WATERDROPLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>


/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * class water droplet creates a object that mimics rain
*/

class game1scene;

class waterDroplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit waterDroplet(game1scene* scene, QGraphicsPixmapItem* parent = nullptr);

signals:
    void score_water();
    void missed_droplets();

public slots:
    void move_droplet();

private:
    QTimer* timer_drop;
    game1scene* gameScene;
};

#endif // WATERDROPLET_H
