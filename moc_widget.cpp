/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Wed Sep 23 11:25:07 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,    7,    7,    7, 0x0a,
      57,    7,    7,    7, 0x0a,
      68,    7,    7,    7, 0x0a,
      89,    8,    7,    7, 0x0a,
     121,  115,    7,    7, 0x0a,
     144,    7,    7,    7, 0x0a,
     155,    7,    7,    7, 0x0a,
     171,    7,    7,    7, 0x0a,
     185,    7,    7,    7, 0x0a,
     200,    7,    7,    7, 0x0a,
     218,    7,    7,    7, 0x0a,
     232,    7,    7,    7, 0x0a,
     251,    7,    7,    7, 0x0a,
     266,    7,    7,    7, 0x0a,
     284,    7,    7,    7, 0x0a,
     302,    7,    7,    7, 0x0a,
     322,    7,    7,    7, 0x0a,
     341,    7,    7,    7, 0x0a,
     362,    7,    7,    7, 0x0a,
     380,    7,    7,    7, 0x0a,
     398,    7,    7,    7, 0x0a,
     416,    7,    7,    7, 0x0a,
     428,    7,    7,    7, 0x0a,
     447,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0time,timeLen\0sendTimePos(char*,char*)\0"
    "nextSong()\0lastSong()\0playModeToNextSong()\0"
    "setLableTime(char*,char*)\0value\0"
    "voiceSliderChange(int)\0singSeek()\0"
    "setVideoSound()\0setListSing()\0"
    "setList2Sing()\0setPauseSongPos()\0"
    "setPlayMode()\0pushButtonObject()\0"
    "sliderFunCmd()\0clickedSingItem()\0"
    "changeBigWindow()\0changeSmallWindow()\0"
    "changeBig2Window()\0changeSmall2Window()\0"
    "setWindowStyle1()\0setWindowStyle2()\0"
    "setWindowStyle3()\0showStyle()\0"
    "showDefaultStyle()\0setSearchSing()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendTimePos((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2]))); break;
        case 1: nextSong(); break;
        case 2: lastSong(); break;
        case 3: playModeToNextSong(); break;
        case 4: setLableTime((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2]))); break;
        case 5: voiceSliderChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: singSeek(); break;
        case 7: setVideoSound(); break;
        case 8: setListSing(); break;
        case 9: setList2Sing(); break;
        case 10: setPauseSongPos(); break;
        case 11: setPlayMode(); break;
        case 12: pushButtonObject(); break;
        case 13: sliderFunCmd(); break;
        case 14: clickedSingItem(); break;
        case 15: changeBigWindow(); break;
        case 16: changeSmallWindow(); break;
        case 17: changeBig2Window(); break;
        case 18: changeSmall2Window(); break;
        case 19: setWindowStyle1(); break;
        case 20: setWindowStyle2(); break;
        case 21: setWindowStyle3(); break;
        case 22: showStyle(); break;
        case 23: showDefaultStyle(); break;
        case 24: setSearchSing(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void Widget::sendTimePos(char * _t1, char * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
