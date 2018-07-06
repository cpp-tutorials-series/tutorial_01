/**
 * \class MouseEvent
 * 
 * \brief MouseEvent represents an event that is triggered by the mouse.
 * 
 * Everytime the user clicked a mouse button, release a mouse button or moved the mouse a MouseEvent is created and 
 * can be process by other classes. 
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef MouseEvent_h
#define MouseEvent_h

#include "Event.h"

enum MouseButton
{
    Left,
    Middle,
    Right,
    NotSpecified
};

class MouseEvent : public Event
{   
    public:
        /// Default constructor
        MouseEvent();

        /**
         * Event capturing a mouse action like mouse move, press or release of a button
         * \param x The x coordinate of the mouse position
         * \param y The y coordinate of the mouse position
         * \param pressed Indicates if a button was pressed or ot
         * \param button The button that was pressed
         */
        MouseEvent(int x, int y, bool pressed, MouseButton button);

        /// Returns the x position where the event occured
        int GetX() const;

        void SetX(int x);

        /// Returns the y position where the event occured
        int GetY() const;

        void SetY(int y);

        /// Returns if the button was pressed
        bool GetPressed() const;

        void SetPressed(bool pressed);

        /// Returns the button which was pressed
        MouseButton GetButton() const;

        void SetButton(MouseButton button);
    private:
        int _x;
        int _y;
        bool _pressed;

        MouseButton _button;  
};

#endif