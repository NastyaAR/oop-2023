#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

#define DEFAULT_FLOOR 1

class Button : public QPushButton
{
	Q_OBJECT;

	enum ButtonState {
		NOT_ACTIVE,
		ACTIVE,
	};

public:
	explicit Button(QWidget *parent = nullptr);
	~Button() = default;
	void setFloor(size_t curFloor);

private slots:
	void unpressedSlot();
	void pressedSlot();

signals:
	void pressedSignal(size_t floor);
	void unpressedSignal();

private:
	ButtonState state;
	size_t floor;
};

#endif // BUTTON_H
