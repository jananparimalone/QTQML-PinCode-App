#include "passcodevalidator.h"

PasscodeValidator::PasscodeValidator(QObject *parent) : QObject(parent) {}

bool PasscodeValidator::validatePin(const QString &enteredPin) {
    QFile file(":/resources/src/passcode.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    QString storedPin = in.readLine().trimmed();
    file.close();

    return enteredPin == storedPin;
}
