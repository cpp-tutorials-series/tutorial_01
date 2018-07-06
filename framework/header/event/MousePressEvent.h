/**
 * Class to represent a mouse press event. Does not implement any functioanlity and
 * is only used to determine between different mouse events
 */
#ifndef MousePressEvent_h
#define MousePressEvent_h

#include "MouseEvent.h"

class MousePressEvent : public MouseEvent
{
    public:
        MousePressEvent();
        
        MousePressEvent(int x, int y, bool pressed, MouseButton button);   
};

#endif