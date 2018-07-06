/**
 * \class Event
 * 
 * \brief Event is an abstract class representing an event like mouse event or a model change event
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef Event_h
#define Event_h

class Event
{
    public:
        /// Default constructor
        Event();

        /// Default deconstructor
        virtual ~Event() = 0;
};

#endif