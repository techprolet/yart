#ifndef BUW_PIXEL_HPP
#define BUW_PIXEL_HPP

// header, system
#include <iosfwd>

// header, project
#include <color.hpp>


class Pixel {
public : // c'tor

  Pixel(std::size_t = 0, std::size_t = 0);
  ~Pixel();

public : // methods

  void print(std::ostream&) const;

public : // member

  std::size_t x;
  std::size_t y;
  Color       rgb;
};

std::ostream& operator<<(std::ostream&, const Pixel&);

#endif // BUW_PIXEL_HPP
