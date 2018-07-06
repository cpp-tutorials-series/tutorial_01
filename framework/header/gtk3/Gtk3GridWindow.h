/**
 * \class Gtk3GridWindow
 * 
 * \brief Displays a window with a grid with the Gtk3 library
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef Gtk3GridWindow_h
#define Gtk3GridWindow_h

#include "Gtk3Window.h"
#include "GridWindow.h"

class Gtk3GridWindow : public Gtk3Window, public GridWindow
{
    public:
        Gtk3GridWindow(int width, int height, int columns, int rows);

        int GetAxisSize() const override;
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        void drawVerticalLine(int i, double axisWidth, double stepSize) override;
        void drawHorizontalLine(int i, double axisWidth, double stepSize) override;

};

#endif