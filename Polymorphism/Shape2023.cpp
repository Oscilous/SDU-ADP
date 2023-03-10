#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Shape
{ 
private:
	double anchor_x{}, anchor_y{};
public:
	Shape(double ax, double ay): anchor_x(ax),anchor_y(ay){}
	void move(double dx, double dy) { anchor_x += dx; anchor_y += dy; }
	virtual string to_string(void)
	{ 
		return "(" + std::to_string(anchor_x) + "," + std::to_string(anchor_y) + ")";
	}
	virtual double get_area(void) = 0; //pure virtual function
	
};

class Rectangle : public Shape
{
private:
	double length, width;
public:
	Rectangle(double ax, double ay, double l, double w): Shape(ax, ay), length(l), width(w) {}
	string to_string(void) override
	{
		return " length: " + std::to_string(length) + " width:" + 
			    std::to_string(width) +
			    " anchor point: " + Shape::to_string();
	}
	double  get_area(void) override
	{
		return length * width;
	}
};

class Square : public Shape
{
private:
	double side;
public:
	Square(double ax, double ay, double s) : Shape(ax, ay),side(s) {}
	string to_string(void) override
	{
		return " side: " + std::to_string(side) +
			" anchor point: " + Shape::to_string();
	}
	double get_area(void) override 
	{
		return side * side;
	}
};

int main(void)
{
	Rectangle r(1.0, 2.0, 3.0, 4.0);
	Square s(5.0, 6.0, 7.0);

	vector<Shape*> shapes{&r,&s};

	for(auto s_ptr : shapes){
		cout << s_ptr->to_string() << " Area:" << s_ptr->get_area()<< endl;
	}

	return 0;
}