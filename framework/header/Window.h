/**
 * \class Window
 * 
 * \brief Abstract class representing a window with a canvas that can be used to draw onto it
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef Window_h
#define Window_h

#include "Observer.h"
#include "Observable.h"

#include <model/Model.h>

#include <event/MouseMoveEvent.h>
#include <event/MousePressEvent.h>
#include <event/MouseReleaseEvent.h>
#include <string>

class Window : public Observable
{
    public:
        /// Default constructor
        Window();
        
        /** Creates a new window and sets its minimal size to the provided parameters
         * \param width The width of the window
         * \param height The height of the window
         */
        Window(int width, int height);

        /// Default deconstructor
        virtual ~Window();

        /// Returns the font size that is used to display the axis descriptions
        int GetFontSize() const;

        /** Sets the font size that is used to display the axis descriptions
         * \param fontSize The new value for the font size
         */
        virtual void SetFontSize(int fontSize) = 0;

        /** Sets the font of the window to the specific font name
         * \param font The font name that is used to render text on the window
         */
        virtual void SetFont(std::string font) = 0;

        /** Sets the font of the window to the specific font name
         * \param font The font name that is used to render text on the window
         * \param size The new value for the font size
         */
        virtual void SetFont(std::string font, int size) = 0;

        /// Returns the width of the window
        int GetWidth();

        /**
         * Sets the width of the window
         * \param width The new width as the preferred width
         */
        void SetWidth(int width);

        /// Return sthe height of the window
        int GetHeight();

        /// Interface to render a model 
        virtual void drawModel() = 0;

        /**
         * Sets the height of the window
         * \param height The new height as the preferred height
         */
        void SetHeight(int height);

        void SetModel(Model* model);
    protected:
        int _fontSize;

        int _width;
        int _height;

        Model* _model;
};

#endif