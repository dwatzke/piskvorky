//#include "board.h"
#include "mainwidget.h"
#include <QComboBox>
#include <QDebug>
//#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolBar>
#include <QSpinBox>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget*) : board(NULL)
{
	layout = new QVBoxLayout(this);
	//cubeSettingsLayout = new QHBoxLayout;

	QPushButton* newgame = new QPushButton(tr("&New game"));
	QLabel* cubeLabel = new QLabel(tr("Board size: "));
	QComboBox* opponent = new QComboBox;
	status = new QLabel;
	cubeSize = new QSpinBox;
	cubeSize->setRange(6, 50);
	cubeSize->setValue(15);
	connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));

	QToolBar* toolbar = new QToolBar(tr("Settings"));
	toolbar->addWidget(cubeLabel);
	toolbar->addWidget(cubeSize);
	toolbar->addSeparator();
	toolbar->addWidget(opponent);
	//cubeSettingsLayout->addWidget(cubeLabel);
	//cubeSettingsLayout->addWidget(cubeSize);

	layout->addWidget(newgame, 1);
	layout->addWidget(toolbar);
	layout->addWidget(status);
	newGame();

	setLayout(layout);
	//setFixedSize(sizeHint());
}

void MainWidget::newGame()
{
	if(board)
	{
		layout->removeWidget(board);
		delete board;
	}

	board = new Board(cubeSize->value(), this);
	board->hide();
	board->show();
	layout->addWidget(board);

	resize(sizeHint());
}

void MainWidget::setStatus(QString str)
{
	status->setText(str);
}
