#include "doors.h"

#define TIME_DOORS 10

Doors::Doors() : state(CLOSE)
{
	QObject::connect(&closingTime, SIGNAL(timeout()), this, SLOT(closeSlot()));
	QObject::connect(&openingTime, SIGNAL(timeout()), this, SLOT(openSlot()));
	QObject::connect(&openTime, SIGNAL(timeout), this, SLOT(closingSlot()));
}

void Doors::setState(DoorState state)
{
	this->state = state;
}

void Doors::openSlot()
{
	if (state == OPENING) {
		setState(OPEN);
		qDebug() << "Двери открыты.";
		openTime.start();
	}
}

void Doors::closeSlot()
{
	if (state == CLOSING) {
		setState(CLOSE);
		qDebug() << "Двери закрыты.";
		emit closeSignal();
	}
}

void Doors::openingSlot()
{
	if (state == CLOSE || state == CLOSING) {
		setState(OPENING);
		qDebug() << "Двери открываются.";

		if (state == CLOSING) {
			auto remain = TIME_DOORS - closingTime.remainingTime();
			closingTime.stop();
			openingTime.start(remain);
		}
		else
			openingTime.start();
	}
}

void Doors::closingSlot()
{

}
