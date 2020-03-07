#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <math.h>

//-------------------------------------------------------------------------------------

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix.h"
#include "Quaternion.h"

//-------------------------------------------------------------------------------------

struct Math
{
    static const float DegToRad;
    static const float RadToDeg;
    
    static const float Infinity;
    static const float NegativeInfinity;
    
    static const float Epsilon;
    static const float E;
    static const float PI;
    static const float TwoPi;
    static const float PiSquared;
    static const float PiOverTwo;
    static const float PiOverFour;

    //-------------------------------------------------------------------------------------

    static unsigned randomSeed;

    static void SetRandomSeed(unsigned seed);
    static unsigned GetRandomSeed();

    static int   Random();
    static int   RandomInRange(int min, int max);
    static float RandomFloat();
    static float RandomFloatInRange(float max);
    static float RandomFloatInRange(float min, float max);
    static bool  RandomBool();

    //-------------------------------------------------------------------------------------

    static int   NoiseHashIndex(int i);
    static float NoiseFade(float t);

    static float NoiseGradient1D(int hash, float x);
    static float NoiseGradient2D(int hash, float x, float y);
    static float NoiseGradient3D(int hash, float x, float y, float z);

    static float PerlinNoise1D(float x);
    static float PerlinNoise2D(float x, float y);
    static float PerlinNoise3D(float x, float y, float z);

    //-------------------------------------------------------------------------------------

    static float ToRadians(float degrees);
    static float ToDegrees(float radians);

    static bool  IsNaN(float f);
    static int   Sign(float f);
    static float Square(float f);
    static float Cube(float f);

    static float Percent(float current, float total);
    static float DeltaAngle(float a, float b);
    static float SmoothStep(float min, float max, float x);
    static float SmoothStepClamped(float min, float max, float x);
    static float SmootherStep(float min, float max, float x);
    static float Min(float a, float b);
    static float Max(float a, float b);
    static float Min3(float a, float b, float c);
    static float Max3(float a, float b, float c);
    static float Clamp(float value, float min, float max);
    static float Saturate(float f);
    static float Lerp(float a, float b, float alpha);
    static float LerpStable(float a, float b, float alpha);
    static float InverseLerp(float a, float b, float alpha);

    static float Sqrt(float f);
    static float InvSqrt(float f);
    static void  SinCos(float a, float& s, float& c);
    static float Sin(float f);
    static float Sinh(float f);
    static float Cos(float f);
    static float Cosh(float f);
    static float Tan(float f);
    static float Tanh(float f);
    static float Asin(float f);
    static float Asinh(float f);
    static float Acos(float f);
    static float Acosh(float f);
    static float Atan(float f);
    static float Atanh(float f);
    static float Atan2(float a, float b);
    static float Mod(float a, float b);
    static float Pow(float a, float b);
    static float Exp(float f);
    static float Log(float f);
    static float Log(float a, float b);
    static float Log2(float f);
    static float Log10(float f);
    
    static int   Abs(int i);
    static float Fabs(float f);
    static float Round(float f);
    static float Floor(float f);
    static float Ceil(float f);
    static float Rint(float f);
    static float Frac(float f);
};


// Vector2
// Vector3
// Vector4
// Matrix
// Quaternion
// Plane
// Ray
// Rectangle (Rect)
// Color
// Sphere
// Box
// BoundingBox
// OrientedBox
// Frustum
// Cylindrical
// Line
// Triangle

