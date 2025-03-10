#ifndef PASSCODEVALIDATOR_H
#define PASSCODEVALIDATOR_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class PasscodeValidator : public QObject {
    Q_OBJECT
public:
    explicit PasscodeValidator(QObject *parent = nullptr);
    Q_INVOKABLE bool validatePin(const QString &enteredPin);
};

#endif // PASSCODEVALIDATOR_H
