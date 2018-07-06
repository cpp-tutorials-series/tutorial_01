/**
 * Class to represent a mouse release event. Does not implement any functioanlity and
 * is only used to determine between different mouse events
 */
#ifndef MouseReleaseEvent_h
#define MouseReleaseEvent_h

#include "MouseEvent.h"

class MouseReleaseEvent : public MouseEvent
{
    public:
        MouseReleaseEvent();
        
        MouseReleaseEvent(int x, int y, bool pressed, MouseButton button);    
};

#endif