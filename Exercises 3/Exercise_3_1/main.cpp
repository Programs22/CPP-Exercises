#include <iostream>

using namespace std;

class Cuboid{
private:
    float length, height, width;
public:
    void set(float l=0, float h=0, float w=0){
        length=l;
        height=h;
        width=w;
    }
    void print(){
        cout << "Length: " << length << ", height: " << height << ", width: " << width << endl;
    }
    bool isCube(){
        if(length==height&&length==width&&height==width)
            return true;
        else
            return false;
    }
    float Area(){
        return 2*(length*height+length*width+height*width);
    }
    float Volume(){
        return length*height*width;
    }
};

int main()
{
    int choice, i=0;
    Cuboid cuboids[10];
    cout << "Enter a number between 0 and 4 to choose from the menu" << endl;
    cout << "0 - Create object" << endl;
    cout << "1 - Change dimensions of object" << endl;
    cout << "2 - Print dimensions of all the cuboids" << endl;
    cout << "3 - Print dimensions of a specific cuboid" << endl;
    cout << "4 - Print dimensions of the cuboid that meets the requirements" << endl;
    cin >> choice;
    while(choice>=0&&choice<=4){
        switch(choice){
        case 0:{
            cout << "Creating an object from class Cuboid" << endl;
            cout << "Enter the dimensions of the cuboid" << endl;
            float l, h, w;
            cin >> l >> h >> w;
            cuboids[i++].set(l,h,w);
            break;
        }
        case 1:{
            cout << "Enter the dimensions of the cuboid" << endl;
            float l, h, w;
            cin >> l >> h >> w;
            cout << "Enter which object's dimensions you want to change" << endl;
            int j;
            cin >> j;
            cuboids[j].set(l,h,w);
            break;
        }
        case 2:{
            for(int j=0;j<i;j++)
                cuboids[j].print();
            break;
        }
        case 3:{
            cout << "Enter which object's dimensions you want to print out" << endl;
            int j;
            cin >> j;
            cuboids[j].print();
            break;
        }
        case 4:{
            int position=0;
            float min=cuboids[0].Area();
            for(int j=1;j<i;j++){
                if(min>cuboids[j].Area()){
                    if(!cuboids[j].isCube()){
                        min=cuboids[j].Area();
                        position=j;
                    }
                }
            }
            cout << "The dimensions of the cuboid with the smallest area are:" << endl;
            cuboids[position].print();
            break;
        }
        default: cout << "Invalid choice from the menu" << endl;
        }
        cout << "Enter a number between 0 and 4 to choose from the menu" << endl;
        cout << "0 - Create object" << endl;
        cout << "1 - Change dimensions of object" << endl;
        cout << "2 - Print dimensions of all the cuboids" << endl;
        cout << "3 - Print dimensions of a specific cuboid" << endl;
        cout << "4 - Print dimensions of the cuboid that meets the requirements" << endl;
        cin >> choice;
    }
    cout << "End of program" << endl;
    return 0;
}

