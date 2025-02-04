#include <iostream>
using namespace std;

class Box{
protected:
    double length;
    double width;
    double height;
};
//smallbox is the derived class
class SmallBox : Box{
public:
    void setSmallDetails(double len, double wid, double h);
    double getVol();
};
// member functions of the derived class
void SmallBox::setSmallDetails(double len, double wid, double h){
    length = len;
    width = wid;
    height = h;
}
double SmallBox :: getVol(){
    return length*width*height;
}

int main(){
    SmallBox box;

    box.setSmallDetails(5.0, 4.0, 3.5);
    cout << "Volume of box : " << box.getVol() << endl;

    return 0;
}