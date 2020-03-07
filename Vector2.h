#pragma once

struct Vector2
{
        //-----------------------------------------------------------------------------
        // Fields
        //-----------------------------------------------------------------------------
        
        float x;
        float y;
    
        //-----------------------------------------------------------------------------
        // Static Fields
        //-----------------------------------------------------------------------------
        
        const static Vector2 One;
        const static Vector2 Zero;
        const static Vector2 Left;
        const static Vector2 Right;
        const static Vector2 Up;
        const static Vector2 Down;
    
        //-----------------------------------------------------------------------------
        // Constructors
        //-----------------------------------------------------------------------------
        
        Vector2();
        Vector2(const Vector2& v);
        Vector2(float x, float y);
    
        //-----------------------------------------------------------------------------
        // Operators
        //-----------------------------------------------------------------------------
        
        Vector2& operator = (const Vector2& v);
        Vector2 operator - ();
        
        bool operator == (const Vector2& v);
        bool operator != (const Vector2& v);
        
        Vector2 operator + (const Vector2& v);
        Vector2 operator += (const Vector2& v);
        Vector2 operator + (const float& f);
        Vector2 operator += (const float& f);
        
        Vector2 operator - (const Vector2& v);
        Vector2 operator -= (const Vector2& v);
        Vector2 operator - (const float& f);
        Vector2 operator -= (const float& f);
        
        Vector2 operator * (const Vector2& v);
        Vector2 operator *= (const Vector2& v);
        Vector2 operator * (const float& f);
        Vector2 operator *= (const float& f);
        
        Vector2 operator / (const Vector2& v);
        Vector2 operator /= (const Vector2& v);
        Vector2 operator / (const float& f);
        Vector2 operator /= (const float& f);
    
        //-----------------------------------------------------------------------------
        // Public Methods
        //-----------------------------------------------------------------------------
        
        std::string ToString();
        Vector2 Negate();
        void Set(float x, float y);
        bool Equals(Vector2 v);
        Vector2 Normalize();
    
        //-----------------------------------------------------------------------------
        // Static Methods
        //-----------------------------------------------------------------------------
        
        static Vector2 GetNormalized(Vector2 v);
        static float   AngleBetween(Vector2 a, Vector2 b);
        static Vector2 Min(Vector2 a, Vector2 b);
        static Vector2 Max(Vector2 a, Vector2 b);
        static float   Length(Vector2 v);
        static float   LengthSquared(Vector2 v);
        static float   Distance(Vector2 a, Vector2 b);
        static float   DistanceSquared(Vector2 a, Vector2 b);
        static float   CrossProduct(Vector2 a, Vector2 b);
        static float   DotProduct(Vector2 a, Vector2 b);
        static Vector2 Lerp(Vector2 a, Vector2 b, float alpha);
        static Vector2 Nlerp(Vector2 a, Vector2 b, float alpha);
        static Vector2 Scale(Vector2 v, float scale);
        static Vector2 Clamp(Vector2 value, Vector2 min, Vector2 max);
};

