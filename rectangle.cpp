#include "Primitives.h"
#include <GL/glut.h>

rectangle::rectangle() {
	this->v2.setX(1);
	this->v3.setX(1);
	this->v3.setY(1);
	this->v4.setY(1);
};

rectangle::rectangle(const T& v1, const T& v2, const T& v3, const T& v4) {
	this->setVector(v1);
	this->v2 = v2;
	this->v3 = v3;
	this->v4 = v4;
};

rectangle::rectangle(const T& v1, const T& v2, const T& v3, const T& v4, float red, float green, float blue) {
	this->setVector(v1);
	this->v2 = v2;
	this->v3 = v3;
	this->v4 = v4;
	this->setColor(red, green, blue);
};

bool rectangle::getEmpty() const {
	return this->empty;
};

void rectangle::setV1(const T& v) {
	this->setVector(v);
};

void rectangle::setV2(const T& v) {
	this->v2 = v;
};

void rectangle::setV3(const T& v) {
	this->v3 = v;
};

void rectangle::setV4(const T& v) {
	this->v4 = v;
};

T rectangle::getV1() const {
	return this->getVector();
};

T rectangle::getV2() const {
	return this->v2;
};

T rectangle::getV3() const {
	return this->v3;
};

T rectangle::getV4() const {
	return this->v4;
};

rectangle::rectangle(const rectangle& R) {
	float r, g, b;
	R.getColor(r, g, b);
	this->setColor(r, g, b);
	this->empty = R.getEmpty();
	this->setVector(R.getVector());
	this->setWidth(R.getWidth());
	this->v2 = R.getV2();
	this->v3 = R.getV3();
	this->v4 = R.getV4();
};

void rectangle::setEmpty(bool empty) {
	this->empty = empty;
};

void rectangle::print() const {
	float r, g, b;
	this->getColor(r, g, b);
	glColor3f(r, g, b);
	if (!this->empty) {
		glBegin(GL_POLYGON);
			glVertex2f(this->getVector().getX(), this->getVector().getY());
			glVertex2f(this->v2.getX(), this->v2.getY());
			glVertex2f(this->v3.getX(), this->v3.getY());
			glVertex2f(this->v4.getX(), this->v4.getY());
		glEnd();
	}
	else {
		glLineWidth(this->getWidth());
		glBegin(GL_LINE_LOOP);
			glVertex2f(this->getVector().getX(), this->getVector().getY());
			glVertex2f(this->v2.getX(), this->v2.getY());
			glVertex2f(this->v3.getX(), this->v3.getY());
			glVertex2f(this->v4.getX(), this->v4.getY());
		glEnd();
	}
};

void rectangle::moveUp(float x) {
	this->setV1(T(this->getV1().getX(), this->getV1().getY() + x));
	this->setV2(T(this->getV2().getX(), this->getV2().getY() + x));
	this->setV3(T(this->getV3().getX(), this->getV3().getY() + x));
	this->setV4(T(this->getV4().getX(), this->getV4().getY() + x));
};
void rectangle::moveDown(float x) {
	this->setV1(T(this->getV1().getX(), this->getV1().getY() - x));
	this->setV2(T(this->getV2().getX(), this->getV2().getY() - x));
	this->setV3(T(this->getV3().getX(), this->getV3().getY() - x));
	this->setV4(T(this->getV4().getX(), this->getV4().getY() - x));
};
void rectangle::moveLeft(float x) {
	this->setV1(T(this->getV1().getX() - x, this->getV1().getY()));
	this->setV2(T(this->getV2().getX() - x, this->getV2().getY()));
	this->setV3(T(this->getV3().getX() - x, this->getV3().getY()));
	this->setV4(T(this->getV4().getX() - x, this->getV4().getY()));
};
void rectangle::moveRight(float x) {
	this->setV1(T(this->getV1().getX() + x, this->getV1().getY()));
	this->setV2(T(this->getV2().getX() + x, this->getV2().getY()));
	this->setV3(T(this->getV3().getX() + x, this->getV3().getY()));
	this->setV4(T(this->getV4().getX() + x, this->getV4().getY()));
};
