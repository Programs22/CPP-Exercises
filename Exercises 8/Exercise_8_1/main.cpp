#include <iostream>

using namespace std;

class Complex{
private:
    double real;
    double imaginary;
public:
    Complex(double r=0.0, double i=0.0){
        real=r;
        imaginary=i;
    }
    Complex operator+(Complex &C){
        real+=C.real;
        imaginary+=C.imaginary;
        return *this;
    }
    Complex operator-(Complex &C){
        real-=C.real;
        imaginary-=C.imaginary;
        return *this;
    }
    Complex &operator=(Complex &C){
        real=C.real;
        imaginary=C.imaginary;
        return *this;
    }
    friend ostream &operator<<(ostream &output, Complex number){
        output << "Real part of complex number: " << number.real << endl;
        output << "Imaginary part of complex number: " << number.imaginary << endl;
        return output;
    }
    friend istream &operator>>(istream &input, Complex &number){
        cout << "Enter the real and imaginary part of the complex number" << endl;
        double real, imaginary;
        input >> real;
        input >> imaginary;
        number.real=real;
        number.imaginary=imaginary;
        return input;
    }
    Complex operator*(Complex &C){
        double r, i;
        r=real*C.real-imaginary*C.imaginary;
        i=real*C.imaginary+imaginary*C.real;
        real=r;
        imaginary=i;
        return *this;
    }
    friend Complex operator*(Complex &C, int number){
        Complex temp;
        temp.real=C.real*number;
        temp.imaginary=C.imaginary*number;
        return temp;
    }
    friend Complex operator*(int number, Complex &C){
        Complex temp;
        temp.real=C.real*number;
        temp.imaginary=C.imaginary*number;
        return temp;
    }
    bool operator==(Complex &C){
        if(real==C.real&&imaginary==C.imaginary)
            return true;
        else
            return false;
    }
    bool operator!=(Complex &C){
        if(real==C.real&&imaginary==C.imaginary)
            return false;
        else
            return true;
    }
    friend Complex operator+=(Complex &C1, Complex &C2){
        C1+C2;
        Complex temp=C1;
        return temp;
    }
    friend Complex operator-=(Complex &C1, Complex &C2){
        C1-C2;
        Complex temp=C1;
        return temp;
    }
    friend Complex operator*=(Complex &C1, Complex&C2){
        C1*C2;
        Complex temp=C1;
        return temp;
    }
};

int main()
{
    Complex x, y(4.3,8.2), z(3.3,1.1);
    y+z;
    x=y;
    cout << x;
    Complex a(4.5,8.2), b(2.3,-6.4);
    a*b;
    cout << a;
    Complex c(9.8,-5.3), d(3.1,8.4);
    c*=d;
    cout << c;
    Complex e, f(2.5,6.7);
    cin >> e;
    if(e==f)
        cout << "The numbers are equal" << endl;
    else
        cout << "The numbers aren't equal" << endl;
    e+=f;
    cout << e;
    Complex r(3.5,4.8);
    Complex result=r*3;
    cout << result;
    return 0;
}
