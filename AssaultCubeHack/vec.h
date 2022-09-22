#pragma once

#include <math.h>
#define SQUARE(x) x * x

struct vec2
{
	float x, y;

	vec2() = default;
	vec2(float x, float y)
		: x(x), y(y) {}

	vec2 operator+(const vec2& other);
	vec2 operator-(const vec2& other);
	vec2 operator*(float factor);
	vec2 operator/(float factor);

	// Dot Product
	float operator*(const vec2& other);

	float magnitude() const;
};

struct vec3
{
	float x, y, z;

	vec3() = default;
	vec3(float x, float y, float z)
		: x(x), y(y), z(z) {}

	vec3 operator+(const vec3& other);
	vec3 operator-(const vec3& other);
	vec3 operator*(float factor);
	vec3 operator/(float factor);

	// Dot Product
	float operator*(const vec3& other);

	float magnitude() const;
};

struct vec4
{
	float x, y, z, w;

	vec4() = default;
	vec4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w) {}

	vec4 operator+(const vec4& other);
	vec4 operator-(const vec4& other);
	vec4 operator*(float factor);
	vec4 operator/(float factor);

	// Dot Product
	float operator*(const vec4& other);

	float magnitude() const;
};
