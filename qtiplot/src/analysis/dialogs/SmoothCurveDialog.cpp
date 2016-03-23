/***************************************************************************
    File                 : SmoothCurveDialog.cpp
    Project              : QtiPlot
    --------------------------------------------------------------------
    Copyright            : (C) 2006 by Ion Vasilief
                           (C) 2009 by Jonas Bähr <jonas * fs.ei.tum.de>
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
#include "SmoothCurveDialog.h"
#include "SmoothFilter.h"
#include <Graph.h>
#include <PlotCurve.h>
#include <MyParser.h>
#include <ColorButton.h>

#include <QGroupBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QLayout>

SmoothCurveDialog::SmoothCurveDialog(int method, QWidget* parent, Qt::WFlags fl )
    : QDialog( parent, fl ), smooth_method(method)
{
	setObjectName( "SmoothCurveDialog" );
	setWindowTitle(tr("QtiPlot - Smoothing Options"));
	setSizeGripEnabled( true );
	setAttribute(Qt::WA_DeleteOnClose);

	QGroupBox *gb1 = new QGroupBox();
	QGridLayout *gl1 = new QGridLayout(gb1);
	gl1->addWidget(new QLabel(tr("Curve")), 0, 0);

	boxName = new QComboBox();
	gl1->addWidget(boxName, 0, 1);

	boxColor = new ColorButton();
	boxColor->setColor(Qt::red);

	if (method == SmoothFilter::SavitzkyGolay){
		gl1->addWidget(new QLabel(tr("Polynomial Order")), 1, 0);
		boxOrder = new QSpinBox();
		boxOrder->setRange(0, 9);
		boxOrder->setValue(2);
		gl1->addWidget(boxOrder, 1, 1);

		gl1->addWidget(new QLabel(tr("Points to the Left")), 2, 0);
		boxPointsLeft = new QSpinBox();
		boxPointsLeft->setRange(1, 25);
		boxPointsLeft->setValue(2);
		gl1->addWidget(boxPointsLeft, 2, 1);

		gl1->addWidget(new QLabel(tr("Points to the Right")), 3, 0);
		boxPointsRight = new QSpinBox();
		boxPointsRight->setRange(1, 25);
		boxPointsRight->setValue(2);
		gl1->addWidget(boxPointsRight, 3, 1);

		gl1->addWidget(new QLabel(tr("Color")), 4, 0);
		gl1->addWidget(boxColor, 4, 1);
		gl1->setRowStretch(5, 1);
	} else if (method == SmoothFilter::Lowess){
		gl1->addWidget(new QLabel(tr("f")), 1, 0);
		boxF = new QDoubleSpinBox();
		boxF->setRange(0, 1);
		boxF->setValue(0.2);
		boxF->setSingleStep(0.05);
		gl1->addWidget(boxF, 1, 1);

		gl1->addWidget(new QLabel(tr("Iterations")), 2, 0);
		boxOrder = new QSpinBox();
		boxOrder->setRange(1, 9);
		boxOrder->setValue(2);
		gl1->addWidget(boxOrder, 2, 1);

		gl1->addWidget(new QLabel(tr("Color")), 3, 0);
		gl1->addWidget(boxColor, 3, 1);
		gl1->setRowStretch(4, 1);
	} else {
		gl1->addWidget(new QLabel(tr("Points")), 1, 0);
		boxPointsLeft = new QSpinBox();
		boxPointsLeft->setRange(1, 1000000);
		boxPointsLeft->setSingleStep(10);
		boxPointsLeft->setValue(5);
		gl1->addWidget(boxPointsLeft, 1, 1);

		gl1->addWidget(new QLabel(tr("Color")), 2, 0);
		gl1->addWidget(boxColor, 2, 1);
		gl1->setRowStretch(3, 1);
	}
	gl1->setColStretch(1, 1);

	btnSmooth = new QPushButton(tr( "&Smooth" ));
	btnSmooth->setDefault(true);
	buttonCancel = new QPushButton(tr( "&Close" ));

	QVBoxLayout *vl = new QVBoxLayout();
	vl->addWidget(btnSmooth);
	vl->addWidget(buttonCancel);
	vl->addStretch();

	QHBoxLayout *hb = new QHBoxLayout(this);
	hb->addWidget(gb1);
	hb->addLayout(vl);

	connect( btnSmooth, SIGNAL(clicked()), this, SLOT( smooth()));
	connect( buttonCancel, SIGNAL(clicked()), this, SLOT( close()));
	connect( boxName, SIGNAL(activated(const QString&)), this, SLOT(activateCurve(const QString&)));
}

void SmoothCurveDialog::smooth()
{
	QString curveName = boxName->currentText();
	curveName = curveName.left(curveName.indexOf(" ["));

	SmoothFilter *sf = new SmoothFilter((ApplicationWindow *)parent(), graph->curve(curveName), smooth_method);
	if (smooth_method == SmoothFilter::SavitzkyGolay){
		sf->setSmoothPoints(boxPointsLeft->value(), boxPointsRight->value());
		sf->setPolynomOrder(boxOrder->value());
	} else if (smooth_method == SmoothFilter::Lowess){
		sf->setLowessParameter(boxF->value(), boxOrder->value()); // we use the "order" spinbox for "iterations"
	} else
		sf->setSmoothPoints(boxPointsLeft->value());

	sf->setColor(boxColor->color());
	sf->run();
	delete sf;
}

void SmoothCurveDialog::setGraph(Graph *g)
{
	if (!g)
		return;

	graph = g;
	boxName->addItems (g->analysableCurvesList());
	activateCurve(boxName->currentText());
}

void SmoothCurveDialog::activateCurve(const QString& s)
{
	if (smooth_method == SmoothFilter::Average){
		PlotCurve *c = graph->curve(s.left(s.indexOf(" [")));
		if (!c || c->rtti() != QwtPlotItem::Rtti_PlotCurve)
			return;

		boxPointsLeft->setMaxValue(c->dataSize()/2);
	}
}
