#include "elements.h"
#include <string>
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H


class ComplexNumber : public Element
{
protected:
    double real{0};
    double imaginaryI{0};
    virtual double getR() const;
    virtual double getFi() const;
public:
    ComplexNumber() = default;
    ComplexNumber(const double real, const double imaginary);
    ComplexNumber(const ComplexNumber& number);
    ComplexNumber operator+(const ComplexNumber&);
    ComplexNumber operator-(const ComplexNumber&);
    ComplexNumber operator/(const ComplexNumber&);
    ComplexNumber operator*(const ComplexNumber&);
    bool operator==(const ComplexNumber&);
    bool operator!=(const ComplexNumber&);
    double getRealPart() const ;
    double getImaginaryIPart() const;
    void setRealPart(const double real);
    void setImaginaryIPart(const double imaginary);
    virtual std::string toString();
    static ComplexNumber* fromString(std::string);
    virtual ~ComplexNumber();
};

#endif // COMPLEXNUMBER_H
