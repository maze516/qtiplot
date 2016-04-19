TEMPLATE = subdirs

SUBDIRS = QtiPlot   \
        QTeXEngine  \
        qwt         \
        qwtplot3d   \
        FitPlugins  \
        OriginPlugin


qwt.subdir          = 3rdparty/qwt
qwtplot3d.subdir    = 3rdparty/qwtplot3d
QTeXEngine.subdir   = 3rdparty/QTeXEngine
FitPlugins.subdir   = fitPlugins
OriginPlugin.subdir = qtiplot/src/plugins/OriginPlugin

QtiPlot.subdir      = qtiplot
QtiPlot.depends     = qwt qwtplot3d QTeXEngine OriginPlugin
