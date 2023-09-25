#pragma once
#include <vector>
#include <memory>

struct Node {
	float X;
	float Y;
	float Z;
};

class Shape {
	friend class Transform;

public:
	Shape();
	virtual float area() const = 0;
	virtual float volume() const = 0;

protected:
	virtual std::unique_ptr<Shape> clone() const = 0;
	std::vector<Node> _nodes;
};

class Line : public Shape {
public:
	Line(Node null, Node one);
	float area() const override;
	float volume() const override;

private:
	std::unique_ptr<Shape> clone() const override;
};

class Rectangle : public Shape {
public:
	Rectangle(Node null, Node one, Node two, Node three);
	float area() const override;
	float volume() const override;

private:
	std::unique_ptr<Shape> clone() const override;
};

class Parallelepiped final : public Rectangle {
public:
	Parallelepiped(Node null, Node one, Node two, Node three, Node four, Node five, Node six, Node seven);
	float area() const;
	float volume() const;

private:
	std::unique_ptr<Shape> clone() const;
};

class Circle : public Shape {
public:
	Circle(Node center, float radius);
	float area() const override;
	float volume() const override;

private:
	std::unique_ptr<Shape> clone() const override;

protected:
	float _radius;
};

class Cylinder : public Circle {
public:
	Cylinder(Node center, float radius, float hight);
	float area() const;
	float volume() const;

private:
	std::unique_ptr<Shape> clone() const;
	
	float _hight;
};