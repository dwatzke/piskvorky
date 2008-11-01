//#include "board.h"
#include "mainwidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget*) : board(NULL)
{
	QPushButton* newgame = new QPushButton("&New game");
	connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));
	QPushButton* quit = new QPushButton("&Quit");
	connect(quit, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout* buttons = new QHBoxLayout;
	buttons->addWidget(newgame, 1);
	buttons->addWidget(quit);

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

	board = new Board(this);
	layout->addWidget(board);
}
