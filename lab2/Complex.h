#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H


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
    Complex* operator+(Complex* n) {
        Complex* sum = new Complex();
        sum -> Re() = re + n->Re();
        sum -> Im() = im + n -> Im();
        return sum;
    }
    Complex* operator+(int n) {
        Complex* sum = new Complex();
        sum -> Re() = re + n;
        return sum;
    }
    Complex* operator*(Complex* n) {
        Complex* multiply = new Complex();
        multiply -> Re() = re * n->Re() - im * n -> Im();
        multiply -> Im() = re * n -> Im() + im * n->Re();
        return multiply;
    }
    Complex* operator*(int n) {
        Complex* multiply = new Complex();
        multiply -> Re() = re * n;
        multiply -> Im() = im * n;
        return multiply;
    }
};


#endif //LAB2_COMPLEX_H
