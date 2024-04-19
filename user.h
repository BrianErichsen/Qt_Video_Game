#ifndef QT_VIDEO_GAME_USER_H
#define QT_VIDEO_GAME_USER_H

#include <string>

class User {
public:
    // Constructor
    User(const std::string &username, const std::string &password, const std::string &firstName,
         const std::string &lastName, const std::string &birthdate, const std::string &profilePicturePath,
         int lastScore = 0, int bestScore = 0, int ranking = 0);

    // Methods to get and set user information
    std::string getUsername() const;                 // Get username
    void setPassword(const std::string &password);    // Set password
    std::string getFirstName() const;                // Get first name
    std::string getLastName() const;                 // Get last name
    std::string getBirthdate() const;                // Get birthdate
    std::string getProfilePicturePath() const;       // Get profile picture path
    int getLastScore() const;                        // Get last score
    void updateLastScore(int score);                 // Update last score
    int getBestScore() const;                        // Get best score
    void updateBestScore(int score);                 // Update best score
    int getRanking() const;                          // Get ranking
    void updateRanking(int ranking);                 // Update ranking

private:
    std::string username;                // User's username
    std::string password;                // User's password
    std::string firstName;               // User's first name
    std::string lastName;                // User's last name
    std::string birthdate;               // User's birthdate
    std::string profilePicturePath;      // User's profile picture path
    int lastScore;                       // User's last score
    int bestScore;                       // User's best score
    int ranking;                         // User's ranking
};

#endif // QT_VIDEO_GAME_USER_H
