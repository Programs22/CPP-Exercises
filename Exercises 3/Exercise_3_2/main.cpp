#include <iostream>
#include <string.h>

using namespace std;

class Saver{
private:
    int ID;
    char NameSurname[30], address[50];
    long amount;
public:
    void set(int id, char ns[], char addr[], unsigned long a){
        ID=id;
        strcpy(NameSurname,ns);
        strcpy(address,addr);
        amount=a;
    }
    void print(){
        cout << "ID number: " << ID << ", Name and surname: " << NameSurname << ", Address: " << address << ", Amount: " << amount << endl;
    }
    void deposit(unsigned long a){
        amount+=a;
    }
    void withdraw(unsigned long a){
        if(a<=amount)
            amount-=a;
        else
            cout << "Not possible to withdraw that amount" << endl;
    }
    long Amount(){
        return amount;
    }
};

int main()
{
    Saver client;
    int id;
    char ns[30], addr[50];
    long a;
    cout << "Enter the data for the client" << endl;
    cin >> id;
    cin.ignore();
    gets(ns);
    gets(addr);
    cin >> a;
    client.set(id,ns,addr,a);
    client.print();
    long d;
    cout << "Enter the amount you want to deposit" << endl;
    cin >> d;
    client.deposit(d);
    long w;
    cout << "Enter the amount you want to withdraw" << endl;
    cin >> w;
    client.withdraw(w);
    cout << "The client has " << client.Amount() << " in the bank" << endl;
    client.print();
    return 0;
}
