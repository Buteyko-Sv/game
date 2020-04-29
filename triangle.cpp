#include "Primitives.h"
#include <GL/glut.h>

triangle::triangle() {
	this->v2.setX(1);
	this->v3.setX(0.5);
	this->v3.setY(1);
};

triangle::triangle(const T& v1, const T& v2, const T& v3) {
	this->setVector(v1);
	this->v2 = v2;
	this->v3 = v3;
};

triangle::triangle(const T& v1, const T& v2, const T& v3, float red, float green, float blue) {
	this->setVector(v1);
	this->v2 = v2;
	this->v3 = v3;
	this->setColor(red, green, blue);
};

triangle::triangle(const triangle& R) {
	float r, g, b;
	R.getColor(r, g, b);
	this->setColor(r, g, b);
	this->empty = R.getEmpty();
	this->setVector(R.getVector());
	this->setWidth(R.getWidth());
	this->v2 = R.getV2();
	this->v3 = R.getV3();
};

bool triangle::getEmpty() const {
	return this->empty;
};

void triangle::setV1(const T& v) {
	this->setVector(v);
};

void triangle::setV2(const T& v) {
	this->v2 = v;
};

void triangle::setV3(const T& v) {
	this->v3 = v;
};

T triangle::getV1() const {
	return this->getVector();
};

T triangle::getV2() const {
	return this->v2;
};

T triangle::getV3() const {
	return this->v3;
};

void triangle::print() const {
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	if (!this->empty) {
		glBegin(GL_POLYGON);
		glVertex2f(this->getVector().getX(), this->getVector().getY());
		glVertex2f(this->v2.getX(), this->v2.getY());
		glVertex2f(this->v3.getX(), this->v3.getY());
		glEnd();
	}
	else {
		glLineWidth(this->getWidth());
		glBegin(GL_LINE_LOOP);
		glVertex2f(this->getVector().getX(), this->getVector().getY());
		glVertex2f(this->v2.getX(), this->v2.getY());
		glVertex2f(this->v3.getX(), this->v3.getY());
		glEnd();
	}
};

void triangle::setEmpty(bool empty) {
	this->empty = empty;
};

void triangle::moveUp(float x) {
	this->setV1(T(this->getV1().getX(), this->getV1().getY() + x));
	this->setV2(T(this->getV2().getX(), this->getV2().getY() + x));
	this->setV3(T(this->getV3().getX(), this->getV3().getY() + x));
};
void triangle::moveDown(float x) {
	this->setV1(T(this->getV1().getX(), this->getV1().getY() - x));
	this->setV2(T(this->getV2().getX(), this->getV2().getY() - x));
	this->setV3(T(this->getV3().getX(), this->getV3().getY() - x));
};
void triangle::moveLeft(float x) {
	this->setV1(T(this->getV1().getX() - x, this->getV1().getY()));
	this->setV2(T(this->getV2().getX() - x, this->getV2().getY()));
	this->setV3(T(this->getV3().getX() - x, this->getV3().getY()));
};
void triangle::moveRight(float x) {
	this->setV1(T(this->getV1().getX() + x, this->getV1().getY()));
	this->setV2(T(this->getV2().getX() + x, this->getV2().getY()));
	this->setV3(T(this->getV3().getX() + x, this->getV3().getY()));
};
