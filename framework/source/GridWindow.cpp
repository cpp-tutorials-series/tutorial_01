#include "GridWindow.h"

GridWindow::GridWindow(int width, int height, int columns, int rows) : Window(width, height)
{
    _columns = columns;
    _rows = rows;
    _width = width;
    _height = height;
}

void GridWindow::drawGrid()
{
    // Select a font for displayong the axis description
    SetFont("Roboto", 12);
    int axisWidth = GetAxisSize();
    
    // Subtract the axisWidth from the height to keep space for the axis description
    double columnStepSize = (_width-axisWidth) / (double)_columns;
    for(int i=0; i<_columns; i++){
        drawVerticalLine(i, axisWidth, columnStepSize);
    }

    // Subtract the axisWidth from the width to keep space for the axis description
    double rowStepSize = (_height-axisWidth) / (double)_rows;
    for(int j=0; j<_rows; j++){
        drawHorizontalLine(j, axisWidth, rowStepSize);
    }
}

int GridWindow::GetRows() const
{
    return _rows;
}

int GridWindow::GetColumns() const
{
    return _columns;
}

std::tuple<int, int> GridWindow::GetGridPosition(int x, int y) const
{
    int axisSize = GetAxisSize();
    int columnsStepSize = (_width - axisSize) / _columns;
    int rowsStepSize = (_height - axisSize) / _rows;
    return std::make_tuple(axisSize + std::rint(x / columnsStepSize) * columnsStepSize, std::rint(y / rowsStepSize) * rowsStepSize);
}