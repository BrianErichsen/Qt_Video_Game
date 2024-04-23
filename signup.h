#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
#include <QDateEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QFileDialog>
#include <userwindow.h>

class Signup : public QWidget {
    Q_OBJECT
public:
    explicit Signup(QWidget* parent = nullptr);
    ~Signup();
    QVBoxLayout* mainLayout_signUp;

signals:
    void signupSuccessful();

private slots:
    void onOkClicked();
    void onCancelClicked();
    void onSelectProfilePictureClicked();

private:
    QLineEdit* firstNameEdit;
    QLineEdit* lastNameEdit;
    QDateEdit* dobEdit;
    QComboBox* genderCombo;
    QLineEdit* profilePicEdit;
    QPushButton* profilePicBtn;
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    QPushButton* okBtn;
    QPushButton* cancelBtn;
    UserWindow* userWindow_signup;

    void setupUI();
    bool validateForm();
    bool validateUsername(const QString& username);
    bool validatePassword(const QString& password);
};

#endif // SIGNUP_H
