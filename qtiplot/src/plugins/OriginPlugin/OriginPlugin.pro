QTI_ROOT = ../../../..
!include( $$QTI_ROOT/build.conf ) {
  message( "You need a build.conf file with local settings!" )
}

INCLUDEPATH += $$MUPARSER_INCLUDEPATH
INCLUDEPATH += $$QWT_INCLUDEPATH
INCLUDEPATH += $$QWT3D_INCLUDEPATH
INCLUDEPATH += $$GSL_INCLUDEPATH

include($$QTI_ROOT/3rdparty/qti/libqti.pri)
include($$QTI_ROOT/qtiplot/src/core/core.pri)
include($$QTI_ROOT/qtiplot/src/plot2D/plot2D.pri)
include($$QTI_ROOT/qtiplot/src/plot3D/plot3D.pri)
include($$QTI_ROOT/qtiplot/src/matrix/matrix.pri)
include($$QTI_ROOT/qtiplot/src/table/table.pri)
include($$QTI_ROOT/qtiplot/src/scripting/scripting.pri)

HEADERS =
SOURCES =

include(src/plugins/OriginPlugin/OriginPlugin.pri)

MOC_DIR     = $$QTI_ROOT/tmp/qtiplot
OBJECTS_DIR = $$QTI_ROOT/tmp/qtiplot
QT          += qt3support network
TEMPLATE    = lib
CONFIG      += plugin release static warn_on thread
TARGET      = $$qtLibraryTarget(FreeSoftwareQtiPlotImportOPJ)
DESTDIR     = $$QTI_ROOT/tmp/qtiplot





###############################################################
######################## OriginPlugin #########################
###############################################################
INCLUDEPATH +=  $$PWD               \
                $$PWD/tree.phi-sci.com    \
                $$PWD/liborigin1    \
                $$PWD/liborigin2


HEADERS +=  $$PWD/OriginPlugin.h    \
            $$PWD/liborigin1/importOPJ.h \
            $$PWD/liborigin2/OriginObj.h \
            $$PWD/liborigin2/OriginFile.h \
            $$PWD/liborigin2/OriginParser.h \
            $$PWD/liborigin2/Origin410Parser.h \
            $$PWD/liborigin2/Origin500Parser.h \
            $$PWD/liborigin2/Origin610Parser.h \
            $$PWD/liborigin2/Origin700Parser.h \
            $$PWD/liborigin2/Origin750Parser.h \
            $$PWD/liborigin2/Origin800Parser.h \
            $$PWD/liborigin2/Origin810Parser.h \
            $$PWD/liborigin2/Origin850Parser.h

SOURCES +=  $$PWD/OriginPlugin.cpp  \
            $$PWD/liborigin1/importOPJ.cpp \
            $$PWD/liborigin2/OriginFile.cpp \
            $$PWD/liborigin2/OriginParser.cpp \
            $$PWD/liborigin2/Origin410Parser.cpp \
            $$PWD/liborigin2/Origin500Parser.cpp \
            $$PWD/liborigin2/Origin610Parser.cpp \
            $$PWD/liborigin2/Origin700Parser.cpp \
            $$PWD/liborigin2/Origin750Parser.cpp \
            $$PWD/liborigin2/Origin800Parser.cpp \
            $$PWD/liborigin2/Origin810Parser.cpp \
            $$PWD/liborigin2/Origin850Parser.cpp

DEFINES +=  NO_LOG_FILE
