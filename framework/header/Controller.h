/**
 * \class Controller
 * 
 * \brief The controller is used to receive and handles user events like mouse events.
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef Controller_h
#define Controller_h

#include <model/Model.h>
#include "Window.h"
#include "Observer.h"

#include <iostream>

class Controller : public Observer
{
    public:
        /**
         * Creates a new instance of the controller and sets model and view
         * accordingly.
         * 
         * \param model The controller will receive change events of this model
         * \param view The view of which the controller will receive user events like mouse input or key press events
         */
        Controller(Model* model, Window* view);

        /// Default deconstructor
        ~Controller();

        void update(Event* event);
    protected:
        Model* _model;
        Window* _view;
};

#endif