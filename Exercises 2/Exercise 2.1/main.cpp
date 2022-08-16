#include <iostream>

using namespace std;

template <class T>
T minimum(T variable1, T variable2){
    T min=variable1;
    if(min>variable2)
        min=variable2;
    return min;
}

int main(){
    int number1, number2;
    cout << "Enter two numbers" << endl;
    cin >> number1 >> number2;
    cout << "The smaller number is " << minimum(number1, number2) << endl;
    double num1, num2;
    cout << "Enter two floating point numbers" << endl;
    cin >> num1 >> num2;
    cout << "The smaller number is " << minimum(num1,num2) << endl;
    char character1, character2;
    cout << "Enter two characters" << endl;
    cin >> character1 >> character2;
    cout << "The smaller character is " << minimum(character1,character2) << endl;
    return 0;
}
