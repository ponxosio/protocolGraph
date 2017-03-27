#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T16:28:11
#
#-------------------------------------------------

# ensure one "debug_and_release" in CONFIG, for clarity...
debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}
    # ensure one "debug" or "release" in CONFIG so they can be used as
    #   conditionals instead of writing "CONFIG(debug, debug|release)"...
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
}
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release
}

QT       -= gui

TARGET = protocolGraph
TEMPLATE = lib

DEFINES += PROTOCOLGRAPH_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += protocolGraph/protocolgraph_global.h \
    protocolGraph/operations/container/ApplyLight.h \
    protocolGraph/operations/container/ApplyTemperature.h \
    protocolGraph/operations/container/ContainerOperation.h \
    protocolGraph/operations/container/GetVolume.h \
    protocolGraph/operations/container/LoadContainerOperation.h \
    protocolGraph/operations/container/MeasureOD.h \
    protocolGraph/operations/container/Mix.h \
    protocolGraph/operations/container/SetContinousFlow.h \
    protocolGraph/operations/container/settimestep.h \
    protocolGraph/operations/container/Stir.h \
    protocolGraph/operations/container/TimeStep.h \
    protocolGraph/operations/container/Transfer.h \
    protocolGraph/operations/AssignationOperation.h \
    protocolGraph/ConditionEdge.h \
    protocolGraph/ProtocolGraph.h \
    protocolGraph/operables/comparison/BooleanComparison.h \
    protocolGraph/operables/comparison/ComparisonOperable.h \
    protocolGraph/operables/comparison/SimpleComparison.h \
    protocolGraph/operables/comparison/Tautology.h \
    protocolGraph/operables/mathematics/ArithmeticOperation.h \
    protocolGraph/operables/mathematics/ConstantNumber.h \
    protocolGraph/operables/mathematics/MathematicOperable.h \
    protocolGraph/operables/mathematics/UnaryOperation.h \
    protocolGraph/operables/mathematics/VariableEntry.h \
    protocolGraph/operables/VariableTable.h \
    protocolGraph/execution_interface/actuatorsexecutioninterface.h \
    protocolGraph/operations/cpuoperation.h \
    protocolGraph/operables/mathematics/protocolmathf.h \
    protocolGraph/operables/comparison/protocolboolf.h \
    protocolGraph/operations/controlnode.h \
    protocolGraph/protocol_graph_utils/controlstackelement.h

SOURCES += \
    protocolGraph/operations/container/ApplyLight.cpp \
    protocolGraph/operations/container/ApplyTemperature.cpp \
    protocolGraph/operations/container/GetVolume.cpp \
    protocolGraph/operations/container/LoadContainerOperation.cpp \
    protocolGraph/operations/container/MeasureOD.cpp \
    protocolGraph/operations/container/Mix.cpp \
    protocolGraph/operations/container/SetContinousFlow.cpp \
    protocolGraph/operations/container/settimestep.cpp \
    protocolGraph/operations/container/Stir.cpp \
    protocolGraph/operations/container/TimeStep.cpp \
    protocolGraph/operations/container/Transfer.cpp \
    protocolGraph/operations/AssignationOperation.cpp \
    protocolGraph/ConditionEdge.cpp \
    protocolGraph/ProtocolGraph.cpp \
    protocolGraph/operables/comparison/BooleanComparison.cpp \
    protocolGraph/operables/comparison/SimpleComparison.cpp \
    protocolGraph/operables/mathematics/ArithmeticOperation.cpp \
    protocolGraph/operables/mathematics/ConstantNumber.cpp \
    protocolGraph/operables/mathematics/UnaryOperation.cpp \
    protocolGraph/operables/mathematics/VariableEntry.cpp \
    protocolGraph/operables/VariableTable.cpp \
    protocolGraph/operables/mathematics/protocolmathf.cpp \
    protocolGraph/operables/comparison/protocolboolf.cpp \
    protocolGraph/operations/controlnode.cpp \
    protocolGraph/protocol_graph_utils/controlstackelement.cpp

debug {
    QMAKE_POST_LINK=X:\protocolGraph\protocolGraph\setDLL.bat $$shell_path($$OUT_PWD/debug) debug
    INCLUDEPATH += X:\utils\dll_debug\include
    LIBS += -L$$quote(X:\utils\dll_debug\bin) -lutils
}

!debug {
    QMAKE_POST_LINK=X:\protocolGraph\protocolGraph\setDLL.bat $$shell_path($$OUT_PWD/release) release
    INCLUDEPATH += X:\utils\dll_release\include
    LIBS += -L$$quote(X:\utils\dll_release\bin) -lutils
}

INCLUDEPATH += X:\libraries\cereal-1.2.2\include


