#include "Math.h"

const Quaternion Quaternion::Identity(0.0, 0.0, 0.0, 1.0);
const Quaternion Quaternion::Zero(0.0, 0.0, 0.0, 0.0);
const Quaternion Quaternion::One(1.0, 1.0, 1.0, 1.0);

Quaternion::Quaternion()
{
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
        this->w = 1.0;
}

Quaternion::Quaternion(const Quaternion& q)
{
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
        this->w = q.w;
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
}

Quaternion& Quaternion::operator=(const Quaternion& q)
{
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
        this->w = q.w;
        
        return *this;
}

Quaternion Quaternion::operator-()
{
        return Quaternion(-this->x, -this->y, -this->z, -this->w);
}

bool Quaternion::operator==(const Quaternion& v)
{
        return x == v.x and y == v.y and z == v.z and w == v.w;
}

bool Quaternion::operator!=(const Quaternion& v)
{
        return !(*this == v);
}

Quaternion Quaternion::operator+(const Quaternion& q)
{
        Quaternion result;
        
        result.x = this->x + q.x;
        result.y = this->y + q.y;
        result.z = this->z + q.z;
        result.w = this->w + q.w;
        
        return result;
}

Quaternion Quaternion::operator+=(const Quaternion& q)
{
        *this = (*this) + q;
        return (*this);
}

Quaternion Quaternion::operator-(const Quaternion& q)
{
        Quaternion result;
        
        result.x = this->x - q.x;
        result.y = this->y - q.y;
        result.z = this->z - q.z;
        result.w = this->w - q.w;
        
        return result;
}

Quaternion Quaternion::operator-=(const Quaternion& q)
{
        *this = (*this) - q;
        return (*this);
}

Quaternion Quaternion::operator*(const Quaternion& q)
{
        Quaternion result;
        
        result.x = (x * q.w) + (w * q.x) + (y * q.z) - (z * q.y);
        result.y = (y * q.w) + (w * q.y) + (z * q.x) - (x * q.z);
        result.z = (z * q.w) + (w * q.z) + (x * q.y) - (y * q.x);
        result.w = (w * q.w) - (x * q.x) - (y * q.y) - (z * q.z);
    
        return result;
}

Quaternion Quaternion::operator*=(const Quaternion& q)
{
        *this = (*this) * q;
        return (*this);
}

Quaternion Quaternion::operator*(const float& f)
{
        Quaternion result;
        
        result.x = this->x * f;
        result.y = this->y * f;
        result.z = this->z * f;
        result.w = this->w * f;
        
        return result;
}

Quaternion Quaternion::operator*=(const float& f)
{
        *this = (*this) * f;
        return (*this);
}

Quaternion Quaternion::operator/(const Quaternion& q)
{
        return ((*this) * Inverse(q));
}

Quaternion Quaternion::operator/=(const Quaternion& q)
{
        *this = (*this) / Inverse(q);
        return (*this);
}

std::string Quaternion::ToString()
{
        std::string result;
        result += std::to_string(this->x) + "\t" + std::to_string(this->y) + "\t" + std::to_string(this->z) + "\t" + std::to_string(this->w);
        
        return result;
}

Quaternion Quaternion::Negate()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    this->w = -this->w;
    
    return *this;
}

void Quaternion::Set(float x, float y, float z, float w)
{
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
}

bool Quaternion::Equals(Quaternion q)
{
        return *this == q;
}

Quaternion Quaternion::Normalize()
{
        float length = Quaternion::Length(*this);
        
        this->x /= length;
        this->y /= length;
        this->z /= length;
        this->w /= length;
        
        return *this;
}

Vector3 Quaternion::GetAxisX()
{
    Vector3 result;
    
    result.x = w * w + x * x - y * y - z * z;
    result.y = (x * y + z * w) * 2.0;
    result.z = (z * x - y * w) * 2.0;
    
    return result;
}

Vector3 Quaternion::GetAxisY()
{
    Vector3 result;
    
    result.x = (x * y - z * w) * 2.0;
    result.y = w * w - x * x + y * y - z * z;
    result.z = (y * z + x * w) * 2.0;
    
    return result;
}

Vector3 Quaternion::GetAxisZ()
{
    Vector3 result;
    
    result.x = (z * x + y * w) * 2.0;
    result.y = (y * z - x * w) * 2.0;
    result.z = w * w - x * x - y * y + z * z;
    
    return result;
}

Vector3 Quaternion::GetLeftVector()
{
    return -GetAxisX();
}

Vector3 Quaternion::GetRightVector()
{
    return GetAxisX();
}

Vector3 Quaternion::GetUpVector()
{
    return GetAxisY();
}

Vector3 Quaternion::GetDownVector()
{
    return -GetAxisY();
}

Vector3 Quaternion::GetForwardVector()
{
    return GetAxisZ();
}

Vector3 Quaternion::GetBackVector()
{
    return -GetAxisZ();
}

