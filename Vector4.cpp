#include "Math.h"

const Vector4 Vector4::One(1.0, 1.0, 1.0, 1.0);
const Vector4 Vector4::Zero(0.0, 0.0, 0.0, 0.0);

Vector4::Vector4()
{
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
        this->w = 0.0;
}

Vector4::Vector4(const Vector4& v)
{
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = v.w;
}

Vector4::Vector4(const Vector3 v, float w)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = w;
}

Vector4::Vector4(float x, float y, float z, float w)
{
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
}

Vector4& Vector4::operator=(const Vector4& v)
{
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = v.w;
        
        return *this;
}

Vector4 Vector4::operator-()
{
        return Vector4(-this->x, -this->y, -this->z, -this->w);
}

bool Vector4::operator==(const Vector4& v)
{
        return x == v.x and y == v.y and z == v.z and w == v.w;
}

bool Vector4::operator!=(const Vector4& v)
{
        return !(*this == v);
}

Vector4 Vector4::operator+(const Vector4& v)
{
        Vector4 result;
        
        result.x = this->x + v.x;
        result.y = this->y + v.y;
        result.z = this->z + v.z;
        result.w = this->w + v.w;
        
        return result;
}

Vector4 Vector4::operator+=(const Vector4& v)
{
        *this = (*this) + v;
        return (*this);
}

Vector4 Vector4::operator+(const float& f)
{
        Vector4 result;
        
        result.x = this->x + f;
        result.y = this->y + f;
        result.z = this->z + f;
        result.w = this->w + f;
        
        return result;
}

Vector4 Vector4::operator+=(const float& f)
{
        *this = (*this) + f;
        return (*this);
}

Vector4 Vector4::operator-(const Vector4& v)
{
        Vector4 result;
        
        result.x = this->x - v.x;
        result.y = this->y - v.y;
        result.z = this->z - v.z;
        result.w = this->w - v.w;
        
        return result;
}

Vector4 Vector4::operator-=(const Vector4& v)
{
        *this = (*this) - v;
        return (*this);
}

Vector4 Vector4::operator-(const float& f)
{
        Vector4 result;
        
        result.x = this->x - f;
        result.y = this->y - f;
        result.z = this->z - f;
        result.w = this->w - f;
        
        return result;
}

Vector4 Vector4::operator-=(const float& f)
{
        *this = (*this) - f;
        return (*this);
}

Vector4 Vector4::operator*(const Vector4& v)
{
        Vector4 result;
        
        result.x = this->x * v.x;
        result.y = this->y * v.y;
        result.z = this->z * v.z;
        result.w = this->w * v.w;
        
        return result;
}

Vector4 Vector4::operator*=(const Vector4& v)
{
        *this = (*this) * v;
        return (*this);
}

Vector4 Vector4::operator*(const Matrix& m)
{
    Vector4 result;
    
    result.x = m(0, 0) * x + m(0, 1) * y + m(0, 2) * z + m(0, 3) * w;
    result.y = m(1, 0) * x + m(1, 1) * y + m(1, 2) * z + m(1, 3) * w;
    result.z = m(2, 0) * x + m(2, 1) * y + m(2, 2) * z + m(2, 3) * w;
    result.w = m(3, 0) * x + m(3, 1) * y + m(3, 2) * z + m(3, 3) * w;
    
    return result;
}

Vector4 Vector4::operator*=(const Matrix& m)
{
        *this = (*this) * m;
        return (*this);
}

Vector4 Vector4::operator*(const float& f)
{
        Vector4 result;
        
        result.x = this->x * f;
        result.y = this->y * f;
        result.z = this->z * f;
        result.w = this->w * f;
        
        return result;
}

Vector4 Vector4::operator*=(const float& f)
{
        *this = (*this) * f;
        return (*this);
}

Vector4 Vector4::operator/(const Vector4& v)
{
        Vector4 result;
        
        result.x = this->x / v.x;
        result.y = this->y / v.y;
        result.z = this->z / v.z;
        result.w = this->w / v.w;
        
        return result;
}

Vector4 Vector4::operator/=(const Vector4& v)
{
        *this = (*this) / v;
        return (*this);
}

Vector4 Vector4::operator/(const float& f)
{
        Vector4 result;
        
        result.x = this->x / f;
        result.y = this->y / f;
        result.z = this->z / f;
        result.w = this->w / f;
        
        return result;
}

Vector4 Vector4::operator/=(const float& f)
{
        *this = *this / f;
        return (*this);
}

std::string Vector4::ToString()
{
        std::string result;
        result += std::to_string(this->x) + "\t" + std::to_string(this->y) + "\t" + std::to_string(this->z) + "\t" + std::to_string(this->w);
        
        return result;
}

Vector4 Vector4::Negate()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    this->w = -this->w;
    
    return *this;
}

void Vector4::Set(float x, float y, float z, float w)
{
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
}

bool Vector4::Equals(Vector4 v)
{
        return *this == v;
}

Vector4 Vector4::Normalize()
{
        float length = Vector4::Length(*this);
        
        this->x /= length;
        this->y /= length;
        this->z /= length;
        this->w /= length;
        
        return *this;
}

Vector4 Vector4::GetNormalized(Vector4 v)
{
        Vector4 result;
        
        float length = Vector4::Length(v);
        
        result.x = v.x / length;
        result.y = v.y / length;
        result.z = v.z / length;
        result.w = v.w / length;
        
        return result;
}

Vector4 Vector4::Min(Vector4 a, Vector4 b)
{
        return Vector4(Math::Min(a.x, b.x), Math::Min(a.y, b.y), Math::Min(a.z, b.z), Math::Min(a.w, b.w));
}

Vector4 Vector4::Max(Vector4 a, Vector4 b)
{
        return Vector4(Math::Max(a.x, b.x), Math::Max(a.y, b.y), Math::Max(a.z, b.z), Math::Max(a.w, b.w));
}

float Vector4::Length(Vector4 v)
{
        return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

float Vector4::LengthSquared(Vector4 v)
{
        return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w);
}

float Vector4::Distance(Vector4 a, Vector4 b)
{
        return Length(b - a);
}

float Vector4::DistanceSquared(Vector4 a, Vector4 b)
{
        return LengthSquared(b - a);
}

float Vector4::DotProduct(Vector4 a, Vector4 b)
{
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

Vector4 Vector4::Lerp(Vector4 a, Vector4 b, float alpha)
{
        Vector4 result;
        
        result.x = Math::Lerp(a.x, b.x, alpha);
        result.y = Math::Lerp(a.y, b.y, alpha);
        result.z = Math::Lerp(a.z, b.z, alpha);
        result.w = Math::Lerp(a.w, b.w, alpha);
        
        return result;
}

Vector4 Vector4::NLerp(Vector4 a, Vector4 b, float alpha)
{
        return Lerp(a, b, alpha).Normalize();
}

Vector4 Vector4::Scale(Vector4 v, float scale)
{
        return Vector4(v.x * scale, v.y * scale, v.z * scale, v.w * scale);
}

Vector4 Vector4::Clamp(Vector4 value, Vector4 min, Vector4 max)
{
        Vector4 result;
        
        result.x = Math::Clamp(value.x, min.x, max.x);
        result.y = Math::Clamp(value.y, min.y, max.y);
        result.z = Math::Clamp(value.z, min.z, max.z);
        result.w = Math::Clamp(value.w, min.w, max.w);
        
        return result;
}

