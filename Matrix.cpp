#include "Math.h"

const Matrix Matrix::Identity(Vector4(1.0, 0.0, 0.0, 0.0), Vector4(0.0, 1.0, 0.0, 0.0), Vector4(0.0, 0.0, 1.0, 0.0), Vector4(0.0, 0.0, 0.0, 1.0));
const Matrix Matrix::Zero(Vector4(0.0, 0.0, 0.0, 0.0), Vector4(0.0, 0.0, 0.0, 0.0), Vector4(0.0, 0.0, 0.0, 0.0), Vector4(0.0, 0.0, 0.0, 0.0));

const Matrix Matrix::MirrorX(Vector4(-1.0, 0.0, 0.0, 0.0), Vector4(0.0, 1.0, 0.0, 0.0), Vector4(0.0, 0.0, 1.0, 0.0), Vector4(0.0, 0.0, 0.0, 1.0));
const Matrix Matrix::MirrorY(Vector4(1.0, 0.0, 0.0, 0.0), Vector4(0.0, -1.0, 0.0, 0.0), Vector4(0.0, 0.0, 1.0, 0.0), Vector4(0.0, 0.0, 0.0, 1.0));
const Matrix Matrix::MirrorZ(Vector4(1.0, 0.0, 0.0, 0.0), Vector4(0.0, 1.0, 0.0, 0.0), Vector4(0.0, 0.0, -1.0, 0.0), Vector4(0.0, 0.0, 0.0, 1.0));

Matrix::Matrix()
{
        this->matrix[0][0] = 1.0; this->matrix[0][1] = 0.0; this->matrix[0][2] = 0.0; this->matrix[0][3] = 0.0;
        this->matrix[1][0] = 0.0; this->matrix[1][1] = 1.0; this->matrix[1][2] = 0.0; this->matrix[1][3] = 0.0;
        this->matrix[2][0] = 0.0; this->matrix[2][1] = 0.0; this->matrix[2][2] = 1.0; this->matrix[2][3] = 0.0;
        this->matrix[3][0] = 0.0; this->matrix[3][1] = 0.0; this->matrix[3][2] = 0.0; this->matrix[3][3] = 1.0;
}

Matrix::Matrix(const Matrix& m)
{
        this->matrix[0][0] = m(0, 0); this->matrix[0][1] = m(0, 1); this->matrix[0][2] = m(0, 2); this->matrix[0][3] = m(0, 3);
        this->matrix[1][0] = m(1, 0); this->matrix[1][1] = m(1, 1); this->matrix[1][2] = m(1, 2); this->matrix[1][3] = m(1, 3);
        this->matrix[2][0] = m(2, 0); this->matrix[2][1] = m(2, 1); this->matrix[2][2] = m(2, 2); this->matrix[2][3] = m(2, 3);
        this->matrix[3][0] = m(3, 0); this->matrix[3][1] = m(3, 1); this->matrix[3][2] = m(3, 2); this->matrix[3][3] = m(3, 3);
}

Matrix::Matrix(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4)
{
        this->matrix[0][0] = v1.x; this->matrix[0][1] = v1.y; this->matrix[0][2] = v1.z; this->matrix[0][3] = v1.w;
        this->matrix[1][0] = v2.x; this->matrix[1][1] = v2.y; this->matrix[1][2] = v2.z; this->matrix[1][3] = v2.w;
        this->matrix[2][0] = v3.x; this->matrix[2][1] = v3.y; this->matrix[2][2] = v3.z; this->matrix[2][3] = v3.w;
        this->matrix[3][0] = v4.x; this->matrix[3][1] = v4.y; this->matrix[3][2] = v4.z; this->matrix[3][3] = v4.w;
}

Matrix::Matrix(float m00, float m01, float m02, float m03,
           float m10, float m11, float m12, float m13,
           float m20, float m21, float m22, float m23,
           float m30, float m31, float m32, float m33)
{
        this->matrix[0][0] = m00; this->matrix[0][1] = m01; this->matrix[0][2] = m02; this->matrix[0][3] = m03;
        this->matrix[1][0] = m10; this->matrix[1][1] = m11; this->matrix[1][2] = m12; this->matrix[1][3] = m13;
        this->matrix[2][0] = m20; this->matrix[2][1] = m21; this->matrix[2][2] = m22; this->matrix[2][3] = m23;
        this->matrix[3][0] = m30; this->matrix[3][1] = m31; this->matrix[3][2] = m32; this->matrix[3][3] = m33;
}

float& Matrix::operator () (const int& row, const int& col)
{
        return this->matrix[row][col];
}

float Matrix::operator () (const int& row, const int& col) const
{
        return this->matrix[row][col];
}

