/**
 * \class QTApplication
 * 
 * \brief Application used to display windows with the Qt library
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef QApplication_h
#define QApplication_h

#include <QtCore>
#include <QApplication>
#include <QtWidgets/QMainWindow>

#include "Application.h"
#include "QTWindow.h"

class QTApplication : public Application
{
    public:
        QTApplication(int argc, char *argv[]);

        int execute() override;

        void addWindow(Window* window) override;

    private:
        QApplication* _application;
        QMainWindow* mainWindow;

};
#endif