TEMPLATE = subdirs

SUBDIRS = QtiPlot   \
        QTeXEngine  \
        qwtplot3d   \
        FitPlugins  \
        OriginPlugin


qwtplot3d.subdir    = 3rdparty/qwtplot3d
QTeXEngine.subdir   = 3rdparty/QTeXEngine
FitPlugins.subdir   = fitPlugins
OriginPlugin.subdir = qtiplot/src/plugins/OriginPlugin

QtiPlot.subdir      = qtiplot
QtiPlot.depends = qwtplot3d QTeXEngine OriginPlugin








#		3rdparty/QTeXEngine \


