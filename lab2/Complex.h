#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H

#include <iostream>


class Complex {
private:
    int re;
    int im;
public:
    Complex(): re(0), im(0) {};
    int & Re() {
        return re;
    }
    int & Im() {
        return im;
    }
    Complex (int n) {
        re = n;
        im = 0;
    }
    Complex operator+(Complex n) {
        Complex sum =Complex();
        sum.Re() = re + n.Re();
        sum.Im() = im + n.Im();
        return sum;
    }
    Complex operator+(int n) {
        Complex sum = Complex();
        sum.Re() = re + n;
        return sum;
    }
    Complex operator*(Complex n) {
        Complex multiply = Complex();
        multiply.Re() = re * n.Re() - im * n.Im();
        multiply.Im() = re * n.Im() + im * n.Re();
        return multiply;
    }
    Complex operator*(int n) {
        Complex multiply = Complex();
        multiply . Re() = re * n;
        multiply . Im() = im * n;
        return multiply;
    }
    Complex operator=(int n) {
        Complex c = Complex();
        c.Re() = n;
        c.Im() = 0;
        return c;
    }
    friend Complex sqrt(Complex c) {
        return c;
    }
    friend std::ostream& operator<<(std::ostream &, const Complex &);
};

std::ostream& operator<<(std::ostream &out, const Complex & c) {
    if (c.im >= 0) {
        out << c.re << "+" << c.im << "i";
    }
    else {
        out << c.re << c.im << "i";
    }
    return out;
};




#endif //LAB2_COMPLEX_H
