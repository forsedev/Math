#include "Math.h"

const Vector2 Vector2::One(1.0, 1.0);
const Vector2 Vector2::Zero(0.0, 0.0);
const Vector2 Vector2::Left(-1.0, 0.0);
const Vector2 Vector2::Right(1.0, 0.0);
const Vector2 Vector2::Up(0.0, 1.0);
const Vector2 Vector2::Down(0.0, -1.0);

Vector2::Vector2()
{
        this->x = 0.0;
        this->y = 0.0;
}

Vector2::Vector2(const Vector2& v)
{
        this->x = v.x;
        this->y = v.y;
}

Vector2::Vector2(float x, float y)
{
        this->x = x;
        this->y = y;
}

Vector2& Vector2::operator=(const Vector2& v)
{
        this->x = v.x;
        this->y = v.y;
        
        return *this;
}

Vector2 Vector2::operator-()
{
        return Vector2(-this->x, -this->y);
}

bool Vector2::operator==(const Vector2& v)
{
        return x == v.x and y == v.y;
}

bool Vector2::operator!=(const Vector2& v)
{
        return !(*this == v);
}

Vector2 Vector2::operator+(const Vector2& v)
{
        Vector2 result;
        
        result.x = this->x + v.x;
        result.y = this->y + v.y;
        
        return result;
}

Vector2 Vector2::operator+=(const Vector2& v)
{
        *this = (*this) + v;
        return (*this);
}

Vector2 Vector2::operator+(const float& f)
{
        Vector2 result;
        
        result.x = this->x + f;
        result.y = this->y + f;
        
        return result;
}

Vector2 Vector2::operator+=(const float& f)
{
        *this = (*this) + f;
        return (*this);
}

Vector2 Vector2::operator-(const Vector2& v)
{
        Vector2 result;
        
        result.x = this->x - v.x;
        result.y = this->y - v.y;
        
        return result;
}

Vector2 Vector2::operator-=(const Vector2& v)
{
        *this = (*this) - v;
        return (*this);
}

Vector2 Vector2::operator-(const float& f)
{
        Vector2 result;
        
        result.x = this->x - f;
        result.y = this->y - f;
        
        return result;
}

Vector2 Vector2::operator-=(const float& f)
{
        *this = (*this) - f;
        return (*this);
}

Vector2 Vector2::operator*(const Vector2& v)
{
        Vector2 result;
        
        result.x = this->x * v.x;
        result.y = this->y * v.y;
        
        return result;
}

Vector2 Vector2::operator*=(const Vector2& v)
{
        *this = (*this) * v;
        return (*this);
}

Vector2 Vector2::operator*(const float& f)
{
        Vector2 result;
        
        result.x = this->x * f;
        result.y = this->y * f;
        
        return result;
}

Vector2 Vector2::operator*=(const float& f)
{
        *this = (*this) * f;
        return (*this);
}

Vector2 Vector2::operator/(const Vector2& v)
{
        Vector2 result;
        
        result.x = this->x / v.x;
        result.y = this->y / v.y;
        
        return result;
}

Vector2 Vector2::operator/=(const Vector2& v)
{
        *this = (*this) / v;
        return (*this);
}

Vector2 Vector2::operator/(const float& f)
{
        Vector2 result;
        
        result.x = this->x / f;
        result.y = this->y / f;
        
        return result;
}

Vector2 Vector2::operator/=(const float& f)
{
        *this = (*this) / f;
        return (*this);
}

std::string Vector2::ToString()
{
        std::string result;
        result += std::to_string(this->x) + "\t" + std::to_string(this->y);
        
        return result;
}

Vector2 Vector2::Negate()
{
    this->x = -this->x;
    this->y = -this->y;
    
    return *this;
}

void Vector2::Set(float x, float y)
{
        this->x = x;
        this->y = y;
}

bool Vector2::Equals(Vector2 v)
{
        return *this == v;
}

Vector2 Vector2::Normalize()
{
        float length = Vector2::Length(*this);
        
        this->x /= length;
        this->y /= length;
        
        return *this;
}

Vector2 Vector2::GetNormalized(Vector2 v)
{
        Vector2 result;
        
        float length = Vector2::Length(v);
        
        result.x = v.x / length;
        result.y = v.y / length;
        
        return result;
}

float Vector2::AngleBetween(Vector2 a, Vector2 b)
{
    return Math::Fabs(atan2(a.x * b.y - b.x * a.y, a.x * b.x + a.y * b.y));
}

Vector2 Vector2::Min(Vector2 a, Vector2 b)
{
        return Vector2(Math::Min(a.x, b.x), Math::Min(a.y, b.y));
}

Vector2 Vector2::Max(Vector2 a, Vector2 b)
{
        return Vector2(Math::Max(a.x, b.x), Math::Max(a.y, b.y));
}

float Vector2::Length(Vector2 v)
{
        return sqrtf((v.x * v.x) + (v.y * v.y));
}

float Vector2::LengthSquared(Vector2 v)
{
        return (v.x * v.x) + (v.y * v.y);
}

float Vector2::Distance(Vector2 a, Vector2 b)
{
        return Vector2::Length(b - a);
}

float Vector2::DistanceSquared(Vector2 a, Vector2 b)
{
        return Vector2::LengthSquared(b - a);
}

float Vector2::CrossProduct(Vector2 a, Vector2 b)
{
        return (a.x * b.y) - (a.y * b.x);
}

float Vector2::DotProduct(Vector2 a, Vector2 b)
{
        return (a.x * b.x) + (a.y * b.y);
}

Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float alpha)
{
        Vector2 result;
        
        result.x = Math::Lerp(a.x, b.x, alpha);
        result.y = Math::Lerp(a.y, b.y, alpha);
        
        return result;
}

Vector2 Vector2::Nlerp(Vector2 a, Vector2 b, float alpha)
{
        Vector2 result;
        
        result = Vector2::Lerp(a, b, alpha);
        result.Normalize();
        
        return result;
}

Vector2 Vector2::Scale(Vector2 v, float scale)
{
        return Vector2(v.x * scale, v.y * scale);
}

Vector2 Vector2::Clamp(Vector2 value, Vector2 min, Vector2 max)
{
        Vector2 result;
        
        result.x = Math::Clamp(value.x, min.x, max.x);
        result.y = Math::Clamp(value.y, min.y, max.y);
        
        return result;
}

