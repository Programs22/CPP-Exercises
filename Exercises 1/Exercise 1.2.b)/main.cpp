#include <iostream>

using namespace std;

void tripleCallByReference(int &count){
    count*=3;
}

int main(){
    int count;
    cout << "Enter a value for the variable" << endl;
    cin >> count;
    tripleCallByReference(count);
    cout << "After the function, the variable is tripled to equal " << count << endl;
    return 0;
}
