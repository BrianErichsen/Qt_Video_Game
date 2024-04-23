#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "user.h"
#include <QComboBox>

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(User* user, QWidget* parent = nullptr);
    void displayScoreHx();

private:
    User* loggedInUser;
    QVBoxLayout* mainLayout;
    QLabel* nameLabel;
    QLabel* profilePictureLabel;
    QLabel* dateLabel;
    QLabel* birthdayLabel;
    QPushButton* startButton;
    QComboBox* difficultyComboBox;
    // QPushButton* logoutButton;

private slots:
    void startGame();
    // void showWindow();
//     void logout();

// signals:
//     void loggedOut();
};

#endif // USERWINDOW_H
