import QtQuick 2.0
import QtQuick.Window 2.13

Rectangle {
    id:rect
    height:  _root.height/6
    width: _root.width/7
    color: "gray"
    Text {
        text: index
        anchors.fill: parent
        color: "white"
    }
    DropArea{
        id:droparea
        anchors.fill: parent
        onDropped:{
            rect.width=_root.width/7
        }
    }
}
