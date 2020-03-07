#include "Math.h"

const Vector3 Vector3::One(1.0, 1.0, 1.0);
const Vector3 Vector3::Zero(0.0, 0.0, 0.0);
const Vector3 Vector3::Left(-1.0, 0.0, 0.0);
const Vector3 Vector3::Right(1.0, 0.0, 0.0);
const Vector3 Vector3::Up(0.0, 1.0, 0.0);
const Vector3 Vector3::Down(0.0, -1.0, 0.0);
const Vector3 Vector3::Forward(0.0, 0.0, 1.0);
const Vector3 Vector3::Back(0.0, 0.0, -1.0);

Vector3::Vector3()
{
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
}

Vector3::Vector3(const Vector3& v)
{
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
}

Vector3::Vector3(float x, float y, float z)
{
        this->x = x;
        this->y = y;
        this->z = z;
}

Vector3& Vector3::operator = (const Vector3& v)
{
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        
        return *this;
}

Vector3 Vector3::operator-()
{
        return Vector3(-this->x, -this->y, -this->z);
}

bool Vector3::operator==(const Vector3& v)
{
        return x == v.x and y == v.y and z == v.z;
}

bool Vector3::operator!=(const Vector3& v)
{
        return !(*this == v);
}

Vector3 Vector3::operator+(const Vector3& v)
{
        return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector3 Vector3::operator+=(const Vector3& v)
{
        *this = (*this) + v;
        return (*this);
}

Vector3 Vector3::operator+(const float& f)
{
        Vector3 result;
        
        result.x = this->x + f;
        result.y = this->y + f;
        result.z = this->z + f;
        
        return result;
}

Vector3 Vector3::operator+=(const float& f)
{
        *this = (*this) + f;
        return (*this);
}

Vector3 Vector3::operator-(const Vector3& v)
{
        Vector3 result;
        
        result.x = this->x - v.x;
        result.y = this->y - v.y;
        result.z = this->z - v.z;
        
        return result;
}

Vector3 Vector3::operator-=(const Vector3& v)
{
        *this = (*this) - v;
        return (*this);
}

Vector3 Vector3::operator-(const float& f)
{
        Vector3 result;
        
        result.x = this->x - f;
        result.y = this->y - f;
        result.z = this->z - f;
        
        return result;
}

Vector3 Vector3::operator-=(const float& f)
{
        *this = (*this) - f;
        return (*this);
}

Vector3 Vector3::operator*(const Vector3& v)
{
        Vector3 result;
        
        result.x = this->x * v.x;
        result.y = this->y * v.y;
        result.z = this->z * v.z;
        
        return result;
}

Vector3 Vector3::operator*=(const Vector3& v)
{
        *this = (*this) * v;
        return (*this);
}

Vector3 Vector3::operator*(const float& f)
{
        Vector3 result;
        
        result.x = this->x * f;
        result.y = this->y * f;
        result.z = this->z * f;
        
        return result;
}

Vector3 Vector3::operator*=(const float& f)
{
        *this = (*this) * f;
        return (*this);
}

Vector3 Vector3::operator/(const Vector3& v)
{
        Vector3 result;
        
        result.x = this->x / v.x;
        result.y = this->y / v.y;
        result.z = this->z / v.z;
        
        return result;
}

Vector3 Vector3::operator/=(const Vector3& v)
{
        *this = (*this) / v;
        return (*this);
}

Vector3 Vector3::operator/(const float& f)
{
        Vector3 result;
        
        result.x = this->x / f;
        result.y = this->y / f;
        result.z = this->z / f;
        
        return result;
}

Vector3 Vector3::operator/=(const float& f)
{
        *this = (*this) / f;
        return (*this);
}

std::string Vector3::ToString()
{
        std::string result;
        result += std::to_string(this->x) + "\t" + std::to_string(this->y) + "\t" + std::to_string(this->z);
        
        return result;
}

Vector3 Vector3::Negate()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    
    return *this;
}

void Vector3::Set(float x, float y, float z)
{
        this->x = x;
        this->y = y;
        this->z = z;
}

bool Vector3::Equals(Vector3 v)
{
        return *this == v;
}

Vector3 Vector3::Normalize()
{
        float length = Vector3::Length(*this);
    
        this->x /= length;
        this->y /= length;
        this->z /= length;
        
        return *this;
}

Vector3 Vector3::GetNormalized(Vector3 v)
{
        Vector3 result;
        
        float length = Vector3::Length(v);
        
        result.x = v.x / length;
        result.y = v.y / length;
        result.z = v.z / length;
        
        return result;
}

float Vector3::AngleBetween(Vector3 a, Vector3 b)
{
    float dot = Vector3::DotProduct(a, b);
    float angleRadians = Math::Acos(dot);
    return Math::ToDegrees(angleRadians);
}

Vector3 Vector3::Min(Vector3 a, Vector3 b)
{
        return Vector3(Math::Min(a.x, b.x), Math::Min(a.y, b.y), Math::Min(a.z, b.z));
}

Vector3 Vector3::Max(Vector3 a, Vector3 b)
{
        return Vector3(Math::Max(a.x, b.x), Math::Max(a.y, b.y), Math::Max(a.z, b.z));
}

float Vector3::Length(Vector3 v)
{
        return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

float Vector3::LengthSquared(Vector3 v)
{
        return (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
}

float Vector3::Distance(Vector3 a, Vector3 b)
{
        return Length(b - a);
}

float Vector3::DistanceSquared(Vector3 a, Vector3 b)
{
        return LengthSquared(b - a);
}

Vector3 Vector3::CrossProduct(Vector3 a, Vector3 b)
{
        Vector3 result;
        
        result.x = a.y * b.z - a.z * b.y;
        result.y = a.z * b.x - a.x * b.z;
        result.z = a.x * b.y - a.y * b.x;
        
        return result;
}

float Vector3::DotProduct(Vector3 a, Vector3 b)
{
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float alpha)
{
        Vector3 result;
        
        result.x = Math::Lerp(a.x, b.x, alpha);
        result.y = Math::Lerp(a.y, b.y, alpha);
        result.z = Math::Lerp(a.z, b.z, alpha);
        
        return result;
}

Vector3 Vector3::Nlerp(Vector3 a, Vector3 b, float alpha)
{
        return Lerp(a, b, alpha).Normalize();
}

Vector3 Vector3::Scale(Vector3 v, float scale)
{
        return Vector3(v.x * scale, v.y * scale, v.z * scale);
}

Vector3 Vector3::Clamp(Vector3 value, Vector3 min, Vector3 max)
{
        return Min(Max(value, min), max);
}

void Vector3::OrthoNormalize(Vector3 &normal, Vector3 &tangent)
{
        normal.Normalize();
        Vector3 p = Scale(normal, DotProduct(tangent, normal));
        tangent -= p;
        tangent.Normalize();
    
    /*
    normal.Normalize();
    Vector3 proj = normal * DotProduct(tangent, normal);
    tangent = tangent - proj;
    tangent.Normalize();
     */
}

