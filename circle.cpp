#include "Primitives.h"
#include <GL/glut.h>
#include <cmath>

circle::circle() {};

circle::circle(const T& v, float R) {
	this->setVector(v);
	this->setSize(R);
};

circle::circle(const T& v, float R, float red, float green, float blue) {
	this->setVector(v);
	this->setSize(R);
	this->setColor(red, green, blue);
};

bool circle::getDotted() const {
	return this->dotted;
};

void circle::setDotted(bool dotted) {
	this->dotted = dotted;
};

bool circle::getEmpty() const {
	return this->empty;
};

void circle::setEmpty(bool empty) {
	this->empty = empty;
};

circle::circle(const circle& C) {
	this->setVector(C.getVector());
	this->setSize(C.getSize());
	float r, g, b;
	C.getColor(r, g, b);
	this->setColor(r, g, b);
	this->setDotted(C.getDotted());
	this->setWidth(C.getWidth());
};

const float pi = 3.14159;

void circle::print() const {
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	if (this->empty) {
		glLineWidth(this->getWidth());
		if (this->dotted) {
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1, 255);
		};
		glBegin(GL_LINE_LOOP);
		for (float a = 0; a < 2 * pi; a += 0.1)
			glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
		glEnd();
		if (this->dotted) glDisable(GL_LINE_STIPPLE);
	}
	else {
		glBegin(GL_TRIANGLE_FAN);
		for (float a = 0; a < 2 * pi; a += 0.1)
		{
			glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
		}
		glEnd();
	}
};

void circle::print(float angle) const {
	angle = angle * pi / 180.0;
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	if (this->empty) {
		glLineWidth(this->getWidth());
		if (this->dotted) {
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1, 255);
		};
		glBegin(GL_LINE_STRIP);
		if (angle >= 0) {
			for (float a = 0; a < angle - 0.1; a += 0.1)
				glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
			glVertex2d(this->getVector().getX() + this->getSize() * cos(angle), this->getVector().getY() + this->getSize() * sin(angle));
		}
		else {
			for (float a = angle; a < -0.1; a += 0.1)
				glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
			glVertex2d(this->getVector().getX() + this->getSize(), this->getVector().getY());
		}
		glEnd();
		if (this->dotted) glDisable(GL_LINE_STIPPLE);
	}
	else {
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(this->getVector().getX(), this->getVector().getY());
		if (angle >= 0) {
			for (float a = 0; a < angle - 0.1; a += 0.1)
				glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
			glVertex2d(this->getVector().getX() + this->getSize() * cos(angle), this->getVector().getY() + this->getSize() * sin(angle));
		}
		else {
			for (float a = angle; a < -0.1; a += 0.1)
				glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
			glVertex2d(this->getVector().getX() + this->getSize(), this->getVector().getY());
		}
		glEnd();
	}
};

void circle::print(float angle1, float angle2) const {
	angle1 = angle1 * pi / 180.0;
	angle2 = angle2 * pi / 180.0;
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	if (this->empty) {
		glLineWidth(this->getWidth());
		if (this->dotted) {
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1, 255);
		};
		glBegin(GL_LINE_STRIP);
		for (float a = angle1; a < angle2 - 0.1; a += 0.1)
			glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
		glVertex2d(this->getVector().getX() + this->getSize() * cos(angle2), this->getVector().getY() + this->getSize() * sin(angle2));
		glEnd();
		if (this->dotted) glDisable(GL_LINE_STIPPLE);
	}
	else {
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(this->getVector().getX(), this->getVector().getY());
		for (float a = angle1; a < angle2 - 0.1; a += 0.1)
			glVertex2d(this->getVector().getX() + this->getSize() * cos(a), this->getVector().getY() + this->getSize() * sin(a));
		glVertex2d(this->getVector().getX() + this->getSize() * cos(angle2), this->getVector().getY() + this->getSize() * sin(angle2));
		glEnd();
	}
};
