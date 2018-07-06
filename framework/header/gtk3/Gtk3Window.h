/**
 * \class Gtk3Window
 * 
 * \brief Displays a window with the Gtk3 library
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef GtkWindow_h
#define GtkWindow_h

#include <gtkmm-3.0/gtkmm/drawingarea.h>
#include <event/MouseEvent.h>
#include <string>
#include "Window.h"


class Gtk3Window : public Gtk::DrawingArea, virtual public Window
{
    public:
        Gtk3Window();
        
        Gtk3Window(int width, int height);

        //! Default deconstructor
        virtual ~Gtk3Window();

        void SetFontSize(int fontSize) override;

        //! Sets the font of the canvas to the one specific parameter
        //! \param font The name of the font you want to use
        void SetFont(std::string font) override;

        //! Sets the font of the canvas to the one specific parameter
        //! \param font The name of the font you want to use
        //! \param size The size of the font you want to use
        void SetFont(std::string font, int size) override;

    protected:        

        //! Override the button press event in order to pass it to the controller
        //! event The GDK event representing the mouse action
        bool on_button_press_event(GdkEventButton* event) override;

        bool on_button_release_event(GdkEventButton* event) override;

    protected:
        Cairo::RefPtr<Cairo::Context> _context;
};

#endif