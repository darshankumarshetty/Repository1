import QtQuick 2.0
import QtQuick.Layouts 1.3

Item{
    height: _root.height; width: _root.width/6
    signal dataRemove(var index)
    ListView {
        height: _root.height
        width: _root.width/7
        spacing: 2
        model:Lvmdl
        delegate:MyListDelegate{
        }
    }
}
