#pragma once
class Vector2
{
public:
	Vector2(float x, float y);
	~Vector2() {};

	static Vector2 operator+(Vector2 vector, Vector2 otherVector);
	static Vector2 operator-(Vector2 vector, Vector2 otherVector);
	static Vector2 operator*(Vector2 vector, float scalar);
	static Vector2 operator/(Vector2 vector, float scalar);

private:
	float m_x;
	float m_y;

};

