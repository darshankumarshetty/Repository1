import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    id:_root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var retVal
    property var newDatA
    Row{
        id:_row
        width:_root.width
        height: _root.height/6
        anchors.margins: 5
        spacing: 3
        Button{
            signal sendSignal
            id:_b1
            anchors.top: parent.top
            anchors.topMargin: 5
            text:"ADD"
            onClicked: {
                console.log("Clicked_"+_b1.text)
                sendSignal()
            }
        }
        TextField{
            id:_txtinpt1
            font.pixelSize: 20
            width: 140;
            height: 50
            placeholderText: "First Name"
            onTextChanged: {
             pop_1.visible=true
            }
            Rectangle{
                id:rec1
                width: _txtinpt1.width
                height: _txtinpt1.height
                anchors.top: _txtinpt1.bottom
                Popup{
                    id:pop_1
                    visible: false
                    Text {
                        id: tx1
                        text: PMdl.searchData(_txtinpt1.text)
                    }
                }
            }
        }
        TextField{
            id:_txtinpt7
            font.pixelSize: 20
            width: 140;
            height: 50
            placeholderText: "Middle Name"
        }
        TextField{
            id:_txtinpt8
            font.pixelSize: 20
            width:140;
            height: 50
            placeholderText: "Last Name"
        }
        Button{
            signal sendData();
            id:_b2
            anchors.top: parent.top
            anchors.topMargin: 5
            text:"Search"
            onClicked: {
                sendData()
            }
        }
    }
    Grid {
        id:_grid
        columns: 2
        columnSpacing: _root.height/7
        rowSpacing: _root.width/12.8
        width:_root.width
        height: _root.height
        anchors.top: _row.bottom
        anchors.topMargin: 30
        Row{
            TextField { id:_txtinpt2; placeholderText: "First Name"; width: 130; height: 40; font.pixelSize: 20}
            TextField { id:_txtinpt2_1; placeholderText: "Middle Name"; width: 130; height: 40; font.pixelSize: 19}
            TextField { id:_txtinpt2_2; placeholderText: "Last Name"; width: 130; height: 40; font.pixelSize: 20}
        }
        TextField { id:_txtinpt3; placeholderText: "Age"; width: 180; height: 40; font.pixelSize: 20 }
        TextField { id:_txtinpt4; placeholderText: "Gender"; width: 200; height: 40; font.pixelSize: 20 }
        TextField { id:_txtinpt5; placeholderText: "Disease"; width: 180; height: 40; font.pixelSize: 20 }
        TextField { id:_txtinpt6; placeholderText: "Address"; width: 200; height: 40; font.pixelSize: 20; }
        Button{
            id:_b3
            text:"CLEAR"
            visible: false
            onClicked: {
                _txtinpt1.clear();
                _txtinpt2.clear();
                _txtinpt2_1.clear();
                _txtinpt2_2.clear();
                _txtinpt3.clear();
                _txtinpt4.clear();
                _txtinpt5.clear();
                _txtinpt6.clear();
                _txtinpt7.clear();
                _txtinpt8.clear();
            }
        }
    }
    Connections{
        id:searchConnection
        target:_b2
        function onSendData(){
            _b3.visible=true
            if(_txtinpt1.text !== ""){
                retVal=PMdl.compareData(_txtinpt1.text,_txtinpt7.text,_txtinpt8.text)
            }
            else{
                console.log("There is no data");
                return;
            }
            console.log("RET V :"+retVal )
            if(retVal!==null){
                _txtinpt2.text=retVal.PName
                _txtinpt2_1.text=retVal.MName
                _txtinpt2_2.text=retVal.LName
                _txtinpt3.text=retVal.PAge
                _txtinpt4.text=retVal.PGender
                _txtinpt5.text=retVal.PDisease
                _txtinpt6.text=retVal.PAddress
            }
            else{
                pop.visible=true
                _txtinpt2.clear();
                _txtinpt2_1.clear();
                _txtinpt2_2.clear();
                _txtinpt3.clear();
                _txtinpt4.clear();
                _txtinpt5.clear();
                _txtinpt6.clear();
            }
        }
    }
    Connections{
        id:addConnection
        target:_b1
        function onSendSignal(){
            _b3.visible=true
            if(_txtinpt2.text !== ""){
                PMdl.addNewData(_txtinpt2.text,_txtinpt3.text,_txtinpt4.text,_txtinpt5.text,_txtinpt6.text,_txtinpt2_1.text,_txtinpt2_2.text)
            }
            else{
                console.log("There is no data");
            }
        }
    }
    Popup{
        id:pop
        width: _root.width-150
        height: _root.height-150
        anchors.centerIn: parent
        modal: true
        focus:true
        visible: false
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        Text{
            id:_txt1
            text: "There is NO DATA"
            font.pixelSize: 25
            anchors.centerIn: parent
        }
    }
}
