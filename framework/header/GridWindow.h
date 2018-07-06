/**
 * \class GridWindow
 * 
 * \brief Displays a window with a grid
 * 
 * Abstract class that provides functions to display a user specified grid
 * on a window. To render the grid use this as a base class and provide 
 * implementations of the drawVerticalLine and drawHorizontalLine functions.
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef GridWindow_h
#define GridWindow_h

#include <cmath>
#include <tuple>
#include "Window.h"

class GridWindow : virtual public Window
{
    public:
        /**
         * Creates a new window displaying the grid
         * \param width The width of the grid window
         * \param height The height of the grid window
         * \param columns The number of columns used for the grid
         * \param rows The number of rows used for the grid
         */
        GridWindow(int width, int height, int columns, int rows);
        
        /// Returns the count of rows of the grid
        int GetRows() const;

        /** Sets the count of the rows of the grid
         * \param rows The new value for the rows used of the grid
         */
        void SetRows(int rows);

        //! Returns the cound of columns of the grid
        int GetColumns() const;

        /** 
         * Sets the count of the columns of the grid
         * \param columns The new value for the columns used of the grid
         */
        int SetColumns(int columns);

        /// Draws the grid on the window
        void drawGrid();

        /**
         * Snaps point to the closest grid point
         * \param x The horizontal coordinate of the point
         * \param y The vertical coordinate of the point
         * 
         * \return Tuple with the grid position
         */
        std::tuple<int, int> GetGridPosition(int x, int y) const;

        /// Calculates the size used to display axis description on the grid window
        virtual int GetAxisSize() const = 0;

    protected:
        /**
         * Draw a vertical line on the grid window
         * \param i The continuous variable used to determine the position of the vertical line
         * \param axisWidth Spared space used to display axis descriptions
         * \param stepSize Size between two lines 
         */
        virtual void drawVerticalLine(int i, double axisWidth, double stepSize) = 0;

        /**
         * Draw a horizontal line on the grid window
         * \param i The continuous variable used to determine the position of the vertical line
         * \param axisWidth Spared space used to display axis descriptions
         * \param stepSize Size between two lines 
         */
        virtual void drawHorizontalLine(int i, double axisWidth, double stepSize) = 0;

    protected:
        int _rows;
        int _columns;
};

#endif