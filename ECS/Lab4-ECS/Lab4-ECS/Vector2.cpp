#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}

Vector2 Vector2::operator+(Vector2 otherVector)
{
	return Vector2(this->m_x + otherVector.m_x, this->m_y + otherVector.m_y);
}

Vector2 Vector2::operator-(Vector2 otherVector)
{
	return Vector2(this->m_x - otherVector.m_x, this->m_y - otherVector.m_y);
}

Vector2 Vector2::operator*(float scalar)
{
	return Vector2(this->m_x * scalar, this->m_y * scalar);
}

Vector2 Vector2::operator/(float scalar)
{
	return Vector2(this->m_x / scalar, this->m_y / scalar);
}

float Vector2::x()
{
	return m_x;
}

float Vector2::y()
{
	return m_y;
}

