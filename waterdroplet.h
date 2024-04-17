#ifndef WATERDROPLET_H
#define WATERDROPLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>

/*Author: Brian Erichsen Fagundes
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * class water droplet creates a object that mimics rain
*/

class waterDroplet : public QObject, public QGraphicsPixmapItem
{

public:
    waterDroplet();

public slots:
    void move_droplet();

private:
    QTimer* timer_drop;
};

#endif // WATERDROPLET_H
