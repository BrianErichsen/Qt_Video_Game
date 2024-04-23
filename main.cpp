#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"
#include "mainwidget.h"
#include "user.h"
#include <QVector>
#include <iostream>

/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * Creates a fun game --- run it and check it out
*/

int main(int argc, char **argv) {
    //creates instance of game
    QApplication app (argc, argv);

    mainwidget* main = new mainwidget();
    //----for testing purposes
    // const QString username("brian");
    // const QDate  dob(2000, 1, 1);
    // const QString firstName("Brian_");
    // const QString lastName("Fagundes");
    // const QString password("Flagelado.123");
    // const QString gender("Male");

    // User* brian = new User(username, dob, nullptr, firstName, lastName, password, gender);
    // if (brian) {
    //     std::cout << "Success" << std::endl;
    // }
    // QVector<User*> users = User::getUsers();
    // users.append(brian);

    main->show();


    return app.exec();
}//end of main bracket
