#include "Primitives.h"
#include <cmath>
#include <GL/glut.h>

leaf::leaf() {};

leaf::leaf(const T& v, float size) {
	this->setVector(v);
	this->setSize(size);
};

leaf::leaf(const T& v, float size, float red, float green, float blue) {
	this->setVector(v);
	this->setSize(size);
	this->setColor(red, green, blue);
};

bool leaf::getEmpty() const {
	return this->empty;
};

void leaf::setEmpty(bool empty) {
	this->empty = empty;
};

leaf::leaf(const leaf& F) {
	this->setVector(F.getVector());
	this->setSize(F.getSize());
	this->setEmpty(F.getEmpty());
	float r, g, b;
	F.getColor(r, g, b);
	this->setColor(r, g, b);
};

const float pi = 3.14159;

void leaf::print() const {
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	if (this->empty) {
		glLineWidth(this->getWidth());
		glBegin(GL_LINE_LOOP);
		for (float a = 0; a < 2 * pi; a += 0.01)
		{
			float r = this->getSize()* 0.2 * (1 + sin(a)) * (1 + 0.9 * cos(8 * a)) * (1 + 0.1 * cos(24 * a));
			glVertex2f(this->getVector().getX() + r * cos(a), this->getVector().getY() + r * sin(a));
		}
		glEnd();
	}
	else {
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(this->getVector().getX(), this->getVector().getY());
		for (float a = 0; a < 2 * pi; a += 0.009)
		{
			float r = this->getSize() * 0.2 * (1 + sin(a)) * (1 + 0.9 * cos(8 * a)) * (1 + 0.1 * cos(24 * a));
			glVertex2f(this->getVector().getX() + r * cos(a), this->getVector().getY() + r * sin(a));
		}
		glEnd();
	}
};
