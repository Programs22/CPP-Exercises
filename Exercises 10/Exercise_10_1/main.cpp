#include <iostream>
#include <cstring>

using namespace std;

class Employee{
private:
    char name[20], surname[20];
    int yearOfEmployment;
public:
    Employee(char n[]=(char *)"", char s[]=(char *)"", int y=2000){
        strcpy(name,n);
        strcpy(surname,s);
        yearOfEmployment=y;
    }
    void setEmployee(char *n, char *s, int y){
        strcpy(name,n);
        strcpy(surname,s);
        yearOfEmployment=y;
    }
    void print(){
        cout << "Name and surname: " << name << " " << surname << endl;
        cout << "Year of emplyment: " << yearOfEmployment << endl;
    }
    ~Employee(){}
};

class Professor:public Employee{
private:
    char fieldOfStudy[20];
    int subjects;
public:
    Professor(char n[]=(char *)"", char s[]=(char *)"", int y=2000, char f[]=(char *)"", int sub=0):Employee(n,s,y){
        strcpy(fieldOfStudy,f);
        subjects=sub;
    }
    void setProfessor(char n[], char s[], int y, char f[], int sub){
        setEmployee(n,s,y);
        strcpy(fieldOfStudy,f);
        subjects=sub;
    }
    void printProfessor(){
        print();
        cout << "Field of study: " << fieldOfStudy << endl;
        cout << "Number of subjects: " << subjects << endl;
    }
    ~Professor(){}
};

class Assistant:public Employee{
private:
    char mentor[20];
    int subjects;
public:
    Assistant(char n[]=(char *)"", char s[]=(char *)"", int y=2000, char m[]=(char *)"", int sub=0):Employee(n,s,y){
        strcpy(mentor,m);
        subjects=sub;
    }
    void setAssistant(char n[], char s[], int y, char m[], int sub){
        setEmployee(n,s,y);
        strcpy(mentor,m);
        subjects=sub;
    }
    void printAssistant(){
        print();
        cout << "Mentor: " << mentor << endl;
        cout << "Number of subjects: " << subjects << endl;
    }
    ~Assistant(){}
};

class Demonstrator:public Employee{
private:
    char workingHours[10];
public:
    Demonstrator(char n[]=(char *)"", char s[]=(char *)"", int y=2000, char w[]=(char *)""):Employee(n,s,y){
        strcpy(workingHours,w);
    }
    void setDemonstrator(char n[], char s[], int y, char w[]){
        setEmployee(n,s,y);
        strcpy(workingHours,w);
    }
    void printDemonstrator(){
        print();
        cout << "Working hours for the demonstrator: " << workingHours << endl;
    }
    ~Demonstrator(){}
};

int main()
{
    Professor P[5];
    Assistant A[5];
    Demonstrator D[5];
    int choice;
    cout << "Enter a choice from the menu" << endl;
    cout << "0 - Enter an object in one of the arrays" << endl;
    cout << "1 - Print each array of objects" << endl;
    cout << "2 - End of program" << endl;
    cin >> choice;
    int p=0, a=0, d=0;
    while(choice==0||choice==1){
        switch(choice){
        case 0:{
            cout << "Enter which array you want to assign an object to" << endl; // 1 for a professor, 2 for an assistant, 3 for a demonstrator
            int array_choice;
            cin >> array_choice;
            switch(array_choice){
            case 1:{
                char n[20], s[20], f[20];
                int y, sub;
                cout << "Enter the name, surname and field of study of the professor" << endl;
                cin >> n >> s >> f;
                cout << "Enter the year of employment and how many subjects he has" << endl;
                cin >> y >> sub;
                P[p++].setProfessor(n,s,y,f,sub);
                break;
            }
            case 2:{
                char n[20], s[20], m[20];
                int y, sub;
                cout << "Enter the name, surname and mentor of the assistant" << endl;
                cin >> n >> s >> m;
                cout << "Enter the year of employment and how many subjects he has" << endl;
                cin >> y >> sub;
                A[a++].setAssistant(n,s,y,m,sub);
                break;
            }
            case 3:{
                char n[20], s[20], w[20];
                int y;
                cout << "Enter the name, surname and working hours of the demonstrator" << endl;
                cin >> n >> s >> w;
                cout << "Enter the year of employment" << endl;
                cin >> y;
                D[d++].setDemonstrator(n,s,y,w);
                break;
            }
            }
            break;
        }
        case 1:{
            cout << "Information about the professors:" << endl;
            for(int i=0;i<p;i++)
                P[i].printProfessor();
            cout << "Information about the assistants:" << endl;
            for(int i=0;i<a;i++)
                A[i].printAssistant();
            cout << "Information about the demonstrators:" << endl;
            for(int i=0;i<d;i++)
                D[i].printDemonstrator();
            break;
        }
        }
        cout << "Enter a choice from the menu" << endl;
        cout << "0 - Enter an object in one of the arrays" << endl;
        cout << "1 - Print each array of objects" << endl;
        cout << "2 - End of program" << endl;
        cin >> choice;
    }
    cout << "End of program" << endl;
    return 0;
}
