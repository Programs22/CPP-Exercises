#include <iostream>

using namespace std;

class Shape{
public:
    virtual float Area(){
        return 0.0;
    }
    virtual float Volume(){
        return 0.0;
    }
    virtual void print()=0;
};

class TwoDimensional:public Shape{
protected:
    int x, y;
public:
    TwoDimensional(int m, int n){
        x=m;
        y=n;
    }
    void print(){
        cout << "Two dimensional figure: ";
    }
};

class ThreeDimensional:public Shape{
protected:
    int x, y, z;
public:
    ThreeDimensional(int m, int n, int p){
        x=m;
        y=n;
        z=p;
    }
    void print(){
        cout << "Three dimensional body: ";
    }
};

class Square:public TwoDimensional{
public:
    Square(int x):TwoDimensional(x,x){}
    void print(){
        TwoDimensional::print();
        cout << "Square" << endl;
        cout << "x=" << x << endl;
    }
    float Area(){
        return x*x;
    }
    float Volume(){
        return 0.0;
    }
};

class Rectangle:public TwoDimensional{
public:
    Rectangle(int x, int y):TwoDimensional(x,y){}
    void print(){
        TwoDimensional::print();
        cout << "Rectangle" << endl;
        cout << "x=" << x << ", y=" << y << endl;
    }
    float Area(){
        return x*y;
    }
    float Volume(){
        return 0.0;
    }
};

class Triangle:public TwoDimensional{
public:
    Triangle(int x, int y):TwoDimensional(x,y){}
    void print(){
        TwoDimensional::print();
        cout << "Triangle" << endl;
        cout << "a=" << x << ", h=" << y << endl;
    }
    float Area(){
        return (float)(x*y)/2;
    }
    float Volume(){
        return 0.0;
    }
};

class Cube:public ThreeDimensional{
public:
    Cube(int x):ThreeDimensional(x,x,x){}
    void print(){
        ThreeDimensional::print();
        cout << "Cube" << endl;
        cout << "x=" << x << endl;
    }
    float Area(){
        return 6*x*x;
    }
    float Volume(){
        return x*x*x;
    }
};

class Cuboid:public ThreeDimensional{
public:
    Cuboid(int x, int y, int z):ThreeDimensional(x,y,z){}
    void print(){
        ThreeDimensional::print();
        cout << "Cuboid" << endl;
        cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
    }
    float Area(){
        return 2*(x*y+x*z+y*z);
    }
    float Volume(){
        return x*y*z;
    }
};

class SquarePrism:public ThreeDimensional{
public:
    SquarePrism(int x, int z):ThreeDimensional(x,x,z){}
    void print(){
        ThreeDimensional::print();
        cout << "Square Prism" << endl;
        cout << "x=" << x << ", H=" << z << endl;
    }
    float Area(){
        Square S(x);
        Rectangle R(x,z);
        return 2*S.Area()+4*R.Area();
    }
    float Volume(){
        Square S(x);
        return (float)(S.Area()*z)/3;
    }
};

int main()
{
    Square S(5);
    S.print();
    cout << "Area of the square: " << S.Area() << endl;
    Rectangle R(3,4);
    R.print();
    cout << "Area of the rectangle: " << R.Area() << endl;
    Triangle T(10,4);
    T.print();
    cout << "Area of the triangle: " << T.Area() << endl;
    Cube C(7);
    C.print();
    cout << "Area of the cube: " << C.Area() << ", volume of the cube: " << C.Volume() << endl;
    Cuboid Cub(3,4,5);
    Cub.print();
    cout << "Area of the cuboid: " << Cub.Area() << ", volume of the cuboid: " << Cub.Volume() << endl;
    SquarePrism SP(4,6);
    SP.print();
    cout << "Area of the prism: " << SP.Area() << ", volume of the prism: " << SP.Volume() << endl;
    return 0;
}
