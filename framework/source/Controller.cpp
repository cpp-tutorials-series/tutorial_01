#include "Controller.h"

Controller::Controller(Model* model, Window* view) : Observer(view)
{
    _model = model;
    _view = view;
}

void Controller::update(Event* event)
{

}