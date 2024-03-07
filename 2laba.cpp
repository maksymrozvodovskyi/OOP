#include <iostream> // Додано підключення бібліотеки iostream
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
    const double pi = 3.14159265358979323846;

    volume = (pi * pow(l, 2) * h) / 3; // V

    surface_area = pi * l * sqrt(pow(l, 2) + pow(h, 2)); // S
}

int main()
{
    double l, h;
    double volume, surface_area;

    input_e(l, h);
    calculate(l, h, volume, surface_area);

    cout << "---- Founded elements -----";
    cout << endl;
    cout << "V: " << volume << endl;
    cout << "Surface Area: " << surface_area << endl;
}

