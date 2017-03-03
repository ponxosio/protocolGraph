COPY %1\protocolGraph.dll X:\protocolGraph\dll_%2\bin\protocolGraph.dll
COPY %1\protocolGraph.lib X:\protocolGraph\dll_%2\bin\protocolGraph.lib

DEL /S X:\protocolGraph\dll_%2\include\*.h
XCOPY /S /Y X:\protocolGraph\protocolGraph\*.h X:\protocolGraph\dll_%2\include