#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T16:28:11
#
#-------------------------------------------------

QT       -= gui

TARGET = protocolGraph
TEMPLATE = lib

DEFINES += PROTOCOLGRAPH_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    protocolGraph/protocolgraph.h \
    protocolGraph/protocolgraph_global.h

SOURCES += \
    protocolGraph/protocolgraph.cpp

debug {
    QMAKE_POST_LINK=X:\protocolGraph\protocolGraph\setDLL.bat $$shell_path($$OUT_PWD/debug) debug
}

!debug {
    QMAKE_POST_LINK=X:\protocolGraph\protocolGraph\setDLL.bat $$shell_path($$OUT_PWD/release) release
}


