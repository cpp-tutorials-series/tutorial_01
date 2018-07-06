/**
 * \class Application
 * 
 * \brief Abstract class to implement an application for an arbitrary GUI toolkit
 * 
 * An application is used to define the entry point of your program. It is used to 
 * provide the backbone of your program and allows to the user to add windows to it.
 * However this class is only an abstract class used as an interface for different
 * GUI toolkits like Gtk3 or Qt.
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef Application_h
#define Application_h

#include "Window.h"

class Application 
{
    public:
        /// Create an application using the arguments specified as console parameters
        Application(int argc, char *argv[]);

        /// Executes the application and displays added windows on the screen
        virtual int execute() = 0;

        /// Adds a window to the application
        virtual void addWindow(Window* window) = 0;
};

#endif