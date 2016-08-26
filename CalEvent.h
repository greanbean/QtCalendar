#ifndef CALEVENT_H
#define CALEVENT_H

#include "CalItem.h"
#include <QString>
#include <QTime>
#include <QSet>

class CalEvent: public CalItem
{
public:
	enum RepeatCycle {None = 0, Day = 1, Week = 2, Month = 3, Year = 4};
	QString		name;
	QString		address;
	QDateTime	tBegin, tEnd;
	QString		note;
	int			priority = 0;
	// Repeat
	RepeatCycle	repeatCycle = None;
	int			repeatTimes = 1;	// -1: +oo
	QSet<int>	deletedRepeatIndex;

	static const int PRIORITY_MAX = 3;

	// CalItem interface
public:
	virtual CalItemType type () const override {return Event;};
	virtual bool inDate (QDate date) const override;
	virtual QVector<QDate> getDateList() const override;
	bool crossDate () const;
	int getRepeatIndex (QDate date) const;
	void delRepeatIndex (int index);
	void delRepeatIndexAfter (int index);
	int error () const;

private:
	void nextDate (QDateTime &t1, QDateTime &t2) const;
};

#endif // CALEVENT_H
