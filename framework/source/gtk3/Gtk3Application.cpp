#include <gtk3/Gtk3Application.h>


Gtk3Application::Gtk3Application(int argc, char *argv[]) : Application(argc, argv)
{
  _application = Gtk::Application::create(argc, argv, "gtk3application");
  _mainWindow = new Gtk::Window();
}

int Gtk3Application::execute()
{
  return _application->run(*_mainWindow);
}

void Gtk3Application::addWindow(Window* window)
{
    if(auto qwindow = dynamic_cast<Gtk::Widget*>(window))
    {
      // Add the widget to a qt main window
       _mainWindow->add(*qwindow);

       // Sets the window size to the specified size
       _mainWindow->set_default_size(window->GetWidth(), window->GetHeight());

       // displays the windows with the widget
       qwindow->show();
    }
}