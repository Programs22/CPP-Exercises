#include <iostream>
#include <cstring>

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

class Article{
protected:
    char Name[20];
    char size[4];
    int price;
    Date date_of_arrival;
public:
    Article(char n[], char s[], int p, Date d){
        strcpy(Name,n);
        strcpy(size,s);
        price=p;
        date_of_arrival=d;
    }
    void print(){
        cout << "Name of article: " << Name << endl;
        cout << "Size: " << size << endl;
        cout << "Price of article: " << price << endl;
        cout << "Date of arrival in the store: ";
        date_of_arrival.print();
    }
    int getPrice(){
        return price;
    }
    int Order(){
        cout << "How many articles of this type do you want to order" << endl;
        int number;
        cin >> number;
        return number*price;
    }
};

class Jeans:public Article{
private:
    Date last_order;
public:
    Jeans(char n[]=(char *)"", char s[]=(char *)"", int p=0, Date d=NULL, Date o=NULL):Article(n,s,p,d){
        last_order=o;
    }
    void printJeans(){
        print();
        cout << "Date of last order to be received: ";
        last_order.print();
    }
    int Order(){
        int check=0;
        int d1=last_order.getDay();
        int d2=date_of_arrival.getDay();
        int m1=last_order.getMonth();
        int m2=date_of_arrival.getMonth();
        int y1=last_order.getYear();
        int y2=date_of_arrival.getYear();
        if(m2-m1>1||y2>y1){
            check=Article::Order();
        }
        else if(m2-m1==1){
            if(d2>=d1)
                check=Article::Order();
        }
        return check;
    }
};

class Shirts:public Article{
public:
    Shirts(char n[]=(char *)"", char s[]=(char *)"", int p=0, Date d=NULL):Article(n,s,p,d){}
};

int main()
{
    Jeans J[10];
    Shirts S[10];
    int choice;
    cout << "Enter a choice from the menu" << endl;
    cout << "0 - Add an object to one of the lists" << endl;
    cout << "1 - Information about a specific article" << endl;
    cout << "2 - Information about all of the articles including the total price" << endl;
    cout << "3 - Information about the articles that need to be ordered and the total price of the order" << endl;
    cout << "4 - End of program" << endl;
    cin >> choice;
    int j=0, i=0;
    while(choice>=0&&choice<=3){
        switch(choice){
        case 0:{
            char n[20], s[4];
            int p, d, m, y;
            cout << "Enter the name and the size of the product" << endl;
            cin.ignore();
            cin >> n >> s;
            cout << "Enter the price of the product and the day, month and year it arrived in the store" << endl;
            cin >> p >> d >> m >> y;
            Date D(d,m,y);
            cout << "Enter whether the article is jeans or shirts" << endl; // 1 for jeans, 2 for shirts
            int array_choice;
            cin >> array_choice;
            if(array_choice==1){
                int day, month, year;
                cout << "Enter the day, month and year of the last order of jeans" << endl;
                cin >> day >> month >> year;
                Date O(day,month,year);
                J[j++]=Jeans(n,s,p,D,O);
            }
            else
                S[i++]=Shirts(n,s,p,D);
            break;
        }
        case 1:{
            int array_choice;
            cout << "Enter whether the articles are jeans or shirts" << endl; // 1 for jeans, 2 for shirts
            cin >> array_choice;
            if(array_choice==1){
                for(int counter=0;counter<j;counter++)
                    J[counter].printJeans();
            }
            else{
                for(int counter=0;counter<i;counter++)
                    S[counter].print();
            }
            break;
        }
        case 2:{
            int sum=0;
            for(int counter=0;counter<j;counter++){
                J[counter].printJeans();
                sum+=J[counter].getPrice();
            }
            for(int counter=0;counter<i;counter++){
                S[counter].print();
                sum+=S[counter].getPrice();
            }
            cout << "Total price: " << sum << endl;
            break;
        }
        case 3:{
            int sum=0;
            for(int counter=0;counter<j;counter++){
                int price=J[counter].Order();
                if(price!=0){
                    J[counter].printJeans();
                    sum+=price;
                }
            }
            for(int counter=0;counter<i;counter++){
                int ask;
                cout << "Do you want to order this specific shirt?" << endl;
                cin >> ask;
                if(ask){
                    S[counter].print();
                    sum+=S[counter].Order();
                }
            }
            cout << "Total price of items ordered: " << sum << endl;
            break;
        }
        }
        cout << "Enter a choice from the menu" << endl;
        cout << "0 - Add an object to one of the lists" << endl;
        cout << "1 - Information about a specific article" << endl;
        cout << "2 - Information about all of the articles including the total price" << endl;
        cout << "3 - Information about the articles that need to be ordered and the total price of the order" << endl;
        cout << "4 - End of program" << endl;
        cin >> choice;
    }
    cout << "End of program" << endl;
    return 0;
}
