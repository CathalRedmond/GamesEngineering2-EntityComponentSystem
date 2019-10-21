#pragma once
class Vector2
{
public:
	Vector2(float x, float y);
	~Vector2() {};

	Vector2 operator+(Vector2 otherVector);
	Vector2 operator-(Vector2 otherVector);
	Vector2 operator*(float scalar);
	Vector2 operator/(float scalar);
	float x();
	float y();
private:
	float m_x;
	float m_y;
};

