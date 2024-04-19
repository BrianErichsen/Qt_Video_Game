#ifndef BUCKET_H
#define BUCKET_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * bucket class represents a QGraphicsPixmapItem object
*/

class bucket : public QObject, public QGraphicsPixmapItem
{
public:
    bucket();
    void keyPressEvent(QKeyEvent* event);
};

#endif // BUCKET_H
