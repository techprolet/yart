#include "material.hpp"

Material::Material():
    ka_(Color()),
    kd_(Color()),
    ks_(Color()),
    m_(0)
{
}

Material::Material(const Material &copy):
    ka_(copy.getKa()),
    kd_(copy.getKd()),
    ks_(copy.getKs()),
    m_(copy.getM())
{
}

Material::Material(Color ka,Color kd,Color ks,float m):
    ka_(ka),
    kd_(kd),
    ks_(ks),
    m_(m)
{
}

void Material::setKa (const Color &  ka){
    ka_=ka;
}
void Material::setKd (const Color &  kd){
    kd_=kd;
}
void Material::setKs (const Color &  ks){
    ks_=ks;
}
void Material::setM (float m){
    m_=m;
}

const Color & Material::getKa() const{
    return ka_;
}
const Color & Material::getKd() const{
    return kd_;
}
const Color & Material::getKs() const{
    return ks_;
}
float Material::getM() const{
    return m_;
}


std::ostream & Material::printOn(std::ostream &out) const{
    out<<"--->Material"<<std::endl;
    out<< "ka: rgb"<<ka_<<std::endl;
    out<< "ks: rgb"<<ks_<<std::endl;
    out<< "ka: rgb"<<ka_<<std::endl;
    out<<"m: "<<m_<<std::endl;
    return out;
}


Material::~Material(){

}
