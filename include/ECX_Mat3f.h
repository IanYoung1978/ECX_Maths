#ifndef ECX_MAT3_H
#define ECX_MAT3_H


#include "ECX_Mat4f.h"
#include "ECX_Vec3f.h"
#include <cassert>

namespace ECX_Maths
{
    struct ECX_Mat3f
    {
        ECX_Vec3f value[3];
        ECX_Mat3f()
        {
            value[0] = ECX_Vec3f();
            value[1] = ECX_Vec3f();
            value[2] = ECX_Vec3f();
        }

        ECX_Mat3f(const float& scalar)
        {
            value[0] = ECX_Vec3f(scalar, 0.0f, 0.0f);
            value[1] = ECX_Vec3f(0.0f, scalar, 0.0f);
            value[2] = ECX_Vec3f(0.0f, 0.0f, scalar);
        }

        ECX_Mat3f(
            const float& x0, const float& y0, const float& z0,
            const float& x1, const float& y1, const float& z1,
            const float& x2, const float& y2, const float& z2
        )
        {
            value[0] = ECX_Vec3f(x0, y0, z0);
            value[1] = ECX_Vec3f(x1, y1, z1);
            value[2] = ECX_Vec3f(x2, y2, z2);
        }

        ECX_Mat3f(const ECX_Vec3f& v0, const ECX_Vec3f& v1, const ECX_Vec3f& v2)
        {
            value[0] = v0;
            value[1] = v1;
            value[2] = v2;
        }

        ECX_Mat3f(const ECX_Mat3f& m)
        {
            value[0] = m[0];
            value[1] = m[1];
            value[2] = m[2];
        }

        ECX_Mat3f(const ECX_Mat4f& m)
        {
            value[0] = ECX_Vec3f(m[0]);
            value[1] = ECX_Vec3f(m[1]);
            value[2] = ECX_Vec3f(m[2]);
        }
        const int length()
        {
            return 3;
        }
        ECX_Vec3f& operator[](int index)
        {
            assert(-1 < index && index < 3);
            return value[index];
        }
        inline ECX_Vec3f const& operator[](const int index) const
        {
            assert(-1 < index && index < 3);
            return this->value[index];
        }
        ECX_Mat3f& operator=(const ECX_Mat3f& m)
        {
            value[0] = m[0];
            value[1] = m[1];
            value[2] = m[2];
            return *this;
        }
        ECX_Mat3f& operator+=(const ECX_Mat3f& m)
        {
            value[0] += m[0];
            value[1] += m[1];
            value[2] += m[2];
            return *this;
        }

        ECX_Mat3f& operator-=(const ECX_Mat3f& m)
        {
            value[0] -= m[0];
            value[1] -= m[1];
            value[2] -= m[2];
            return *this;
        }

        ECX_Mat3f operator*(const ECX_Mat3f& rhs)
        {
            return ECX_Mat3f(
                value[0].x * rhs[0].x + value[0].y * rhs[1].x + value[0].z * rhs[2].x,
                value[0].x * rhs[0].y + value[0].y * rhs[1].y + value[0].z * rhs[2].y,
                value[0].x * rhs[0].z + value[0].y * rhs[1].z + value[0].z * rhs[2].z,

                value[1].x * rhs[1].x + value[1].y * rhs[1].x + value[1].z * rhs[2].x,
                value[1].x * rhs[1].y + value[1].y * rhs[1].y + value[1].z * rhs[2].y,
                value[1].x * rhs[1].z + value[1].y * rhs[1].z + value[1].z * rhs[2].z,

                value[2].x * rhs[2].x + value[2].y * rhs[2].x + value[2].z * rhs[2].x,
                value[2].x * rhs[2].y + value[2].y * rhs[2].y + value[2].z * rhs[2].y,
                value[2].x * rhs[2].z + value[2].y * rhs[2].z + value[2].z * rhs[2].z
            );
        }

        ECX_Mat3f operator /=(const float& divisor)
        {
            ECX_Mat3f m = *this;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    m[i][j] /= divisor;
                }
            }
            return m;
        }
    };
}
#endif // !ECX_MAT3_H
