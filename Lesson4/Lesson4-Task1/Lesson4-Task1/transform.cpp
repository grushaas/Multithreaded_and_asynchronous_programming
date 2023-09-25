#include <stdexcept>
#include "transform.h"

Transform::Transform(const Shape* shape) {
	if (shape == nullptr) {
		throw std::invalid_argument{ "nullptr passed!" };
	}
	else {
		_shape = std::move(shape->clone());
	}
}

std::unique_ptr<Shape> Transform::shift(float x, float y, float z) {
	for (auto& node : _shape->_nodes) {
		node.X += x;
		node.Y += y;
		node.Z += z;
	}
	return std::move(_shape);
}

std::unique_ptr<Shape> Transform::scale(float f) {
	for (auto& node : _shape->_nodes) {
		node.X *= f;
		node.Y *= f;
		node.Z *= f;
	}
	return std::move(_shape);
}

std::unique_ptr<Shape> Transform::scale_X(float f) {
	for (auto& node : _shape->_nodes) {
		node.X *= f;
	}
	return std::move(_shape);
}

std::unique_ptr<Shape> Transform::scale_Y(float f) {
	for (auto& node : _shape->_nodes) {
		node.Y *= f;
	}
	return std::move(_shape);
}

std::unique_ptr<Shape> Transform::scale_Z(float f) {
	for (auto& node : _shape->_nodes) {
		node.Z *= f;
	}
	return std::move(_shape);
}