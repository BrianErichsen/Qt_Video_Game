#include "user.h"

// Constructor
User::User(const std::string &username, const std::string &password, const std::string &firstName,
           const std::string &lastName, const std::string &birthdate, const std::string &profilePicturePath,
           int lastScore, int bestScore, int ranking) :
        username(username), password(password), firstName(firstName), lastName(lastName),
        birthdate(birthdate), profilePicturePath(profilePicturePath), lastScore(lastScore),
        bestScore(bestScore), ranking(ranking) {}

// Get username
std::string User::getUsername() const {
    return username;
}

// Set password
void User::setPassword(const std::string &newPassword) {
    password = newPassword;
}

// Get first name
std::string User::getFirstName() const {
    return firstName;
}

// Get last name
std::string User::getLastName() const {
    return lastName;
}

// Get birthdate
std::string User::getBirthdate() const {
    return birthdate;
}

// Get profile picture path
std::string User::getProfilePicturePath() const {
    return profilePicturePath;
}

// Get last score
int User::getLastScore() const {
    return lastScore;
}

// Update last score
void User::updateLastScore(int score) {
    lastScore = score;
}

// Get best score
int User::getBestScore() const {
    return bestScore;
}

// Update best score
void User::updateBestScore(int score) {
    if (score > bestScore) {
        bestScore = score;
    }
}

// Get ranking
int User::getRanking() const {
    return ranking;
}

// Update ranking
void User::updateRanking(int newRanking) {
    ranking = newRanking;
}
