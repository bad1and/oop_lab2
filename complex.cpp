#include "complex.h"

TComplex::TComplex() : re(0), im(0) {}
TComplex::TComplex(double r, double i) : re(r), im(i) {}

TComplex TComplex::operator+(const TComplex& other) const {
    return TComplex(re + other.re, im + other.im);
}
TComplex TComplex::operator-(const TComplex& other) const {
    return TComplex(re - other.re, im - other.im);
}
TComplex TComplex::operator*(const TComplex& other) const {
    return TComplex(re * other.re - im * other.im,
                    re * other.im + im * other.re);
}
TComplex TComplex::operator/(const TComplex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    return TComplex((re * other.re + im * other.im) / denom,
                    (im * other.re - re * other.im) / denom);
}

bool TComplex::operator==(const TComplex& other) const {
    return re == other.re && im == other.im;
}
bool TComplex::operator!=(const TComplex& other) const {
    return !(*this == other);
}

double TComplex::abs() const {
    return std::sqrt(re * re + im * im);
}

void TComplex::print() const {
    printw("(%g%+gi)", re, im);
}
