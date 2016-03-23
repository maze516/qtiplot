/***************************************************************************
    File                 : ScriptWindow.h
    Project              : QtiPlot
    --------------------------------------------------------------------
    Copyright            : (C) 2006 - 2009 by Ion Vasilief                           Knut Franke
    Email (use @ for *)  : ion_vasilief*yahoo.fr
    Description          : Python script window

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
#ifndef SCRIPTWINDOW_H
#define SCRIPTWINDOW_H

#include "ScriptEdit.h"

#include <QMainWindow>
#include <QMenu>
#include <QCloseEvent>
class ScriptingEnv;
class ApplicationWindow;
class LineNumberDisplay;
class QAction;

//! Python script window
class ScriptWindow: public QMainWindow
{
	Q_OBJECT

public:
		ScriptWindow(ScriptingEnv *env, ApplicationWindow *app);
        ~ScriptWindow(){exit(0);};

public slots:
		void newScript();
		void open(const QString& fn = QString());
		void save();
		void saveAs();
		void languageChange();
		virtual void setVisible(bool visible);

		ScriptEdit* editor(){return te;};
		void executeAll(){te->executeAll();};

		//! Enables/Disables the line number display
		void showLineNumbers(bool show = true);

private slots:
		void setAlwaysOnTop(bool on);
		void redirectOutput(bool);
		void printPreview();
		void showWorkspace(bool on = true);
		void find();
		void findNext();
		void findPrevious();
		void replace();
		void increaseIndent();
		void decreaseIndent();
		void enableActions();

signals:
		void visibilityChanged(bool visible);

private:
		void moveEvent( QMoveEvent* );
		void resizeEvent( QResizeEvent* );

		void initMenu();
		void initActions();
		ScriptEdit *te;
		ApplicationWindow *d_app;
		LineNumberDisplay *d_line_number;
		QWidget *d_frame;

		QString fileName;

		QMenu *file, *edit, *run, *windowMenu;
		QAction *actionNew, *actionUndo, *actionRedo, *actionCut, *actionCopy, *actionPaste;
		QAction *actionExecute, *actionExecuteAll, *actionEval, *actionPrint, *actionOpen;
		QAction *actionSave, *actionSaveAs;
		QAction *actionAlwaysOnTop, *actionHide, *actionShowLineNumbers;
		QAction *actionShowConsole, *actionRedirectOutput, *actionPrintPreview;
		QAction *actionShowWorkspace;
		QAction *actionFind, *actionFindNext, *actionFindPrev, *actionReplace;
		QAction *actionIncreaseIndent, *actionDecreaseIndent;
		QDockWidget *consoleWindow;
		QTextEdit *console;
};

#endif
