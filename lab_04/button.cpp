#include "button.h"

Button::Button(QWidget *parent) : QPushButton(parent)
{
	state = NOT_ACTIVE;
	floor = DEFAULT_FLOOR;

	setStyleSheet("background-color: blue");

	QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(unpressedSignal()), this, SLOT(unpressedSlot()));
}

void Button::unpressedSlot()
{
	state = NOT_ACTIVE;
}

void Button::pressedSlot()
{
	state = ACTIVE;
	emit pressedSignal(this->floor);
}

void Button::setFloor(size_t curFloor)
{
	floor = curFloor;
}
