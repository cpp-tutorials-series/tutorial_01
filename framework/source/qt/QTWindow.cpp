#include <qt/QTWindow.h>

QTWindow::QTWindow()
{

}

QTWindow::QTWindow(int width, int height) : Window(width, height)
{

}

QTWindow::~QTWindow()
{
    
}

void QTWindow::SetFont(std::string font)
{
    _font = QFont(QString::fromStdString(font));
}

void QTWindow::SetFont(std::string font, int size)
{
    _font = QFont(QString::fromStdString(font), size);
}

void QTWindow::SetFontSize(int fontSize)
{
    _fontSize = fontSize;
}

void QTWindow::internalMouseEvent(MouseEvent* genericEvent, QMouseEvent* event, bool pressed)
{
    MouseButton button;
    switch(event->button())
    {
        case Qt::LeftButton:
            button = Left;
            break;
        case Qt::MiddleButton:
            button = Middle;
            break;
        case Qt::RightButton:
            button = Right;
            break;
        default:
            button = NotSpecified;
            break;
    }

    genericEvent->SetX(event->x());
    genericEvent->SetY(event->y());
    genericEvent->SetPressed(true);
    genericEvent->SetButton(button);
}

void QTWindow::mouseMoveEvent(QMouseEvent* event)
{
    MouseMoveEvent* nativeEvent = new MouseMoveEvent();
    internalMouseEvent(nativeEvent, event, false);

    for(auto&& observer : observables)
    {
        observer->update(nativeEvent);
    } 

    update();
}
void QTWindow::mousePressEvent(QMouseEvent* event) 
{
    MousePressEvent* nativeEvent = new MousePressEvent();
    internalMouseEvent(nativeEvent, event, true);
    for(auto&& observer : observables)
    {
        observer->update(nativeEvent);
    } 

    update();
}
void QTWindow::mouseReleaseEvent(QMouseEvent* event) 
{
        MouseButton button;   
    switch(event->button())
    {
        case Qt::LeftButton:
            button = Left;
            break;
        case Qt::MiddleButton:
            button = Middle;
            break;
        case Qt::RightButton:
            button = Right;
            break;
        default:
            button = NotSpecified;
            break;
    }

    MouseReleaseEvent* nativeEvent = new MouseReleaseEvent();
    internalMouseEvent(nativeEvent, event, false);
    for(auto&& observer : observables)
    {
        observer->update(nativeEvent);
    } 

    update();
}

