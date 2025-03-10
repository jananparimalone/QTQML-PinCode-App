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

    // Check if it's a resource path (qrc:/) or regular path
    if (filePath.startsWith("qrc:/")) {
        // If the file path points to a resource, open it with QFile
        file.setFileName(filePath);
    } else {
        // Otherwise, treat it as a regular file system path
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
        emit sourceChanged(mSource);  // Pass mSource as argument
    }
}
