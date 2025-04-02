#include <iostream>
using namespace std;

class Line{
    private:
        double length;
    public:
        void setLength(double l);
        double getLength();
        Line(); //Constructor
        Line(double l); //Parameterized constructor
};
Line :: Line(){
    cout << "Empty Constructor" << endl;
}
void Line :: setLength(double l){
    length = l;
}
double Line :: getLength(){
    return length;
}
Line :: Line(double l){
    length = l;
    cout << "Length of obj2 : " << length << endl;
}

int main(){
    Line l1;
    l1.setLength(4.5);
    cout << "Length of obj1 : " << l1.getLength() << endl;
    Line l2(5.4);
    
    return 0;
}