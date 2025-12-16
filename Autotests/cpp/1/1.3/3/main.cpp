#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double r;
    cout<<"Радиус шара ";
    cin>>r;
    double V = (4.0/3.0)*M_PI*pow(r, 3);
    cout<<"Объем шара "<<V;
    return 0;
}