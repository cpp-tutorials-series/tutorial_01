#include <qt/QTGridWindow.h>

QTGridWindow::QTGridWindow(int width, int height, int columns, int rows) : GridWindow(width, height, columns, rows)
{

}

int QTGridWindow::GetAxisSize() const
 {
     QFontMetrics fm(_font);
     
    int width = fm.width(QString::fromStdString(std::to_string(_columns > _rows ? _columns : _rows)));
    
    // Determine axis width by comparing the width of the largest text value with the font size and set the bigger value as the axis width
    return _fontSize * 3 > width * 2 ? _fontSize * 3 : width * 2; 
 }

void QTGridWindow::paintEvent(QPaintEvent *event)
{
    _painter = new QPainter();
    _painter->begin(this);
    _painter->setRenderHint(QPainter::Antialiasing);
   
    drawGrid();

    drawModel();

    _painter->end();
}

void QTGridWindow::drawVerticalLine(int i, double axisWidth, double stepSize)
{
    int x = axisWidth+i * stepSize;

    // Move to the x position of the i-th column
    _painter->drawLine(x, 0, x, _height-axisWidth);

    QFontMetrics fm(_font);
    int width = fm.width(QString::fromStdString(std::to_string(i)));

    // Draw vertical values for axis description
    _painter->drawText(x - width / 2, _height-axisWidth + _fontSize, QString::fromStdString(std::to_string(i)));
}

void QTGridWindow::drawHorizontalLine(int i, double axisWidth, double stepSize)
{
    int y = (i + 1) * stepSize;

    // Move to the x position of the i-th column
    _painter->drawLine(axisWidth, (i+1) * stepSize, _width, (i+1) * stepSize);


    std::string value = std::to_string(_rows - i - 1);

    QFontMetrics fm(_font);
    int width = fm.width(QString::fromStdString(value));

    // Draw vertical values for axis description
    _painter->drawText(axisWidth - (int)width - _fontSize * 0.5, y + _fontSize / 2.0, QString::fromStdString(value));
}

void QTGridWindow::drawModel()
{
    
}
