QTI_ROOT = ..
!include( $$QTI_ROOT/build.conf ) {
  message( "You need a build.conf file with local settings!" )
}

INCLUDEPATH += $$MUPARSER_INCLUDEPATH
INCLUDEPATH	+= $$QWT_INCLUDEPATH
INCLUDEPATH += $$QWT3D_INCLUDEPATH
INCLUDEPATH	+= $$GSL_INCLUDEPATH

include(src/core/core.pri)
include(src/lib/libqti.pri)
include(src/plot2D/plot2D.pri)
include(src/plot3D/plot3D.pri)
include(src/matrix/matrix.pri)
include(src/table/table.pri)
include(src/scripting/scripting.pri)

HEADERS =
SOURCES =

include(src/plugins/OriginPlugin/OriginPlugin.pri)

MOC_DIR		= ../tmp/qtiplot
OBJECTS_DIR	= ../tmp/qtiplot
QT			+= qt3support network
TEMPLATE	= lib
CONFIG		+= plugin release static warn_on thread
TARGET		= $$qtLibraryTarget(FreeSoftwareQtiPlotImportOPJ)
DESTDIR		= ../tmp/qtiplot
