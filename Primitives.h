#include "DrawingObject.h"
 
// T = Vector2D

class rectangle:public DrawingObject {
private:
	bool empty = false;
	T v2, v3, v4;
public:
	rectangle();
	rectangle(const T& v1, const T& v2, const T& v3, const T& v4);
	rectangle(const T& v1, const T& v2, const T& v3, const T& v4, float red, float green, float blue);
	rectangle(const rectangle& P);
	void setV1(const T& v);
	void setV2(const T& v);
	void setV3(const T& v);
	void setV4(const T& v);
	T getV1() const;
	T getV2() const;
	T getV3() const;
	T getV4() const;
	void moveUp(float x);
	void moveDown(float x);
	void moveLeft(float x);
	void moveRight(float x);
	bool getEmpty() const;
	void print() const;
	void setEmpty(bool empty); // makes the rectangle empty inside
};

class triangle:public DrawingObject {
private:
	bool empty = false;
	T v2, v3;
public:
	triangle();
	triangle(const T& v1, const T& v2, const T& v3);
	triangle(const T& v1, const T& v2, const T& v3, float red, float green, float blue);
	triangle(const triangle& P);
	void setV1(const T& v);
	void setV2(const T& v);
	void setV3(const T& v);
	T getV1() const;
	T getV2() const;
	T getV3() const;
	void moveUp(float x);
	void moveDown(float x);
	void moveLeft(float x);
	void moveRight(float x);
	bool getEmpty() const;
	void print() const;
	void setEmpty(bool empty); // makes the triangle empty inside
};

class line:public DrawingObject { // vectors point the begin and the end of line
private:
	T v2;
	bool dotted = false;
public:
	line();
	line(const T& v1, const T& v2);
	line(const T& v1, const T& v2, float width, float red, float green, float blue);
	line(const line& L);
	void setV1(const T& v);
	void setV2(const T& v);
	T getV1() const;
	T getV2() const;
	void moveUp(float x);
	void moveDown(float x);
	void moveLeft(float x);
	void moveRight(float x);
	bool getDotted() const;
	void print() const;
	void setDotted(bool dotted); // makes the line dotted
};

class circle:public DrawingObject {
private:
	bool dotted = false;
	bool empty = true;
public:
	circle();
	circle(const T& v, float R); // v points the center of object
	circle(const T& v, float R, float red, float green, float blue);
	circle(const circle& C);
	void print() const;
	void print(float angle) const; // you can choose how many parts of a circle to draw
								   // the angle is counted from the x axis
	void print(float angle1, float angle2) const;
	bool getDotted() const;		 // actual for empty circle
	void setDotted(bool dotted); // makes the circle dotted
	bool getEmpty() const;
	void setEmpty(bool empty); // makes the circle empty inside
};

class leaf:public DrawingObject {
private:
	bool empty = false;
public:
	leaf();
	leaf(const T& v, float size);
	leaf(const T& v, float size, float red, float green, float blue);
	leaf(const leaf& F);
	void print() const;
	bool getEmpty() const;
	void setEmpty(bool empty);
};