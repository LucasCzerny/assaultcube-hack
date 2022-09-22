#include "vec.h"

// VEC2

vec2 vec2::operator+(const vec2& other)
{
	return vec2(x + other.x, y + other.y);
}

vec2 vec2::operator-(const vec2& other)
{
	return vec2(x - other.x, y - other.y);
}

vec2 vec2::operator*(float factor)
{
	return vec2(x * factor, y * factor);
}

vec2 vec2::operator/(float factor)
{
	return vec2(x / factor, y / factor);
}

float vec2::operator*(const vec2& other)
{
	return x * other.x + y * other.y;
}

float vec2::magnitude() const
{
	return sqrt(SQUARE(x) + SQUARE(y));
}

// VEC3

vec3 vec3::operator+(const vec3& other)
{
	return vec3(x + other.x, y + other.y, z + other.z);
}

vec3 vec3::operator-(const vec3& other)
{
	return vec3(x - other.x, y - other.y, z - other.z);
}

vec3 vec3::operator*(float factor)
{
	return vec3(x * factor, y * factor, z * factor);
}

vec3 vec3::operator/(float factor)
{
	return vec3(x / factor, y / factor, z / factor);
}

float vec3::operator*(const vec3& other)
{
	return x * other.x + y * other.y + z * other.z;
}

float vec3::magnitude() const
{
	return sqrt(SQUARE(x) + SQUARE(y) + SQUARE(z));
}

// VEC4

vec4 vec4::operator+(const vec4& other)
{
	return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

vec4 vec4::operator-(const vec4& other)
{
	return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

vec4 vec4::operator*(float factor)
{
	return vec4(x * factor, y * factor, z * factor, w * factor);
}

vec4 vec4::operator/(float factor)
{
	return vec4(x / factor, y / factor, z / factor, w / factor);
}

float vec4::operator*(const vec4& other)
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float vec4::magnitude() const
{
	return sqrt(SQUARE(x) + SQUARE(y) + SQUARE(z) + SQUARE(w));
}
