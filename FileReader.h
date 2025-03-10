#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QString>

class FileReader : public QObject
{
    Q_OBJECT

public:
    explicit FileReader(QObject *parent = nullptr) : QObject(parent) {}

    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)

    Q_INVOKABLE QString read(const QString &filePath);
    bool write(const QString &data);
    QString source() const { return mSource; }
    void setSource(const QString &source);

signals:
    void sourceChanged(const QString &source);
    void error(const QString &message);

private:
    QString mSource;
};

#endif
