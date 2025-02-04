/*Write a C++ program to create class with three data members (or sections): private, public, protected.
Declare 1 data member for each section.
The class should have a public function setvalue() to set values of data members. Make another public function showValue() to show the details.*/

#include <iostream>
using namespace std;

class Question1{
    private:
        int privateVal;
    protected:
        int protectedVal;
    public:
        int publicVal;

    void setValue(int priv, int prot, int pub){
        privateVal = priv;
        protectedVal = prot;
        publicVal = pub;
    }

    void showValue(){
        cout << "Private Value : " << privateVal << endl;
        cout << "Protected Value : " << protectedVal << endl;
        cout << "Public Value : " << publicVal << endl;
    }
};

int main(){
    Question1 obj1;
    obj1.setValue(10, 20, 30);
    obj1.showValue();

    return 0;
}