Matrix& Matrix::operator = (const Matrix& m)
{
        this->matrix[0][0] = m(0, 0); this->matrix[0][1] = m(0, 1); this->matrix[0][2] = m(0, 2); this->matrix[0][3] = m(0, 3);
        this->matrix[1][0] = m(1, 0); this->matrix[1][1] = m(1, 1); this->matrix[1][2] = m(1, 2); this->matrix[1][3] = m(1, 3);
        this->matrix[2][0] = m(2, 0); this->matrix[2][1] = m(2, 1); this->matrix[2][2] = m(2, 2); this->matrix[2][3] = m(2, 3);
        this->matrix[3][0] = m(3, 0); this->matrix[3][1] = m(3, 1); this->matrix[3][2] = m(3, 2); this->matrix[3][3] = m(3, 3);
        
        return *this;
}

Matrix Matrix::operator-()
{
    Matrix result;
    
    result(0, 0) = -matrix[0][0];
    result(1, 0) = -matrix[1][0];
    result(2, 0) = -matrix[2][0];
    result(3, 0) = -matrix[3][0];
    
    result(0, 1) = -matrix[0][1];
    result(1, 1) = -matrix[1][1];
    result(2, 1) = -matrix[2][1];
    result(3, 1) = -matrix[3][1];
    
    result(0, 2) = -matrix[0][2];
    result(1, 2) = -matrix[1][2];
    result(2, 2) = -matrix[2][2];
    result(3, 2) = -matrix[3][2];
    
    result(0, 3) = -matrix[0][3];
    result(1, 3) = -matrix[1][3];
    result(2, 3) = -matrix[2][3];
    result(3, 3) = -matrix[3][3];
    
    return result;
}

bool Matrix::operator==(const Matrix& m)
{
        return matrix[0][0] == m(0, 0) and matrix[0][1] == m(0, 1) and matrix[0][2] == m(0, 2) and matrix[0][3] == m(0, 3) and
               matrix[1][0] == m(1, 0) and matrix[1][1] == m(1, 1) and matrix[1][2] == m(1, 2) and matrix[1][3] == m(1, 3) and
               matrix[2][0] == m(2, 0) and matrix[2][1] == m(2, 1) and matrix[2][2] == m(2, 2) and matrix[2][3] == m(2, 3) and
               matrix[3][0] == m(3, 0) and matrix[3][1] == m(3, 1) and matrix[3][2] == m(3, 2) and matrix[3][3] == m(3, 3);
}

bool Matrix::operator!=(const Matrix& m)
{
        return !(*this == m);
}

Matrix Matrix::operator+(const Matrix& m)
{
        Matrix result;
        
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
                for (unsigned int j = 0 ; j < 4 ; j++)
                {
                        result.matrix[i][j] = matrix[i][j] + m(i, j);
                }
        }
        
        return result;
}

Matrix Matrix::operator+=(const Matrix& m)
{
        *this = (*this) + m;
        return (*this);
}

Matrix Matrix::operator+(const float& f)
{
        Matrix result;
        
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
                for (unsigned int j = 0 ; j < 4 ; j++)
                {
                        result.matrix[i][j] = matrix[i][j] + f;
                }
        }
        
        return result;
}

Matrix Matrix::operator+=(const float& f)
{
        *this = (*this) + f;
        return (*this);
}

Matrix Matrix::operator-(const Matrix& m)
{
        Matrix result;
        
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
                for (unsigned int j = 0 ; j < 4 ; j++)
                {
                        result.matrix[i][j] = matrix[i][j] - m(i, j);
                }
        }
        
        return result;
}

Matrix Matrix::operator-=(const Matrix& m)
{
        *this = (*this) - m;
        return (*this);
}

Matrix Matrix::operator-(const float& f)
{
        Matrix result;
        
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
                for (unsigned int j = 0 ; j < 4 ; j++)
                {
                        result.matrix[i][j] = matrix[i][j] - f;
                }
        }
        
        return result;
}

Matrix Matrix::operator-=(const float& f)
{
        *this = (*this) - f;
        return (*this);
}

Matrix Matrix::operator*(const Matrix& m)
{
        Matrix result;
        
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
                for (unsigned int j = 0 ; j < 4 ; j++)
                {
                        result.matrix[i][j] =
                        matrix[i][0] * m(0, j) +
                        matrix[i][1] * m(1, j) +
                        matrix[i][2] * m(2, j) +
                        matrix[i][3] * m(3, j);
                }
        }
        
        return result;
}

Matrix Matrix::operator*=(const Matrix& m)
{
        *this = (*this) * m;
        return (*this);
}

