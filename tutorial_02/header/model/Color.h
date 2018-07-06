#ifndef Color_h
#define Color_h


struct Color3
{
    float red;
    float green;
    float blue;
};

struct Color4
{
    float red;
    float green;
    float blue;
    float alpha;

    Color4()
    {
        
    }

    Color4(float red, float green, float blue, float alpha)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->alpha = alpha;
    }
};

#endif