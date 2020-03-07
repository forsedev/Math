#pragma once

struct Matrix;

struct Vector4
{
        //-----------------------------------------------------------------------------
        // Fields
        //-----------------------------------------------------------------------------
        
        float x;
        float y;
        float z;
        float w;
        
        //-----------------------------------------------------------------------------
        // Static Fields
        //-----------------------------------------------------------------------------
        
        const static Vector4 One;
        const static Vector4 Zero;
        
        //-----------------------------------------------------------------------------
        // Constructors
        //-----------------------------------------------------------------------------
        
        Vector4();
        Vector4(const Vector4& v);
        Vector4(const Vector3 v, float w);
        Vector4(float x, float y, float z, float w);
        
        //-----------------------------------------------------------------------------
        // Operators
        //-----------------------------------------------------------------------------
        
        Vector4& operator = (const Vector4& v);
        Vector4 operator - ();
        
        bool operator == (const Vector4& v);
        bool operator != (const Vector4& v);
        
        Vector4 operator + (const Vector4& v);
        Vector4 operator += (const Vector4& v);
        Vector4 operator + (const float& f);
        Vector4 operator += (const float& f);
        
        Vector4 operator - (const Vector4& v);
        Vector4 operator -= (const Vector4& v);
        Vector4 operator - (const float& f);
        Vector4 operator -= (const float& f);
        
        Vector4 operator * (const Vector4& v);
        Vector4 operator *= (const Vector4& v);
        Vector4 operator * (const Matrix& m);
        Vector4 operator *= (const Matrix& m);
        Vector4 operator * (const float& f);
        Vector4 operator *= (const float& f);
        
        Vector4 operator / (const Vector4& v);
        Vector4 operator /= (const Vector4& v);
        Vector4 operator / (const float& f);
        Vector4 operator /= (const float& f);

        //-----------------------------------------------------------------------------
        // Public Methods
        //-----------------------------------------------------------------------------
        
        std::string ToString();
        Vector4 Negate();
        void Set(float x, float y, float z, float w);
        bool Equals(Vector4 v);
        Vector4 Normalize();
        
        //-----------------------------------------------------------------------------
        // Static Methods
        //-----------------------------------------------------------------------------
        
        static Vector4  GetNormalized(Vector4 v);
        static Vector4  Min(Vector4 a, Vector4 b);
        static Vector4  Max(Vector4 a, Vector4 b);
        static float    Length(Vector4 v);
        static float    LengthSquared(Vector4 v);
        static float    Distance(Vector4 a, Vector4 b);
        static float    DistanceSquared(Vector4 a, Vector4 b);
        static float    DotProduct(Vector4 a, Vector4 b);
        static Vector4  Lerp(Vector4 a, Vector4 b, float alpha);
        static Vector4  NLerp(Vector4 a, Vector4 b, float alpha);
        static Vector4  Scale(Vector4 v, float scale);
        static Vector4  Clamp(Vector4 value, Vector4 min, Vector4 max);
};

