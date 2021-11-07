#ifndef ECX_VEC4_H
#define ECX_VEC4_H

#include <cassert>

namespace ECX_Maths
{
	struct ECX_Vec4f
	{
		union
		{
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};

		ECX_Vec4f() :
			x(0.0f),
			y(0.0f),
			z(0.0f),
			w(0.0f)
		{

		}

		ECX_Vec4f(const float& scalar) :
			x(scalar),
			y(scalar),
			z(scalar),
			w(scalar)
		{

		}

		ECX_Vec4f(ECX_Vec4f const& v) :
			x(v.x),
			y(v.y),
			z(v.z),
			w(v.w)
		{

		}

		ECX_Vec4f(const float& ix, const float& iy, const float& iz, const float& iw) :
			x(ix),
			y(iy),
			z(iz),
			w(iw)
		{

		}
		const int length()
		{
			return 4;
		}
		// Operators
		float& operator[](int index)
		{
			assert(index > -1 && index < 4);
			return (&x)[index];
		}
		inline float const& operator[](const int index) const
		{
			assert(index > -1 && index < 4);
			return (&x)[index];
		}
		ECX_Vec4f& operator=(ECX_Vec4f const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
			return *this;
		}

		ECX_Vec4f& operator+=(ECX_Vec4f const& v)
		{
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
			this->w += v.w;
			return *this;
		}

		ECX_Vec4f& operator-=(ECX_Vec4f const& v)
		{
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
			this->w -= v.w;
			return *this;
		}
		ECX_Vec4f& operator*=(float const& scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;
			return *this;
		}
		ECX_Vec4f& operator/=(float const& scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			this->w /= scalar;
			return *this;
		}

		ECX_Vec4f operator+(ECX_Vec4f const& v)
		{
			return ECX_Vec4f(
				x + v.x,
				y + v.y,
				z + v.z,
				w + v.w
			);
		}
		ECX_Vec4f operator-(ECX_Vec4f const& v)
		{
			return ECX_Vec4f(
				x - v.x,
				y - v.y,
				z - v.z,
				w - v.w
			);
		}
		ECX_Vec4f operator*(float const& scalar)
		{
			return ECX_Vec4f(
				x * scalar,
				y * scalar,
				z * scalar,
				w * scalar
			);
		}
		ECX_Vec4f operator/(float const& scalar)
		{
			return ECX_Vec4f(
				x / scalar,
				y / scalar,
				z / scalar,
				w / scalar
			);
		}
	};
}
#endif // !ECX_VEC4_H
