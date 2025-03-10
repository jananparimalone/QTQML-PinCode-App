#include "FileReader.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QString FileReader::read(const QString &filePath) {
    if (filePath.isEmpty()) {
        emit error("Source is empty");
        return QString();
    }

    QFile file;
    QString fileContent;

    if (filePath.startsWith("qrc:/")) {

        file.setFileName(filePath);
    } else {

        file.setFileName(filePath);
    }

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        fileContent = stream.readAll();
        file.close();
    } else {
        emit error("Unable to open the file: " + filePath);
        return QString();
    }

    return fileContent;
}

bool FileReader::write(const QString &data) {
    if (mSource.isEmpty()) {
        emit error("Source is empty");
        return false;
    }

    QFile file(mSource);
    if (!file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)) {
        emit error("Unable to open file for writing");
        return false;
    }

    QTextStream out(&file);
    out << data;
    file.close();
    return true;
}

void FileReader::setSource(const QString &source)
{
    if (mSource != source) {
        mSource = source;
        emit sourceChanged(mSource);
    }
}
