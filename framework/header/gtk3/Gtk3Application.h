/**
 * \class Gtk3Application
 * 
 * \brief Application used to display windows with the Gtk3 library
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef GtkApplication_h
#define GtkApplication_h

#include <gtkmm-3.0/gtkmm.h>
#include "Application.h"

class Gtk3Application : public Application
{
    public:
        Gtk3Application(int argc, char *argv[]);

        int execute() override;

        void addWindow(Window* window) override;
    private:
        Glib::RefPtr<Gtk::Application> _application;   
        Gtk::Window* _mainWindow;
};

#endif
