#ifndef BUW_RGB_HPP
#define BUW_RGB_HPP

// header, system
#include <iosfwd>


class Color {
public : // enums, typedefs

  typedef float value_t;
 
public : // c'tor
  Color   ();
  Color   ( Color const& );
  Color   ( value_t r, value_t g, value_t b ); 

  ~Color  ();

public : // methods
  void            swap        ( Color& );
  void            print       ( std::ostream& os ) const;

  value_t&        operator[]  ( unsigned component );
  const value_t&  operator[]  ( unsigned component ) const;

  Color&          operator=   ( const Color& );
  void            operator+=  ( const Color& );


private: // members
  value_t data_[3]; // rgb
};

Color operator+(const Color& a, const Color& b);
std::ostream& operator<<(std::ostream& os, Color const&);

#endif // BUW_RGB_HPP
