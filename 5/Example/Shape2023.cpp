#include<iostream>
#include<string>
using namespace std;

class Shape
{ 
private:
	double anchor_x{}, anchor_y{};
public:
	Shape(double ax, double ay): anchor_x(ax),anchor_y(ay){}
	void move(double dx, double dy) { anchor_x += dx; anchor_y += dy; }
	string to_string(void)
	{ 
		return "(" + std::to_string(anchor_x) + "," + std::to_string(anchor_y) + ")";
	}
};

class Rectangle : public Shape
{
private:
	double length, width;
public:
	Rectangle(double ax, double ay, double l, double w): Shape(ax, ay), length(l), width(w) {}
	string to_string(void)
	{
		return " length: " + std::to_string(length) + " width:" + 
			    std::to_string(width) +
			    " anchor point: " + Shape::to_string();
	}
};

class Square : public Shape
{
private:
	double side;
public:
	Square(double ax, double ay, double s) : Shape(ax, ay),side(s) {}
	string to_string(void)
	{
		return " side: " + std::to_string(side) +
			" anchor point: " + Shape::to_string();
	}
};

int main(void)
{
	Rectangle r(1.0, 2.0, 3.0, 4.0);
	Square s(5.0, 6.0, 7.0);

	cout << r.to_string() << endl << s.to_string();

	return 0;
}