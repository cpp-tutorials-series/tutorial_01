/**
 * \class QtWindow
 * 
 * \brief Displays a window with the Qt library
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef QTWindow_h
#define QTWindow_h

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QFont>
#include "Window.h"

#include <model/PointCloud.h>

#include <iostream>

class QTWindow : public QWidget, virtual public Window 
{
    Q_OBJECT

    public:
        QTWindow();

        QTWindow(int width, int height);

        ~QTWindow();

        void SetFont(std::string font) override;

        void SetFont(std::string font, int size) override;

        void SetFontSize(int fontSize) override;

        void mouseMoveEvent(QMouseEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;
    protected:
        void internalMouseEvent(MouseEvent* genericEvent, QMouseEvent* event, bool pressed);
    protected:
        QFont _font;
};
#endif