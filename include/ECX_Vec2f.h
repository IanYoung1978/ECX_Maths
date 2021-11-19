#ifndef ECX_VEC2_H
#define ECX_VEC2_H

#include "ECX_Vec3f.h"
#include <cassert>

namespace ECX_Maths
{
	struct ECX_Vec2f
	{

		union { float x, y; };
		union { float s, t; };
		union { float u, v; };


		// basic contructor
		ECX_Vec2f() :
			x(0.0f),
			y(0.0f)
		{

		}
		//Single value constructor
		ECX_Vec2f(const float scalar) :
			x(scalar),
			y(scalar)
		{

		}

		ECX_Vec2f(const float ix, const float iy) :
			x(ix),
			y(iy)
		{

		}

		ECX_Vec2f(ECX_Vec3f const & v) :
			x(v.x),
			y(v.y)
		{

		}

		ECX_Vec2f(ECX_Vec4f const & v) :
			x(v.x),
			y(v.y)
		{

		}
		const int length()
		{
			return 2;
		}
		// Operators
		float & operator[](int index)
		{
			assert(index < 2);
			return (&x)[index];
		}

		inline float const & operator[](const int index) const
		{
			assert(index > -1 && index < 2);
			return (&x)[index];
		}
		ECX_Vec2f & operator=(ECX_Vec2f const & v)
		{
			this->x = v.x;
			this->y = v.y;
			return *this;
		}

		ECX_Vec2f & operator+=(ECX_Vec2f const & v)
		{
			this->x += v.x;
			this->y += v.y;
			return *this;
		}
		ECX_Vec2f & operator-=(ECX_Vec2f const & v)
		{
			this->x -= v.x;
			this->y -= v.y;
			return *this;
		}
		ECX_Vec2f & operator*=(float const & scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			return *this;
		}
		ECX_Vec2f & operator/=(float const & scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			return *this;
		}

		ECX_Vec2f operator+(ECX_Vec2f const & v)
		{
			return ECX_Vec2f(
				x + v.x,
				y + v.y
			);
		}
		ECX_Vec2f operator-(ECX_Vec2f const & v)
		{
			return ECX_Vec2f(
				x - v.x,
				y - v.y
			);
		}
		ECX_Vec2f operator*(float const & scalar)
		{
			return ECX_Vec2f(
				x * scalar,
				y * scalar
			);
		}
		ECX_Vec2f operator/(float const & scalar)
		{
			return ECX_Vec2f(
				x / scalar,
				y / scalar
			);
		}
	};
}
#endif // !ECX_VEC2_H