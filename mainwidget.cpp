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
	cubeSize->setRange(5, 50);
	cubeSize->setValue(15);

	cubeSettingsLayout = new QHBoxLayout;
	cubeSettingsLayout->addWidget(cubeLabel);
	cubeSettingsLayout->addWidget(cubeSize);

	status = new QLabel;

	layout = new QVBoxLayout;
	layout->addWidget(newgame, 1);
	layout->addLayout(cubeSettingsLayout);
	layout->addWidget(status);
	newGame();

	setLayout(layout);
}

MainWidget::~MainWidget()
{
	QLayoutItem *child;
	while((child = cubeSettingsLayout->takeAt(0)) != 0)
		delete child;
	while((child = layout->takeAt(0)) != 0)
		delete child;
	layout->setEnabled(false);
	delete layout;
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
