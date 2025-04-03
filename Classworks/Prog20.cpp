//Friend Function
// It is not a member of the class but can access 
// private and protected data
// It is defined outside the class

#include <iostream>
using namespace std;

class Box{
    double width;
    public:
    //Friend function declaration
        friend void print(Box box);

        void setWidth(double wid){
            width = wid;
        }
};

//Friend fucntion definition
void print(Box box){
    cout << "Width : " << box.width << endl;
}

int main(){
    Box box;
    box.setWidth(14.0);
    print(box);

    return 0;
}