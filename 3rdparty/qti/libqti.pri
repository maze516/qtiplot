###############################################################
##################### libqti ##################################
###############################################################

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/3rdparty/qtcolorpicker/src

HEADERS +=  $$PWD/include/CollapsiveGroupBox.h \
            $$PWD/include/ColorBox.h \
            $$PWD/include/ColorButton.h \
            $$PWD/include/ColorMapEditor.h \
            $$PWD/include/DoubleSpinBox.h \
            $$PWD/include/ExtensibleFileDialog.h \
            $$PWD/include/LinearColorMap.h \
            $$PWD/include/LineNumberDisplay.h \
            $$PWD/include/PatternBox.h \
            $$PWD/include/PenStyleBox.h \
            $$PWD/include/SymbolBox.h \
            $$PWD/include/SymbolDialog.h \
            $$PWD/include/TextFormatButtons.h \

SOURCES +=  $$PWD/src/CollapsiveGroupBox.cpp \
            $$PWD/src/ColorBox.cpp \
            $$PWD/src/ColorButton.cpp \
            $$PWD/src/ColorMapEditor.cpp \
            $$PWD/src/DoubleSpinBox.cpp \
            $$PWD/src/ExtensibleFileDialog.cpp \
            $$PWD/src/LinearColorMap.cpp \
            $$PWD/src/LineNumberDisplay.cpp \
            $$PWD/src/PatternBox.cpp \
            $$PWD/src/PenStyleBox.cpp \
            $$PWD/src/SymbolBox.cpp \
            $$PWD/src/SymbolDialog.cpp \
            $$PWD/src/TextFormatButtons.cpp \

###############################################################
##################### 3rdparty Qt Solutions ###################
###############################################################

INCLUDEPATH +=  $$PWD/3rdparty/qtcolorpicker/src
HEADERS +=      $$PWD/3rdparty/qtcolorpicker/src/qtcolorpicker.h
SOURCES +=      $$PWD/3rdparty/qtcolorpicker/src/qtcolorpicker.cpp
