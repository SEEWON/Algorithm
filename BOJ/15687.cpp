#include <iostream>

using namespace std;

class Rectangle
{
private:
  int width, height;

public:
  Rectangle(int _width, int _height)
  {
    width = _width;
    height = _height;
  }
  int get_width() const
  {
    return width;
  }
  int get_height() const
  {
    return height;
  }
  void set_width(int _width)
  {
    if (_width <= 0 || _width > 1000)
      return;
    width = _width;
  }
  void set_height(int _height)
  {
    if (_height <= 0 || _height > 2000)
      return;
    height = _height;
  }
  int area() const
  {
    return width * height;
  }
  int perimeter() const
  {
    return 2 * (width + height);
  }
  bool is_square() const
  {
    return width == height;
  }
};


