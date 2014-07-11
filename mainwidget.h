#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "board.h"
#include <QWidget>
//class QHBoxLayout;
class QComboBox;
class QLabel;
class QSpinBox;
class QVBoxLayout;

class MainWidget : public QWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget* parent = 0);
	void setStatus(QString);
private slots:
	void newGame();
private:
	Board* board;
	QLabel* status;
	QSpinBox* cubeSize;
	//QHBoxLayout* cubeSettingsLayout;
	QVBoxLayout* layout;
};

#endif
