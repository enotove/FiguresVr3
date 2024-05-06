#include <iostream>
#include <string>

class Figure
{
protected:
    int corners;
    std::string nameFigure = "Figure";
public:
    Figure()
    {
        this->corners = 0;
    }
    std::string PringNameFigure() { return nameFigure; }
    virtual std::string PrintSide() { return ""; }
    virtual std::string PrintAngle() { return ""; }
    virtual bool IsTrueFigure() {
        return (this->corners == 0) ? true : false;
    }
    void Print_info() {
        std::cout << PringNameFigure() << std::endl;
        std::cout << "Count of corners: " << corners << std::endl;
        if (corners > 0) {
            std::cout << PrintSide() << std::endl;
            std::cout << PrintAngle() << std::endl ;
        }
        if (IsTrueFigure())
        {
            std::cout << "Figure is true!" << std::endl << std::endl;
        }
        else std::cout << "Figure isn't true!" << std::endl << std::endl;
    }
};
class Triangle : public Figure
{
protected:


    float a, b, c;
    float A, B, C;
public:
    Triangle(float a, float b, float c, float A, float B, float C)
    {
        this->nameFigure = "Triangle";
        this->corners = 3;
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
    }

    std::string PrintSide() override
    {
        return "Side: a = " + std::to_string(a) + " b = " + std::to_string(b) + "  c = " + std::to_string(c);
    }
    std::string PrintAngle() override
    {
        return "Angle: a = " + std::to_string(A) + " B = " + std::to_string(B) + " C = " + std::to_string(C);
    }
    bool IsTrueFigure() override
    {
        return ((corners == 3) && ((A + B + C) == 180)) ? true : false;
    }
};
class Quadrilateral : public Figure
{
protected:

    float a, b, c, d;
    float A, B, C, D;
public:
    Quadrilateral(float a, float b, float c, float d, float A, float B, float C, float D)
    {
        this->nameFigure = "Quadrelaterial";
        this->corners = 4;
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;
    }
    std::string PrintSide() override
    {
        return "Side: a = " + std::to_string(a) + " b = " + std::to_string(b) + "  c = " + std::to_string(c) + " d = " + std::to_string(d);
    }
    std::string PrintAngle() override
    {
        return "Angle: a = " + std::to_string(A) + " B = " + std::to_string(B) + " C = " + std::to_string(C) + " D = " + std::to_string(D);
    }
    bool IsTrueFigure() override
    {
        return ((corners == 4) && ((A + B + C + D) == 360)) ? true : false;
    }
};
class RightAnglesTriangle : public Triangle
{
public:
    RightAnglesTriangle(float a, float b, float c, float A, float B) : Triangle(a, b, c, A, B, 90) { this->nameFigure = "Right-angles Triangle"; this->corners = 3;}
    bool IsTrueFigure() override
    {
        return ((corners == 3) && ( C == 90)) ? true : false;
    }
};
class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(float a, float b, float A, float B) : Triangle(a, b, a, A, B, A) { this->nameFigure = "Isosceles Triangle"; this->corners = 3;}
    bool IsTrueFigure() override
    {
        return ((corners == 3) && ((a == c) && (A == C))) ? true : false;
    }
};
class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(float a) : Triangle(a, a, a, 60, 60, 60) { this->nameFigure = "Equilateral Triangle"; this->corners = 3;}
    bool IsTrueFigure() override
    {
        return ((corners == 3) && ((a==b) && (b == c) && (a==c)) && ((A == B) && (C==A) && (B == C))) ? true : false;
    }
};
class Rectangle : public Quadrilateral
{
public:
    Rectangle(float a, float b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) { this->nameFigure = "Rectangle"; this->corners = 4;
    }
    bool IsTrueFigure() override
    {
        return ((corners == 4) && ((a==c) && (b == d)) && (90 == A) && (90 == B) && (90 == C) && (90 == D)) ? true : false;
    }
};
class Square : public Quadrilateral
{
public:
    Square(float a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) { this->nameFigure = "Square"; this->corners = 4;
    }
    bool IsTrueFigure() override
    {
        return ((corners == 4) && ((a == c) && (c== b) && (b== d) && (c==d)) && (90 == A) && (90 == B) && (90 == C) && (90 == D)) ? true : false;
    }
};
class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(float a, float b, float A, float B) : Quadrilateral(a, b, a, b, A, B, A, B) { this->nameFigure = "Parallelogram"; this->corners = 4;
    }
    bool IsTrueFigure() override
    {
        return ((corners == 4) && ((a == c) && (b == d)) && ( (A == C) && (B == D))) ? true : false;
    }
};
class Rhomb : public Quadrilateral
{
public:
    Rhomb(float a, float A, float B) : Quadrilateral(a, a, a, a, A, B, A, B) { this->nameFigure = "Rhomb"; this->corners = 4;
    }
    bool IsTrueFigure() override
    {
        return ((corners == 4) && ((a == c) && (c == b) && (b == d) && (c == d)) && ((A == C) && (B == D))) ? true : false;
    }
};

int main()
{
    Figure figure = Figure();
    Triangle triangle = Triangle(42.f, 32.f, 43.f, 53.f, 53.f, 23.f);
    RightAnglesTriangle r_a_triagle = RightAnglesTriangle(23.f, 24.f, 35.f, 20.f, 43.f);
    IsoscelesTriangle isoscelesTriagle = IsoscelesTriangle(32.f, 43.f, 43.f, 65.f);
    EquilateralTriangle equilateralTriangle = EquilateralTriangle(32.f);
    Quadrilateral quadrilateral = Quadrilateral(50.f, 70.f, 32.f, 67.f, 85.f, 74.f, 54.f, 23.f);
    Rectangle rectangle = Rectangle(70.f, 30.f);
    Square square = Square(78.f);
    Parallelogram parallelogram = Parallelogram(32.f, 64.f, 70.f, 43.f);
    Rhomb rhomb = Rhomb(60.f, 64.f, 32.f);
    figure.Print_info();
    triangle.Print_info();
    r_a_triagle.Print_info();
    isoscelesTriagle.Print_info();
    equilateralTriangle.Print_info();
    quadrilateral.Print_info();
    rectangle.Print_info();
    square.Print_info();
    parallelogram.Print_info();
    rhomb.Print_info();
}

