#ifndef ECX_MAT2_H
#define ECX_MAT2_H


#include "ECX_Mat3f.h"
#include "ECX_Vec2f.h"
#include <cassert>

namespace ECX_Maths
{
	struct ECX_Mat2f
	{
		ECX_Vec2f value[2];
		ECX_Mat2f()
		{
			value[0] = ECX_Vec2f();
			value[1] = ECX_Vec2f();
		}

		ECX_Mat2f(ECX_Mat2f const& m)
		{
			value[0] = m.value[0];
			value[1] = m.value[1];
		}

		ECX_Mat2f(const float& scalar)
		{
			value[0] = ECX_Vec2f(scalar);
			value[1] = ECX_Vec2f(scalar);
		}

		ECX_Mat2f(const float& x0, const float& y0, const float& x1, const float& y1)
		{
			value[0] = ECX_Vec2f(x0, y0);
			value[1] = ECX_Vec2f(x1, y1);
		}

		ECX_Mat2f(ECX_Mat3f const& m)
		{
			value[0] = ECX_Vec2f(m[0]);
			value[1] = ECX_Vec2f(m[1]);
		}

		ECX_Mat2f(ECX_Mat4f const& m)
		{
			value[0] = ECX_Vec2f(m[0]);
			value[1] = ECX_Vec2f(m[1]);
		}
		const int length()
		{
			return 2;
		}
		ECX_Vec2f& operator[](int index)
		{
			assert(index < 2);
			return value[index];
		}
		inline ECX_Vec2f const& operator[](const int index) const
		{
			assert(-1 < index && index < 2);
			return this->value[index];
		}
		ECX_Mat2f operator* (ECX_Mat2f const& m)
		{
			return ECX_Mat2f(
				value[0].x * m.value[0].x + value[0].y * m.value[1].x,
				value[0].x * m.value[0].y + value[0].y * m.value[1].y,
				value[1].x * m.value[0].x + value[1].y * m.value[1].x,
				value[1].x * m.value[0].y + value[1].y * m.value[1].y
			);
		}
	};
}
#endif // !ECX_MAT2_H
