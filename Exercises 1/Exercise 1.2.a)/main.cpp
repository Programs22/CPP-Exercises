#include <iostream>

using namespace std;

int tripleCallByValue(int count){
    return 3*count;
}

int main(){
    int count;
    cout << "Enter a value for the variable" << endl;
    cin >> count;
    cout << count << " tripled is equal to " << tripleCallByValue(count) << endl;
    return 0;
}
