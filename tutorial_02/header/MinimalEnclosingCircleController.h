#ifndef MinimalEnclosingCircleController_h
#define MinimalEnclosingCircleController_h

#include <event/MouseEvent.h>
#include <Controller.h>
#include <model/Container.h>
#include <GridWindow.h>
#include "PointView.h"
#include "CircleView.h"

#include "MinimalEnclosingCircle.h"

class MinimalEnclosingCircleController : public Controller
{
    public:
        MinimalEnclosingCircleController(Model* model, Window* view);

        void update(Event* event);

        void removeCirclesFromModel();
};

#endif