Vector3 Quaternion::RotateVector(Vector3 v)
{
    Vector3 result;
    
    Vector3 q = Vector3(x, y, z);
    Vector3 t = Vector3::CrossProduct(q, v) * 2.0;
    
    result = Vector3::CrossProduct(q, t) + (v + (t * w));
    
    return result;
}

Vector3 Quaternion::GetEulerAngles()
{
    Vector3 result;
    float test = (w * y - x * z) * 2.0;
    
    if (test >= 0.99999)
    {
        result.x = Math::Atan2(x, w) * 2.0;
        result.y = Math::PI * 0.5;
        result.z = 0.0;
        
        return result;
    }
    
    if (test <= -0.99999)
    {
        result.x = Math::Atan2(x, w) * 2.0;
        result.y = -Math::PI * 0.5;
        result.z = 0.0;
        
        return result;
    }
    
    result.x = Math::Atan2(2.0 * (w * x + y * z), 1.0 - 2.0 * (x * x + y * y));
    result.y = Math::Asin(test);
    result.z = Math::Atan2(2.0 * (w * z + x * y), 1.0 - 2.0 * (y * y + z * z));
    
    result = Vector3::Scale(result, Math::RadToDeg);
    
    return result;
}

Vector4 Quaternion::GetAxisAngle()
{
    Vector4 result;
    
    Vector3 axis = Vector3(x, y, z) / Math::Sqrt(1.0 - w * w);
    float angle = Math::ToDegrees(Math::Acos(w) * 2.0);
    
    return Vector4(axis, angle);
}

Quaternion Quaternion::SetFromEulerAngles(float x, float y, float z)
{
    Quaternion result;
    
    x = Math::ToRadians(x);
    y = Math::ToRadians(y);
    z = Math::ToRadians(z);
    
    float cx = Math::Cos(x * 0.5);
    float cy = Math::Cos(y * 0.5);
    float cz = Math::Cos(z * 0.5);
    
    float sx = Math::Sin(x * 0.5);
    float sy = Math::Sin(y * 0.5);
    float sz = Math::Sin(z * 0.5);
    
    result.x = sx * cy * cz - cx * sy * sz;
    result.y = cx * sy * cz + sx * cy * sz;
    result.z = cx * cy * sz - sx * sy * cz;
    result.w = cx * cy * cz + sx * sy * sz;
    
    return result;
}

Quaternion Quaternion::SetFromEulerAngles(Vector3 v)
{
        return SetFromEulerAngles(v.x, v.y, v.z);
}

Quaternion Quaternion::SetFromAxisAngle(Vector3 axis, float angle)
{
        Quaternion result;
    
        angle = Math::ToRadians(angle) * 0.5;
    
        float sin = Math::Sin(angle);
    
        result.x = sin * axis.x;
        result.y = sin * axis.y;
        result.z = sin * axis.z;
        result.w = Math::Cos(angle);
        
        return result;
}

Quaternion Quaternion::SetFromRotationMatrix(Matrix m)
{
    Quaternion result;
    
    float trace = m(0, 0) + m(1, 1) + m(2, 2);
    float s = 0.0;
    
    if (trace > 0.0)
    {
        s = 0.5 / Math::Sqrt(1.0 + trace);
        
        result.x = (m(2, 1) - m(1, 2)) * s;
        result.y = (m(0, 2) - m(2, 0)) * s;
        result.z = (m(1, 0) - m(0, 1)) * s;
        result.w = 0.25 / s;
    }
    else
    {
        if (m(0, 0) > m(1, 1) and m(0, 0) > m(2, 2))
        {
            s = 0.5 / Math::Sqrt(1.0 + m(0, 0) - m(1, 1) - m(2, 2));
            
            result.x = 0.25 / s;
            result.y = (m(0, 1) + m(1, 0)) * s;
            result.z = (m(2, 0) + m(0, 2)) * s;
            result.w = (m(2, 1) - m(1, 2)) * s;
        }
        else if (m(1, 1) > m(2, 2))
        {
            s = 0.5 / Math::Sqrt(1.0 + m(1, 1) - m(0, 0) - m(2, 2));
            
            result.x = (m(0, 1) + m(1, 0)) * s;
            result.y = 0.25 / s;
            result.z = (m(1, 2) + m(2, 1)) * s;
            result.w = (m(0, 2) - m(2, 0)) * s;
        }
        else
        {
            s = 0.5 / Math::Sqrt(1.0 + m(2, 2) - m(0, 0) - m(1, 1));
            
            result.x = (m(0, 2) + m(2, 0)) * s;
            result.y = (m(1, 2) + m(2, 1)) * s;
            result.z = 0.25 / s;
            result.w = (m(1, 0) - m(0, 1)) * s;
        }
    }
    
    return result;
}

