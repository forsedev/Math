#pragma once

struct Vector3
{
        //-----------------------------------------------------------------------------
        // Fields
        //-----------------------------------------------------------------------------
        
        float x;
        float y;
        float z;
        
        //-----------------------------------------------------------------------------
        // Static Fields
        //-----------------------------------------------------------------------------
        
        const static Vector3 One;
        const static Vector3 Zero;
        const static Vector3 Left;
        const static Vector3 Right;
        const static Vector3 Up;
        const static Vector3 Down;
        const static Vector3 Forward;
        const static Vector3 Back;
        
        //-----------------------------------------------------------------------------
        // Constructors
        //-----------------------------------------------------------------------------
        
        Vector3();
        Vector3(const Vector3& v);
        Vector3(float x, float y, float z);
        
        //-----------------------------------------------------------------------------
        // Operators
        //-----------------------------------------------------------------------------
        
        Vector3& operator = (const Vector3& v);
        Vector3 operator - ();
        
        bool operator == (const Vector3& v);
        bool operator != (const Vector3& v);
        
        Vector3 operator + (const Vector3& v);
        Vector3 operator += (const Vector3& v);
        Vector3 operator + (const float& f);
        Vector3 operator += (const float& f);
        
        Vector3 operator - (const Vector3& v);
        Vector3 operator -= (const Vector3& v);
        Vector3 operator - (const float& f);
        Vector3 operator -= (const float& f);
        
        Vector3 operator * (const Vector3& v);
        Vector3 operator *= (const Vector3& v);
        Vector3 operator * (const float& f);
        Vector3 operator *= (const float& f);
        
        Vector3 operator / (const Vector3& v);
        Vector3 operator /= (const Vector3& v);
        Vector3 operator / (const float& f);
        Vector3 operator /= (const float& f);
        
        //-----------------------------------------------------------------------------
        // Public Methods
        //-----------------------------------------------------------------------------
        
        std::string ToString();
        Vector3 Negate();
        void Set(float x, float y, float z);
        bool Equals(Vector3 v);
        Vector3 Normalize();
        
        //-----------------------------------------------------------------------------
        // Static Methods
        //-----------------------------------------------------------------------------
        
        static Vector3 GetNormalized(Vector3 v);
        static float   AngleBetween(Vector3 a, Vector3 b);
        static Vector3 Min(Vector3 a, Vector3 b);
        static Vector3 Max(Vector3 a, Vector3 b);
        static float   Length(Vector3 v);
        static float   LengthSquared(Vector3 v);
        static float   Distance(Vector3 a, Vector3 b);
        static float   DistanceSquared(Vector3 a, Vector3 b);
        static Vector3 CrossProduct(Vector3 v1, Vector3 v2);
        static float   DotProduct(Vector3 a, Vector3 b);
        static Vector3 Lerp(Vector3 a, Vector3 b, float alpha);
        static Vector3 Nlerp(Vector3 a, Vector3 b, float alpha);
        static Vector3 Scale(Vector3 v, float scale);
        static Vector3 Clamp(Vector3 value, Vector3 min, Vector3 max);
        static void    OrthoNormalize(Vector3& normal, Vector3& tangent);
};

