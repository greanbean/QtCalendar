#ifndef DAYINFOWIDGET_H
#define DAYINFOWIDGET_H

#include <QWidget>
#include <QPoint>
#include "calitemall.h"
#include "CalManager.h"
#include "windowdrag.h"

namespace Ui {
class DayInfoWidget;
}

class DayInfoWidget : public QWidget
{
	Q_OBJECT

public:
	explicit DayInfoWidget(const QDate &_date, ICalManager* _calManager, QWidget *parent = 0);
	~DayInfoWidget();
	void update ();

	WINDOW_DRAG

private:
	Ui::DayInfoWidget *ui;
	QDate date;
	ICalManager* calManager;
};

#endif // DAYINFOWIDGET_H
