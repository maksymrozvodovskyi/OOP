#include ,iostream.
using namespace std;

class Transport
{

private:
bool p;
float speed;

public:
void SetSpeed(newspeed){speed = newspeed;}
float GetSpeed(){return speed;}

void Move(float speed)
{   if ( speed > 0)
    {
    p = true;
   if (p)
   {
    cout << "Car is moving";
   }
    }
}

void Brake(float speed)
{
  if ( speed <= 0)
    {
    p = false;
   if (!p)
    {
    cout << "The car is brake";
    }
    }
}
}

class Car : public Transport
{

private:
string make;
string model;
int year;

public:
void SetMake(newmake){make = newmake;}
string GetMake(){return make;}

void SetModel(newmodel){model = newmodel;}
string GetModel(){return model;}

void SetYear(newyear){year = newyear;}
string GetYear(){return year;}

void Info()
{
    cout << "The car has make: " << make << endl;
    cout << "The car has model: " << model << endl;
    cout << "The car has year: " << year << endl;
}
}



int main()
{













}