#include "userwindow.h"
#include <QPixmap>
#include <QDateTime>
#include "game1scene.h"
#include <QGraphicsView>
#include <QMessageBox>
#include <QFileDialog>

UserWindow::UserWindow(User* user, QWidget* parent) : QWidget(parent), loggedInUser(user)
{
    mainLayout = new QVBoxLayout;
    setStyleSheet("background-color: lightblue; color: black;");
    if (loggedInUser) {
        nameLabel = new QLabel("Username: " + loggedInUser->getUsername());
        profilePictureLabel = new QLabel;
        dateLabel = new QLabel;
        birthdayLabel = new QLabel;


        QPixmap profilePicture(loggedInUser->getProfilePicturePath());
        if (profilePicture.isNull()) {
            profilePicture.load(":/resources/test.png");
        }
        profilePictureLabel->setPixmap(profilePicture.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        QDate currentDate = QDate::currentDate();
        dateLabel->setText("Current Date: " + currentDate.toString("yyyy-MM-dd"));

        if (loggedInUser->getBirthday().month() == currentDate.month() &&
            loggedInUser->getBirthday().day() == currentDate.day()) {
            birthdayLabel->setText("Happy Birthday!");


            QMessageBox::information(this, "Birthday Wishes", "Happy Birthday, " + loggedInUser->getUsername() + "!\nWishing you a fantastic day filled with love, laughter, and all your heart's desires.");
        } else {
            birthdayLabel->setText("Birthday: " + loggedInUser->getBirthday().toString("yyyy-MM-dd"));
        }

        startButton = new QPushButton("Start Game");
        connect(startButton, &QPushButton::clicked, this, &UserWindow::startGame);


        // logoutButton = new QPushButton("Logout");
        // connect(logoutButton, &QPushButton::clicked, this, &::UserWindow::layout);

        mainLayout->addWidget(nameLabel);
        mainLayout->addWidget(profilePictureLabel);
        mainLayout->addWidget(dateLabel);
        mainLayout->addWidget(birthdayLabel);
        mainLayout->addWidget(startButton);
        // mainLayout->addWidget(logoutButton);
        setLayout(mainLayout);
    } else {
        qDebug() << "User object is nullptr";
    }
}

void UserWindow::startGame()
{
    game1scene* gameScene = new game1scene();
    QGraphicsView* gameView = new QGraphicsView(gameScene);
    connect(gameScene, &game1scene::gameFinished, this, [this](int score) {
    loggedInUser->addGameScore(score);
    });
    gameScene->this_user = loggedInUser;
    gameView->setFixedSize(910, 512);
    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->show();
    this->hide();
    //    static QMetaObject::Connection connect(const QObject *sender, const QMetaMethod &signal,
                        // const QObject *receiver, const QMetaMethod &method,
                        // Qt::ConnectionType type = Qt::AutoConnection);
}

// void UserWindow::logout() {
//     emit loggedOut();
//     this->close();
// }

void UserWindow::displayScoreHx() {
    if (loggedInUser->gameScores.size() > 0) {
        for (int score : loggedInUser->gameScores) {
            QLabel* scoreLabel = new QLabel("Score: " + QString::number(score));
            mainLayout->addWidget(scoreLabel);
        }
    }
}

// void UserWindow::showWindow(){
//     this->show();
// }

