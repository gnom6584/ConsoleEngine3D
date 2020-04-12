#include "Color.hpp"

Color::Color(COLOR_VALUE_TYPE red, COLOR_VALUE_TYPE green, COLOR_VALUE_TYPE blue, COLOR_VALUE_TYPE alpha): red(red), green(green), blue(blue), alpha(alpha){}

Color::Color(COLOR_VALUE_TYPE red, COLOR_VALUE_TYPE green, COLOR_VALUE_TYPE blue): red(red), green(green), blue(blue), alpha(COLOR_VALUE_MAX){}

Color::Color(COLOR_VALUE_TYPE value): red(value), green(value), blue(value), alpha(value){}

Color::Color(): red(0), green(0), blue(0), alpha(0){}

Color Color::lerp(const Color &color0, const Color &color1, float t) {
    return color0 + t * (color1 - color0);
}

Color Color::clamp() {
    red = (red > COLOR_VALUE_MAX)? COLOR_VALUE_MAX : (red < 0)? 0 : red;
    green = (green > COLOR_VALUE_MAX)? COLOR_VALUE_MAX : (green < 0)? 0 : green;
    blue = (blue > COLOR_VALUE_MAX)? COLOR_VALUE_MAX : (blue < 0)? 0 : blue;
    alpha = (alpha > COLOR_VALUE_MAX)? COLOR_VALUE_MAX : (alpha < 0)? 0 : alpha;
    return *this;
}

COLOR_VALUE_TYPE Color::getLuminosity() const {
    return ((0.21f * red + 0.72f * green + 0.07f * blue) * alpha) / COLOR_VALUE_MAX;
}

Color Color::operator+(const Color &color) const {
    return Color(red + color.red, green + color.green, blue + color.blue, alpha + color.alpha);
}

Color Color::operator-(const Color &color) const {
    return Color(red - color.red, green - color.green, blue - color.blue, alpha - color.alpha);
}

void Color::operator+=(const Color &color) {
    *this = *this + color;
}

void Color::operator-=(const Color &color) {
    *this = *this - color;
}

Color Color::operator*(MULTIPLY_TYPE inscrement) const {
    return Color(red * inscrement, green * inscrement, blue * inscrement, alpha * inscrement);
}

Color Color::operator/(MULTIPLY_TYPE inscrement) const {
    return Color(red / inscrement, green / inscrement, blue / inscrement, alpha / inscrement);
}

void Color::operator *= (MULTIPLY_TYPE inscrement){
    *this = *this * inscrement;
}

void Color::operator /= (MULTIPLY_TYPE inscrement){
    *this = *this / inscrement;
}

Color Color::operator-() const {
    return Color(-red, -green, -blue, -alpha);
}

Color operator*(MULTIPLY_TYPE inscrement, const Color &color) {
    return color * inscrement;
}
