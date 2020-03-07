#pragma once

struct Vector3;
struct Matrix;

struct Quaternion
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
        
        const static Quaternion Identity;
        const static Quaternion Zero;
        const static Quaternion One;
    
        //-----------------------------------------------------------------------------
        // Constructors
        //-----------------------------------------------------------------------------
        
        Quaternion();
        Quaternion(const Quaternion& q);
        Quaternion(float x, float y, float z, float w);
        
        //-----------------------------------------------------------------------------
        // Operators
        //-----------------------------------------------------------------------------
        
        Quaternion& operator = (const Quaternion& q);
        Quaternion operator - ();
        
        bool operator == (const Quaternion& q);
        bool operator != (const Quaternion& q);

        Quaternion operator + (const Quaternion& q);
        Quaternion operator += (const Quaternion& q);
        
        Quaternion operator - (const Quaternion& q);
        Quaternion operator -= (const Quaternion& q);
        
        Quaternion operator * (const Quaternion& q);
        Quaternion operator *= (const Quaternion& q);
        Quaternion operator * (const float& f);
        Quaternion operator *= (const float& f);
        
        Quaternion operator / (const Quaternion& q);
        Quaternion operator /= (const Quaternion& q);
        
        //-----------------------------------------------------------------------------
        // Public Methods
        //-----------------------------------------------------------------------------
        
        std::string ToString();
        Quaternion Negate();
        void Set(float x, float y, float z, float w);
        bool Equals(Quaternion q);
        Quaternion Normalize();
    
        Vector3 GetAxisX();
        Vector3 GetAxisY();
        Vector3 GetAxisZ();
        
        Vector3 GetLeftVector();
        Vector3 GetRightVector();
        Vector3 GetUpVector();
        Vector3 GetDownVector();
        Vector3 GetForwardVector();
        Vector3 GetBackVector();
    
        Vector3 RotateVector(Vector3 v);
        Vector3 GetEulerAngles();
        Vector4 GetAxisAngle();
        
        //-----------------------------------------------------------------------------
        // Static Methods
        //-----------------------------------------------------------------------------
    
        static Quaternion Inverse(Quaternion q); // Check it
        static Quaternion Conjugate(Quaternion q); // and it
        static Quaternion Exponential(Quaternion q); // and it
        static Quaternion Logarithm(Quaternion q); // and it
        static Quaternion Power(Quaternion q, float e);
    
        static Quaternion SetFromEulerAngles(float x, float y, float z);
        static Quaternion SetFromEulerAngles(Vector3 v); // and it
        static Quaternion SetFromAxisAngle(Vector3 axis, float angle); // and it
        static Quaternion SetFromRotationMatrix(Matrix m);
    
        static Quaternion GetNormalized(Quaternion q);
        static float      AngleBetween(Quaternion a, Quaternion b);
        static Quaternion LookRotation(Vector3 forward, Vector3 up = Vector3::Up);
        static Quaternion LookAt(Vector3 from, Vector3 to, Vector3 up);
        static float      Length(Quaternion q);
        static float      LengthSquared(Quaternion q);
        static float      DotProduct(Quaternion a, Quaternion b);
        static Quaternion Lerp(Quaternion a, Quaternion b, float alpha);
        static Quaternion Nlerp(Quaternion a, Quaternion b, float alpha);
        static Quaternion Slerp(Quaternion a, Quaternion b, float alpha);
        static Quaternion Scale(Quaternion v, float scale);
};

