#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>
#include <QVector>

class User
{
public:
    User(const QString& username, const QDate& birthday, const QString& profilePicturePath, const QString& firstName,
         const QString& lastName, const QString& password, const QString gender);
    QString getUsername() const;
    QDate getBirthday() const;
    QString getProfilePicturePath() const;
    static QVector<User*>& getUsers();//static function to get list of users
    QString getPassword() const;

private:
    QString username;
    QDate birthday;
    QString profilePicturePath;
    QString password;
    QString firstName;
    QString lastName;
    QString gender;
};

#endif // USER_H
