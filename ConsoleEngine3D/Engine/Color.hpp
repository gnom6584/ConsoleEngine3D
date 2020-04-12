#ifndef Color_hpp
#define Color_hpp

typedef short COLOR_VALUE_TYPE;
typedef float MULTIPLY_TYPE;
const COLOR_VALUE_TYPE COLOR_VALUE_MAX = 255;

struct Color{
    COLOR_VALUE_TYPE red;
    COLOR_VALUE_TYPE green;
    COLOR_VALUE_TYPE blue;
    COLOR_VALUE_TYPE alpha;
    
    Color(COLOR_VALUE_TYPE red, COLOR_VALUE_TYPE green, COLOR_VALUE_TYPE blue, COLOR_VALUE_TYPE alpha);
    Color(COLOR_VALUE_TYPE red, COLOR_VALUE_TYPE green, COLOR_VALUE_TYPE blue);
    Color(COLOR_VALUE_TYPE value);
    Color();
    
    static Color lerp(const Color& color0, const Color& color1, float t);
    
    Color clamp();
    COLOR_VALUE_TYPE getLuminosity() const;
    
    Color operator + (const Color &color) const;
    Color operator - (const Color &color) const;
    
    void operator += (const Color &color);
    void operator -= (const Color &color);
    
    Color operator * (MULTIPLY_TYPE inscrement) const;
    
    Color operator / (MULTIPLY_TYPE inscrement) const;
    
    void operator *= (MULTIPLY_TYPE inscrement);
    
    void operator /= (MULTIPLY_TYPE inscrement);
    
    Color operator-() const;
};

Color operator*(MULTIPLY_TYPE inscrement, const Color &color);

#endif /* Color_hpp */
