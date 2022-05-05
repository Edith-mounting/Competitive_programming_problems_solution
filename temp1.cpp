#include <iostream>
using namespace std;
int main(){
    int a = 1;
    double b = 2.0;
    float c = 1.0;
    long d = 1;
    cout<<  typeid(((a+d)*(c + b))). name() << "\n";
}