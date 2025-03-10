#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "passcodevalidator.h"
#include "videohandler.h"
#include "FileReader.h"
#include <QDir>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    PasscodeValidator validator;
    engine.rootContext()->setContextProperty("passcodeValidator", &validator);

    VideoHandler videoHandler;
    engine.rootContext()->setContextProperty("videoHandler", &videoHandler);

    FileReader fileReader;
    engine.rootContext()->setContextProperty("fileReader", &fileReader);

    QString appDirPath = QCoreApplication::applicationDirPath();

    QString qmlFilePath = appDirPath + "/PinApp/Main.qml";

    qDebug() << "Loading QML from:" << qmlFilePath;

    engine.load(QUrl::fromLocalFile(qmlFilePath));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
