#include <iostream>

using namespace std;

inline double circleArea(double radius){
    return radius*radius*3.14;
}

int main(){
    double radius;
    cout << "Enter the radius of the circle" <<endl;
    cin >> radius;
    cout << "The area of the circle with radius " << radius << " is " << circleArea(radius) << endl;
    return 0;
}
