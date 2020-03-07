#pragma once

struct Vector2;
struct Vector3;
struct Vector4;
struct Quaternion;

struct Matrix
{
        //-----------------------------------------------------------------------------
        // Fields
        //-----------------------------------------------------------------------------
        
        float matrix[4][4];
        
        //-----------------------------------------------------------------------------
        // Static Fields
        //-----------------------------------------------------------------------------
        
        const static Matrix Identity;
        const static Matrix Zero;
    
        const static Matrix MirrorX;
        const static Matrix MirrorY;
        const static Matrix MirrorZ;
        
        //-----------------------------------------------------------------------------
        // Constructors
        //-----------------------------------------------------------------------------
        
        Matrix();
        
        Matrix(const Matrix& m);
        
        Matrix(Vector4 a, Vector4 b, Vector4 c, Vector4 d);
        
        Matrix(float m00, float m01, float m02, float m03,
               float m10, float m11, float m12, float m13,
               float m20, float m21, float m22, float m23,
               float m30, float m31, float m32, float m33);
        
        //-----------------------------------------------------------------------------
        // Operators
        //-----------------------------------------------------------------------------
        
        float& operator () (const int& row, const int& col);
        float  operator () (const int& row, const int& col) const;
        
        Matrix& operator = (const Matrix& m);
        Matrix operator - ();
        
        bool operator == (const Matrix& m);
        bool operator != (const Matrix& m);
        
        Matrix operator + (const Matrix& m);
        Matrix operator += (const Matrix& m);
        Matrix operator + (const float& f);
        Matrix operator += (const float& f);
        
        Matrix operator - (const Matrix& m);
        Matrix operator -= (const Matrix& m);
        Matrix operator - (const float& f);
        Matrix operator -= (const float& f);
        
        Matrix operator * (const Matrix& m);
        Matrix operator *= (const Matrix& m);
        Vector4 operator * (const Vector4& v);
        Matrix operator * (const float& f);
        Matrix operator *= (const float& f);
        
        Matrix operator / (const float& f);
        Matrix operator /= (const float& f);
        
        //-----------------------------------------------------------------------------
        // Public Methods
        //-----------------------------------------------------------------------------
        
        std::string ToString();
        Matrix Negate();
    
        void SetRow(int index, Vector4 value);
        Vector4 GetRow(int index);
        void SetColumn(int index, Vector4 value);
        Vector4 GetColumn(int index);
    
        Vector3 GetAxisX();
        Vector3 GetAxisY();
        Vector3 GetAxisZ();
    
        Vector3 GetLeftVector();
        Vector3 GetRightVector();
        Vector3 GetUpVector();
        Vector3 GetDownVector();
        Vector3 GetForwardVector();
        Vector3 GetBackVector();
    
        Vector3    GetTranslation();
        Matrix     GetRotationMatrix();
        Quaternion GetQuaternion();
        Vector3    GetEulerAngles();
        Vector4    GetAxisAngle();
        Vector3    GetScale();
        
        //-----------------------------------------------------------------------------
        // Static Methods
        //-----------------------------------------------------------------------------
        
        static float  Determinant(Matrix m);
        static Matrix Adjugate(Matrix m);
        static Matrix Inverse(Matrix m);
        static Matrix Transpose(Matrix m);
    
        static Matrix Billboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 cameraUpVector, Vector3 cameraForwardVector);
        static Matrix Frustum(float left, float right, float bottom, float top, float zNear, float zFar);
        static Matrix Perspective(float fov, float aspect, float zNear, float zFar);
        static Matrix Orthogonal(float left, float right, float bottom, float top, float zNear, float zFar);
        static Matrix LookRotation(Vector3 forward, Vector3 up = Vector3::Up);
        static Matrix LookAt(Vector3 from, Vector3 to, Vector3 up);
        
        static Matrix SetTransform(Matrix translation, Matrix rotation, Matrix scale);
        static Matrix SetTransform(Vector3 translation, Vector3 rotation, Vector3 scale);
        static Matrix SetTransform(Vector3 translation, Quaternion rotation, Vector3 scale);
        
        static Matrix SetDefaultTranslation();
        static Matrix SetTranslation(float x, float y, float z);
        static Matrix SetTranslation(Vector3 v);
        
        static Matrix SetDefaultRotation();
        static Matrix SetFromAxisX(float angle);
        static Matrix SetFromAxisY(float angle);
        static Matrix SetFromAxisZ(float angle);
        static Matrix SetFromEulerAngles(float x, float y, float z);
        static Matrix SetFromEulerAngles(Vector3 euler);
        static Matrix SetFromAxisAngle(Vector3 axis, float angle);
        static Matrix SetFromQuaternion(Quaternion q);
        
        static Matrix SetDefaultScale();
        static Matrix SetScale(float x, float y, float z);
        static Matrix SetScale(Vector3 v);
};

