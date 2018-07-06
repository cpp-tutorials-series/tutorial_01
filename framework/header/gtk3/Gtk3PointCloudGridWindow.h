#ifndef Gtk3PointCloudGridWindow_h
#define Gtk3PointCloudGridWindow_h

#include "Gtk3GridWindow.h"
#include <model/PointCloud.h>

class Gtk3PointCloudGridWindow : public Gtk3GridWindow
{
    public:
        Gtk3PointCloudGridWindow(int width, int height, int columns, int rows);

        void drawModel() override;
};

#endif