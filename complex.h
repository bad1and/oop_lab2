#pragma once
#include <cmath>
#include <ncurses.h>

class TComplex {
private:
    double re;
    double im;
public:
    TComplex();
    TComplex(double r, double i = 0.0);

    double real() const { return re; }
    double imag() const { return im; }

    void setReal(double r) { re = r; }
    void setImag(double i) { im = i; }

    TComplex operator+(const TComplex& other) const;
    TComplex operator-(const TComplex& other) const;
    TComplex operator*(const TComplex& other) const;
    TComplex operator/(const TComplex& other) const;

    bool operator==(const TComplex& other) const;
    bool operator!=(const TComplex& other) const;

    double abs() const;

    void print() const;
};
