/*#include <stdio.h>
void myName(){
    printf("Omm..");
}
void myName(){
    printf("Shivam");
}

int main(){
    myName();
    return 0;
}*/

#include <iostream>
using namespace std;

namespace lib1{
    void myName(){
        cout << "Omm.." << endl;
    }
}
namespace lib2{
    void myName(){
        cout << "Shivam" << endl;
    }
}

int main(){
    lib1::myName();
    lib2::myName();

    return 0;
}