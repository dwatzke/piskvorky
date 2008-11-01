#include "board.h"
#include "mainwidget.h"
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QWidget>
/**
TODO:
	* add support for a board of any size, not 10x10 only
	* maybe add a timer
	* highlight 5 cells in a row
**/
Board::Board(QWidget* parent) : QWidget(parent), padding(3), size(20), turn(Red), gameover(false)
{
	setPalette(QPalette(QColor(255, 255, 255)));
	setAutoFillBackground(true);
	setFixedSize(psize()*10+padding, psize()*10+padding);

	updateStatus(NULL);

	for(int x = padding; x+size < height(); x += psize())
	for(int y = padding; y+size < width(); y += psize())
		rects << qMakePair<QRect,Owner>(QRect(x, y, size, size), Nobody);
}

void Board::paintEvent(QPaintEvent*)
{
	if(gameover) return;

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	for(int i=0; i < rects.size(); ++i)
	{
		painter.setPen(Qt::black);
		//TODO: optimize this (black borders between cells)
		painter.drawRect(QRectF(rects[i].first).adjusted(-1.5, -1.5, 1.5, 1.5));

		// skip them fools without owner
		if(rects[i].second == Nobody)
			continue;

		switch(rects[i].second)
		{
		case Red:
			//qDebug() << "red on" << rects[i].first;
			painter.setPen(Qt::red);
			painter.drawEllipse(rects[i].first);
			break;
		case Blue:
			painter.setPen(Qt::blue);
			painter.drawLine(rects[i].first.x(), rects[i].first.y(),
					 rects[i].first.x()+size, rects[i].first.y()+size);
			painter.drawLine(rects[i].first.x(), rects[i].first.y()+size,
					 rects[i].first.x()+size, rects[i].first.y());
			break;
		default:
			break;
		}
	}

	if(!checkGameOver())
		updateStatus(NULL);
}

void Board::mousePressEvent(QMouseEvent* e)
{
	if(gameover) return;

	for(int i=0; i < rects.size(); ++i)
	if(rects[i].first.contains(e->x(), e->y()))
	{
		// skip owned ones
		if(rects[i].second != Nobody)
			continue;

		// set next turn
		rects[i].second = turn;
		if(turn == Red)
			turn = Blue;
		else
			turn = Red;

		// update this rectangle in the paintEvent
		this->update(rects[i].first);

		return;
	}
}

void Board::updateStatus(QString status)
{
	MainWidget* mw = static_cast<MainWidget*>(parentWidget());

	QString l_status = "Status: <font color='";
	if(turn == Red)
		l_status += "red'>Red";
	else
		l_status += "blue'>Blue";
	l_status += "</font>";

	if(status == NULL)
		l_status += "'s turn...";
	else
		l_status += status;

	mw->status->setText(l_status);
}

bool Board::checkGameOver()
{
	int i=0 /*index*/, t=-1, r=0, b=0, n=0;

	// check vertically
	for(int x=0; x<100; x++, i++)
	{
		if(x%10 == 0)
			r=0, b=0;

		if(gameOverSwitch(&rects[i].second, r, b))
			return true;
	}

	// check horizontally
	if(!gameover)
        for(int x=0; x<100; x++)
	{
		n = x % 10;
		if(n == 0)
			r=0, b=0, t++;

		i = t + n*10; // y*10+x;

		if(gameOverSwitch(&rects[i].second, r, b))
			return true;
	}

	b=0, r=0;

        // check main diagonal
	if(!gameover)
	for(int x=4; x<60;)
	{
		if(x>=10)
		{
			x += 10;
			i = x-1;
			t--;
		} else
		{
			i = x;
			t = ++x;
		}

		for(int c=t; c>0; c--, i += 9)
			if(gameOverSwitch(&rects[i].second, r, b))
				return true;
	}

	t=4;

        // check minor diagonal
	if(!gameover)
	for(int x=5; x<60;)
	{
		if(x<0 || x>5)
		{
			x += 10;
			i = x+1;
			t--;
		} else
		{
			i = x--;
			t++;
		}

		for(int c=t; c>0; c--, i += 11)
			if(gameOverSwitch(&rects[i].second, r, b))
				return true;
	}

	return false;
}

bool Board::gameOverSwitch(Owner* owner, int& r, int& b)
{
	switch(*owner)
	{
	case Red:
		if(++r == 5)
			gameover = true;
		b=0;
		break;
	case Blue:
		if(++b == 5)
			gameover = true;
		r=0;
		break;
	default:
		b=0, r=0;
		break;
	}

	if(gameover)
	{
		turn = *owner;
		updateStatus(QString(" wins."));
	}

	return gameover;
}
