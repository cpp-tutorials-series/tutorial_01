/**
 * \class Observable
 * 
 * \brief Class that can register observers to inform them about changes
 * 
 * Observable adds the ability to inform classes about changes. First you
 * have to add observers with the attach function. After a change iterate
 * over all registered observers and call the update function of each observer.
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef Observable_h
#define Observable_h

#include <vector>

class Observer;
class Observable
{
    public:
        /**
         * Add an observer to the list of observers
         * \param observer The observer you want to add
         */
        void attach(Observer* observer);
    protected:
        std::vector<Observer*> observables;
};

#endif