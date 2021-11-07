#ifndef ECX_VEC3_H
#define ECX_VEC3_H

#include "ECX_Vec3f.h"
#include <cassert>

namespace ECX_Maths
{
	struct ECX_Vec3f
	{
		union
		{
			struct { float x, y, z; };
			struct { float r, g, b; };
		};

		ECX_Vec3f() :
			x(0.0f),
			y(0.0f),
			z(0.0f)
		{

		}

		ECX_Vec3f(const float& scalar) :
			x(scalar),
			y(scalar),
			z(scalar)
		{

		}

		ECX_Vec3f(ECX_Vec3f const& v) :
			x(v.x),
			y(v.y),
			z(v.z)
		{

		}

		ECX_Vec3f(const float& ix, const float& iy, const float& iz) :
			x(ix),
			y(iy),
			z(iz)
		{

		}

		ECX_Vec3f(ECX_Vec4f const& v) :
			x(v.x),
			y(v.y),
			z(v.z)
		{

		}
		const int length()
		{
			return 3;
		}
		// Operators
		float& operator[](int index)
		{
			assert(index < 3);
			return (&x)[index];

		}
		inline float const& operator[](const int index) const
		{
			assert(index > -1 && index < 3);
			return (&x)[index];
		}
		ECX_Vec3f& operator=(ECX_Vec3f const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}

		ECX_Vec3f& operator+=(ECX_Vec3f const& v)
		{
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
			return *this;
		}
		ECX_Vec3f& operator-=(ECX_Vec3f const& v)
		{
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
			return *this;
		}
		ECX_Vec3f& operator*=(float const& scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			return *this;
		}
		ECX_Vec3f& operator/=(float const& scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			return *this;
		}

		ECX_Vec3f operator+(ECX_Vec3f const& v)
		{
			return ECX_Vec3f(
				x + v.x,
				y + v.y,
				z + v.z
			);
		}
		ECX_Vec3f operator-(ECX_Vec3f const& v)
		{
			return ECX_Vec3f(
				x - v.x,
				y - v.y,
				z - v.z
			);
		}
		ECX_Vec3f operator*(float const& scalar)
		{
			return ECX_Vec3f(
				x * scalar,
				y * scalar,
				z * scalar
			);
		}
		ECX_Vec3f operator/(float const& scalar)
		{
			return ECX_Vec3f(
				x / scalar,
				y / scalar,
				z / scalar
			);
		}
	};
}

#endif // ! ECX_VEC3_H
