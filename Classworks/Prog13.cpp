/*Write a C++ program to create class with a variable x. 
The class should have two functions:
	setVal(int) to assign a value to x.
	display() to display the value of x.
Define these function outside the class. 
Initialise the variable and display the value.*/

#include <iostream>
using namespace std;

class Question2{
    private:
        int x;
    public:
        void setVal(int val){
            x = val;
        }
        void display(){
            cout << "Value of x is " << x << endl;
        }
};

int main(){
    Question2 obj1;
    obj1.setVal(34);
    obj1.display();

    return 0;
}