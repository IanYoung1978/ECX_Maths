#ifndef ECX_MAT4_H
#define ECX_MAT4_H

#include "ECX_Vec4f.h"
#include "ECX_Mat3f.h"
#include <cassert>

namespace ECX_Maths
{
    struct ECX_Mat4f
    {
        ECX_Vec4f value[4];
        ECX_Mat4f()
        {
            value[0] = ECX_Vec4f();
            value[1] = ECX_Vec4f();
            value[2] = ECX_Vec4f();
            value[3] = ECX_Vec4f();
        }
        ECX_Mat4f(const float& scalar)
        {
            value[0] = ECX_Vec4f(scalar, 0.0f, 0.0f, 0.0f);
            value[1] = ECX_Vec4f(0.0f, scalar, 0.0f, 0.0f);
            value[2] = ECX_Vec4f(0.0f, 0.0f, scalar, 0.0f);
            value[3] = ECX_Vec4f(0.0f, 0.0f, 0.0f,   1.0f);
        }
        ECX_Mat4f(
            const float& x0, const float& y0, const float& z0, const float w0,
            const float& x1, const float& y1, const float& z1, const float w1,
            const float& x2, const float& y2, const float& z2, const float w2,
            const float& x3, const float& y3, const float& z3, const float w3
        )
        {
            value[0] = ECX_Vec4f(x0, y0, z0, w0);
            value[1] = ECX_Vec4f(x1, y1, z1, w1);
            value[2] = ECX_Vec4f(x2, y2, z2, w2);
            value[3] = ECX_Vec4f(x3, y3, z3, w3);
        }
        ECX_Mat4f(const ECX_Vec4f& v0, const ECX_Vec4f& v1, const ECX_Vec4f& v2, const ECX_Vec4f& v3)
        {
            value[0] = v0;
            value[1] = v1;
            value[2] = v2;
            value[2] = v3;
        }
        ECX_Mat4f(const ECX_Mat3f& m)
        {
            value[0][0] = m[0][0];
            value[1][0] = m[1][0];
            value[2][0] = m[2][0];
            value[0][1] = m[0][1];
            value[1][1] = m[1][1];
            value[1][1] = m[2][1];
            value[0][2] = m[0][2];
            value[1][2] = m[1][2];
            value[2][2] = m[2][2];

            value[0][3] = 0.0f;
            value[1][3] = 0.0f;
            value[2][3] = 0.0f;
            value[3][3] = 1.0f;

            value[3][0] = 0.0f;
            value[3][1] = 0.0f;
            value[3][2] = 0.0f;

        }

        const int length()
        {
            return 4;
        }
        inline ECX_Vec4f& operator[](const int index)
        {
            assert(-1 < index && index < 4);
            return this->value[index];
        }
        inline ECX_Vec4f const& operator[](const int index) const
        {
            assert(-1 < index && index < 4);
            return this->value[index];
        }
        ECX_Mat4f(const ECX_Mat4f& m)
        {
            value[0] = m[0];
            value[1] = m[1];
            value[2] = m[2];
            value[2] = m[3];
        }

        ECX_Mat4f& operator=(const ECX_Mat4f& m)
        {
            value[0] = m[0];
            value[1] = m[1];
            value[2] = m[2];
            value[3] = m[3];
            return *this;
        }
        ECX_Mat4f& operator+=(const ECX_Mat4f& m)
        {
            value[0] += m[0];
            value[1] += m[1];
            value[2] += m[2];
            value[3] += m[3];
            return *this;
        }

        ECX_Mat4f& operator-=(const ECX_Mat4f& m)
        {
            value[0] -= m[0];
            value[1] -= m[1];
            value[2] -= m[2];
            value[3] -= m[3];
            return *this;
        }

        ECX_Mat4f operator*(const ECX_Mat4f& rhs)
        {
            return ECX_Mat4f(
                value[0].x * rhs[0].x + value[0].y * rhs[1].x + value[0].z * rhs[2].x + value[0].w * rhs[3].x,
                value[0].x * rhs[0].y + value[0].y * rhs[1].y + value[0].z * rhs[2].y + value[0].w * rhs[3].y,
                value[0].x * rhs[0].z + value[0].y * rhs[1].z + value[0].z * rhs[2].z + value[0].w * rhs[3].z,
                value[0].x * rhs[0].w + value[0].y * rhs[1].w + value[0].z * rhs[2].w + value[0].w * rhs[3].w,

                value[1].x * rhs[0].x + value[1].y * rhs[1].x + value[1].z * rhs[2].x + value[1].w * rhs[3].x,
                value[1].x * rhs[0].y + value[1].y * rhs[1].y + value[1].z * rhs[2].y + value[1].w * rhs[3].y,
                value[1].x * rhs[0].z + value[1].y * rhs[1].z + value[1].z * rhs[2].z + value[1].w * rhs[3].z,
                value[1].x * rhs[0].w + value[1].y * rhs[1].w + value[1].z * rhs[2].w + value[1].w * rhs[3].w,

                value[2].x * rhs[0].x + value[2].y * rhs[1].x + value[2].z * rhs[2].x + value[2].w * rhs[3].x,
                value[2].x * rhs[0].y + value[2].y * rhs[1].y + value[2].z * rhs[2].y + value[2].w * rhs[3].y,
                value[2].x * rhs[0].z + value[2].y * rhs[1].z + value[2].z * rhs[2].z + value[2].w * rhs[3].z,
                value[2].x * rhs[0].w + value[2].y * rhs[1].w + value[2].z * rhs[2].w + value[2].w * rhs[3].w,

                value[3].x * rhs[0].x + value[3].y * rhs[1].x + value[3].z * rhs[2].x + value[3].w * rhs[3].x,
                value[3].x * rhs[0].y + value[3].y * rhs[1].y + value[3].z * rhs[2].y + value[3].w * rhs[3].y,
                value[3].x * rhs[0].z + value[3].y * rhs[1].z + value[3].z * rhs[2].z + value[3].w * rhs[3].z,
                value[3].x * rhs[0].w + value[3].y * rhs[1].w + value[3].z * rhs[2].w + value[3].w * rhs[3].w
            );
        }

        ECX_Mat4f& operator /= (const float& divisor)
        {
            for (int i = 0; i < 4; i++)
            {
                value[i] /= divisor;
            }
            value[3][3] = 1.0f;
            return *this;
        }

        ECX_Mat4f& operator *= (const float& divisor)
        {
            for (int i = 0; i < 4; i++)
            {
                value[i] *= divisor;
            }
            value[3][3] = 1.0f;
            return *this;
        }
    };
}
#endif // !ECX_MAT4_H
