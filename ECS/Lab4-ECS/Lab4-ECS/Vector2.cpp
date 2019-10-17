#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}

Vector2 Vector2::operator+(Vector2 vector, Vector2 otherVector)
{
	return Vector2(vector.m_x + otherVector.m_x, vector.m_x + otherVector.m_x);
}

Vector2 Vector2::operator-(Vector2 vector, Vector2 otherVector)
{
	return Vector2(vector.m_x - otherVector.m_x, vector.m_x - otherVector.m_x);
}

Vector2 Vector2::operator*(Vector2 vector, float scalar)
{
	return Vector2(vector.m_x * scalar, vector.m_x * scalar);
}

Vector2 Vector2::operator/(Vector2 vector, float scalar)
{
	return Vector2(vector.m_x / scalar, vector.m_x / scalar);
}


