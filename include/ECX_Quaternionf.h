#ifndef ECX_QUAT_H
#define ECX_QUAT_H


#include "ECX_Vec3f.h"
#include <cmath>

namespace ECX_Maths
{
	struct ECX_Quat4f
	{
		float s;
		float i;
		float j;
		float k;

		ECX_Quat4f(float _s = 1.0f) :
			i(0.0f),
			j(0.0f),
			k(0.0f),
			s(_s)
		{

		}

		ECX_Quat4f(float _s, float _i, float _j, float _k):
			i(_i),
			j(_j),
			k(_k),
			s(_s)
		{

		}

		ECX_Quat4f(ECX_Vec3f& euler)
		{
			ECX_Vec3f c{ cos(euler.x * 0.5f), cos(euler.y * 0.5f), cos(euler.z * 0.5f) };
			ECX_Vec3f s{ sin(euler.x * 0.5f), sin(euler.y * 0.5f), sin(euler.z * 0.5f) };

			this->s = c.x * c.y * c.z + s.x * s.y * s.z;
			this->i = s.x * c.y * c.z - c.x * s.y * s.z;
			this->j = c.x * s.y * c.z + s.x * c.y * s.z;
			this->k = c.x * c.y * s.z - s.x * s.y * c.z;
		}

		ECX_Quat4f(const ECX_Quat4f& rhs)
		{
			i = rhs.i;
			j = rhs.j;
			k = rhs.k;
			s = rhs.s;
		}

		ECX_Quat4f operator * (ECX_Quat4f const& rhs)
		{
			return ECX_Quat4f(
				s * rhs.s - i * rhs.i - j * rhs.j - k * rhs.k,
				s * rhs.i + i * rhs.s + j * rhs.k - k * rhs.j,
				s * rhs.j + j * rhs.s + k * rhs.i - i * rhs.k,
				s * rhs.k + k * rhs.s + i * rhs.j - j * rhs.i
			);
		}

		ECX_Quat4f operator * (float const& scalar)
		{
			return ECX_Quat4f(
				s * scalar,
				i * scalar,
				j * scalar,
				k * scalar
			);
		}

		ECX_Quat4f operator / (float const& scalar)
		{
			return ECX_Quat4f(
				s / scalar,
				i / scalar,
				j / scalar,
				k / scalar
			);
		}

		ECX_Quat4f operator + (ECX_Quat4f const& rhs)
		{
			return ECX_Quat4f(
				s + rhs.s,
				i + rhs.i,
				j + rhs.j,
				k + rhs.k
			);
		}

		ECX_Quat4f operator - (ECX_Quat4f const& rhs)
		{
			return ECX_Quat4f(
				s - rhs.s,
				i - rhs.i,
				j - rhs.j,
				k - rhs.k
			);
		}

		ECX_Quat4f operator += (ECX_Quat4f const& rhs)
		{
			s += rhs.s;
			i += rhs.i;
			j += rhs.j;
			k += rhs.k;
			return *this;
		}

		ECX_Quat4f operator -= (ECX_Quat4f const& rhs)
		{
			s -= rhs.s;
			i -= rhs.i;
			j -= rhs.j;
			k -= rhs.k;
			return *this;
		}

		ECX_Quat4f operator *= (float const& scalar)
		{
			s *= scalar;
			i *= scalar;
			j *= scalar;
			k *= scalar;
			return *this;
		}

		ECX_Quat4f operator *= (ECX_Quat4f const& rhs)
		{
			ECX_Quat4f p(*this);
			ECX_Quat4f q(rhs);

			this->s = p.s * q.s - p.i * q.i - p.j * q.j - p.k * q.k;
			this->i = p.s * q.i + p.i * q.s + p.j * q.k - p.k * q.j;
			this->j = p.s * q.j + p.j * q.s + p.k * q.i - p.i * q.k;
			this->k = p.s * q.k + p.k * q.s + p.i * q.j - p.j * q.i;
			return *this;
		}

		ECX_Quat4f operator /= (float const& scalar)
		{
			s /= scalar;
			i /= scalar;
			j /= scalar;
			k /= scalar;
			return *this;
		}

		ECX_Quat4f operator = (float const& scalar)
		{
			s = scalar;
			i = scalar;
			j = scalar;
			k = scalar;
			return *this;
		}

	};
}
#endif // !ECX_QUAT_H
