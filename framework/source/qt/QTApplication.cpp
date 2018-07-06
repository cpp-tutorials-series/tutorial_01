#include <qt/QTApplication.h>

QTApplication::QTApplication(int argc, char *argv[]) : Application(argc, argv)
{
    _application = new QApplication(argc, argv);
    mainWindow = new QMainWindow();
}

int QTApplication::execute()
{
    mainWindow->show();

    return _application->exec();
}

void QTApplication::addWindow(Window* window)
{
    if(auto qwindow = dynamic_cast<QWidget*>(window))
    {
       mainWindow->setCentralWidget(qwindow);
       mainWindow->setFixedSize(window->GetWidth(), window->GetHeight());
    }
}