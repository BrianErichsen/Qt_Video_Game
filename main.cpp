#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"

/*Author: Brian Erichsen Fagundes
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * Creates a fun game --- run it and check it out
*/

int main(int argc, char **argv) {
    //creates instance of game
    QApplication app (argc, argv);
    //creates game scene from main class
    game1scene* gameScene = new game1scene();
    //creates the view object
    QGraphicsView* mainView = new QGraphicsView();
    //adds the scene to the view ->setScene and its size
    mainView->setScene(gameScene);
    //sets proper sizes
    mainView->setFixedSize(910, 512);
    //no scrolling for you
    mainView->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    mainView->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    //shows the view
    mainView->show();

    return app.exec();
}//end of main bracket
