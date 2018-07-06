#include <qt/QTModelWindow.h>


QTModelWindow::QTModelWindow(int width, int height, int columns, int rows) : QTGridWindow(width, height, columns, rows)
{
    
}

void QTModelWindow::drawModel()
{
    if(auto container = dynamic_cast<Container*>(_model))
    {
        for(auto it = container->GetBegin(); it != container->GetEnd(); it++)
        {
            auto modelView = dynamic_cast<ModelView*>(*it);
            Color4 background = modelView->GetBackgroundColor();
            //_painter->setBrush(QBrush(QColor((int)(background.red * 255), (int)(background.green * 255), (int)(background.blue * 255), (int)(background.alpha * 255)))); 
            _painter->setBrush(QBrush(QColor(255, 0, 0, 50)));
            
            Color4 border = modelView->GetBorderColor();
           // _painter->setPen(QPen(QBrush(QColor(std::max(255, (int)(border.red * 255)), std::max(255, (int)(border.green * 255)), std::max(255, (int)(border.blue * 255)), std::max(255, (int)(border.alpha * 255)))), modelView->GetBorderSize()));

            if(auto point = dynamic_cast<PointView<double>*>(*it))
            {
                _painter->drawEllipse(QPointF(point->x(), point->y()), 8, 8);
            }

            if(auto circle = dynamic_cast<CircleView<double>*>(*it))
            {
                auto radius = circle->GetRadius();
                 _painter->drawEllipse(QPointF(circle->x(), circle->y()), radius, radius);

                 //
                 _painter->drawEllipse(QPointF(circle->x(), circle->y()), 8, 8);
            }
        }
    }
}