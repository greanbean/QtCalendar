#ifndef CALENDARMANAGER_H
#define CALENDARMANAGER_H

#include "calitem.h"
#include <QVector>
#include <functional>

auto ALWAYS_TRUE = [](const CalItem*){return true;};

class ICalManager
{
public:
	ICalManager();
public:
	virtual void addItem (const CalItem*) = 0;
	virtual void delItem (const CalItem*) = 0;
	virtual void clear () = 0;

	virtual void save () = 0;
	virtual void load () = 0;
	virtual void merge (ICalManager&);

	virtual QVector<const CalItem*> getItemListInDate (QDate) const = 0;
	virtual QVector<const CalItem*> getItemList ( std::function<bool(const CalItem*)> filter = ALWAYS_TRUE ) const = 0;
};

#endif // CALENDARMANAGER_H