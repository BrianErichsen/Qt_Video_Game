#include "bucket.h"
#include <QGraphicsScene>
#include "game1scene.h"

/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * class bucket implementation
*/

bucket::bucket(game1scene* scene) : gameScene_bucket(scene) {
    setPixmap(QPixmap("://resources/bucket.png").scaled(150, 150));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}
//method to move buket either left or right based on user input
void bucket::keyPressEvent(QKeyEvent* event) {
    //calculates the left edge of scene
    qreal left_limit = scene()->sceneRect().left();
    //calculates the right edge of scene minus with width of the bucket
    qreal right_limit = scene()->sceneRect().right() - pixmap().width();

    //if key is right & pos within limits then move x pos 10 pixels to the right
    if (event->key() == Qt::Key_Right && pos().x() < right_limit) {
            setPos(x() + 10, y());
    //if key is left & pos within limits then move x pos - 10 pixels
    } else if (event->key() == Qt::Key_Left && pos().x() > left_limit) {
        setPos(x() - 10, y());
    } else if (gameScene_bucket->getMissedDroplets() >= 5 || gameScene_bucket->getScore() >= 150) {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
