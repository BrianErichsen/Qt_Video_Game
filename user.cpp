#include "user.h"

User::User(const QString& username, const QDate& birthday, const QString& profilePicturePath)
    : username(username), birthday(birthday), profilePicturePath(profilePicturePath)
{
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
