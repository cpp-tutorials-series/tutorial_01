#ifndef QTPointCloudGridWindow_h
#define QTPointCloudGridWindow_h

#include "QTGridWindow.h"
#include <model/PointCloud.h>

class QTPointCloudGridWindow : public QTGridWindow
{
    public:
        QTPointCloudGridWindow(int width, int height, int columns, int rows);

        void drawModel() override;
};

#endif