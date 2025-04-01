#include <iostream>
using namespace std;

class Line{
    private:
        double length;
    public:
        void setLength(double l);
        double getLength();  //double getLength(void);
        Line();  //Constructor declaration

};
Line :: Line(){
    cout << "Constructor is implemented." << endl;
}
void Line :: setLength(double l){
    length = l;
}
double Line :: getLength(){
    return length;
}

int main(){
    Line line;
    line.setLength(6.5);
    cout << "Length of line : " << line.getLength() << endl;
    return 0;
}