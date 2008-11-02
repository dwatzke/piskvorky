#ifndef BOARD_H
#define BOARD_H

#include <QList>
#include <QPair>
#include <QRect>
#include <QWidget>
class QPaintEvent;
class QMouseEvent;

class Board : public QWidget
{
public:
	Board(int cb, QWidget* parent = 0);
protected:
	void mousePressEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);
private:
	enum Owner { Nobody, Blue, Red };

	int m_padding;
	int m_size;
	int m_cube;
	Owner turn;
	bool gameover;
	QList< QPair<QRect,Owner> > rects;

	int psize() { return m_padding+m_size; }
	int cube() const;
	void updateStatus(QString status = NULL);
	bool checkGameOver();
	bool gameOverSwitch(Owner* owner, int& r, int& b);
};

#endif
