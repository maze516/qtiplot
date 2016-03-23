/***************************************************************************
    File                 : AxesDialog.h
    Project              : QtiPlot
    --------------------------------------------------------------------
	Copyright            : (C) 2004 - 2011 by Ion Vasilief
						   (C) 2006 Tilman Hoener zu Siederdissen
	Email (use @ for *)  : ion_vasilief*yahoo.fr
	Description          : Axes preferences dialog

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *  This program is free software; you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation; either version 2 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the Free Software           *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor,                    *
 *   Boston, MA  02110-1301  USA                                           *
 *                                                                         *
 ***************************************************************************/
#ifndef AXESDIALOG_H
#define AXESDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QList>
#include <QTextEdit>

class QLineEdit;
class QTimeEdit;
class QDateTimeEdit;
class QListWidget;
class QListWidgetItem;
class QCheckBox;
class QGroupBox;
class QComboBox;
class QLabel;
class QPushButton;
class QRadioButton;
class QSpinBox;
class QTabWidget;
class QWidget;
class QStringList;
class ColorButton;
class Graph;
class TextFormatButtons;
class DoubleSpinBox;
class Grid;
class PenStyleBox;

//! General plot options dialog
/**
 * Remark: Don't use this dialog as a non modal dialog!
 */
class AxesDialog : public QDialog
{
    Q_OBJECT

public:
	//! Constructor
	/**
	 * \param parent parent widget
	 * \param fl window flags
	 */
    AxesDialog( QWidget* parent = 0, Qt::WFlags fl = 0 );

	void setGraph(Graph *g);

public slots:
	void setCurrentScale(int axisPos);
	void showGeneralPage();
	void showAxesPage();
	void showGridPage();
	void showFormulaBox();

	//! Shows the dialog as a modal dialog
	/**
	 * Show the dialog as a modal dialog and do
	 * some initialization.
	 */
	int exec();

private slots:
	void showAxisFormula(int axis);
	void customAxisLabelFont();
	void pickAxisLabelColor();
	void setAxisType(int axis);
	void updateAxisType(int axis);
	void updateTitleBox(int axis);
	bool updatePlot(QWidget *page = NULL);
	void updateScale();
	void stepEnabled();
	void stepDisabled();
	void majorGridEnabled(bool on);
	void minorGridEnabled(bool on);
    void showGridOptions(int axis);
	void accept();
	void customAxisFont();
	void showAxis();
	void updateShowBox(int axis);
	void updateAxisColor(int);
	int mapToQwtAxis(int axis);
	int mapToQwtAxisId();
	void updateTickLabelsList(bool);
	void updateMinorTicksList(int scaleType);
	void setTicksType(int);
	void updateGrid();
	void setLabelsNumericFormat(int);
	void updateLabelsFormat(int);
	void showAxisFormatOptions(int format);
	void setBaselineDist(int);
	void changeMinorTicksLength (int minLength);
	void changeMajorTicksLength (int majLength);
	void pageChanged ( QWidget *page);
	void showAxis(int, int, const QString&, bool, int, int, bool, const QColor&, int, int, int, int, const QString&, const QColor&, int, bool, int);
    void applyCanvasFormat();
    void setFrameDefaultValues();
	void applyAxisFormat();
	void updateCurrentAxis();

protected:
    void applyCanvasFormatTo(Graph *g);
	//! generate UI for the axes page
	void initAxesPage();
	//! generate UI for the scales page
	void initScalesPage();
	//! generate UI for the grid page
	void initGridPage();
	//! generate UI for the general page
	void initFramePage();
	//! Modifies the grid
	void applyChangesToGrid(Grid *grid);
	//! Customizes graph axes
	void applyAxisFormatToLayer(Graph *g);

    QPushButton* buttonApply;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;
    QTabWidget* generalDialog;
    QWidget* scalesPage;
    DoubleSpinBox* boxEnd;
    DoubleSpinBox* boxStart;
    QComboBox* boxScaleType;
    QComboBox* boxMinorValue;
    DoubleSpinBox* boxStep;
    QRadioButton* btnStep;
    QCheckBox *btnInvert;
    QSpinBox* boxMajorValue;
    QRadioButton* btnMajor;
    QListWidget* axesList;
    QWidget* gridPage;
    QCheckBox* boxMajorGrid;
    QCheckBox* boxMinorGrid;
    PenStyleBox* boxTypeMajor;
	ColorButton* boxColorMinor;
	ColorButton* boxColorMajor;
	ColorButton *boxCanvasColor;
    DoubleSpinBox* boxWidthMajor;
    PenStyleBox* boxTypeMinor;
    DoubleSpinBox* boxWidthMinor;
    QCheckBox* boxXLine;
    QCheckBox* boxYLine;
    QListWidget* axesGridList;
    QWidget* axesPage, *frame;
    QListWidget* axesTitlesList;
	QGroupBox *boxShowLabels;
    QCheckBox *boxShowAxis;

	QTextEdit *boxFormula, *boxTitle;
	QSpinBox *boxFrameWidth, *boxPrecision, *boxAngle, *boxBaseline, *boxAxesLinewidth;
    QPushButton* btnAxesFont;
	QCheckBox *boxBackbones, *boxShowFormula;
	ColorButton* boxAxisColor;
	QComboBox *boxMajorTicksType, *boxMinorTicksType, *boxFormat, *boxAxisType, *boxColName;
	QGroupBox *boxFramed;
	QLabel *label1, *label2, *label3, *boxScaleTypeLabel, *minorBoxLabel, *labelTable;
	QSpinBox *boxMajorTicksLength, *boxMinorTicksLength, *boxBorderWidth;
	QComboBox *boxUnit, *boxTableName, *boxGridXAxis, *boxGridYAxis;
	ColorButton *boxFrameColor, *boxAxisNumColor;
	QGroupBox  *labelBox;
	QPushButton * buttonLabelFont;
	TextFormatButtons *formatButtons;

	QStringList tickLabelsOn;
	QGroupBox *boxAxesBreaks;
	DoubleSpinBox *boxBreakStart, *boxBreakEnd, *boxStepBeforeBreak, *boxStepAfterBreak;
	QSpinBox *boxBreakPosition, *boxBreakWidth;
	QComboBox *boxMinorTicksBeforeBreak, *boxMinorTicksAfterBreak;
	QCheckBox *boxLog10AfterBreak, *boxBreakDecoration, *boxAntialiseGrid;
    QComboBox *boxApplyGridFormat;
	Graph* d_graph;
	//! Last selected tab
  	QWidget* lastPage;
    QDateTimeEdit *boxStartDateTime, *boxEndDateTime;
    QComboBox *canvasFrameApplyToBox;
    QPushButton *frameDefaultBtn;
	QSpinBox *boxLabelsDistance;
	QGroupBox *axisFormatBox;
	QComboBox *axisFormatApplyToBox;
	QCheckBox *invertTitleBox;
	QCheckBox* boxAxisBackbone;
	QSpinBox *boxTickLabelDistance;
	QLineEdit *boxPrefix, *boxSuffix;

	QComboBox *showTicksPolicyBox;
	ColorButton *axisLabelColorButton;
};

#endif
