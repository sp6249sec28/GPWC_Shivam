#include <iostream>
using namespace std;

namespace lib1{
    void sum(){
        int n1, n2;
        /*cout << "Enter the numbers : ";
        cin >> n1 >> n2;*/
        cout << "Sum : " << n1+n2 << endl;
    }
    void sub(){
        int n1, n2;
        /*cout << "Enter the numbers : ";
        cin >> n1 >> n2;*/
        cout << "Difference : " << n1-n2 << endl;
    }
    void mul(){
        int n1, n2;
        /*cout << "Enter the numbers : ";
        cin >> n1 >> n2;*/
        cout << "Product : " << n1*n2 << endl;
    }
    void div(){
        int n1, n2;
        /*cout << "Enter the numbers : ";
        cin >> n1 >> n2;
        if(n2!=0){
            cout << "Division : " << n1/n2 << endl;
        }
        else{
            cout << "Error: Division cannot be performed by zero." << endl;
        }
        */
        cout << "Division : " << n1/n2 << endl;
    }
}
namespace lib2{
    void myName(){
        cout << "Shivam" << endl;
    }
}

int main(){    
    namespace l1 = lib1;
    namespace l2 = lib2;
    l1::sum();
    l1::sub();
    l1::mul();
    l1::div();
    l2::myName();    

    return 0;
}

//The above code shows garbage values as the variables n1 and n2 are not initialized.