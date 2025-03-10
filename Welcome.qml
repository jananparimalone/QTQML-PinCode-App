import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Video Player"
    color: "#ADD8E6"

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "Welcome to Janan's World!"
            font.pixelSize: 20
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            id: videoContainer
            width: 350
            height: 180
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter

            Video {
                id: videoPlayer
                source: "qrc:/resources/src/ParaglidingSamoyed.mp4"
                visible: true

                width: videoContainer.width
                height: videoContainer.height
            }
        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Play"
                onClicked: videoPlayer.play()
            }

            Button {
                text: "Stop"
                onClicked: videoPlayer.stop()
            }

            Button {
                text: "Exit"
                onClicked: Qt.quit()
            }
        }
    }
}
