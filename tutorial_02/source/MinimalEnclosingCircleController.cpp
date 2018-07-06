#include "MinimalEnclosingCircleController.h"

MinimalEnclosingCircleController::MinimalEnclosingCircleController(Model *model, Window *view) : Controller(model, view)
{
}

void MinimalEnclosingCircleController::update(Event *event)
{
    if (auto mouseEvent = dynamic_cast<MousePressEvent *>(event))
    {
        if(mouseEvent->GetButton() == Left)
        {
if (auto container = dynamic_cast<Container *>(_model))
            {
                if (auto gridView = dynamic_cast<GridWindow *>(_view))
                {
                    int axisSize = gridView->GetAxisSize();

                    int x = mouseEvent->GetX() - axisSize;
                    int y = mouseEvent->GetY();

                    int height = gridView->GetHeight() - axisSize;

                    int columnsStepSize = (gridView->GetWidth() - axisSize) / gridView->GetColumns();
                    int rowsStepSize = (gridView->GetHeight() - axisSize) / gridView->GetRows();

                    if (x >= 0)
                    {
                        Point2<double> position(axisSize + ((int)x / columnsStepSize) * columnsStepSize, ((int)y / rowsStepSize) * rowsStepSize);
                        position = Point2<double>(mouseEvent->GetX(), y);
                        auto point = new PointView<double>(position, Color4(0.0, 0.0, 0.0, 1.0));

                        bool contains = false;
                        for (auto &&models : container->GetModels())
                        {
                            if (auto model = dynamic_cast<Point2<double>*>(models))
                            {
                                if (*model == *point)
                                {
                                    contains = true;
                                }
                            }
                        }

                        if (!contains)
                        {
                            container->addModel(point);

                            // Calculate the smallest enclosing circle if the point cloud contains more than three points
                            if (container->GetModels().size() >= 3)
                            {
                                std::vector<Point2<double>*> points;

                                for (auto &&point : container->GetModels())
                                {
                                    if (auto&& model = dynamic_cast<PointView<double> *>(point))
                                    {
                                        points.push_back(new Point2<double>(*model));
                                    }
                                }

                                // Clear the previous circles
                                removeCirclesFromModel();

                                // Use welzl's algorithm that is able to compute the minimal enclosing circle in O(n) time
                                Circle<double> result = calculateSmallestEnclosingCircle<double>(points);

                                CircleView<double> *circle = new CircleView<double>(result, Color4(1.0, 0.0, 0.0, 0.25));
                                circle->SetBorder(Color4(1.0, 0.0, 0.0, 1.0), 2);



                                container->addModel(circle);
                            }
                        }                        
                    }                    
                }
            }
        }
        if(mouseEvent->GetButton() == Right)
        {
            if (auto container = dynamic_cast<Container *>(_model))
            {
                container->clear();
            }
        }
    }
}

void MinimalEnclosingCircleController::removeCirclesFromModel()
{
    // Clear all saved elements within the container
    if (auto container = dynamic_cast<Container *>(_model))
    {

        int i = 0;
        for (auto &&point : container->GetModels())
        {
            if (auto model = dynamic_cast<CircleView<double> *>(point))
            {
                container->removeModel(i);
            }
            else
            {
                i++;
            }
        }
    }
}