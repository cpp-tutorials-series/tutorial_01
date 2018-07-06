/**
 * \class Observer
 * 
 * \brief Abstract class that receives events of Observable objects
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef Observer_h
#define Observer_h

#include <event/Event.h>
#include "Observable.h"

class Observer
{
    public:
        Observer(Observable* subject);

        /**
         * Gets calld each time an observable object triggers an event that is handled by this
         * function of the observer
         * \param Event The event thrown by Observable
         */
        virtual void update(Event* event) = 0;
    
    protected:
        /// Returns the subject
        Observable* GetSubject();
    private:
        Observable* _subject;
};

#endif