Vector4 Matrix::operator*(const Vector4& v)
{
    Vector4 result;
    
    result.x = matrix[0][0] * v.x + matrix[0][1] * v.y + matrix[0][2] * v.z + matrix[0][3] * v.w;
    result.y = matrix[1][0] * v.x + matrix[1][1] * v.y + matrix[1][2] * v.z + matrix[1][3] * v.w;
    result.z = matrix[2][0] * v.x + matrix[2][1] * v.y + matrix[2][2] * v.z + matrix[2][3] * v.w;
    result.w = matrix[3][0] * v.x + matrix[3][1] * v.y + matrix[3][2] * v.z + matrix[3][3] * v.w;
    
    return result;
}

Matrix Matrix::operator*(const float& f)
{
        Matrix result;
        
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
                for (unsigned int j = 0 ; j < 4 ; j++)
                {
                        result.matrix[i][j] = matrix[i][j] * f;
                }
        }
        
        return result;
}

Matrix Matrix::operator*=(const float& f)
{
        *this = (*this) * f;
        return (*this);
}

Matrix Matrix::operator/(const float& f)
{
        Matrix result;
    
        float inv = 1.0 / f;
    
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
                for (unsigned int j = 0 ; j < 4 ; j++)
                {
                        result.matrix[i][j] = matrix[i][j] * inv;
                }
        }
        
        return result;
}

Matrix Matrix::operator/=(const float& f)
{
        *this = (*this) / f;
        return (*this);
}

std::string Matrix::ToString()
{
        std::string result;
        
        result += std::to_string(matrix[0][0]) + "\t" + std::to_string(matrix[0][1]) + "\t" + std::to_string(matrix[0][2]) + "\t" + std::to_string(matrix[0][3]) + "\n";
        result += std::to_string(matrix[1][0]) + "\t" + std::to_string(matrix[1][1]) + "\t" + std::to_string(matrix[1][2]) + "\t" + std::to_string(matrix[1][3]) + "\n";
        result += std::to_string(matrix[2][0]) + "\t" + std::to_string(matrix[2][1]) + "\t" + std::to_string(matrix[2][2]) + "\t" + std::to_string(matrix[2][3]) + "\n";
        result += std::to_string(matrix[3][0]) + "\t" + std::to_string(matrix[3][1]) + "\t" + std::to_string(matrix[3][2]) + "\t" + std::to_string(matrix[3][3]);
        
        return result;
}

Matrix Matrix::Negate()
{
    matrix[0][0] = -matrix[0][0];
    matrix[1][0] = -matrix[1][0];
    matrix[2][0] = -matrix[2][0];
    matrix[3][0] = -matrix[3][0];
    
    matrix[0][1] = -matrix[0][1];
    matrix[1][1] = -matrix[1][1];
    matrix[2][1] = -matrix[2][1];
    matrix[3][1] = -matrix[3][1];
    
    matrix[0][2] = -matrix[0][2];
    matrix[1][2] = -matrix[1][2];
    matrix[2][2] = -matrix[2][2];
    matrix[3][2] = -matrix[3][2];
    
    matrix[0][3] = -matrix[0][3];
    matrix[1][3] = -matrix[1][3];
    matrix[2][3] = -matrix[2][3];
    matrix[3][3] = -matrix[3][3];
    
    return *this;
}

void Matrix::SetRow(int index, Vector4 value)
{
    if (index >= 0 and index <= 3)
    {
        matrix[index][0] = value.x;
        matrix[index][1] = value.y;
        matrix[index][2] = value.z;
        matrix[index][3] = value.w;
    }
}

Vector4 Matrix::GetRow(int index)
{
    Vector4 result;
    
    result.x = matrix[index][0];
    result.y = matrix[index][1];
    result.z = matrix[index][2];
    result.w = matrix[index][3];
    
    return result;
}

void Matrix::SetColumn(int index, Vector4 value)
{
    if (index >= 0 and index <= 3)
    {
        matrix[0][index] = value.x;
        matrix[1][index] = value.y;
        matrix[2][index] = value.z;
        matrix[3][index] = value.w;
    }
}

Vector4 Matrix::GetColumn(int index)
{
    Vector4 result;
    
    result.x = matrix[0][index];
    result.y = matrix[1][index];
    result.z = matrix[2][index];
    result.w = matrix[3][index];
    
    return result;
}

Vector3 Matrix::GetLeftVector()
{
    return -GetAxisX();
}

Vector3 Matrix::GetRightVector()
{
    return GetAxisX();
}

Vector3 Matrix::GetUpVector()
{
    return GetAxisY();
}

Vector3 Matrix::GetDownVector()
{
    return -GetAxisY();
}

Vector3 Matrix::GetForwardVector()
{
    return GetAxisZ();
}

Vector3 Matrix::GetBackVector()
{
    return -GetAxisZ();
}

Vector3 Matrix::GetTranslation()
{
    Vector3 result;
    
    result.x = matrix[0][3];
    result.y = matrix[1][3];
    result.z = matrix[2][3];
    
    return result;
}

