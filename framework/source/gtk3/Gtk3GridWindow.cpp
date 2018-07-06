#include <gtk3/Gtk3GridWindow.h>

Gtk3GridWindow::Gtk3GridWindow(int width, int height, int columns, int rows) : GridWindow(width, height, columns, rows)
{

}

void Gtk3GridWindow::drawVerticalLine(int i, double axisWidth, double stepSize)
{
    int x = axisWidth+i * stepSize;

    _context->save();

    // Move to the x position of the i-th column
    _context->move_to(x, 0);

    // Draw a line from the current position to the lower y position 
    _context->line_to(x, _height-axisWidth);
    _context->stroke();

    Cairo::TextExtents extends;
    _context->get_text_extents(std::to_string(i), extends);

    // Draw vertical values for axis description
    _context->move_to(x - extends.width / 2, _height-axisWidth + _fontSize);
    _context->show_text(std::to_string(i));

    _context->restore();
}

void Gtk3GridWindow::drawHorizontalLine(int i, double axisWidth, double stepSize)
{
    int y = (i + 1) * stepSize;

    _context->save();

    // Move to the x position of the i-th column
    _context->move_to(axisWidth, (i+1) * stepSize);

    // Draw a line from the current position to the lower y position 
    _context->line_to(_width, (i+1) * stepSize);
    _context->stroke();

    std::string value = std::to_string(_rows - i - 1);

    // Calculates the bounding box of a string for the canvas
    Cairo::TextExtents extends;
    _context->get_text_extents(value, extends);

    // Draw vertical values for axis description
    _context->move_to(axisWidth - (int)extends.width - _fontSize * 0.5, y + extends.height / 2.0);

    // Displays the text
    _context->show_text(value);

    _context->restore();
}

int Gtk3GridWindow::GetAxisSize() const
{
    // Calculate the width of the largest text value in order to determine the width needed to display the axis labels
    Cairo::TextExtents extends;
    _context->get_text_extents(std::to_string(_columns > _rows ? _columns : _rows), extends);

    // Determine axis width by comparing the width of the largest text value with the font size and set the bigger value as the axis width
    return _fontSize * 3 > extends.width * 2 ? _fontSize * 3 : extends.width * 2; 
}

bool Gtk3GridWindow::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    // Set the context variable to use for the drawing functions
    _context = cr;

    // Set the background color to white
    _context->set_source_rgba(1.0, 1.0, 1.0, 1.0);   
    _context->paint();
    _context->restore();
    _context->save();

    // Set the line width to 1
    _context->set_line_width(1);


    // Draws the grid
    _context->restore();
    drawGrid();
     _context->save();

    drawModel();

    return true;
}