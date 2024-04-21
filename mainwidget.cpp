#include "mainwidget.h"
#include "game1scene.h"
#include "QGraphicsView"

mainwidget::mainwidget(QWidget* parent) : QWidget{parent}
{
    mainLayout = new QVBoxLayout;
    play_btn = new QPushButton("Play as a guest");
    signup_btn = new QPushButton("Sign up");
    login_btn = new QPushButton("Login");

    mainLayout->addWidget(play_btn, 2);
    mainLayout->addWidget(signup_btn, 0);
    mainLayout->addWidget(login_btn, 1);
    setLayout(mainLayout);

    connect(play_btn, &QPushButton::clicked, this, &mainwidget::start_game_easy);
    connect(login_btn, &QPushButton::clicked, this, &mainwidget::login_);
    connect(signup_btn, &QPushButton::clicked, this, &mainwidget::signup_);
}

void mainwidget::start_game_easy() {
    //implements
    game1scene* gameScene = new game1scene();
    //creates the view object
    QGraphicsView* mainView = new QGraphicsView(gameScene);
    // //sets proper sizes
    mainView->setFixedSize(910, 512);
    // //no scrolling for you
    mainView->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    mainView->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    // //shows the view
    mainView->show();
    this->close();
}

void mainwidget::login_() {

}

void mainwidget::signup_() {

}

