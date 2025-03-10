#include "VideoHandler.h"

VideoHandler::VideoHandler(QObject *parent) : QObject(parent) {
    player = new QMediaPlayer(this);
}

void VideoHandler::playVideo(const QString &filePath) {
    player->setSource(QUrl::fromLocalFile(filePath));
    player->play();
}

void VideoHandler::stopVideo() {
    player->stop();
}

QMediaPlayer* VideoHandler::getPlayer() {
    return player;
}
