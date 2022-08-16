#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Date{
private:
    int day, month, year;
public:
    Date(int d=1, int m=1, int y=2000){
        day=d;
        month=m;
        year=y;
    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    void print(){
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Animal{
protected:
    Date dateOfBirth, dateOfArrival, dateOfLastVaccination;
    char gender;
    char *name;
public:
    Animal(Date DoB, Date DoA, Date DoLV, char g, char *n){
        dateOfBirth=DoB;
        dateOfArrival=DoA;
        dateOfLastVaccination=DoLV;
        gender=g;
        name=new char[strlen(n)-1];
        strcpy(name,n);
    }
    void print(){
        cout << "Name and gender: " << name << " " << gender << endl;
        cout << "Date of birth: ";
        dateOfBirth.print();
        cout << "Date of arrival: ";
        dateOfArrival.print();
        cout << "Date of last vaccination: ";
        dateOfLastVaccination.print();
    }
    virtual int Vaccination(Date D)=0;
};

class Reptile:public Animal{
private:
    Date dateOfNextVaccination;
public:
    Reptile(Date DoB=NULL, Date DoA=NULL, Date DoLV=NULL, char g=' ', char *n=(char *)" ", Date DoNV=NULL):Animal(DoB,DoA,DoLV,g,n){
        dateOfNextVaccination=DoNV;
    }
    void print(){
        Animal::print();
        cout << "Date of next vaccination: ";
        dateOfNextVaccination.print();
    }
    int Vaccination(Date D){
        int d1=dateOfNextVaccination.getDay();
        int m1=dateOfNextVaccination.getMonth();
        int y1=dateOfNextVaccination.getYear();
        int d2=D.getDay();
        int m2=D.getMonth();
        int y2=D.getYear();
        if(y1==y2&&m1==m2){
            if(abs(d1-d2)<=7)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
};

class Bird:public Animal{
private:
    bool flier;
public:
    Bird(Date DoB=NULL, Date DoA=NULL, Date DoLV=NULL, char g=' ', char *n=(char *)" ", bool f=false):Animal(DoB,DoA,DoLV,g,n){
        flier=f;
    }
    void print(){
        Animal::print();
        if(flier)
            cout << "Flying bird" << endl;
        else
            cout << "Grounded bird" << endl;
    }
    int Vaccination(Date Today){
        int d1=dateOfLastVaccination.getDay();
        int m1=dateOfLastVaccination.getMonth();
        int y1=dateOfLastVaccination.getYear();
        int d2=Today.getDay();
        int m2=Today.getMonth();
        int y2=Today.getYear();
        if(y2-y1>1)
            return 1;
        else if(y2-y1==1){
            if(m2>(m1-6))
                return 1;
            else if(m2==(m1-6)){
                if(d2>=d1)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
        else{
            if(m2-m1>6)
                return 1;
            else if(m2-m1==6){
                if(d1>=d2)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
    }
};

class Mammal:public Animal{
private:
    bool ruminant;
public:
    Mammal(Date DoB=NULL, Date DoA=NULL, Date DoLV=NULL, char g=' ', char *n=(char *)" ", bool r=false):Animal(DoB,DoA,DoLV,g,n){
        ruminant=r;
    }
    void print(){
        Animal::print();
        if(ruminant)
            cout << "Ruminant mammal" << endl;
        else
            cout << "Non-ruminant mammal" << endl;
    }
    int Vaccination(Date Today){
        int d1=dateOfLastVaccination.getDay();
        int m1=dateOfLastVaccination.getMonth();
        int y1=dateOfLastVaccination.getYear();
        int d2=Today.getDay();
        int m2=Today.getMonth();
        int y2=Today.getYear();
        if(y2-y1>1)
            return 1;
        else if(y2-y1==1){
            if(m2>m1)
                return 1;
            else if(m2==m1){
                if(d2>=d1)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }
};

int main()
{
    Reptile R[5];
    Bird B[5];
    Mammal M[5];
    int choice, count=0;
    cout << "Enter a choice from the menu" << endl;
    cout << "0 - Enter an object into an array" << endl;
    cout << "1 - Print the number of animals in the zoo" << endl;
    cout << "2 - Print information about the animals from a specific group" << endl;
    cout << "3 - Print information about all of the animals in the zoo" << endl;
    cout << "4 - Print information about the animals that need to be vaccinated" << endl;
    cout << "5 - End of program" << endl;
    cin >> choice;
    int r=0, b=0, m=0; // Counters for the arrays
    while(choice>=0&&choice<=4){
        switch(choice){
        case 0:{
            char n[20], g;
            int day, month, year;
            cout << "Enter the name and the gender of the animal" << endl;
            cin >> n >> g;
            cout << "Enter the day, month and year the animal was born" << endl;
            cin >> day >> month >> year;
            Date DoB(day,month,year);
            cout << "Enter the day, month and year of the arrival in the zoo" << endl;
            cin >> day >> month >> year;
            Date DoA(day,month,year);
            cout << "Enter the day, month and year of the last vaccination" << endl;
            cin >> day >> month >> year;
            Date DoLV(day,month,year);
            int array;
            cout << "Enter which array you want to insert an object into" << endl; // 1 for reptiles, 2 for birds, 3 for mammals
            cin >> array;
            switch(array){
            case 1:{
                cout << "Enter the day, month and year of the next vaccination" << endl;
                cin >> day >> month >> year;
                Date DoNV(day,month,year);
                R[r++]=Reptile(DoB,DoA,DoLV,g,n,DoNV);
                break;
            }
            case 2:{
                int f;
                cout << "Enter whether the bird is a flier" << endl;
                cin >> f;
                if(f)
                    B[b++]=Bird(DoB,DoA,DoLV,g,n,true);
                else
                    B[b++]=Bird(DoB,DoA,DoLV,g,n,false);
                break;
            }
            case 3:{
                int a;
                cout << "Enter whether the mammal is a ruminant" << endl;
                cin >> a;
                if(a)
                    M[m++]=Mammal(DoB,DoA,DoLV,g,n,true);
                else
                    M[m++]=Mammal(DoB,DoA,DoLV,g,n,false);
                break;
            }
            }
            count++;
            break;
        }
        case 1:{
            cout << "There are " << count << " animals in the zoo" << endl;
            break;
        }
        case 2:{
            int array;
            cout << "Enter which group of animals you want to view" << endl; // 1 for reptiles, 2 for birds, 3 for mammals
            cin >> array;
            switch(array){
            case 1:{
                for(int i=0;i<r;i++)
                    R[i].print();
                break;
            }
            case 2:{
                for(int i=0;i<b;i++)
                    B[i].print();
                break;
            }
            case 3:{
                for(int i=0;i<m;i++)
                    M[i].print();
                break;
            }
            }
            break;
        }
        case 3:{
            cout << "Information about the reptiles:" << endl;
            for(int i=0;i<r;i++)
                R[i].print();
            cout << "Information about the birds:" << endl;
            for(int i=0;i<b;i++)
                B[i].print();
            cout << "Information about the mammals:" << endl;
            for(int i=0;i<m;i++)
                M[i].print();
            break;
        }
        case 4:{
            Date Today(15,8,2022);
            cout << "Information about the reptiles that need to be vaccinated:" << endl;
            for(int i=0;i<r;i++){
                if(R[i].Vaccination(Today))
                    R[i].print();
            }
            Today=Date(15,8,2022);
            cout << "Information about the birds that need to be vaccinated:" << endl;
            for(int i=0;i<b;i++){
                if(B[i].Vaccination(Today))
                    B[i].print();
            }
            Today=Date(15,8,2022);
            cout << "Information about the mammals that need to be vaccinated:" << endl;
            for(int i=0;i<m;i++){
                if(M[i].Vaccination(Today))
                    M[i].print();
            }
            break;
        }
        }
        cout << "Enter a choice from the menu" << endl;
        cout << "0 - Enter an object into an array" << endl;
        cout << "1 - Print the number of animals in the zoo" << endl;
        cout << "2 - Print information about the animals from a specific group" << endl;
        cout << "3 - Print information about all of the animals in the zoo" << endl;
        cout << "4 - Print information about the animals that need to be vaccinated" << endl;
        cout << "5 - End of program" << endl;
        cin >> choice;
    }
    cout << "End of program" << endl;
    return 0;
}
