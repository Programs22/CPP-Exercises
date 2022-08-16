#include <iostream>
#include <cmath>

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
    Fraction operator+(Fraction &F){
        if(denominator==F.denominator)
            numerator+=F.numerator;
        else{
            numerator=numerator*F.denominator+F.numerator*denominator;
            denominator*=F.denominator;
        }
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    Fraction operator+(int number){
        numerator+=number*denominator;
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    Fraction operator-(Fraction &F){
        if(denominator==F.denominator)
            numerator-=F.numerator;
        else{
            numerator=numerator*F.denominator-F.numerator*denominator;
            denominator*=F.denominator;
        }
        int n=abs(numerator);
        int flag=min(n,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(n%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    Fraction operator-(int number){
        numerator-=number*denominator;
        int n=abs(numerator);
        int flag=min(n,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(n%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    Fraction operator*(Fraction &F){
        numerator*=F.numerator;
        denominator*=F.denominator;
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    Fraction operator*(int number){
        numerator*=number;
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    Fraction operator/(Fraction &F){
        numerator*=F.denominator;
        denominator*=F.numerator;
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    Fraction operator/(int number){
        denominator*=number;
        int flag=min(numerator,denominator); // Variable to hold the GCD (Greatest Common Divisor)
        while(flag>0){
            if(numerator%flag==0&&denominator%flag==0)
                break;
            flag--;
        }
        numerator/=flag;
        denominator/=flag;
        return *this;
    }
    void print(){
        cout << "The fraction is: " << numerator << "/" << denominator << endl;
    }
    double fraction(){
        return (double)numerator/denominator;
    }
};

int main()
{
    Fraction F1(2,5), F2(3,4);
    F1=F1+F2;
    F1.print();
    Fraction F3=F1-F2;
    F3.print();
    Fraction F4(3,11), F5(4,7);
    F4=F4*F5;
    F4.print();
    Fraction F6=F4/F5;
    F6.print();
    Fraction F7(6,4), F8(3,2), F9(2,7), F10(5,8);
    F7=F7*2;
    F8=F8+8;
    F9=F9-1;
    F10=F10/2;
    F7.print();
    F8.print();
    F9.print();
    F10.print();
    Fraction F11(2,5), F12(3,4);
    F11=F11-F12;
    F11.print();
    return 0;
}
