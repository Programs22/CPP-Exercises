#include <iostream>

using namespace std;

class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(int n=0, int d=1){
        numerator=n;
        if(d==0){
            denominator=1;
        }
        else
            denominator=d;
    }
    int getNumerator(){
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }
    void Addition(int n, int d){
        if(denominator==d)
            numerator+=n;
        else{
            numerator=numerator*d+n*denominator;
            denominator*=d;
        }
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
    }
    void Subtraction(int n, int d){
        if(denominator==d)
            numerator-=n;
        else{
            numerator=numerator*d-n*denominator;
            denominator*=d;
        }
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
    }
    void Multiplication(int n, int d){
        numerator*=n;
        denominator*=d;
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
    }
    void Division(int n, int d){
        numerator*=d;
        denominator*=n;
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
    }
    void print(){
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        cout << "The fraction is: " << numerator << "/" << denominator << endl;
    }
    double fraction(){
        return (double)numerator/denominator;
    }
};


int main()
{
    Fraction fraction1(2,4), fraction2(3,5);
    fraction1.Addition(fraction2.getNumerator(),fraction2.getDenominator());
    fraction1.print();
    cout << "The fraction is equal to " << fraction1.fraction() << endl;
    Fraction fraction3(3,8), fraction4(2,8);
    fraction3.Subtraction(fraction4.getNumerator(),fraction4.getDenominator());
    fraction3.print();
    cout << "The fraction is equal to " << fraction3.fraction() << endl;
    Fraction fraction5(4,5), fraction6(3,8);
    fraction5.Multiplication(fraction6.getNumerator(),fraction6.getDenominator());
    fraction5.print();
    cout << "The fraction is equal to " << fraction5.fraction() << endl;
    Fraction fraction7(5,4), fraction8(2,7);
    fraction7.Division(fraction8.getNumerator(),fraction8.getDenominator());
    fraction7.print();
    cout << "The fraction is equal to " << fraction7.fraction() << endl;
    return 0;
}
