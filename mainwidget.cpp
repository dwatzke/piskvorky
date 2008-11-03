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
	layout = new QVBoxLayout(this);
	cubeSettingsLayout = new QHBoxLayout;

	QPushButton* newgame = new QPushButton(tr("&New game"));
	QLabel* cubeLabel = new QLabel(tr("Board size:"));
	cubeSize = new QSpinBox;
	cubeSize->setRange(6, 50);
	cubeSize->setValue(15);
	connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));

	cubeSettingsLayout->addWidget(cubeLabel);
	cubeSettingsLayout->addWidget(cubeSize);

	status = new QLabel;

	layout->addWidget(newgame, 1);
	layout->addLayout(cubeSettingsLayout);
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
