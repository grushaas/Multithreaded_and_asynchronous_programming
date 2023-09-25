#pragma once
#include "shape.h"

class Transform {
public:
	Transform(const Shape* shape);
	std::unique_ptr<Shape> shift(float x, float y, float z);
	std::unique_ptr<Shape> scale(float f);
	std::unique_ptr<Shape> scale_X(float f);
	std::unique_ptr<Shape> scale_Y(float f);
	std::unique_ptr<Shape> scale_Z(float f);

private:
	std::unique_ptr<Shape> _shape;
};