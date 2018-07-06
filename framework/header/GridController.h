#ifndef GridController_h
#define GridController_h

#include <event/MouseEvent.h>
#include "GridWindow.h"
#include "Controller.h"
#include <model/PointCloud.h>

class GridController : public Controller
{
    public:
        GridController(Model* model, Window* view);

        void update(Event* event);
};

#endif 