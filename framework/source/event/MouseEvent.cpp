#include <event/MouseEvent.h>

MouseEvent::MouseEvent()
{
    
}

MouseEvent::MouseEvent(int x, int y, bool pressed, MouseButton button) 
{
    _x = x;
    _y = y;
    _pressed = pressed;
    _button = button;
}

int MouseEvent::GetX() const
{
    return _x;
}

void MouseEvent::SetX(int x)
{
    _x = x;
}

int MouseEvent::GetY() const
{
    return _y;
}

void MouseEvent::SetY(int y)
{
    _y = y;
}

bool MouseEvent::GetPressed() const
{
    return _pressed;
}

void MouseEvent::SetPressed(bool pressed)
{
    _pressed = pressed;
}

MouseButton MouseEvent::GetButton() const
{
    return _button;
}

void MouseEvent::SetButton(MouseButton button)
{
    _button = button;
}