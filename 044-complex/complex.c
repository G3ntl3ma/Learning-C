//create complex numbers and make some operations on them
#include <stdio.h>

typedef struct complex {
    double real;
    double imaginary;
} Complex;

Complex MakeComplex(double real, double imaginary);
Complex AddComplex(struct complex c1, struct complex c2);

int main(void){
    Complex c1 = {13.3, 25};
    Complex c2 = {15, 2.2};
    Complex c3 = {1, 2};

    printf("Real: %f, Imaginary: %f\n", c1.real, c1.imaginary);
    Complex c4 = MakeComplex(43, 54);
    printf("MakeComplex Test: Real: %f, Imaginary: %f\n", c4.real, c4.imaginary);
    Complex c5 = AddComplex(c2, c3);
    printf("AddComplex Test: Real: %f, Imaginary: %f\n", c5.real, c5.imaginary);
    return 0;
}

Complex MakeComplex(double real, double imaginary){
    return (Complex){real, imaginary};
}

Complex AddComplex(Complex c1, Complex c2){
    return (Complex){c1.real + c2.real, c1.imaginary + c2.imaginary};
}