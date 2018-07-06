#include "Window.h"

Window::Window()
{

}

Window::Window(int width, int height)
{
    _width = width;
    _height = height;
}

Window::~Window()
{
    
}

int Window::GetWidth()
{
    return _width;
}

void Window::SetWidth(int width)
{
    _width = width;
}

int Window::GetHeight()
{
    return _height;
}

void Window::SetHeight(int height)
{
    _height = height;
}

void Window::SetFontSize(int fontSize)
{
    _fontSize = fontSize;
}

void Window::SetModel(Model* model)
{
    _model = model;
}