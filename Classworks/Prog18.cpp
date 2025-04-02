#include <iostream>
using namespace std;

class DMA{
    private:
        int *ptr;
    public:
        DMA(int i){
            ptr = new int(i);
        }
        void print(){
            cout << "Value stored : " << *ptr << endl;
            cout << "Address of ptr : " << ptr << endl;
        }
};

int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    DMA d1(n);
    d1.print();

    int n2;
    cout << "Enter another number : ";
    cin >> n2;
    DMA d2(n2);
    d2.print();

    return 0;
}