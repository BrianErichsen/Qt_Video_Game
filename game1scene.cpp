#include "game1scene.h"
#include <QtCore/QCoreApplication>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include "waterdroplet.h"
#include <QMessageBox>
#include <QSignalBlocker>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "userwindow.h"
#include <QGraphicsProxyWidget>



/*Author: Brian Erichsen Fagundes, Xiyao Xu & Xuan Zhang
 * MSD - CS6015 Software Engineering
 * Spring - 2024 - UofU
 * class game part 1 scene implementation
*/

game1scene::game1scene(QGraphicsScene* parent) : QGraphicsScene(parent)
{
    // Load background into scene and scale it
    setBackgroundBrush(QBrush(QImage(":/resources/background.jpg").scaledToHeight(512).scaledToWidth(910)));
    setSceneRect(0, 0, 908, 510);

    // Initialize sound effects
    scoreSound.setSource(QUrl("qrc:/resources/score_water.wav"));
    scoreSound.setVolume(0.75); // Set volume for scoring sound
    missSound.setSource(QUrl("qrc:/resources/missed_droplets.wav"));
    missSound.setVolume(0.75); // Set volume for missed sound

    backgroundMusic = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);  // 初始化 QAudioOutput
    backgroundMusic->setAudioOutput(audioOutput); // 设置 QMediaPlayer 使用的音频输出
    backgroundMusic->setSource(QUrl("qrc:/resources/background_music.mp3")); // 设置背景音乐源
    audioOutput->setVolume(0.5); // 设置音量为 50%
    backgroundMusic->play(); // 播放背景音乐

    //creates instance of bucket
    bucket* bucket_item = new bucket(this);
    bucket_item->setPos(400, 365);//sets it's initial position
    addItem(bucket_item);//adds item into scene
    //sets variables into 0 in initial state
    score = 0;
    collectedDroplets = 0;
    missedDroplets = 0;
    //------------------- creates text item for collected droplets
    droplet_count = new QGraphicsTextItem();
    droplet_count->setHtml("<font color='blue' size='5'>Collected Droplets: </font>" + QString("<font color='blue' size='5'>%1</font>").arg(collectedDroplets) + "</font");
    droplet_count->setPos(10, 120);
    addItem(droplet_count);
    //------------------- creates text item for showing total score
    score_count = new QGraphicsTextItem();
    score_count->setHtml("<font color='red' size='5'>Score: </font>" + QString("<font color='red' size='5'>%1</font>").arg(score) + "</font");
    score_count->setPos(10, 100);
    addItem(score_count);
    //-------------------- creates text item for showing how many missed droplets are there
    missed_count = new QGraphicsTextItem();
    missed_count->setHtml("<font color='green' size='5'>Missed Droplets: </font>" + QString("<font color='green' size='5'>%1</font>").arg(missedDroplets) + "</font");
    missed_count->setPos(10, 140);
    addItem(missed_count);
    //----creates timer for spawning droplets through the play of the game
    spawn_droplets = new QTimer(this);
    connect(spawn_droplets, &QTimer::timeout, this, &game1scene::spawn_water_slot);
    spawn_droplets->start(0);
    spawn_droplets->setInterval(10000);

    openUserWindow_btn = new QPushButton("User Window");
    QGraphicsProxyWidget* proxy = addWidget(openUserWindow_btn);
    proxy->setPos(10, 10); // Adjust position as needed
    connect(openUserWindow_btn, &QPushButton::clicked, this, &game1scene::openUserWindow);

    //creates appropriate number of water droplets --16
    spawn_water_slot();
    //creates appropriate number of clouds up on the screen
    for (int i = 0; i < 7; ++i) {
        QGraphicsPixmapItem* clouds = new QGraphicsPixmapItem();
        clouds->setPixmap(QPixmap("://resources/cloud.png").scaled(125, 100));
        clouds->setPos(750 - i * 120, 0);
        addItem(clouds);
    }
    this_user;
}

void game1scene::updateScore() {
    collectedDroplets++;//increments collected droplets variable
    score += 20;//each droplet is worth 5 points
    //we can change design for something better
    droplet_count->setHtml("<font color='blue' size='5'>Collected Droplets: </font>" + QString("<font color='blue' size='5'>%1</font>").arg(collectedDroplets) + "</font");
    score_count->setHtml("<font color='red' size='5'>Score: </font>" + QString("<font color='red' size='5'>%1</font>").arg(score) + "</font");
    if (score >= 150) {
        QGraphicsTextItem* winText = new QGraphicsTextItem();
        winText->setHtml("<font color='red' size='8'> You Won the Game!!!! </font");
        int xPos = width() / 2 - winText->boundingRect().width() / 2;
        int yPos = width() / 2 - winText->boundingRect().height() / 2;
        winText->setPos(xPos, yPos);
        addItem(winText);
        spawn_droplets->stop();
        backgroundMusic->stop();
        emit gameFinished(score);
    }
}

void game1scene::updateMissedDroplet() {
    missedDroplets++;//increments missed droplets and set new text to screen
    missed_count->setHtml("<font color='green' size='5'>Missed Droplets: </font>" + QString("<font color='green' size='5'>%1</font>").arg(missedDroplets) + "</font");
    //sets the rule to lose the game condition
    if (missedDroplets >= 5) {
        //creates a new text that will display loosing message
        QGraphicsTextItem* gameOverText = new QGraphicsTextItem();
        gameOverText->setHtml("<font color='red' size='8'> Game Over! </font");
        int xPos = width() / 2 - gameOverText->boundingRect().width() / 2;
        int yPos = width() / 2 - gameOverText->boundingRect().height() / 2;
        gameOverText->setPos(xPos, yPos);
        //adds it to main layout
        addItem(gameOverText);
        //stops creating new droplets
        spawn_droplets->stop();
        backgroundMusic->stop();
    }
}
//-------------  getters methods
int game1scene::getCollectedDroplets() {
    return collectedDroplets;
}

int game1scene::getMissedDroplets() {
    return missedDroplets;
}

int game1scene::getScore() {
    return score;
}

void game1scene::spawn_water_slot() {
    for (int i = 0; i < 7; ++i) {
        waterDroplet* water_droplets = new waterDroplet(this);
        //connects score water signal to update score slot / method
        connect(water_droplets, &waterDroplet::score_water, this, &game1scene::updateScore);
        //connects missed droplets signal to update amount of missed droplets
        connect(water_droplets, &waterDroplet::missed_droplets, this, &game1scene::updateMissedDroplet);
        connect(water_droplets, &waterDroplet::score_water, &scoreSound, &QSoundEffect::play);
        connect(water_droplets, &waterDroplet::missed_droplets, &missSound, &QSoundEffect::play);
        //randomly chooses a spawn point
        int rand_number_x = QRandomGenerator::global()->bounded(860);
        int rand_number_y = QRandomGenerator::global()->bounded(150);
        //making sure that no droplet is out of reach from bucket
        water_droplets->setPos(rand_number_x + 10, 75 + rand_number_y);
        addItem(water_droplets);
    }
}

int game1scene::setDifficulty(int difficulty) {
    currentDifficulty = difficulty;  // Store the difficulty value set from outside
}

int game1scene::getDifficulty() {
    return currentDifficulty;  // Return the currently stored difficulty value
}

void game1scene::openUserWindow() {
    UserWindow* userW = new UserWindow(this_user);
    userW->show();
}



