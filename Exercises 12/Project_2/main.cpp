#include <iostream>

using namespace std;

class OneDimensional{
protected:
    int x;
public:
    OneDimensional(int n){
        x=n;
    }
    void print(){
        cout << "x=" << x << endl;
    }
};

class TwoDimensional:public OneDimensional{
protected:
    int y;
public:
    TwoDimensional(int m, int n):OneDimensional(m){
        y=n;
    }
    void print(){
        OneDimensional::print();
        cout << "y=" << y << endl;
    }
};

class ThreeDimensional:public TwoDimensional{
protected:
    int z;
public:
    ThreeDimensional(int m, int n, int p):TwoDimensional(m,n){
        z=p;
    }
    void print(){
        TwoDimensional::print();
        cout << "z=" << z << endl;
    }
};

class Square:public TwoDimensional{
public:
    Square(int m):TwoDimensional(m,m){}
    int Perimeter(){
        return (4*x);
    }
    int Area(){
        return (x*x);
    }
};

class Rectangle:public TwoDimensional{
public:
    Rectangle(int m, int n):TwoDimensional(m,n){}
    int Perimeter(){
        return (2*x+2*y);
    }
    int Area(){
        return (x*y);
    }
};

class Triangle:public TwoDimensional{
private:
    int a, b; // The other two sides including variable x
public:
    Triangle(int m, int n, int a, int b):TwoDimensional(m,n){
        this->a=a;
        this->b=b;
    }
    void print(){
        TwoDimensional::print();
        cout << "a=" << a << endl;
        cout << "b=" << b << endl;
    }
    int Perimeter(){
        return (x+a+b);
    }
    float Area(){
        return (float)(x*y)/2;
    }
};

class Cube:public ThreeDimensional{
public:
    Cube(int m):ThreeDimensional(m,m,m){}
    int Area(){
        return 6*x*x;
    }
    int Volume(){
        return x*x*x;
    }
};

class Cuboid:public ThreeDimensional{
public:
    Cuboid(int m, int n, int p):ThreeDimensional(m,n,p){}
    int Area(){
        return 2*(x*y+x*z+y*z);
    }
    int Volume(){
        return x*y*z;
    }
};

class SquarePrism:public ThreeDimensional{
public:
    SquarePrism(int m, int p):ThreeDimensional(m,m,p){}
    int Area(){
        Square S(x);
        Rectangle R(y,z);
        return 2*S.Area()+4*R.Area();
    }
    float Volume(){
        Square S(x);
        return (float)(S.Area()*z)/3;
    }
};

int main()
{
    Square S(3);
    cout << "Square:" << endl;
    S.print();
    cout << "Square area: " << S.Area() << ", square perimeter: " << S.Perimeter() << endl;
    Rectangle R(4,7);
    cout << "Rectangle:" << endl;
    R.print();
    cout << "Rectangle perimeter: " << R.Perimeter() << ", rectangle area: " << R.Area() << endl;
    Triangle T(4,5,3,6);
    cout << "Triangle:" << endl;
    T.print();
    cout << "Triangle perimeter: " << T.Perimeter() << ", triangle area: " << T.Area() << endl;
    Cube C(5);
    cout << "Cube:" << endl;
    C.print();
    cout << "Cube area: " << C.Area() << ", cube volume: " << C.Volume() << endl;
    Cuboid Cub(3,4,5);
    cout << "Cuboid:" << endl;
    Cub.print();
    cout << "Cuboid area: " << Cub.Area() << ", cuboid volume: " << Cub.Volume() << endl;
    SquarePrism SP(6,4);
    cout << "Square Prism:" << endl;
    SP.print();
    cout << "Square prism area: " << SP.Area() << ", square prism volume: " << SP.Volume() << endl;
    return 0;
}
