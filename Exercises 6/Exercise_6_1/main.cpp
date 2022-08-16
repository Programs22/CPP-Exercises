#include <iostream>
#include <cstring>

using namespace std;

class Person{
private:
    char Name[20];
    char Surname[20];
    char Address[20];
    char Telephone[10];
public:
    Person(char *n=(char*)"", char *s=(char*)"", char *a=(char*)"", char *t=(char*)""){
        strncpy(Name,n,20);
        strncpy(Surname,s,20);
        strncpy(Address,a,20);
        strncpy(Telephone,t,10);
    }
    void print(){
        cout << "Name and surname: " << Name << " " << Surname << endl;
        cout << "Address: " << Address << endl;
        cout << "Telephone: " << Telephone << endl;
    }
    ~Person(){}
};

class Saver{
private:
    static int count;
    static float percent;
    float balance;
    float credit;
    Person ID;
public:
    Saver(float c, Person P){
        credit=c;
        balance=credit+credit*percent;
        ID=P;
        count++;
    }
    static int getCount(){
        return count;
    }
    void print(){
        ID.print();
        cout << "Credit in the bank: " << credit << endl;
        cout << "Total balance: " << balance << endl;
    }
    ~Saver(){}
};

int Saver::count=0;
float Saver::percent=0.07;

int main()
{
    cout << "Enter the name, surname, address and telephone number of the client" << endl;
    char n[20], s[20], a[20], t[10];
    cin >> n >> s >> a >> t;
    Person P1(n,s,a,t);
    cout << "Enter the credit of the client in the bank" << endl;
    float c;
    cin >> c;
    Saver S1(c,P1);
    cout << "There are " << Saver::getCount() << " clients in the bank" << endl;
    S1.print();
    cout << "Enter the name, surname, address and telephone number of the client" << endl;
    cin >> n >> s >> a >> t;
    Person P2(n,s,a,t);
    cout << "Enter the credit of the client in the bank" << endl;
    cin >> c;
    Saver S2(c,P2);
    cout << "There are " << Saver::getCount() << " clients in the bank" << endl;
    S2.print();
    return 0;
}
