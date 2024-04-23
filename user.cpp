#include "user.h"

User::User(const QString& username, const QDate& birthday, const QString& profilePicturePath, const QString& firstName,
         const QString& lastName, const QString& password, const QString gender)
    : username(username), birthday(birthday), profilePicturePath(profilePicturePath), firstName(firstName),
    lastName(lastName), password(password), gender(gender)
{
    gameScores = QVector<int>();
}

QString User::getUsername() const {
    return username;
}

QDate User::getBirthday() const {
    return birthday;
}

QString User::getProfilePicturePath() const {
    return profilePicturePath;
}

QVector<User*>& User::getUsers() {
    static QVector<User*> users;
    return users;
}

QString User::getPassword() const {
    return password;
}

void User::addGameScore(int score) {
    gameScores.append(score);
}