Quaternion Quaternion::Inverse(Quaternion q)
{
        float lsq = LengthSquared(q);
        lsq = 1.0 / lsq;

        q.x = -q.x * lsq;
        q.y = -q.y * lsq;
        q.z = -q.z * lsq;
        q.w =  q.w * lsq;

        return q;
}

Quaternion Quaternion::Conjugate(Quaternion q)
{
        return Quaternion(-q.x, -q.y, -q.z, q.w);
}

Quaternion Quaternion::Exponential(Quaternion q)
{
        float angle = Math::Sqrt(q.x * q.x + q.y * q.y + q.z * q.z);
        float sa = Math::Sin(angle);
        float ca = Math::Cos(angle);
        
        if (Math::Fabs(sa) < 0.001)
        {
                return Quaternion(ca, q.x, q.y, q.z);
        }
        else
        {
                float ratio = sa / angle;
                return Quaternion(ca, q.x * ratio, q.y * ratio, q.z * ratio);
        }
}

Quaternion Quaternion::Logarithm(Quaternion q)
{
        if (Math::Fabs(q.w) < 1.0)
        {
                float angle = acos(q.w);
                float sin   = Math::Sin(angle);
            
                if (Math::Fabs(sin) >= 0.001)
                {
                        float ratio = angle / sin;
                        return Quaternion(0.0, q.x * ratio, q.y * ratio, q.z * ratio);
                }
        }
        
        return Quaternion(0.0, q.x, q.y, q.z);
}

Quaternion Quaternion::Power(Quaternion q, float e)
{
        Quaternion result;
        
        if (Math::Fabs(q.w) > 0.9999f)
        {
                return q;
        }
        
        float acos = Math::Acos(q.w);
        float alpha = acos * e;
        
        result.w = Math::Cos(alpha);
        
        float m = Math::Sin(alpha) / Math::Sin(acos);
        result.x = q.x * m;
        result.y = q.y * m;
        result.z = q.z * m;
        
        return result;
}

Quaternion Quaternion::GetNormalized(Quaternion q)
{
        Quaternion result;
        
        float length = Quaternion::Length(q);
        
        result.x = q.x / length;
        result.y = q.y / length;
        result.z = q.z / length;
        result.w = q.w / length;
        
        return result;
}

float Quaternion::AngleBetween(Quaternion a, Quaternion b)
{
        float dot = DotProduct(a, b);
        return Math::Acos(Math::Min(Math::Abs(dot), 1.0)) * 2.0 * Math::RadToDeg;
}

Quaternion Quaternion::LookRotation(Vector3 forward, Vector3 up)
{
    return Matrix::LookRotation(forward, up).GetQuaternion();
}

Quaternion Quaternion::LookAt(Vector3 from, Vector3 to, Vector3 up)
{
    return Matrix::LookAt(from, to, up).GetQuaternion();
}

float Quaternion::Length(Quaternion q)
{
        return Math::Sqrt((q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w)); // return Sqrt(DotProduct(q, q))
}

float Quaternion::LengthSquared(Quaternion q)
{
        return (q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w); // return DotProduct(q, q)
}

float Quaternion::DotProduct(Quaternion a, Quaternion b)
{
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

Quaternion Quaternion::Lerp(Quaternion a, Quaternion b, float alpha)
{
        Quaternion result;
        
        float inverse = 1.0f - alpha;
    
        if (Quaternion::DotProduct(a, b) >= 0.0f)
        {
            result.x = (inverse * a.x) + (alpha * b.x);
            result.y = (inverse * a.y) + (alpha * b.y);
            result.z = (inverse * a.z) + (alpha * b.z);
            result.w = (inverse * a.w) + (alpha * b.w);
        }
        else
        {
            result.x = (inverse * a.x) - (alpha * b.x);
            result.y = (inverse * a.y) - (alpha * b.y);
            result.z = (inverse * a.z) - (alpha * b.z);
            result.w = (inverse * a.w) - (alpha * b.w);
        }
        
        return result;
}

Quaternion Quaternion::Nlerp(Quaternion a, Quaternion b, float alpha)
{
    return Lerp(a, b, alpha).Normalize();
}

Quaternion Quaternion::Slerp(Quaternion a, Quaternion b, float alpha)
{
        float cos = DotProduct(a, b);
        
        Quaternion q;
        
        if (cos < float(0))
        {
                cos = -cos;
                q = -b;
        }
        else
        {
                q = b;
        }
        
        float f1;
        float f2;
        
        if ((1.0 - cos) > 0.001)
        {
                float angle = acos(cos);
                float sin   = Math::Sin(angle);
                f1 = Math::Sin((1.0 - alpha) * angle) / sin;
                f2 = Math::Sin(alpha * angle) / sin;
        }
        else
        {
                f1 = 1.0 - alpha;
                f2 = alpha;
        }
        
        return (a * f1 + q * f2).Normalize();
}

Quaternion Quaternion::Scale(Quaternion q, float scale)
{
        return Quaternion(q.x * scale, q.y * scale, q.z * scale, q.w * scale);
}

