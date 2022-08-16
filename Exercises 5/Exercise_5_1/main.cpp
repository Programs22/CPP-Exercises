#include <iostream>
#include <string.h>

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
    void setDate(int d, int m, int y){
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
private:
    Date date_of_birth;
    Date date_of_arrival;
    Date date_of_vaccination;
    char type; // M - mammal, B - bird, R - reptile
    char gender; // M - male, F - female
    char name[20];
public:
    Animal(char t='M', char g='M', char *n=(char*)"Human"):date_of_birth(),date_of_arrival(),date_of_vaccination(){
        type=t;
        gender=g;
        strcpy(name,n);
    }
    void setAnimal(char t, char g, char *n, int b_day, int b_month, int b_year, int a_day, int a_month, int a_year, int v_day, int v_month, int v_year){
        type=t;
        gender=g;
        strcpy(name,n);
        date_of_birth=Date(b_day,b_month,b_year);
        date_of_arrival=Date(a_day,a_month,a_year);
        date_of_vaccination=Date(v_day,v_month,v_year);
    }
    char getType(){
        return type;
    }
    void print(){
        switch(type){
        case 'M': cout << "Type: Mammal" << endl; break;
        case 'B': cout << "Type: Bird" << endl; break;
        case 'R': cout << "Type: Reptile" << endl; break;
        default: cout << "No such animal in this zoo" << endl;
        }
        switch(gender){
        case 'M': cout << "Gender: Male" << endl; break;
        case 'F': cout << "Gender: Female" << endl; break;
        default: cout << "The gender doesn't exist" << endl;
        }
        cout << "Name of animal: " << name << endl;
        cout << "Date of birth: ";
        date_of_birth.print();
        cout << "Date of arrival: ";
        date_of_arrival.print();
        cout << "Date of last vaccination: ";
        date_of_vaccination.print();
    }
    int checkVaccination(int day, int month, int year){
        if(type=='M'){
            int d=date_of_vaccination.getDay();
            int m=date_of_vaccination.getMonth();
            int y=date_of_vaccination.getYear();
            if(year-y>1){
                date_of_vaccination.setDate(day,month,year);
                return 1;
            }
            else if(year-y==1){
                if(month>m){
                    date_of_vaccination.setDate(day,month,year);
                    return 1;
                }
                else if(month==m){
                    if(day>=d){
                        date_of_vaccination.setDate(day,month,year);
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else if(type=='R'){
            int d=date_of_vaccination.getDay();
            int m=date_of_vaccination.getMonth();
            int y=date_of_vaccination.getYear();
            if(year-y>1){
                date_of_vaccination.setDate(day,month,year);
                return 1;
            }
            else if(year-y==1){
                if(month>(m-4)){
                    date_of_vaccination.setDate(day,month,year);
                    return 1;
                }
                else if(month==(m-4)){
                    if(day>=d){
                        date_of_vaccination.setDate(day,month,year);
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else{
                if(month-m>8){
                    date_of_vaccination.setDate(day,month,year);
                    return 1;
                }
                else if(month-m==8){
                    if(day>=d){
                        date_of_vaccination.setDate(day,month,year);
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
        }
        else{
            int d=date_of_vaccination.getDay();
            int m=date_of_vaccination.getMonth();
            int y=date_of_vaccination.getYear();
            if(year-y>1){
                date_of_vaccination.setDate(day,month,year);
                return 1;
            }
            else if(year-y==1){
                if(month>(m-6)){
                    date_of_vaccination.setDate(day,month,year);
                    return 1;
                }
                else if(month==(m-6)){
                    if(day>=d){
                        date_of_vaccination.setDate(day,month,year);
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else{
                if(month-m>6){
                    date_of_vaccination.setDate(day,month,year);
                    return 1;
                }
                else if(month-m==6){
                    if(day>=d){
                        date_of_vaccination.setDate(day,month,year);
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
        }
    }
};

int main()
{
    Animal Zoo[10];
    int choice, i=0;
    cout << "Enter a choice from the menu" << endl;
    cout << "0 - Add an animal" << endl;
    cout << "1 - Show the number of animals in the zoo" << endl;
    cout << "2 - Show the animals of a specific type" << endl;
    cout << "3 - Show all the animals in the zoo" << endl;
    cout << "4 - Show all the animals that need to be vaccinated" << endl;
    cout << "5 - End of program" << endl ;
    cin >> choice;
    while(choice>=0&&choice<=4){
        switch(choice){
        case 0:{
            cin.ignore();
            char t, g, n[20];
            cout << "Enter the type, gender and the name of the animal" << endl;
            cin >> t >> g >> n;
            int b_day, b_month, b_year;
            cout << "Enter the date of birth of the animal" << endl;
            cin >> b_day >> b_month >> b_year;
            int a_day, a_month, a_year;
            cout << "Enter the arrival date of the animal in the zoo" << endl;
            cin >> a_day >> a_month >> a_year;
            int v_day, v_month, v_year;
            cout << "Enter the vaccination date of the animal" << endl;
            cin >> v_day >> v_month >> v_year;
            Zoo[i++].setAnimal(t,g,n,b_day,b_month,b_year,a_day,a_month,a_year,v_day,v_month,v_year);
            break;
        }
        case 1: cout << "The number of animals in the zoo is " << i << endl; break;
        case 2:{
            cout << "Enter the type of animal you want to examine in the zoo" << endl;
            char t;
            cin >> t;
            for(int j=0;j<i;j++){
                if(Zoo[j].getType()==t)
                    Zoo[j].print();
            }
            break;
        }
        case 3:{
            for(int j=0;j<i;j++)
                Zoo[j].print();
            break;
        }
        case 4:{
            for(int j=0;j<i;j++){
                if(Zoo[j].checkVaccination(12,8,2022)==1)
                    Zoo[j].print();
            }
            break;
        }
        }
        cout << "Enter a choice from the menu" << endl;
        cout << "0 - Add an animal" << endl;
        cout << "1 - Show the number of animals in the zoo" << endl;
        cout << "2 - Show the animals of a specific type" << endl;
        cout << "3 - Show all the animals in the zoo" << endl;
        cout << "4 - Show all the animals that need to be vaccinated" << endl;
        cout << "5 - End of program" << endl ;
        cin >> choice;
    }
    cout << "End of program" << endl;
    return 0;
}
