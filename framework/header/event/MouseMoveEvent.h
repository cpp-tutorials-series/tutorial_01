/**
 * Class to represent a mouse move event. Does not implement any functioanlity and
 * is only used to determine between different mouse events
 */
#ifndef MouseMoveEvent_h
#define MouseMoveEvent_h

#include "MouseEvent.h"

class MouseMoveEvent : public MouseEvent
{
    public:
        MouseMoveEvent();
        
        MouseMoveEvent(int x, int y, bool pressed, MouseButton button);
};

#endif