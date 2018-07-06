#include <gtk3/Gtk3Window.h>

Gtk3Window::Gtk3Window()
{
    // Enable mouse button press events of the window
    add_events(Gdk::BUTTON_PRESS_MASK);
}

Gtk3Window::Gtk3Window(int width, int height) : Window(width, height)
{
}

Gtk3Window::~Gtk3Window()
{

}

void Gtk3Window::SetFontSize(int fontSize) 
{
    _fontSize = fontSize;
}

void Gtk3Window::SetFont(std::string font)
{
    // Sets the font to normal, light font
    _context->select_font_face(font, Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_NORMAL);
}

void Gtk3Window::SetFont(std::string font, int size)
{
    SetFont(font);

    // Sets the font size
    _context->set_font_size(size);
}

bool Gtk3Window::on_button_press_event(GdkEventButton * event)
{
    MouseButton button;
    if(event->type == GDK_BUTTON_PRESS)
    {
        switch(event->button)
        {
            case 1:
                button = Left;
                break;
            case 2: 
                button = Middle;
                break;
            case 3:
                button = Right;
                break;
            default:
                button = NotSpecified;
                break;
        }
        
    }

    MousePressEvent* nativeEvent = new MousePressEvent(event->x, event->y, true, button);
    for(auto&& observer : observables)
    {
        observer->update(nativeEvent);
    } 

    // Redraw the widget
    queue_draw_area(0, 0, _width, _height);

    return true;
}

bool Gtk3Window::on_button_release_event(GdkEventButton* event)
{
    MouseButton button;
    if(event->type == GDK_BUTTON_RELEASE)
    {
        switch(event->button)
        {
            case 1:
                button = Left;
                break;
            case 2: 
                button = Middle;
                break;
            case 3:
                button = Right;
                break;
            default:
                button = NotSpecified;
                break;
        }
        
    }


    MouseReleaseEvent* nativeEvent = new MouseReleaseEvent(event->x, event->y, true, button);
    for(auto&& observer : observables)
    {
        observer->update(nativeEvent);
    } 

    // Redraw the widget
    queue_draw_area(0, 0, _width, _height);

    return true;    
}