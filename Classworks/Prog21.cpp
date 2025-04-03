#include <iostream>
using namespace std;

class Box1{
    private:
        double width;
        double height;
        double length;
    public:
        friend void print(Box1 box);
        friend void setWidth(Box1 &box, double w);
        friend void setLength(Box1 &box, double l);
        friend void setHeight(Box1 &box, double h);
};

void setWidth(Box1 &box, double w){
    box.width = w;
}
void setLength(Box1 &box, double l){
    box.length = l;
}
void setHeight(Box1 &box, double h){
    box.height = h;
}
void print(Box1 box){
    cout << "Volume : " << box.width * box.length * box.height << endl;
}

int main(){
    Box1 box;
    setWidth(box, 13.2);
    setHeight(box, 8.5);
    setLength(box, 12.8);

    print(box);
    return 0;
}