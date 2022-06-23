import QtQuick 2.0
import QtQuick.Window 2.13
import comps 1.0
Item {
    id: item
    height: _root.height/7
    width:_root.width/8
    //    signal dataRemove()
    MouseArea {
        id: mouseArea
        height: parent.height
        width:parent.width
        drag.target: rect
        onReleased: {
            parent = rect.Drag.target !== null ? rect.Drag.target : item
            rect.Drag.drop()
            console.log(" Item_index:"+index+" Item_Object:"+rect)
        }

        Rectangle {
            id:rect
            height: parent.height
            width: parent.width
            color: "maroon"
            Text {
                text: index
                color: "white"
            }
            MyRect{
                id:rec
                height: rect.height-20
                width: rect.width-20
            }
            Drag.active: mouseArea.drag.active
            Drag.hotSpot.x:10
            Drag.hotSpot.y:10
            Drag.onActiveChanged: {
                //                dataRemove()
            }
            Drag.onDragFinished: {
                console.log(rect.x)
            }

            states: [
                State {
                    when: mouseArea.drag.active
                    ParentChange{target:rect;parent:item}
                }
            ]
        }
    }
}
