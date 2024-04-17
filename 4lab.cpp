#include <iostream>
using namespace std;

class Transport
{
private:
    bool p;
    float speed;

public:
    void SetSpeed(float newspeed)
    {
        speed = newspeed;
    }

    float GetSpeed()
    {
        return speed;
    }

    void Move(float speed)
    {
        if (speed > 0)
        {
            p = true;
            if (p)
            {
                cout << "Wroten speed is: " << speed << " - Car is moving" << endl << endl;
            }
        }
    }

    void Brake(float speed)
    {
        if (speed <= 0)
        {
            p = false;
            if (!p)
            {
                cout << "Oooops, The car is brake!! Check it please" << endl << endl;
            }
        }
    }
};

class Car : public Transport
{

private:
    string make;
    string model;
    int year;
    string color; 

public:
    void SetMake(string newmake)
    {
        make = newmake;
    }

    string GetMake()
    {
        return make;
    }

    void SetModel(string newmodel)
    {
        model = newmodel;
    }

    string GetModel()
    {
        return model;
    }

    void SetYear(int newyear)
    {
        year = newyear;
    }

    int GetYear()
    {
        return year;
    }

    void SetColor(string newcolor)
    {
        color = newcolor;
    }

    string GetColor()
    {
        return color;
    }

    void Info()
    {
        cout << "The car has make: " << make << endl;
        cout << "The car has model: " << model << endl;
        cout << "The car has year: " << year << endl;
        cout << "The car has color: " << color << endl << endl;
    }

    void Honk()
    {
        cout << "Beep! Beep! " << endl << endl;
    }
};

int main()
{
    Car myCar;

    myCar.SetMake("Honda");
    myCar.SetModel("Accord");
    myCar.SetYear(2023);
    myCar.SetColor("Blue");

    myCar.Info();

    myCar.Move(80.0);
    myCar.Brake(0.0);

    myCar.Honk();

    return 0;
}

