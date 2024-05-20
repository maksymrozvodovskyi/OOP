1)	Заголовочний файл GRAPHIC_OBJECT_HPP
КОД:

#ifndef GRAPHIC_OBJECT_HPP
#define GRAPHIC_OBJECT_HPP

#include <SFML/Graphics.hpp> 
using namespace sf; // простір імен SFML для спрощення синтаксису (комусь треба по кд писати sf::?? xd покажіть)

class GraphicObject
{
protected:
    double x, y; 
    double size; 
    Color color; 

public:
   
    GraphicObject(double x = 0, double y = 0, double size = 10, Color color = Color::White)
        : x(x), y(y), size(size), color(color) {}

    // віртуальні методи, які реалізовані в похідних класах
    virtual void move(double dx, double dy) = 0; // зміщення об'єкту
    virtual void resize(double newSize) = 0; // зміна розміру об'єкту
    virtual void changeColor(Color newColor) = 0; // зміна кольору об'єкту
    virtual void draw(RenderWindow& window) const = 0; // малювання об'єкту на вікні

    virtual ~GraphicObject() = default; // віртуальний деструктор
};

#endif

2)	Заголовочний файл POINT_HPP:
КОД:

#ifndef POINT_HPP
#define POINT_HPP

#include "GraphicObject.hpp" 
using namespace std; 

class Point : public GraphicObject
{ 
public:
    
    Point(double x = 0, double y = 0, double size = 10, Color color = Color::White)
        : GraphicObject(x, y, size, color) {}

    void move(double dx, double dy) override;          // переміщення
    void resize(double newSize) override;              // зміна розміру
    void changeColor(Color newColor) override;         // зміна кольору
    void draw(RenderWindow& window) const override;    // малювання
};

#endif 

3)	.cpp файл Point:
КОД:

#include "Point.hpp" 

void Point::move(double dx, double dy)
{
    x = x +  dx; // зміщення по X
    y = y + dy; // зміщення по Y
}

void Point::resize(double newSize)
{
    size = newSize; // зміна розміру точки
}

void Point::changeColor(Color newColor)
{
    color = newColor; // зміна кольору точки
}

void Point::draw(RenderWindow& window) const
{
    CircleShape shape(static_cast<float>(size)); // створення кола з вказаним розміром
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // встановлення позиції
    shape.setFillColor(color); // встановлення кольору заливки
    window.draw(shape); // малювання на вікні
}

4)	Заголовочний файл Ellipse.hpp:
КОД:

#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <SFML/Graphics.hpp>
#include <cmath> 
using namespace sf; 
using namespace std; 

class Ellipse
{
private:
    float width, height; // ширина та висота 
    int numPoints; // кількість точок для наближення
    float angleStep; // кутовий крок між точками 
    float posX, posY; // позиція центра еліпса
    float radiusX, radiusY; // радіуси еліпса
    float time; // час для анімації

public:
    Ellipse(float width = 300.0f, float height = 150.0f, int numPoints = 100, float radiusX = 800.0f, float radiusY = 400.0f);

    // <методи оновлення параметрів еліпса>

    void updatePosition(); // оновлення позиції
    void updateSize(); // оновлення розміру
    void updateColor(Color& color); // оновлення кольору
    void draw(RenderWindow& window); // малювання еліпса на вікні
    void incrementTime(float increment); // інкрементування часу для анімації
};

#endif 

5)	.cpp Ellipse:
КОД:

#include "Ellipse.hpp"

Ellipse::Ellipse(float width, float height, int numPoints, float radiusX, float radiusY)
    : width(width), height(height), numPoints(numPoints), radiusX(radiusX), radiusY(radiusY), time(0.0f) 
{
    angleStep = 2 * 3.14159f / numPoints; // кроку між точками
    posX = 960.0f; // Центр екрану (1920 / 2)
    posY = 540.0f; // Центр екрану (1080 / 2)
}

void Ellipse::updatePosition()
{
    posX = 960.0f + cos(time) * radiusX; // оновлення позиції по X та Y
    posY = 540.0f + sin(time) * radiusY; 
}

void Ellipse::updateSize()
{
    width = 300.0f * (0.5f + 0.5f * sin(time)); // оновлення ширини та висоти
    height = 150.0f * (0.5f + 0.5f * cos(time)); 
}

void Ellipse::updateColor(Color& color)
{
    color.r = static_cast<Uint8>(127 + 127 * sin(time)); // оновлення складових R - G - B;
    color.g = static_cast<Uint8>(127 + 127 * sin(time + 2)); 
    color.b = static_cast<Uint8>(127 + 127 * sin(time + 4)); 
}

void Ellipse::draw(RenderWindow& window) 
{
    ConvexShape ellipse; // створення об'єкта для малювання еліпса
    ellipse.setPointCount(numPoints); // встановлення кількості точок

    Color dynamicColor; // динамічний колір
    updateColor(dynamicColor); // оновлення кольору

    for (int i = 0; i < numPoints; ++i)
    {
        float angle = i * angleStep; // кут для поточної точки
        float x = posX + width * cos(angle); // Координата X та Y
        float y = posY + height * sin(angle); 

        ellipse.setPoint(i, Vector2f(x, y)); // встановлення координат точки
    }

    ellipse.setFillColor(dynamicColor); // встановлення кольору заливки
    window.draw(ellipse); // малювання еліпса на вікні
}

void Ellipse::incrementTime(float increment) 
{
    time += increment; // для того аби зробити ілюзію кадрів
}

6)	ГОЛОВНА ФУНКЦІЯ:
КОД:

#include <SFML/Graphics.hpp>
#include "Ellipse.hpp"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML Ellipse"); // створення вікна з роздільною здатністю 1920x1080

    Ellipse ellipse;

    while (window.isOpen())
    { 
        Event event; // об'єкт події
        while (window.pollEvent(event)) // перевіряє чергу подій вікна і, якщо є подія, витягає її з черги і зберігає в об'єкті event
        { 
            if (event.type == Event::Closed) // якщо вікно закрито... ну то бог з ним <3
                window.close();
        }

        window.clear();

        ellipse.updatePosition(); // оновлення позиції еліпса
        ellipse.updateSize(); // оновлення розміру еліпса
        ellipse.draw(window); // малювання еліпса на вікні

        window.display();

        ellipse.incrementTime(0.005f); // інкрементування часу для анімації
    }
}
