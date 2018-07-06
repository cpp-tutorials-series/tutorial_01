/**
 * \class QtGridWindow
 * 
 * \brief Displays a window with a grid with the Qt library
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef QTGridWindow_h
#define QTGridWindow_h

#include <QPainter>
#include "QTWindow.h"
#include "GridWindow.h"

class QTGridWindow : public QTWindow, public GridWindow
{
    public:
        QTGridWindow(int width, int height, int columns, int rows);

        int GetAxisSize() const override;

        void drawModel() override;
    protected:

        void drawVerticalLine(int i, double axisWidth, double stepSize) override;
        void drawHorizontalLine(int i, double axisWidth, double stepSize) override;

        void paintEvent(QPaintEvent *event) override;
    protected:
        QPainter* _painter;
};

#endif