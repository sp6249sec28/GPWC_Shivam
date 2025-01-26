#include <iostream>
#include <string>
using namespace std;

class Forest{
    private:
        void treesStanding(){
            cout << "Trees are standing." << endl;
        }
        void birdsFlying(){
            cout << "Birds are flying." << endl;
        }
        void birdsStanding(){
            cout << "Birds are standing." << endl;
        }
        void manMoving(){
            cout << "Men are moving." << endl;
        }
        void manStanding(){
            cout << "Men are standing." << endl;
        }
    public:
        void TreesStanding(){
            treesStanding();
        }
        void BirdsFlying(){
            birdsFlying();
        }
        void BirdsStanding(){
            birdsStanding();
        }
        void ManMoving(){
            manMoving();
        }
        void ManStanding(){
            manStanding();
        }
};

int main(){
    class Forest forest;

    int choice;
    do{
        cout << "\nForest Activity Details :" << endl;
        cout << "1. Trees Standing" << endl;
        cout << "2. Birds Flying" << endl;
        cout << "3. Birds Standing" << endl;
        cout << "4. Man Moving" << endl;
        cout << "5. Man Standing" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice){
            case 1:
                forest.TreesStanding(); break;
            case 2:
                forest.BirdsFlying(); break;
            case 3:
                forest.BirdsStanding(); break;
            case 4:
                forest.ManMoving(); break;
            case 5:
                forest.ManStanding(); break;
            case 6:
                cout << "Exiting the forest program...\n";
                break;
            default:
                cout << "Invalid Choice !!\n";
        }
    }
    while (choice != 6);

    return 0;
}