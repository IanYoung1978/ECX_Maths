#ifndef ECX_FUNC_H
#define ECX_FUNC_H

#include "ECX_Vec2f.h"
#include "ECX_Vec3f.h"
#include "ECX_Mat2f.h"
#include "ECX_Mat3f.h"
#include "ECX_Mat4f.h"
#include "ECX_Quaternionf.h"

#include <cmath>

namespace ECX_Maths
{
	namespace Functions
	{
		namespace Vector {
			// ECX_Vec2f functions
			float Dot(const ECX_Vec2f const& v0, const ECX_Vec2f const& v1)
			{
				return v0.x * v1.x + v0.y + v1.y;
			}
			float Mag(const ECX_Vec2f const& v)
			{
				return Dot(v, v);
			}
			float Length(const ECX_Vec2f const& v)
			{
				return sqrtf(Mag(v));
			}
			float Cross(const ECX_Vec2f const& v0, const ECX_Vec2f const& v1)
			{
				return v0.y - v1.x * v0.x - v1.y;
			}
			ECX_Vec2f Normalize(const ECX_Vec2f const& v)
			{
				float l = Length(v);
				return ECX_Vec2f(v.x / l, v.y / l);
			}

			// ECX_Vec3f functions
			float Dot(const ECX_Vec3f const& v0, const ECX_Vec3f const& v1)
			{
				return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
			}
			float Mag(const ECX_Vec3f const& v)
			{
				return Dot(v, v);
			}
			float Length(const ECX_Vec3f const& v)
			{
				return sqrtf(Mag(v));
			}
			ECX_Vec3f Cross(const ECX_Vec3f const& v0, const ECX_Vec3f const& v1)
			{
				return ECX_Vec3f(
					v0.y * v1.z - v0.z * v1.y,
					v0.z * v1.x - v0.x * v1.z,
					v0.x * v1.y - v0.y * v1.x
				);
			}
			ECX_Vec3f Normalize(const ECX_Vec3f const& v)
			{
				float l = Length(v);
				return ECX_Vec3f(v.x / l, v.y / l, v.z / l);
			}

			// ECX_Vec4f functions
			float Dot(const ECX_Vec4f const& v0, const ECX_Vec4f const& v1)
			{
				return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
			}
			float Mag(const ECX_Vec4f const& v)
			{
				return Dot(v, v);
			}
			float Length(const ECX_Vec4f const& v)
			{
				return sqrtf(Mag(v));
			}
			ECX_Vec4f Normalize(const ECX_Vec4f const& v)
			{
				float l = Length(v);
				return ECX_Vec4f(v.x / l, v.y / l, v.z / l, v.w / l);
			}
		} // End namespace Vector
		namespace Matrix
		{
			//	Determinant
			//	inverse
			//	transpose
			//	ECX_Mat3f functions
			ECX_Mat3f Transpose(ECX_Mat3f const& m)
			{
				ECX_Mat3f t = m;
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						int temp = t[a][b];
						t[a][b] = t[b][a];
						t[b][a] = temp;
					}
				}
				return t;
			}

			ECX_Mat3f Inverse(const ECX_Mat3f& m)
			{
				// Build a ECX_Matrix of minors
				float SubFactor00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
				float SubFactor01 = m[0][1] * m[2][2] - m[0][2] * m[2][1];
				float SubFactor02 = m[0][1] * m[1][2] - m[0][2] * m[1][1];

				float SubFactor03 = m[1][0] * m[2][2] - m[1][2] * m[2][0];
				float SubFactor04 = m[0][0] * m[2][2] - m[0][2] * m[2][0];
				float SubFactor05 = m[0][0] * m[1][2] - m[0][2] * m[1][0];

				float SubFactor06 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
				float SubFactor07 = m[0][0] * m[2][1] - m[0][1] * m[2][0];
				float SubFactor08 = m[0][0] * m[1][1] - m[0][1] * m[1][0];

				ECX_Mat3f Inverse(0.0f);
				//this part transposes and assigns
				Inverse[0][0] = SubFactor00;
				Inverse[0][1] = SubFactor01;
				Inverse[0][2] = SubFactor02;
				Inverse[1][0] = SubFactor03;
				Inverse[1][1] = SubFactor04;
				Inverse[1][2] = SubFactor05;
				Inverse[2][0] = SubFactor06;
				Inverse[2][1] = SubFactor07;
				Inverse[2][2] = SubFactor08;

				float determinant = m[0][0] * SubFactor00
					- m[1][0] * SubFactor01
					+ m[2][0] * SubFactor02;
				Inverse /= determinant;
				return Inverse;
			}
			//	ECX_Mat4f functions

