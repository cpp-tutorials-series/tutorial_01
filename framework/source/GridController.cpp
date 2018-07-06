#include "GridController.h"

GridController::GridController(Model* model, Window* view) : Controller(model, view)
{

}

void GridController::update(Event* event)
{
    if(auto mouseEvent = dynamic_cast<MousePressEvent*>(event))
    {
        if(auto pointCloud = dynamic_cast<PointCloud*>(_model))
        {
            if(auto gridView = dynamic_cast<GridWindow*>(_view))
            {
                int axisSize = gridView->GetAxisSize();

                int x = mouseEvent->GetX() - axisSize;
                int y = mouseEvent->GetY();

                
                int height = gridView->GetHeight() - axisSize;

                int columnsStepSize = (gridView->GetWidth() - axisSize) / gridView->GetColumns();
                int rowsStepSize = (gridView->GetHeight() - axisSize) / gridView->GetRows();
                
                if(x >= 0){
                    pointCloud->addPoint(axisSize + ((int)x / columnsStepSize) * columnsStepSize, ((int)y / rowsStepSize) * rowsStepSize);
                }                
            }            
        }
    }    
}