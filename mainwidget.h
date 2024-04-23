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
#include "user.h"

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

private slots:
    void start_game_easy();
    void login_();
    void signup_();
    void onSignupSuccessful();
    // void handleLogout();
};

#endif // MAINWIDGET_H
