#include <memory>
#include <format>
#include <iostream>
#include "shape.h"
#include "transform.h"

int main() {
	// line
	Node l_null{ 1.0f, 2.0f, 3.0f };
	Node l_one{ 4.0f, 5.0f, 6.0f };
	std::unique_ptr<Shape> shape{ std::make_unique<Line>(l_null, l_one) };
	std::cout << std::format("line area: {:19.1f}\n", shape->area());
	std::cout << std::format("line volume: {:17.1f}\n", shape->volume());
	// rectangle
	Node r_null{ 1.0f, 1.0f, 0.0f };
	Node r_one{ 5.0f, 1.0f, 0.0f };
	Node r_two{ 5.0f, 5.0f, 0.0f };
	Node r_three{ 1.0f, 5.0f, 0.0f };
	shape.reset(new Rectangle(r_null, r_one, r_two, r_three));
	std::cout << std::format("\nrectangle area: {:15.1f}\n", shape->area());
	std::cout << std::format("rectangle volume: {:12.1f}\n", shape->volume());
	// parallelepiped
	Node p_null{ 1.0f, 1.0f, 1.0f };
	Node p_one{ 5.0f, 1.0f, 1.0f };
	Node p_two{ 5.0f, 5.0f, 1.0f };
	Node p_three{ 1.0f, 5.0f, 1.0f };
	Node p_four{ 1.0f, 1.0f, 7.0f };
	Node p_five{ 5.0f, 1.0f, 7.0f };
	Node p_six{ 5.0f, 5.0f, 7.0f };
	Node p_seven{ 1.0f,5.0f, 7.0f };
	shape.reset(new Parallelepiped(p_null,
		p_one,
		p_two,
		p_three,
		p_four,
		p_five,
		p_six,
		p_seven));
	std::cout << std::format("\nparallelepiped area: {:10.1f}\n", shape->area());
	std::cout << std::format("parallelepiped volume: {:8.1f}\n", shape->volume());
	std::cout << "\nscale parallelepiped up to 10 times\n";
	try
	{
		Transform transform(shape.get());
		auto transformed_shape{ transform.scale(10.0f) };
		std::cout << std::format("new parallelepiped area: {:8.1f}\n", transformed_shape->area());
		std::cout << std::format("new parallelepiped volume: {:5.1f}\n", transformed_shape->volume());
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << ex.what() << '\n';
	}
	// circle
	Node c_centre{ 5.0f, 5.0f, 5.0f };
	shape.reset(new Circle(c_centre, 10));
	std::cout << std::format("\ncircle area: {:19.1f}\n", shape->area());
	std::cout << std::format("circle volume: {:15.1f}\n", shape->volume());
	// cylinder
	shape.reset(new Cylinder(c_centre, 10, 100));
	std::cout << std::format("\ncylinder area: {:18.1f}\n", shape->area());
	std::cout << std::format("cylinder volume: {:17.1f}\n", shape->volume());
	return 0;
}