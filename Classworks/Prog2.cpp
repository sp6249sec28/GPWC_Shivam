#include <iostream>

using namespace std;

int main(){
    int n1, n2;
    int sum=0;

    cout << "Enter 1st number: "<< endl;
    cin >> n1;
    cout << "Enter 2nd number: "<< endl;
    cin >> n2;

    sum = n1+n2;

    cout << "Sum of two numbers : " << sum << endl;
    cout << "Sum : " << sum << "\t" << n1 << "\t" << n2 << endl;

    return 0;
}