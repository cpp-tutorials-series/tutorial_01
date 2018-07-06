#include <event/MouseReleaseEvent.h>

MouseReleaseEvent::MouseReleaseEvent()
{
    
}

MouseReleaseEvent::MouseReleaseEvent(int x, int y, bool pressed, MouseButton button) : MouseEvent(x, y, pressed, button)
{
    
}