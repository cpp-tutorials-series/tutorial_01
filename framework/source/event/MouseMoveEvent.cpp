#include <event/MouseMoveEvent.h>

MouseMoveEvent::MouseMoveEvent()
{
    
}

MouseMoveEvent::MouseMoveEvent(int x, int y, bool pressed, MouseButton button) : MouseEvent(x, y, pressed, button)
{
    
}