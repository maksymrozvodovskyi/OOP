#include <iostream>
#include <cmath>
using namespace std;

void input_e(double& l, double& h)
{
    cout << "Input l: ";
    cin >> l;

    cout << endl;

    cout << "Input h: ";
    cin >> h;
    cout << endl;
}

void calculate(double l, double h, double& volume, double& surface_area)
{
    const double pi = 3.14;

    double r = l / (pi * 2);

    volume = (pi * r * r * h) / 3; 
    surface_area = pi * r * l; 
}

int main()
{
    double l, h;
    double volume, surface_area;

    input_e(l, h);
    calculate(l, h, volume, surface_area);

    cout << "---- Founded elements -----" << endl;
    cout << "V: " << volume << endl;
    cout << "Surface Area: " << surface_area << endl;

    return 0;
}
