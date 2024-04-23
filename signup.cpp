#include "signup.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "user.h"
#include <QVector>

Signup::Signup(QWidget* parent) : QWidget(parent) {
    setupUI();
}

Signup::~Signup() {

    delete firstNameEdit;
    delete lastNameEdit;
    delete dobEdit;
    delete genderCombo;
    delete profilePicEdit;
    delete profilePicBtn;
    delete usernameEdit;
    delete passwordEdit;
    delete okBtn;
    delete cancelBtn;
}

void Signup::setupUI() {
    mainLayout_signUp = new QVBoxLayout(this);
    QFormLayout* formLayout = new QFormLayout();

    firstNameEdit = new QLineEdit();
    lastNameEdit = new QLineEdit();
    dobEdit = new QDateEdit();
    dobEdit->setCalendarPopup(true);
    genderCombo = new QComboBox();
    genderCombo->addItem("Male");
    genderCombo->addItem("Female");
    genderCombo->addItem("Other");
    profilePicEdit = new QLineEdit();
    profilePicEdit->setReadOnly(true);
    profilePicBtn = new QPushButton("Select Picture");
    usernameEdit = new QLineEdit();
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);

    formLayout->addRow(new QLabel("First Name:"), firstNameEdit);
    formLayout->addRow(new QLabel("Last Name:"), lastNameEdit);
    formLayout->addRow(new QLabel("Date of Birth:"), dobEdit);
    formLayout->addRow(new QLabel("Gender:"), genderCombo);
    QHBoxLayout* picLayout = new QHBoxLayout();
    picLayout->addWidget(profilePicEdit);
    picLayout->addWidget(profilePicBtn);
    formLayout->addRow(new QLabel("Profile Picture:"), picLayout);
    formLayout->addRow(new QLabel("Username:"), usernameEdit);
    formLayout->addRow(new QLabel("Password:"), passwordEdit);

    okBtn = new QPushButton("OK");
    cancelBtn = new QPushButton("Cancel");
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(cancelBtn);

    mainLayout_signUp->addLayout(formLayout);
    mainLayout_signUp->addLayout(btnLayout);

    connect(okBtn, &QPushButton::clicked, this, &Signup::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked, this, &Signup::onCancelClicked);
    connect(profilePicBtn, &QPushButton::clicked, this, &Signup::onSelectProfilePictureClicked);
    userWindow_signup = nullptr;
}

void Signup::onOkClicked() {
    if (validateForm()) {
        QString firstName = firstNameEdit->text();
        QString lastName = lastNameEdit->text();
        QDate dob = dobEdit->date();
        QString gender = genderCombo->currentText();
        QString profilePicturePath = profilePicEdit->text();
        QString username = usernameEdit->text();
        QString password = passwordEdit->text();

        User* newUser = new User(username, dob, profilePicturePath, username, password, lastName, gender);
        QVector<User*>& users = User::getUsers();
        users.append(newUser);
        userWindow_signup = new UserWindow(newUser);

        userWindow_signup->show();
        this->close();
        emit signupSuccessful();

    }
}

void Signup::onCancelClicked() {
    this->close();
}

void Signup::onSelectProfilePictureClicked() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select Profile Picture", "", "Image Files (*.png *.jpg *.jpeg)");
    if (!fileName.isEmpty()) {
        profilePicEdit->setText(fileName);
    }
}

bool Signup::validateForm() {
    if (firstNameEdit->text().isEmpty() || lastNameEdit->text().isEmpty() || usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Please fill in all required fields.");
        return false;
    }

    if (!validatePassword(passwordEdit->text())) {
        QMessageBox::warning(this, "Validation Error", "Password must be at least 8 characters long and include numbers, uppercase and lowercase letters.");
        return false;
    }

    return true;
}

bool Signup::validatePassword(const QString& password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (int i = 0; i < password.length(); ++i) {
        if (password[i].isUpper()) hasUpper = true;
        if (password[i].isLower()) hasLower = true;
        if (password[i].isDigit()) hasDigit = true;
    }

    return hasUpper && hasLower && hasDigit;
}