Matrix Matrix::GetRotationMatrix()
{
    Matrix result;
    Vector3 scale = GetScale();
    
    scale.x = 1.0 / scale.x;
    scale.y = 1.0 / scale.y;
    scale.z = 1.0 / scale.z;
    
    result(0, 0) = matrix[0][0] * scale.x;
    result(1, 0) = matrix[1][0] * scale.x;
    result(2, 0) = matrix[2][0] * scale.x;
    
    result(0, 1) = matrix[0][1] * scale.y;
    result(1, 1) = matrix[1][1] * scale.y;
    result(2, 1) = matrix[2][1] * scale.y;
    
    result(0, 2) = matrix[0][2] * scale.z;
    result(1, 2) = matrix[1][2] * scale.z;
    result(2, 2) = matrix[2][2] * scale.z;
    
    return result;
}

Quaternion Matrix::GetQuaternion()
{    
    Quaternion result;
    Matrix rotate = GetRotationMatrix();
    
    float trace = rotate(0, 0) + rotate(1, 1) + rotate(2, 2);
    float s = 0.0;
    
    if (trace > 0.0)
    {
        s = 0.5 / Math::Sqrt(1.0 + trace);
        
        result.x = (rotate(2, 1) - rotate(1, 2)) * s;
        result.y = (rotate(0, 2) - rotate(2, 0)) * s;
        result.z = (rotate(1, 0) - rotate(0, 1)) * s;
        result.w = 0.25 / s;
    }
    else
    {
        if (rotate(0, 0) > rotate(1, 1) and rotate(0, 0) > rotate(2, 2))
        {
            s = 0.5 / Math::Sqrt(1.0 + rotate(0, 0) - rotate(1, 1) - rotate(2, 2));
            
            result.x = 0.25 / s;
            result.y = (rotate(0, 1) + rotate(1, 0)) * s;
            result.z = (rotate(2, 0) + rotate(0, 2)) * s;
            result.w = (rotate(2, 1) - rotate(1, 2)) * s;
        }
        else if (rotate(1, 1) > rotate(2, 2))
        {
            s = 0.5 / Math::Sqrt(1.0 + rotate(1, 1) - rotate(0, 0) - rotate(2, 2));
            
            result.x = (rotate(0, 1) + rotate(1, 0)) * s;
            result.y = 0.25 / s;
            result.z = (rotate(1, 2) + rotate(2, 1)) * s;
            result.w = (rotate(0, 2) - rotate(2, 0)) * s;
        }
        else
        {
            s = 0.5 / Math::Sqrt(1.0 + rotate(2, 2) - rotate(0, 0) - rotate(1, 1));
            
            result.x = (rotate(0, 2) + rotate(2, 0)) * s;
            result.y = (rotate(1, 2) + rotate(2, 1)) * s;
            result.z = 0.25 / s;
            result.w = (rotate(1, 0) - rotate(0, 1)) * s;
        }
    }
    
    return result;
}

Vector3 Matrix::GetEulerAngles()
{
        Vector3 result;
        Matrix rotate = GetRotationMatrix();
    
        result.y = Math::Asin(-Math::Clamp(rotate(2, 0), -1.0, 1.0));
    
        if (Math::Fabs(rotate(2, 0)) < 0.999999)
        {
            result.x = Math::Atan2(rotate(2, 1), rotate(2, 2));
            result.z = Math::Atan2(rotate(1, 0), rotate(0, 0));
        }
        else
        {
            result.x = 0.0;
            result.z = Math::Atan2(-rotate(0, 1), rotate(1, 1));
        }
    
        result.x = Math::ToDegrees(result.x);
        result.y = Math::ToDegrees(result.y);
        result.z = Math::ToDegrees(result.z);
    
        return result;
}

Vector4 Matrix::GetAxisAngle()
{
    Vector4 result;
    
    Quaternion q = GetQuaternion();
    
    Vector3 axis;
    float angle = 2.0 * Math::Acos(q.w);
    
    if (1.0 - (q.w * q.w) < 0.000001)
    {
        axis.x = q.x;
        axis.y = q.y;
        axis.z = q.z;
    }
    else
    {
        float s = Math::Sqrt(1.0 - (q.w * q.w));
        
        axis.x = q.x / s;
        axis.y = q.y / s;
        axis.z = q.z / s;
    }
    
    return Vector4(axis.x, axis.y, axis.z, Math::ToDegrees(angle));
}

Vector3 Matrix::GetAxisX()
{
        Vector3 result;
    
        result.x = matrix[0][0];
        result.y = matrix[1][0];
        result.z = matrix[2][0];
    
        return result;
}

Vector3 Matrix::GetAxisY()
{
        Vector3 result;
        
        result.x = matrix[0][1];
        result.y = matrix[1][1];
        result.z = matrix[2][1];
        
        return result;
}