			ECX_Mat4f Transpose(const ECX_Mat4f const& m)
			{
				ECX_Mat4f t = m;
				for (int a = 0; a < 4; a++) {
					for (int b = 0; b < 4; b++) {
						int temp = t[a][b];
						t[a][b] = t[b][a];
						t[b][a] = temp;
					}
				}
				return t;
			}
			ECX_Mat4f Inverse(const ECX_Mat4f const& m)
			{
				float SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
				float SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
				float SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
				float SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
				float SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
				float SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
				float SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
				float SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
				float SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
				float SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
				float SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
				float SubFactor11 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
				float SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
				float SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
				float SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
				float SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
				float SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
				float SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
				float SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

				ECX_Mat4f Inverse(0.0f);

				Inverse[0][0] = (m[1][1] * SubFactor00 - m[1][2] * SubFactor01 + m[1][3] * SubFactor02);
				Inverse[0][1] = -(m[1][0] * SubFactor00 - m[1][2] * SubFactor03 + m[1][3] * SubFactor04);
				Inverse[0][2] = (m[1][0] * SubFactor01 - m[1][1] * SubFactor03 + m[1][3] * SubFactor05);
				Inverse[0][3] = -(m[1][0] * SubFactor02 - m[1][1] * SubFactor04 + m[1][2] * SubFactor05);

				Inverse[1][0] = -(m[0][1] * SubFactor00 - m[0][2] * SubFactor01 + m[0][3] * SubFactor02);
				Inverse[1][1] = (m[0][0] * SubFactor00 - m[0][2] * SubFactor03 + m[0][3] * SubFactor04);
				Inverse[1][2] = -(m[0][0] * SubFactor01 - m[0][1] * SubFactor03 + m[0][3] * SubFactor05);
				Inverse[1][3] = (m[0][0] * SubFactor02 - m[0][1] * SubFactor04 + m[0][2] * SubFactor05);

				Inverse[2][0] = (m[0][1] * SubFactor06 - m[0][2] * SubFactor07 + m[0][3] * SubFactor08);
				Inverse[2][1] = -(m[0][0] * SubFactor06 - m[0][2] * SubFactor09 + m[0][3] * SubFactor10);
				Inverse[2][2] = (m[0][0] * SubFactor11 - m[0][1] * SubFactor09 + m[0][3] * SubFactor12);
				Inverse[2][3] = -(m[0][0] * SubFactor08 - m[0][1] * SubFactor10 + m[0][2] * SubFactor12);

				Inverse[3][0] = -(m[0][1] * SubFactor13 - m[0][2] * SubFactor14 + m[0][3] * SubFactor15);
				Inverse[3][1] = (m[0][0] * SubFactor13 - m[0][2] * SubFactor16 + m[0][3] * SubFactor17);
				Inverse[3][2] = -(m[0][0] * SubFactor14 - m[0][1] * SubFactor16 + m[0][3] * SubFactor18);
				Inverse[3][3] = (m[0][0] * SubFactor15 - m[0][1] * SubFactor17 + m[0][2] * SubFactor18);

				float Determinant =
					+m[0][0] * Inverse[0][0]
					+ m[0][1] * Inverse[0][1]
					+ m[0][2] * Inverse[0][2]
					+ m[0][3] * Inverse[0][3];

				Inverse /= Determinant;

				return Inverse;
			}

			ECX_Mat4f Translate(const ECX_Mat4f const& m, const ECX_Vec3f const& v)
			{
				ECX_Mat4f t(1.0f);
				t[2][0] = v.x;
				t[2][1] = v.y;
				t[2][2] = v.z;
				return t;
			}

			ECX_Mat4f Rotate(const ECX_Mat4f const& m, const ECX_Vec3f const& radians)
			{
				ECX_Mat4f rx(1.0f);
				rx[1][1] = cos(radians.x);
				rx[2][1] = sin(radians.x);
				rx[1][2] = -sin(radians.x);
				rx[2][2] = cos(radians.x);

				ECX_Mat4f ry(1.0f);
				ry[0][0] = cos(radians.y);
				ry[0][2] = sin(radians.y);
				ry[2][0] = -sin(radians.y);
				ry[2][2] = cos(radians.y);

				ECX_Mat4f rz(1.0f);
				rz[0][0] = cos(radians.z);
				rz[1][0] = sin(radians.z);
				rz[0][1] = -sin(radians.z);
				rz[1][1] = cos(radians.z);

				return (rz * ry * rx) * m;
			}

