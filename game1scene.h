#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsScene>
#include "bucket.h"
#include <QSoundEffect> // Include for sound effects
#include "waterdroplet.h"
#include <QMediaPlayer>
#include <QAudioOutput>


/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * game1Scene class represents a QGraphicsScene object
*/
class game1scene : public QGraphicsScene
{
    Q_OBJECT
private:
    QGraphicsTextItem* droplet_count;
    QGraphicsTextItem* score_count;
    QGraphicsTextItem* missed_count;
    QTimer* spawn_droplets;
    QSoundEffect scoreSound; // Sound effect for scoring
    QSoundEffect missSound; // Sound effect for missing a droplet
    QMediaPlayer* backgroundMusic;
    QAudioOutput* audioOutput;
    int score;
    int collectedDroplets;
    int missedDroplets;
    int currentDifficulty;//Used for storing the current game difficulty


public:
    explicit game1scene(QGraphicsScene* parent = nullptr);
    int getCollectedDroplets();
    int getScore();
    int getMissedDroplets();
    int getDifficulty();
    int setDifficulty(int difficulty);

public slots:
    void updateScore();
    void updateMissedDroplet();
    void spawn_water_slot();
};

#endif // GAME1SCENE_H
