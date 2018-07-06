#define QT

#if defined(QT) 
    #include <qt/QTApplication.h>
    #include <qt/QTPointCloudGridWindow.h>
#else
    #include <gtk3/Gtk3Application.h>
    #include <gtk3/Gtk3PointCloudGridWindow.h>
#endif

#include <model/PointCloud.h>
#include "Application.h"
#include "GridController.h"

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
        new QTPointCloudGridWindow(800, 800, 40, 40);
    #else
        new Gtk3PointCloudGridWindow(800, 800, 40, 40);
    #endif

    // Set the font size of the grid window
    gridWindow->SetFontSize(12);

    // Add the window to the application to display it
    app->addWindow(gridWindow);

    // Create a point cloud model
    PointCloud* model = new PointCloud();

    // Set the model to the view
    gridWindow->SetModel(model);

    // Create the controller for the application to handle user events
    GridController* controller = new GridController(model, gridWindow);

    // Execute the application and display the window
    return app->execute();
}