			ECX_Mat4f Scale(const ECX_Mat4f const& m, const ECX_Vec3f const& scale)
			{
				ECX_Mat4f s(1.0f);
				s[0][0] = scale.x;
				s[1][1] = scale.y;
				s[2][2] = scale.z;

				return s * m;
			}
		} //End namespace Matrix
		namespace Quaternion
		{
			float Magnitude(const ECX_Quat4f const& q)
			{
				return q.s * q.s + q.i * q.i + q.j * q.j + q.k * q.k;
			}

			ECX_Quat4f Normalize(const ECX_Quat4f const& q)
			{
				ECX_Quat4f q1 = q;
				float discriminant = 1.0f / sqrtf(Dot(q, q));
				return q1 * discriminant;
			}

			ECX_Quat4f Inverse(const ECX_Quat4f const& q)
			{
				return Conjugate(q) / Dot(q, q);
			}

			ECX_Quat4f Conjugate(const ECX_Quat4f const& q)
			{
				return ECX_Quat4f(q.s, -q.i, -q.j, -q.k);
			}

			float Dot(const ECX_Quat4f const& q1, const ECX_Quat4f const& q2)
			{
				return q1.i * q2.i + q1.j * q2.j + q1.k * q2.k + q1.s * q2.s;
			}

			ECX_Mat3f Mat3_cast(const ECX_Quat4f const& q)
			{
				ECX_Mat3f Result;
				Result[0][0] = 1 - 2 * q.j * q.j - 2 * q.k * q.k;
				Result[0][1] = 2 * q.i * q.j + 2 * q.j * q.k;
				Result[0][2] = 2 * q.i * q.k - 2 * q.j * q.j;

				Result[1][0] = 2 * q.i * q.j - 2 * q.j * q.k;
				Result[1][1] = 1 - 2 * q.i * q.i - 2 * q.k * q.k;
				Result[1][2] = 2 * q.j * q.k + 2 * q.j * q.i;

				Result[2][0] = 2 * q.i * q.k + 2 * q.j * q.j;
				Result[2][1] = 2 * q.j * q.k - 2 * q.j * q.i;
				Result[2][2] = 1 - 2 * q.i * q.i - 2 * q.j * q.j;

				return Result;
			}
			ECX_Mat4f Mat4_cast(const ECX_Quat4f const& q)
			{
				return ECX_Mat4f(Mat3_cast(q));
			}

			ECX_Quat4f Quat_cast(const ECX_Mat3f const& m)
			{
				float fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
				float fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
				float fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
				float fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

				int biggestIndex = 0;
				float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
				if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
				{
					fourBiggestSquaredMinus1 = fourXSquaredMinus1;
					biggestIndex = 1;
				}
				if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
				{
					fourBiggestSquaredMinus1 = fourYSquaredMinus1;
					biggestIndex = 2;
				}
				if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
				{
					fourBiggestSquaredMinus1 = fourZSquaredMinus1;
					biggestIndex = 3;
				}

				float biggestVal = sqrtf(fourBiggestSquaredMinus1 + 1) * 0.5f;
				float mult = 0.25f / biggestVal;

				ECX_Quat4f Result(1.0f);
				switch (biggestIndex)
				{
				case 0:
					Result.s = biggestVal;
					Result.i = (m[1][2] - m[2][1]) * mult;
					Result.j = (m[2][0] - m[0][2]) * mult;
					Result.k = (m[0][1] - m[1][0]) * mult;
					break;
				case 1:
					Result.s = (m[1][2] - m[2][1]) * mult;
					Result.i = biggestVal;
					Result.j = (m[0][1] + m[1][0]) * mult;
					Result.k = (m[2][0] + m[0][2]) * mult;
					break;
				case 2:
					Result.s = (m[2][0] - m[0][2]) * mult;
					Result.i = (m[0][1] + m[1][0]) * mult;
					Result.j = biggestVal;
					Result.k = (m[1][2] + m[2][1]) * mult;
					break;
				case 3:
					Result.s = (m[0][1] - m[1][0]) * mult;
					Result.i = (m[2][0] + m[0][2]) * mult;
					Result.j = (m[1][2] + m[2][1]) * mult;
					Result.k = biggestVal;
					break;
				}
				return Result;
			}

			ECX_Quat4f Quat_cast(const ECX_Mat4f const& m)
			{
				return Quat_cast(ECX_Mat3f(m));
			}

			ECX_Quat4f AxisAngle(const ECX_Vec3f& axis, const float angle)
			{
				ECX_Vec3f v = axis;
				if (Vector::Length(v) > 1.0f)
					v = Vector::Normalize(v);

				ECX_Quat4f q;

				q.s = cosf(angle * 0.5f);
				q.i = v.x * sinf(angle * 0.5f);
				q.j = v.y * sinf(angle * 0.5f);
				q.k = v.z * sinf(angle * 0.5f);

				return q;
			}
		} //End namespace Quaternion
	}
}
#endif // !ECX_FUNC_H
