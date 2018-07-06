#ifndef QTModelWindow_h
#define QTModelWindow_h

#include <qt/QTPointCloudGridWindow.h>
#include <model/Container.h>
#include "PointView.h"
#include "CircleView.h"

class QTModelWindow : public QTGridWindow
{
    public:
        QTModelWindow(int width, int height, int columns, int rows);

        void drawModel() override;
};


#endif 