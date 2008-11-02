#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "board.h"
#include <QWidget>
class QHBoxLayout;
class QLabel;
class QSpinBox;
class QVBoxLayout;

class MainWidget : public QWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget* parent = 0);
	~MainWidget();
	QLabel* status;
private slots:
	void newGame();
private:
	Board* board;
	QSpinBox* cubeSize;
	QHBoxLayout* cubeSettingsLayout;
	QVBoxLayout* layout;
};

#endif
