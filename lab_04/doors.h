#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Doors : public QObject
{
	Q_OBJECT;

	enum DoorState {
		OPEN,
		CLOSE,
		OPENING,
		CLOSING,
	};

public:
	Doors();
	~Doors() = default;

private slots:
	void openSlot();
	void closeSlot();
	void openingSlot();
	void closingSlot();

signals:
	void openSignal();
	void closeSignal();

private:
	DoorState state;

	QTimer openingTime;
	QTimer closingTime;
	QTimer openTime;

	void setState(DoorState state);
};

#endif // DOORS_H
