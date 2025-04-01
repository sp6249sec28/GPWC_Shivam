//Empty Constructor

#include <iostream>
using namespace std;

class Line{
    private:
        double *ptr;
    public:
        void setLength(double l);
        double getLength(void);
        Line();
        Line(int len); //Parameterized constructor
        Line(const Line &obj); // Copy constructor
        ~Line(); // Destructor
        // Destructor to free memory allocated for ptr
};

Line :: Line(){
    ptr = new double;
    *ptr = 1;
    cout << "Empty Constructor" << endl;
}
Line :: Line(int len){
    ptr = new double;
    *ptr = len;
}
Line :: Line(const Line &obj){
    ptr = new double;
    *ptr = *obj.ptr;
}

//Deconstructor
Line :: ~Line(){
    delete ptr;
}
double Line :: getLength(void){
    return *ptr;
}
//print length
void printLength(Line obj){
    cout << "Length " << obj.getLength() << endl;
}

int main(){
    Line l1;
}