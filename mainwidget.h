#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "board.h"
#include <QWidget>
class QLabel;
class QVBoxLayout;

class MainWidget : public QWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget* parent = 0);
	QLabel* status;
private slots:
	void newGame();
private:
	Board* board;
	QVBoxLayout* layout;
};

#endif
