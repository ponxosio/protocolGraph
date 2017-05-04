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
    protocolGraph/protocol_graph_utils/controlstackelement.h \
    protocolGraph/operations/container/stopcontinuosflow.h \
    protocolGraph/operations/container/actuatorsoperation.h \
    protocolGraph/operables/comparison/characteristiccheck.h \
    protocolGraph/operables/mathematics/randomfraction.h \
    protocolGraph/operables/mathematics/randominteger.h \
    protocolGraph/operables/mathematics/testoperation.h \
    protocolGraph/container/virtualcontainer.h \
    protocolGraph/operations/container/finishoperation.h \
    protocolGraph/operations/container/finishableoperation.h \
    protocolGraph/operations/container/electrophoresisoperation.h \
    protocolGraph/execution_interface/electrophoresisresult.h \
    protocolGraph/operations/container/centrifugateoperation.h \
    protocolGraph/operations/container/shakeoperation.h \
    protocolGraph/operations/container/measurefluorescence.h \
    protocolGraph/operations/container/measureluminiscence.h \
    protocolGraph/operations/container/measurevolume.h \
    protocolGraph/operations/container/measuretemperature.h

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
    protocolGraph/protocol_graph_utils/controlstackelement.cpp \
    protocolGraph/operations/container/stopcontinuosflow.cpp \
    protocolGraph/operables/comparison/characteristiccheck.cpp \
    protocolGraph/operables/mathematics/randomfraction.cpp \
    protocolGraph/operables/mathematics/randominteger.cpp \
    protocolGraph/operables/mathematics/testoperation.cpp \
    protocolGraph/operations/container/finishoperation.cpp \
    protocolGraph/operations/container/electrophoresisoperation.cpp \
    protocolGraph/operations/container/centrifugateoperation.cpp \
    protocolGraph/operations/container/shakeoperation.cpp \
    protocolGraph/operations/container/measurefluorescence.cpp \
    protocolGraph/operations/container/measureluminiscence.cpp \
    protocolGraph/operations/container/measurevolume.cpp \
    protocolGraph/operations/container/measuretemperature.cpp

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


