#include <event/MousePressEvent.h>

MousePressEvent::MousePressEvent()
{
    
}

MousePressEvent::MousePressEvent(int x, int y, bool pressed, MouseButton button) : MouseEvent(x, y, pressed, button)
{
    
}