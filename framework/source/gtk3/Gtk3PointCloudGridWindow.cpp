#include <gtk3/Gtk3PointCloudGridWindow.h>

Gtk3PointCloudGridWindow::Gtk3PointCloudGridWindow(int width, int height, int columns, int rows) : Gtk3GridWindow(width, height, columns, rows)
{

}

void Gtk3PointCloudGridWindow::drawModel()
{
    // Sets the circle fill color
    if(auto pointCloud = dynamic_cast<PointCloud*>(_model))
    {
        _context->set_source_rgba(0.0, 0.0, 0.0, 1.0);  

        std::vector<Point>::const_iterator begin = pointCloud->GetBegin();
        std::vector<Point>::const_iterator end = pointCloud->GetEnd();
        for(auto it = begin; it != end; it++)
        {
            _context->save();
            _context->translate((*it).x+4, (*it).y);
            _context->scale(8, 8);
            _context->arc(0.0, 0.0, 1.0, 0.0, 2.0 * M_PI); 
            _context->close_path();                
            _context->fill_preserve();
            _context->restore();  
        }
    }    



}