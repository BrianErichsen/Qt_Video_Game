#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>

class User
{
public:
    User(const QString& username, const QDate& birthday, const QString& profilePicturePath);
    QString getUsername() const;
    QDate getBirthday() const;
    QString getProfilePicturePath() const;

private:
    QString username;
    QDate birthday;
    QString profilePicturePath;
};

#endif // USER_H
