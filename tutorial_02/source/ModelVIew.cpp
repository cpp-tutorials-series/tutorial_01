#include "ModelView.h"

ModelView::ModelView()
{

}

void ModelView::SetBorder(Color4 borderColor, int borderSize)
{
    _borderColor = borderColor;
    _borderSize = borderSize;
}

Color4 ModelView::GetBorderColor()
{
    return _borderColor;
}

Color4 ModelView::GetBackgroundColor()
{
    return _backgroundColor;
}

int ModelView::GetBorderSize()
{
    return _borderSize;
}