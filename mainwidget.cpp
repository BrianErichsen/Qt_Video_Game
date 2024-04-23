#include "mainwidget.h"
#include "game1scene.h"
#include <QGraphicsView>
#include <QMessageBox>

mainwidget::mainwidget(QWidget* parent) : QWidget{parent}
{
    mainLayout = new QVBoxLayout;
    play_btn = new QPushButton("Play as a guest");
    signup_btn = new QPushButton("Sign up");
    login_btn = new QPushButton("Login");
    username_edit = new QLineEdit;
    password_edit = new QLineEdit;
    username_label = new QLabel("Username:");
    password_label = new QLabel("Password:");
    password_edit->setEchoMode(QLineEdit::Password);

    mainLayout->addWidget(username_label);
    mainLayout->addWidget(username_edit);
    mainLayout->addWidget(password_label);
    mainLayout->addWidget(password_edit);
    mainLayout->addWidget(play_btn, 2);
    mainLayout->addWidget(signup_btn, 0);
    mainLayout->addWidget(login_btn, 1);
    setLayout(mainLayout);

// Create a QComboBox widget for selecting game difficulty
    difficultyComboBox = new QComboBox(this);

// Add options for game difficulty: Easy, Medium, Hard
    difficultyComboBox->addItem("Easy", QVariant(1));
    difficultyComboBox->addItem("Medium", QVariant(2));
    difficultyComboBox->addItem("Hard", QVariant(3));

// Add the difficultyComboBox to the main layout
    mainLayout->addWidget(difficultyComboBox);


    connect(play_btn, &QPushButton::clicked, this, &mainwidget::start_game_easy);
    connect(login_btn, &QPushButton::clicked, this, &mainwidget::login_);
    connect(signup_btn, &QPushButton::clicked, this, &mainwidget::signup_);

    signupWidget = new Signup(this);
    connect(signupWidget, &Signup::signupSuccessful, this, &mainwidget::onSignupSuccessful);

    userWindow = nullptr;
}

mainwidget::~mainwidget()
{
    delete signupWidget;
    delete userWindow;
}

void mainwidget::start_game_easy() {
    int difficulty = difficultyComboBox->currentData().toInt();
    game1scene* gameScene = new game1scene();
    gameScene->setDifficulty(difficulty);  // Set the difficulty level for the game scene
    QGraphicsView* mainView = new QGraphicsView(gameScene);
    mainView->setFixedSize(910, 512);
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->show();
    this->close();
}



void mainwidget::login_() {
    QString username = username_edit->text();
    QString password = password_edit->text();


    QDate birthday(2000, 1, 1);
    QString profilePicturePath = "path/to/profile/picture.png";
    User* loggedInUser = new User(username, birthday, profilePicturePath);


    userWindow = new UserWindow(loggedInUser);
    userWindow->show();


    this->hide();
}

void mainwidget::signup_() {
    signupWidget->show();
}

void mainwidget::onSignupSuccessful() {
    QMessageBox::information(this, "Signup Successful", "You have successfully signed up!");
}

