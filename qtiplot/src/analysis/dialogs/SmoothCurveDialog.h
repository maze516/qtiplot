/***************************************************************************
    File                 : SmoothCurveDialog.h
    Project              : QtiPlot
    --------------------------------------------------------------------
	Copyright            : (C) 2006 - 2011 by Ion Vasilief
    Email (use @ for *)  : ion_vasilief*yahoo.fr
    Description          : Smoothing options dialog

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
#ifndef SMOOTHDIALOG_H
#define SMOOTHDIALOG_H

#include <QDialog>

class QPushButton;
class QComboBox;
class QSpinBox;
class QDoubleSpinBox;
class Graph;
class ColorButton;

//! Smoothing options dialog
class SmoothCurveDialog : public QDialog
{
	Q_OBJECT

public:
	SmoothCurveDialog(int method, QWidget* parent = 0, Qt::WFlags fl = 0 );

public slots:
	void setGraph(Graph *g);
	void smooth();
	void activateCurve(const QString&);

private:
	Graph *graph;
	int smooth_method;
    QPushButton* btnSmooth;
	QPushButton* buttonCancel;
	QComboBox* boxName;
	QSpinBox *boxPointsLeft, *boxPointsRight, *boxOrder;
	QDoubleSpinBox *boxF;
	ColorButton* boxColor;
};

#endif



