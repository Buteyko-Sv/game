#ifndef Primitiv
#define Primitiv

#include "Vector2D.h"

typedef Vector2D T; // you can use any vector

class DrawingObject {        //parent class for primitives
private:
	float red = 1, green = 1, blue = 1; //colors
	T v;
	float size = 1;
	float width = 1;
public:
	void setVector(const T& V) {
		this->v.setX(V.getX());
		this->v.setY(V.getY());
	};
	T getVector() const {
		return this->v;
	};
	void setColor(float r, float g, float b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	};
	void getColor(float& r, float& g, float& b) const {
		r = this->red;
		g = this->green;
		b = this->blue;
	};
	void setSize(float size) {
		this->size = size;
	};
	float getSize() const {
		return this->size;
	};
	void setWidth(float width) {
		this->width = width;
	};
	float getWidth() const {
		return this->width;
	};
	void moveUp(float x) {
		this->v.setY(this->v.getY() + x);
	};
	void moveDown(float x) {
		this->v.setY(this->v.getY() - x);
	};
	void moveLeft(float x) {
		this->v.setX(this->v.getX() - x);
	};
    void moveRight(float x) {
		this->v.setX(this->v.getX() + x);
	};
	virtual void print() const {};
};
#endif // !Primitiv
