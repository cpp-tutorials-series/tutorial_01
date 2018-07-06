#define QT

#if defined(QT) 
    #include <qt/QTApplication.h>
    #include <qt/QTModelWindow.h>
#else
    #include <gtk3/Gtk3Application.h>
    #include <gtk3/Gtk3PointCloudGridWindow.h>
#endif

#include <model/Container.h>
#include "Application.h"
#include "MinimalEnclosingCircleController.h"

#include <math/Point2.h>
#include <math/Vector2.h>
#include "CircleView.h"

#include "MinimalEnclosingCircle.h"

int main(int argc, char *argv[])
{
    Application* app = 
    #if defined(QT)
        new QTApplication(argc, argv); 
    #else
        new Gtk3Application(argc, argv);   
    #endif

    Window* gridWindow =
    #if defined(QT)
        new QTModelWindow(800, 800, 40, 40);
    #else
        new Gtk3PointCloudGridWindow(800, 800, 40, 40);
    #endif

    // Set the font size of the grid window
    gridWindow->SetFontSize(12);

    // Add the window to the application to display it
    app->addWindow(gridWindow);

    // Create a point cloud model
    Container* model = new Container();


    // Set the model to the view
    gridWindow->SetModel(model);

    Math::Vector2<int> vec;

    // Create the controller for the application to handle user events
    MinimalEnclosingCircleController* controller = new MinimalEnclosingCircleController(model, gridWindow);

    // Execute the application and display the window
    return app->execute();
}