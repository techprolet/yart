#include "light.hpp"


Light::Light():       // Standard-Konstr.
    name_(),
    pos_(),
    la_(),
    ld_()
{}


Light::Light(std::string const& name, math3d::point const& pos, Color const& la, Color const& ld):   // Konstr.
    name_(name),
    pos_(pos),
    la_(la),
    ld_(ld)
{}


Light::Light(const Light& lit):  // Copy-Konstr.
    name_(lit.name_),
    pos_(lit.pos_),
    la_(lit.la_),
    ld_(lit.ld_)
{}


Light::~Light()    // Destr.
{}


// Getter

std::string Light::name() {
	return name_;
}

math3d::point Light::pos() {
	return pos_;
}

Color Light::la() {
	return la_;
}

Color Light::ld() {
	return ld_;
}

void Light::print(std::ostream& os) const
{
 os << "Name: " << name_ << ", Position:" << pos_ << " ambient:" << la_ << " diffus:"<< ld_ << std::endl;
}


// Streamop. <<

std::ostream& operator<<(std::ostream& os, Light const& light)
    {
        light.print(os);
		return os;
	}

