#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class mainwidget : public QWidget
{
public:
    explicit mainwidget(QWidget* parent = nullptr);

private:
    QVBoxLayout* mainLayout;
    QPushButton* play_btn;
    QPushButton* signup_btn;
    QPushButton* login_btn;

private slots:
    void start_game_easy();
    void login_();
    void signup_();
};

#endif // MAINWIDGET_H
