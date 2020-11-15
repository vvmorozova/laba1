#include "complexnumber.h"
#include <cmath>
#include <string.h>

ComplexNumber::ComplexNumber(const double real, const double imaginary)
{
    this->real = real;
    imaginaryI=imaginary;
}

ComplexNumber::ComplexNumber(const ComplexNumber& number)
{
    this->real=number.real;
    this->imaginaryI=number.imaginaryI;
}

double ComplexNumber::getR() const
{
    return sqrt(real*real+imaginaryI*imaginaryI);
}

double ComplexNumber::getFi() const
{
    return atan2(imaginaryI, real);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& number)
{
    return ComplexNumber(this->real+number.real, this->imaginaryI+number.imaginaryI);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& number)
{
    return ComplexNumber(this->real-number.real, this->imaginaryI-number.imaginaryI);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& number)
{
    return ComplexNumber(getR()*number.getR()*cos(getFi()+number.getFi()), getR()*number.getR()*sin(getFi()+number.getFi()));
}

bool ComplexNumber::operator==(const ComplexNumber & number)
{
    if (this->real==number.real && this->imaginaryI==number.imaginaryI) return true;
    else return false;
}

bool ComplexNumber::operator!=(const ComplexNumber &number)
{
    return !operator==(number);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& number)
{
    return ComplexNumber(getR()/number.getR()*cos(getFi()-number.getFi()), getR()/number.getR()*sin(getFi()-number.getFi()));
}

double ComplexNumber::getImaginaryIPart() const
{
    return imaginaryI;
}

double ComplexNumber::getRealPart() const
{
    return real;
}

void ComplexNumber::setImaginaryIPart(const double imaginary)
{
    imaginaryI=imaginary;
}

void ComplexNumber::setRealPart(const double real)
{
    this->real=real;
}

std::string ComplexNumber::toString()
{
    std::string str = std::to_string(real);
    if (imaginaryI>=0) str+=" + "+std::to_string(imaginaryI)+"i";
    else str+=std::to_string(imaginaryI)+"i";
    return str;
}

ComplexNumber *ComplexNumber::fromString(std::string str)
{
    std::size_t loc = str.find("+");
    std::string real,img;
    if (loc!=std::string::npos)
    {
        real = str.substr(0,loc);
        img = str.substr(loc+1,str.length()-loc-2);
        return new ComplexNumber(std::stod(real), std::stod(img));
    }
    else
    {
        loc = str.find("-");
        real = str.substr(0,loc);
        img = str.substr(loc+1,str.length()-loc-2);
        return new ComplexNumber(std::stod(real), -1*std::stod(img));
    }

}

ComplexNumber::~ComplexNumber()
{
    real=0.0;
    imaginaryI=0.0;
}
