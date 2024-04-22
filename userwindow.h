#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "user.h"

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(User* user, QWidget* parent = nullptr);

private:
    User* loggedInUser;
    QVBoxLayout* mainLayout;
    QLabel* nameLabel;
    QLabel* profilePictureLabel;
    QLabel* dateLabel;
    QLabel* birthdayLabel;
    QPushButton* startButton;

private slots:
    void startGame();
};

#endif // USERWINDOW_H
