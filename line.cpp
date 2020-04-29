#include "Primitives.h"
#include <GL/glut.h>

line::line() {
	this->v2.setX(1);
};

line::line(const T& v1, const T& v2) {
	this->v2 = v2;
	this->setVector(v1);
};

line::line(const T& v1, const T& v2, float width, float red, float green, float blue) {
	this->v2 = v2;
	this->setVector(v1);
	this->setColor(red, green, blue);
	this->setWidth(width);
};

void line::setV1(const T& v) {
	this->setVector(v);
};

void line::setV2(const T& v) {
	this->v2 = v;
};

T line::getV1() const{
	return this->getVector();
};

T line::getV2() const {
	return this->v2;
};

bool line::getDotted() const {
	return this->dotted;
};

void line::setDotted(bool dotted) {
	this->dotted = dotted;
};

line::line(const line& L) {
	this->v2 = L.getV2();
	this->setVector(L.getV1());
	float r, g, b;
	L.getColor(r, g, b);
	this->setColor(r, g, b);
	this->setDotted(L.getDotted());
	this->setWidth(L.getWidth());
};

void line::print() const {
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	glLineWidth(this->getWidth());
	if (this->dotted) {
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(1, 255);
	};
	glBegin(GL_LINES);
		glVertex2f(this->getV1().getX(), this->getV1().getY());
		glVertex2f(this->v2.getX(), this->v2.getY());
	glEnd();
	if (this->dotted) glDisable(GL_LINE_STIPPLE);
};

void line::moveUp(float x) {
	this->setV1(T(this->getV1().getX(), this->getV1().getY() + x));
	this->setV2(T(this->getV2().getX(), this->getV2().getY() + x));
};
void line::moveDown(float x) {
	this->setV1(T(this->getV1().getX(), this->getV1().getY() - x));
	this->setV2(T(this->getV2().getX(), this->getV2().getY() - x));
};
void line::moveLeft(float x) {
	this->setV1(T(this->getV1().getX() + x, this->getV1().getY()));
	this->setV2(T(this->getV2().getX() + x, this->getV2().getY()));
};
void line::moveRight(float x) {
	this->setV1(T(this->getV1().getX() + x, this->getV1().getY()));
	this->setV2(T(this->getV2().getX() + x, this->getV2().getY()));
};