Vector3 Matrix::GetAxisZ()
{
        Vector3 result;
    
        result.x = matrix[0][2];
        result.y = matrix[1][2];
        result.z = matrix[2][2];
    
        return result;
}

Vector3 Matrix::GetScale()
{
        Vector3 result;
        
        result.x = Vector3::Length(GetAxisX());
        result.y = Vector3::Length(GetAxisY());
        result.z = Vector3::Length(GetAxisZ());
        
        return result;
}

float Matrix::Determinant(Matrix m)
{
    float a = m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0);
    float b = m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0);
    float c = m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0);
    float d = m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1);
    float e = m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1);
    float f = m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2);
    
    float tmp0 =  (f * m(1, 1) - e * m(1, 2) + d * m(1, 3));
    float tmp1 = -(f * m(1, 0) - c * m(1, 2) + b * m(1, 3));
    float tmp2 =  (e * m(1, 0) - c * m(1, 1) + a * m(1, 3));
    float tmp3 = -(d * m(1, 0) - b * m(1, 1) + a * m(1, 2));
    
    return tmp0 * m(0, 0) + tmp1 * m(0, 1) + tmp2 * m(0, 2) + tmp3 * m(0, 3);
}

Matrix Matrix::Adjugate(Matrix m)
{
        return {m(1, 1) * m(2, 2) * m(3, 3) + m(3, 1) * m(1, 2) * m(2, 3) + m(2, 1) * m(3, 2) * m(1, 3) - m(1, 1) * m(3, 2) * m(2, 3) - m(2, 1) * m(1, 2) * m(3, 3) - m(3, 1) * m(2, 2) * m(1, 3),
                m(0, 1) * m(3, 2) * m(2, 3) + m(2, 1) * m(0, 2) * m(3, 3) + m(3, 1) * m(2, 2) * m(0, 3) - m(3, 1) * m(0, 2) * m(2, 3) - m(2, 1) * m(3, 2) * m(0, 3) - m(0, 1) * m(2, 2) * m(3, 3),
                m(0, 1) * m(1, 2) * m(3, 3) + m(3, 1) * m(0, 2) * m(1, 3) + m(1, 1) * m(3, 2) * m(0, 3) - m(0, 1) * m(3, 2) * m(1, 3) - m(1, 1) * m(0, 2) * m(3, 3) - m(3, 1) * m(1, 2) * m(0, 3),
                m(0, 1) * m(2, 2) * m(1, 3) + m(1, 1) * m(0, 2) * m(2, 3) + m(2, 1) * m(1, 2) * m(0, 3) - m(0, 1) * m(1, 2) * m(2, 3) - m(2, 1) * m(0, 2) * m(1, 3) - m(1, 1) * m(2, 2) * m(0, 3),
                
                m(1, 2) * m(3, 3) * m(2, 0) + m(2, 2) * m(1, 3) * m(3, 0) + m(3, 2) * m(2, 3) * m(1, 0) - m(1, 2) * m(2, 3) * m(3, 0) - m(3, 2) * m(1, 3) * m(2, 0) - m(2, 2) * m(3, 3) * m(1, 0),
                m(0, 2) * m(2, 3) * m(3, 0) + m(3, 2) * m(0, 3) * m(2, 0) + m(2, 2) * m(3, 3) * m(0, 0) - m(0, 2) * m(3, 3) * m(2, 0) - m(2, 2) * m(0, 3) * m(3, 0) - m(3, 2) * m(2, 3) * m(0, 0),
                m(0, 2) * m(3, 3) * m(1, 0) + m(1, 2) * m(0, 3) * m(3, 0) + m(3, 2) * m(1, 3) * m(0, 0) - m(0, 2) * m(1, 3) * m(3, 0) - m(3, 2) * m(0, 3) * m(1, 0) - m(1, 2) * m(3, 3) * m(0, 0),
                m(0, 2) * m(1, 3) * m(2, 0) + m(2, 2) * m(0, 3) * m(1, 0) + m(1, 2) * m(2, 3) * m(0, 0) - m(0, 2) * m(2, 3) * m(1, 0) - m(1, 2) * m(0, 3) * m(2, 0) - m(2, 2) * m(1, 3) * m(0, 0),
                
                m(1, 3) * m(2, 0) * m(3, 1) + m(3, 3) * m(1, 0) * m(2, 1) + m(2, 3) * m(3, 0) * m(1, 1) - m(1, 3) * m(3, 0) * m(2, 1) - m(2, 3) * m(1, 0) * m(3, 1) - m(3, 3) * m(2, 0) * m(1, 1),
                m(0, 3) * m(3, 0) * m(2, 1) + m(2, 3) * m(0, 0) * m(3, 1) + m(3, 3) * m(2, 0) * m(0, 1) - m(0, 3) * m(2, 0) * m(3, 1) - m(3, 3) * m(0, 0) * m(2, 1) - m(2, 3) * m(3, 0) * m(0, 1),
                m(0, 3) * m(1, 0) * m(3, 1) + m(3, 3) * m(0, 0) * m(1, 1) + m(1, 3) * m(3, 0) * m(0, 1) - m(0, 3) * m(3, 0) * m(1, 1) - m(1, 3) * m(0, 0) * m(3, 1) - m(3, 3) * m(1, 0) * m(0, 1),
                m(0, 3) * m(2, 0) * m(1, 1) + m(1, 3) * m(0, 0) * m(2, 1) + m(2, 3) * m(1, 0) * m(0, 1) - m(0, 3) * m(1, 0) * m(2, 1) - m(2, 3) * m(0, 0) * m(1, 1) - m(1, 3) * m(2, 0) * m(0, 1),
                
                m(1, 0) * m(3, 1) * m(2, 2) + m(2, 0) * m(1, 1) * m(3, 2) + m(3, 0) * m(2, 1) * m(1, 2) - m(1, 0) * m(2, 1) * m(3, 2) - m(3, 0) * m(1, 1) * m(2, 2) - m(2, 0) * m(3, 1) * m(1, 2),
                m(0, 0) * m(2, 1) * m(3, 2) + m(3, 0) * m(0, 1) * m(2, 2) + m(2, 0) * m(3, 1) * m(0, 2) - m(0, 0) * m(3, 1) * m(2, 2) - m(2, 0) * m(0, 1) * m(3, 2) - m(3, 0) * m(2, 1) * m(0, 2),
                m(0, 0) * m(3, 1) * m(1, 2) + m(1, 0) * m(0, 1) * m(3, 2) + m(3, 0) * m(1, 1) * m(0, 2) - m(0, 0) * m(1, 1) * m(3, 2) - m(3, 0) * m(0, 1) * m(1, 2) - m(1, 0) * m(3, 1) * m(0, 2),
                m(0, 0) * m(1, 1) * m(2, 2) + m(2, 0) * m(0, 1) * m(1, 2) + m(1, 0) * m(2, 1) * m(0, 2) - m(0, 0) * m(2, 1) * m(1, 2) - m(1, 0) * m(0, 1) * m(2, 2) - m(2, 0) * m(1, 1) * m(0, 2)};
}

