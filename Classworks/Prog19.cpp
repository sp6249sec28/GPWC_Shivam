#include <iostream>
using namespace std;

class DMA2{
    int *arr;
    int size;

    public:
        DMA2(int i){
            size = i;
            arr = new int[i];
        }
        ~DMA2(){
            delete [] arr;
        }

        void insert(){
            cout << "Enter array elements : " << endl;
            for (int i=0; i<size; i++){
                cin >> arr[i];
            }
        }
        void print(){
            cout << "Printing Array Elements : " << endl;
            for (int i=0; i<size; i++){
                cout << "Value stored : " << arr[i] << ", Address : " << &arr[i] << endl;
            }
        }
};

int main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    DMA2 d1(n);

    d1.insert();
    d1.print();

    return 0;
}