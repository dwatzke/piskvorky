//#include "board.h"
#include "mainwidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget*) : board(NULL)
{
	QPushButton* newgame = new QPushButton("&New game");
	connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));
	QLabel* cubeLabel = new QLabel("Board size:");
	cubeSize = new QSpinBox;
	cubeSize->setRange(5, 30);
	cubeSize->setValue(15);

	QHBoxLayout* buttons = new QHBoxLayout;
	buttons->addWidget(newgame, 1);
	buttons->addWidget(cubeLabel);
	buttons->addWidget(cubeSize);

	status = new QLabel;

	layout = new QVBoxLayout;
	layout->addLayout(buttons);
	layout->addWidget(status);
	newGame();

	setLayout(layout);
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