Matrix Matrix::Inverse(Matrix m)
{
    float determinant = Determinant(m);
    
    if (determinant != 0.0)
    {
        return Adjugate(m) / determinant;
    }
    
    return Identity;
}

Matrix Matrix::Transpose(Matrix m)
{
        Matrix result;
        
        result(0, 0) = m(0, 0);
        result(1, 0) = m(0, 1);
        result(2, 0) = m(0, 2);
        result(3, 0) = m(0, 3);
    
        result(0, 1) = m(1, 0);
        result(1, 1) = m(1, 1);
        result(2, 1) = m(1, 2);
        result(3, 1) = m(1, 3);
    
        result(0, 2) = m(2, 0);
        result(1, 2) = m(2, 1);
        result(2, 2) = m(2, 2);
        result(3, 2) = m(2, 3);
    
        result(0, 3) = m(3, 0);
        result(1, 3) = m(3, 1);
        result(2, 3) = m(3, 2);
        result(3, 3) = m(3, 3);
        
        return result;
}

Matrix Matrix::Billboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 cameraUpVector, Vector3 cameraForwardVector)
{
    Matrix result;
    
    Vector3 crossed;
    Vector3 finalVec;
    Vector3 difference = objectPosition - cameraPosition;
    
    float lengthsq = Vector3::LengthSquared(difference);
    
    if (lengthsq < 1e-6f)
        difference = -cameraForwardVector;
    else
        difference *= (float)(1.0 / Math::Sqrt(lengthsq));
    
    crossed = Vector3::CrossProduct(cameraUpVector, difference);
    crossed.Normalize();
    finalVec = Vector3::CrossProduct(difference, crossed);
    
    result(0, 0) = crossed.z;
    result(1, 0) = crossed.y;
    result(2, 0) = crossed.z;
    
    result(0, 1) = finalVec.x;
    result(1, 1) = finalVec.y;
    result(2, 1) = finalVec.z;
    
    result(0, 2) = difference.x;
    result(1, 2) = difference.y;
    result(2, 2) = difference.z;
    
    result(0, 3) = objectPosition.x;
    result(1, 3) = objectPosition.y;
    result(2, 3) = objectPosition.z;
    
    return result;
}

