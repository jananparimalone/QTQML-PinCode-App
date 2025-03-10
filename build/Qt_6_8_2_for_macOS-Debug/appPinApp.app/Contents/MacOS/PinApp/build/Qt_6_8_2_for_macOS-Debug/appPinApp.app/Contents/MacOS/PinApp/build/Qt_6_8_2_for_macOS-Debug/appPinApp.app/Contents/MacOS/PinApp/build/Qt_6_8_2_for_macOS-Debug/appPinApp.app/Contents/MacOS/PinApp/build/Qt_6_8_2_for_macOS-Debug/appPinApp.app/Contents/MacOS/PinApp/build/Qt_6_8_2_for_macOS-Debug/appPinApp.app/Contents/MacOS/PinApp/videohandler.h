#ifndef VIDEOHANDLER_H
#define VIDEOHANDLER_H

#include <QObject>
#include <QMediaPlayer>

class VideoHandler : public QObject {
    Q_OBJECT  // Ensure MOC processes this

public:
    explicit VideoHandler(QObject *parent = nullptr);

    Q_INVOKABLE void playVideo(const QString &filePath);
    Q_INVOKABLE void stopVideo();
    Q_INVOKABLE QMediaPlayer* getPlayer();

private:
    QMediaPlayer *player;
};

#endif // VIDEOHANDLER_H
