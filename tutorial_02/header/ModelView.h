#ifndef ModelView_h
#define ModelView_h

#include <model/Color.h>
#include <model/Model.h>

class ModelView : public Model
{
    public:
        ModelView();

        void SetBorder(Color4 borderColor, int borderSize);

        Color4 GetBorderColor();

        Color4 GetBackgroundColor();

        int GetBorderSize();
    protected:
        int _borderSize;
        Color4 _borderColor;
        Color4 _backgroundColor;
};

#endif