Matrix Matrix::Frustum(float left, float right, float bottom, float top, float near, float far)
{
    Matrix result = Matrix::Zero;
    
    float a = 2.0 * near;
    float b = right - left;
    float c = top - bottom;
    float d = far - near;
    
    result(0, 0) = a / b;
    result(1, 1) = a / c;
    result(0, 2) = (right + left) / b;
    result(1, 2) = (top + bottom) / c;
    result(2, 2) = (far + near) / d;
    result(3, 2) = 1.0;
    result(2, 3) = -(a * far) / d;
    
    return result;
}

Matrix Matrix::Perspective(float fov, float aspect, float near, float far)
{
    Matrix result = Matrix::Zero;
    
    float a = Math::Tan(fov / 2.0);
    float b = far - near;
    
    result(0, 0) = 1.0 / (aspect * a);
    result(1, 1) = 1.0 / a;
    result(2, 2) = (far + near) / b;
    
    result(3, 2) = 1.0;
    result(2, 3) = -(2.0 * near * far) / b;
    
    return result;
}

Matrix Matrix::Orthogonal(float left, float right, float bottom, float top, float near, float far)
{
    Matrix result;
    
    float a = right - left;
    float b = top - bottom;
    float c = far - near;
    
    result(0, 0) = 2.0 / a;
    result(1, 1) = 2.0 / b;
    result(2, 2) = 2.0 / c;
    
    result(0, 3) = -(right + left) / a;
    result(1, 3) = -(top + bottom) / b;
    result(2, 3) = -(far + near) / c;
    
    return result;
}

Matrix Matrix::LookRotation(Vector3 forward, Vector3 up)
{
    Matrix result;
    
    Vector3 x;
    Vector3 y;
    Vector3 z;
    
    z = forward;
    
    if (Vector3::LengthSquared(z) == 0.0)
    {
        z.z = 1.0;
    }
    
    z.Normalize();
    x = Vector3::CrossProduct(up, z);
    
    if (Vector3::LengthSquared(x) == 0.0)
    {
        if (Math::Fabs(up.z) == 1.0)
        {
            z.x += 0.0001;
        }
        else
        {
            z.z += 0.0001;
        }
        
        z.Normalize();
        x = Vector3::CrossProduct(up, z);
    }
    
    x.Normalize();
    y = Vector3::CrossProduct(z, x);
    
    result(0, 0) = x.x; result(0, 1) = y.x; result(0, 2) = z.x;
    result(1, 0) = x.y; result(1, 1) = y.y; result(1, 2) = z.y;
    result(2, 0) = x.z; result(2, 1) = y.z; result(2, 2) = z.z;
    
    return result;
}

Matrix Matrix::LookAt(Vector3 from, Vector3 to, Vector3 up)
{
    Matrix result;

    Vector3 x;
    Vector3 y;
    Vector3 z;

    z = to - from;

    if (Vector3::LengthSquared(z) == 0.0)
    {
        z.z = 1.0;
    }

    z.Normalize();
    x = Vector3::CrossProduct(up, z);

    if (Vector3::LengthSquared(x) == 0.0)
    {
        if (Math::Fabs(up.z) == 1.0)
        {
            z.x += 0.0001;
        }
        else
        {
            z.z += 0.0001;
        }

        z.Normalize();
        x = Vector3::CrossProduct(up, z);
    }

    x.Normalize();
    y = Vector3::CrossProduct(z, x);

    result(0, 0) = x.x; result(0, 1) = y.x; result(0, 2) = z.x; result(0, 3) = from.x;
    result(1, 0) = x.y; result(1, 1) = y.y; result(1, 2) = z.y; result(1, 3) = from.y;
    result(2, 0) = x.z; result(2, 1) = y.z; result(2, 2) = z.z; result(2, 3) = from.z;

    return result;
}

Matrix Matrix::SetTransform(Matrix translation, Matrix rotation, Matrix scale)
{
        return translation * rotation * scale;
}

