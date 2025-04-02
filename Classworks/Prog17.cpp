#include <iostream>
using namespace std;

int main(){
    int *ptr = new int;
    int *ptr2 = new int;
    *ptr = 56;

    cout << "Value stored in ptr: " << *ptr << endl;
    cout << "Address of ptr : " << ptr << endl;

    cin >> *ptr2;
    cout << "Value stored in ptr2 : " << *ptr2 << endl;
    cout << "Address of ptr2 : " << ptr2 << endl;

    delete ptr, ptr2;
    return 0;
}