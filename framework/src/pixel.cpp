// header i/f
#include "pixel.hpp"

// header, system
#include <ostream>


Pixel::Pixel(std::size_t a, std::size_t b)
  : x(a),
    y(b),
    rgb()
{}


///////////////////////////////////////////////////////////////////////////////
Pixel::~Pixel()
{}


///////////////////////////////////////////////////////////////////////////////
void
Pixel::print(std::ostream& os) const
{
  os << "pixel[" << (int)x << ',' << (int)y << "]("
     << rgb[0] << ','
     << rgb[1] << ','
     << rgb[2] << ')';
}


///////////////////////////////////////////////////////////////////////////////
std::ostream&
operator<<(std::ostream& os, const Pixel& a)
{
  std::ostream::sentry cerberus (os);
  if (cerberus)
    a.print(os);
  return os;
}