Matrix Matrix::SetTransform(Vector3 translation, Vector3 rotation, Vector3 scale)
{
        Matrix translationMatrix = SetTranslation(translation);
        Matrix rotationMatrix = SetFromEulerAngles(rotation);
        Matrix scaleMatrix = SetScale(scale);
        
        return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix Matrix::SetTransform(Vector3 translation, Quaternion rotation, Vector3 scale)
{
        Matrix translationMatrix = SetTranslation(translation);
        Matrix rotationMatrix = SetFromQuaternion(rotation);
        Matrix scaleMatrix = SetScale(scale);
        
        return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix Matrix::SetDefaultTranslation()
{
        return SetTranslation(0.0, 0.0, 0.0);
}

Matrix Matrix::SetTranslation(float x, float y, float z)
{
        Matrix result;
        
        result(0, 3) = x;
        result(1, 3) = y;
        result(2, 3) = z;
        
        return result;
}

Matrix Matrix::SetTranslation(Vector3 v)
{
        return SetTranslation(v.x, v.y, v.z);
}

Matrix Matrix::SetDefaultRotation()
{
        return SetFromQuaternion(Quaternion::Identity);
}

Matrix Matrix::SetFromAxisX(float angle)
{
    Matrix result;
    
    angle = Math::ToRadians(angle);
    float cos = Math::Cos(angle);
    float sin = Math::Sin(angle);
    
    result(1, 1) = cos;
    result(2, 1) = sin;
    result(1, 2) = -sin;
    result(2, 2) = cos;
    
    return result;
}

Matrix Matrix::SetFromAxisY(float angle)
{
    Matrix result;
    
    angle = Math::ToRadians(angle);
    float cos = Math::Cos(angle);
    float sin = Math::Sin(angle);
    
    result(0, 0) = cos;
    result(2, 0) = -sin;
    result(0, 2) = sin;
    result(2, 2) = cos;
    
    return result;
}

Matrix Matrix::SetFromAxisZ(float angle)
{
    Matrix result;
    
    angle = Math::ToRadians(angle);
    float cos = Math::Cos(angle);
    float sin = Math::Sin(angle);
    
    result(0, 0) = cos;
    result(1, 0) = sin;
    result(0, 1) = -sin;
    result(1, 1) = cos;
    
    return result;
}

Matrix Matrix::SetFromEulerAngles(float x, float y, float z)
{
    Matrix result;
    
    x = Math::ToRadians(x);
    y = Math::ToRadians(y);
    z = Math::ToRadians(z);
    
    float cx = Math::Cos(x);
    float cy = Math::Cos(y);
    float cz = Math::Cos(z);
    float sx = Math::Sin(x);
    float sy = Math::Sin(y);
    float sz = Math::Sin(z);
    
    float a = cx * cz;
    float b = cx * sz;
    float c = sx * cz;
    float d = sx * sz;
    
    result(0, 0) = cy * cz;
    result(1, 0) = cy * sz;
    result(2, 0) = -sy;
    
    result(0, 1) = c * sy - b;
    result(1, 1) = d * sy + a;
    result(2, 1) = sx * cy;
    
    result(0, 2) = a * sy + d;
    result(1, 2) = b * sy - c;
    result(2, 2) = cx * cy;
    
    return result;
}

Matrix Matrix::SetFromEulerAngles(Vector3 euler)
{
        return SetFromEulerAngles(euler.x, euler.y, euler.z);
}

Matrix Matrix::SetFromAxisAngle(Vector3 axis, float angle)
{
        Matrix result;
        
        angle = Math::ToRadians(angle);
        float cos = Math::Cos(angle);
        float sin = Math::Sin(angle);
        float t = 1.0 - cos;
        float tx = t * axis.x;
        float ty = t * axis.y;
    
        result(0, 0) = tx * axis.x + cos;
        result(1, 0) = tx * axis.y + sin * axis.z;
        result(2, 0) = tx * axis.z - sin * axis.y;

        result(0, 1) = tx * axis.y - sin * axis.z;
        result(1, 1) = ty * axis.y + cos;
        result(2, 1) = ty * axis.z + sin * axis.x;

        result(0, 2) = tx * axis.z + sin * axis.y;
        result(1, 2) = ty * axis.z - axis.x * sin;
        result(2, 2) = t *  axis.z * axis.z + cos;
    
        return result;
}

Matrix Matrix::SetFromQuaternion(Quaternion q)
{
        Matrix result;
    
        float x2 = q.x + q.x;
        float y2 = q.y + q.y;
        float z2 = q.z + q.z;
    
        float xx = q.x * x2;
        float xy = q.x * y2;
        float xz = q.x * z2;
        float yy = q.y * y2;
        float yz = q.y * z2;
        float zz = q.z * z2;
        float wx = q.w * x2;
        float wy = q.w * y2;
        float wz = q.w * z2;
    
        result(0, 0) = 1 - (yy + zz);
        result(1, 0) = xy + wz;
        result(2, 0) = xz - wy;

        result(0, 1) = xy - wz;
        result(1, 1) = 1 - (xx + zz);
        result(2, 1) = yz + wx;

        result(0, 2) = xz + wy;
        result(1, 2) = yz - wx;
        result(2, 2) = 1 - (xx + yy);
    
        return result;
}

Matrix Matrix::SetDefaultScale()
{
        return SetScale(1.0, 1.0, 1.0);
}

Matrix Matrix::SetScale(float x, float y, float z)
{
        Matrix result;
        
        result(0, 0) = x;
        result(1, 1) = y;
        result(2, 2) = z;
        
        return result;
}

Matrix Matrix::SetScale(Vector3 v)
{
        return SetScale(v.x, v.y, v.z);
}

