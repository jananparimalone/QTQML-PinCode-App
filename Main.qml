import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 300
    height: 475
    color: "lightblue"
    title: "Pin App"

    Loader {
        id: pageLoader
        anchors.fill: parent
    }

    property string storedPin: ""

    function loadPinFromFile() {
        storedPin = fileReader.read(":/resources/src/passcode.txt").trim();
        console.log("Loaded PIN from file: " + storedPin);
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20
        visible: pageLoader.source !== ""

        Image {
            source: "qrc:/resources/src/logo.png"
            width: parent.width * 0.2
            height: parent.height * 0.1
            Layout.alignment: Qt.AlignHCenter
        }

        ColumnLayout {
            spacing: 5
            Layout.fillWidth: true

            Rectangle {
                width: 250
                height: 30
                color: "white"
                radius: 5
                border.color: "black"

                TextInput {
                    id: pinInput
                    anchors.fill: parent
                    echoMode: TextInput.Password
                    font.pixelSize: 18
                    leftPadding: 10
                    topPadding: 2

                    onFocusChanged: {
                        if (!focus && pinInput.text === "") {
                            placeholder.visible = true;
                        } else {
                            placeholder.visible = false;
                        }
                    }

                    anchors.verticalCenter: parent.verticalCenter

                    Text {
                        id: placeholder
                        text: "Enter PIN"
                        color: "gray"
                        anchors.left: pinInput.left
                        anchors.margins: 10
                        anchors.verticalCenter: pinInput.verticalCenter
                        visible: pinInput.text === ""
                    }
                }
            }

            Text {
                text: "Please Enter Password"
                font.pixelSize: 14
                color: "Black"
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                topPadding: 15
            }
        }

        GridLayout {
            columns: 3
            rowSpacing: 10
            columnSpacing: 10
            Layout.fillWidth: true
            Layout.fillHeight: true

            Repeater {
                model: ["1", "2\nABC", "3\nDEF", "4\nGHI", "5\nJKL", "6\nMNO",
                        "7\nPQRS", "8\nTUV", "9\nWXYZ", "Clear", "0", "Enter"]
                delegate: RoundButton {
                    text: modelData
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    onClicked: {
                        if (modelData === "Clear") {
                            pinInput.text = "";
                        } else if (modelData === "Enter") {
                            var enteredPin = pinInput.text.trim();
                            console.log("Entered PIN: " + enteredPin);
                            console.log("Stored PIN: " + storedPin);
                            if (enteredPin === storedPin) {
                                console.log("PIN Correct!");
                                pageLoader.source = "Welcome.qml";
                            } else {
                                console.log("Incorrect PIN");
                            }
                        } else {
                            pinInput.text += modelData.charAt(0);
                        }
                    }
                    background: Rectangle {
                        color: "blue"
                        radius: parent.height / 2
                        border.color: "darkblue"
                        border.width: 2
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: "skyblue" }
                            GradientStop { position: 1.0; color: "blue" }
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        loadPinFromFile();
    }
}
