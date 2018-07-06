#include <qt/QTPointCloudGridWindow.h>

QTPointCloudGridWindow::QTPointCloudGridWindow(int width, int height, int columns, int rows) : QTGridWindow(width, height, columns, rows)
{

}

void QTPointCloudGridWindow::drawModel() 
{
    // Sets the circle fill color
    _painter->setBrush(Qt::black);
    if(auto pointCloud = dynamic_cast<PointCloud*>(_model))
    {
        std::vector<Point>::const_iterator begin = pointCloud->GetBegin();
        std::vector<Point>::const_iterator end = pointCloud->GetEnd();
        for(auto it = begin; it != end; it++)
        {
            _painter->drawEllipse(QPointF((*it).x, (*it).y), 8, 8);
        }
    }    
}