import QtQuick 2.0
import QtQuick.Window 2.13

Item {
    height: _root.height
    width: _root.width
    MyGrid{
        id:_grid1
    }
    MyListView{
        id:_list1
        anchors.left: _grid1.right
        anchors.leftMargin: _root.width/4
    }
}
