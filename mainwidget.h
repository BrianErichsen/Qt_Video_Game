#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "signup.h"
#include "userwindow.h"
<<<<<<< HEAD
#include "user.h"
=======
#include <QComboBox>//Game difficulty dropdown menu

>>>>>>> 238a4b1b031bd99913846e6248172b6519b8e3b5

class mainwidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainwidget(QWidget* parent = nullptr);
    ~mainwidget();

private:
    QVBoxLayout* mainLayout;
    QPushButton* play_btn;
    QPushButton* signup_btn;
    QPushButton* login_btn;
    QLineEdit* username_edit;
    QLineEdit* password_edit;
    QLabel* username_label;
    QLabel* password_label;
    Signup* signupWidget;
    UserWindow* userWindow;
    QComboBox* difficultyComboBox;

private slots:
    void start_game_easy();
    void login_();
    void signup_();
    void onSignupSuccessful();
    // void handleLogout();
};

#endif // MAINWIDGET_H
