#include "Math.h"

const float Math::DegToRad = 0.0174532;  // PI / 180
const float Math::RadToDeg = 57.2957795; // 180 / PI

const float Math::Infinity = 1e30;
const float Math::NegativeInfinity = -1e30;

const float Math::Epsilon = 1.192092896e-07;
const float Math::E = 2.7182818;
const float Math::PI = 3.1415926;
const float Math::TwoPi = 6.2831853;      // PI * 2
const float Math::PiSquared = 9.8696044;  // PI * PI
const float Math::PiOverTwo = 1.5707963;  // PI / 2
const float Math::PiOverFour = 0.7853981; // PI / 4

//-------------------------------------------------------------------------------------

unsigned Math::randomSeed = (unsigned)std::clock();

void Math::SetRandomSeed(unsigned seed)
{
    randomSeed = seed;
}

unsigned Math::GetRandomSeed()
{
    return randomSeed;
}

int Math::Random()
{
    randomSeed = randomSeed * 214013 + 2531011;
    return (randomSeed >> 16) & 32767;
}

int Math::RandomInRange(int min, int max)
{
    int range = (max - min) + 1;
    
    if (range > 0)
    {
        range = Min(int(RandomFloat() * range), range - 1);
    }
    else
    {
        range = 0;
    }
    
    return min + range;
}

float Math::RandomFloat()
{
    return Random() / (float)32767;
}

float Math::RandomFloatInRange(float max)
{
    return Random() * max / (float)32767;
}

float Math::RandomFloatInRange(float min, float max)
{
    return min + (max - min) * RandomFloat();
}

bool Math::RandomBool()
{
    return RandomInRange(0, 1) == 1 ? true : false;
}

//-------------------------------------------------------------------------------------

int Math::NoiseHashIndex(int i)
{
    static int permutation[] =
    {
        151,160,137,91,90,15,
        131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
        190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
        88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
        77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
        102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
        135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
        5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
        223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
        129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
        251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
        49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
        138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
    };
    
    return permutation[i & 255];
}

float Math::NoiseFade(float t)
{
    return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}

float Math::NoiseGradient1D(int hash, float x)
{
    return (hash & 1) == 0 ? x : -x;
}

float Math::NoiseGradient2D(int hash, float x, float y)
{
    return ((hash & 1) == 0 ? x : -x) + ((hash & 2) == 0 ? y : -y);
}

float Math::NoiseGradient3D(int hash, float x, float y, float z)
{
    switch(hash & 15)
    {
        case  0: return  x + y;
        case  1: return -x + y;
        case  2: return  x - y;
        case  3: return -x - y;
        case  4: return  x + z;
        case  5: return -x + z;
        case  6: return  x - z;
        case  7: return -x - z;
        case  8: return  y + z;
        case  9: return -y + z;
        case 10: return  y - z;
        case 11: return -y - z;
        case 12: return  y + x;
        case 13: return -x + y;
        case 14: return -y + z;
        case 15: return -y - z;
        default: return 0;
    }
}

float Math::PerlinNoise1D(float x)
{
    int X = (int)Math::Floor(x) & 255;
    
    x -= Math::Floor(x);
    
    float u = NoiseFade(x);
    
    float grad1 = NoiseGradient1D(NoiseHashIndex(X    ), x    );
    float grad2 = NoiseGradient1D(NoiseHashIndex(X + 1), x - 1);
    
    return Math::Lerp(grad1, grad2, u) * 2.0;
}

float Math::PerlinNoise2D(float x, float y)
{
    int X = (int)Math::Floor(x) & 255;
    int Y = (int)Math::Floor(y) & 255;
    
    x -= Math::Floor(x);
    y -= Math::Floor(y);
    
    float u = NoiseFade(x);
    float v = NoiseFade(y);
    
    int A = NoiseHashIndex(X    ) + Y;
    int B = NoiseHashIndex(X + 1) + Y;
    
    float grad1 = NoiseGradient2D(NoiseHashIndex(A    ), x,     y    );
    float grad2 = NoiseGradient2D(NoiseHashIndex(B    ), x - 1, y    );
    float grad3 = NoiseGradient2D(NoiseHashIndex(A + 1), x,     y - 1);
    float grad4 = NoiseGradient2D(NoiseHashIndex(B + 1), x - 1, y - 1);
    
    float lerp1 = Math::Lerp(grad1, grad2, u);
    float lerp2 = Math::Lerp(grad3, grad4, u);
    
    return Math::Lerp(lerp1, lerp2, v);
}

float Math::PerlinNoise3D(float x, float y, float z)
{
    int X = (int)Math::Floor(x) & 255;
    int Y = (int)Math::Floor(y) & 255;
    int Z = (int)Math::Floor(z) & 255;
    
    x -= Math::Floor(x);
    y -= Math::Floor(y);
    z -= Math::Floor(z);
    
    float u = NoiseFade(x);
    float v = NoiseFade(y);
    float w = NoiseFade(z);
    
    int A  = NoiseHashIndex(X    ) + Y;
    int AA = NoiseHashIndex(A    ) + Z;
    int AB = NoiseHashIndex(A + 1) + Z;
    int B  = NoiseHashIndex(X + 1) + Y;
    int BA = NoiseHashIndex(B    ) + Z;
    int BB = NoiseHashIndex(B + 1) + Z;
    
    float grad1 = NoiseGradient3D(NoiseHashIndex(AA    ), x,     y,     z    );
    float grad2 = NoiseGradient3D(NoiseHashIndex(BA    ), x - 1, y,     z    );
    float grad3 = NoiseGradient3D(NoiseHashIndex(AB    ), x,     y - 1, z    );
    float grad4 = NoiseGradient3D(NoiseHashIndex(BB    ), x - 1, y - 1, z    );
    float grad5 = NoiseGradient3D(NoiseHashIndex(AA + 1), x,     y,     z - 1);
    float grad6 = NoiseGradient3D(NoiseHashIndex(BA + 1), x - 1, y,     z - 1);
    float grad7 = NoiseGradient3D(NoiseHashIndex(AB + 1), x,     y - 1, z - 1);
    float grad8 = NoiseGradient3D(NoiseHashIndex(BB + 1), x - 1, y - 1, z - 1);
    
    float lerp1 = Math::Lerp(grad1, grad2, u);
    float lerp2 = Math::Lerp(grad3, grad4, u);
    float lerp3 = Math::Lerp(grad5, grad6, u);
    float lerp4 = Math::Lerp(grad7, grad8, u);
    float lerp5 = Math::Lerp(lerp1, lerp2, v);
    float lerp6 = Math::Lerp(lerp3, lerp4, v);
    
    return Math::Saturate(Math::Lerp(lerp5, lerp6, w) * 0.97);
}

//-------------------------------------------------------------------------------------

float Math::ToRadians(float degrees)
{
    return degrees * DegToRad;
}

float Math::ToDegrees(float radians)
{
    return radians * RadToDeg;
}

bool Math::IsNaN(float f)
{
    return isnan(f);
}

int Math::Sign(float f)
{
    return f > 0.0 ? 1 : (f < 0.0 ? -1 : 0);
}

float Math::Square(float f)
{
    return f * f;
}

float Math::Cube(float f)
{
    return f * f * f;
}

float Math::Percent(float current, float total)
{
    return current / total;
}

float Math::DeltaAngle(float a, float b)
{
    float result = b - a;
    
    if ((result >= 360.0) or (result < 0.0))
    {
        result -= Floor(result * (1.0 / 360.0)) * 360.0;
    }
    
    if (result > 180.0)
    {
        result -= 360.0;
    }
    
    return result;
}

float Math::SmoothStep(float min, float max, float x)
{
    x = Saturate(x);
    x = -2.0 * Cube(x) + 3.0 * Square(x);
    
    return Lerp(min, max, x);
}

float Math::SmoothStepClamped(float min, float max, float x)
{
    if (x <= min) return 0.0;
    if (x >= max) return 1.0;
    
    x = (x - min) / (max - min);
    
    return x * x * (3.0 - 2.0 * x);
}

float Math::SmootherStep(float min, float max, float x)
{
    if (x <= min) return 0.0;
    if (x >= max) return 1.0;
    
    x = (x - min) / (max - min);
    
    return x * x * x * (x * (x * 6.0 - 15.0) + 10.0);
}

float Math::Min(float a, float b)
{
    return (a < b) ? a : b;
}

float Math::Max(float a, float b)
{
    return (a > b) ? a : b;
}

float Math::Min3(float a, float b, float c)
{
    return Min(Min(a, b), c);
}

float Math::Max3(float a, float b, float c)
{
    return Max(Max(a, b), c);
}

float Math::Clamp(float value, float min, float max)
{
    if (value >= max) return max;
    if (value <= min) return min;
    return value;
}

float Math::Saturate(float f)
{
    return Clamp(f, 0.0, 1.0);
}

float Math::Lerp(float a, float b, float alpha)
{
    return a + (b - a) * alpha;
}

float Math::LerpStable(float a, float b, float alpha)
{
    return a * (1.0 - alpha) + b * alpha;
}

float Math::InverseLerp(float a, float b, float alpha)
{
    return (alpha - a) / (b - a);
}

float Math::Sqrt(float f)
{
    return sqrtf(f);
}

float Math::InvSqrt(float f)
{
    return 1.0 / sqrtf(f);
}

void Math::SinCos(float a, float& s, float& c)
{
    s = sinf(a);
    c = cosf(a);
}

float Math::Sin(float f)
{
    return sinf(f);
}

float Math::Sinh(float f)
{
    return sinhf(f);
}

float Math::Cos(float f)
{
    return cosf(f);
}

float Math::Cosh(float f)
{
    return coshf(f);
}

float Math::Tan(float f)
{
    return tanf(f);
}

float Math::Tanh(float f)
{
    return tanhf(f);
}

float Math::Asin(float f)
{
    return asinf(f);
}

float Math::Asinh(float f)
{
    return asinhf(f);
}

float Math::Acos(float f)
{
    return acosf(f);
}

float Math::Acosh(float f)
{
    return acoshf(f);
}

float Math::Atan(float f)
{
    return atanf(f);
}

float Math::Atanh(float f)
{
    return atanhf(f);
}

float Math::Atan2(float a, float b)
{
    return atan2(a, b);
}

float Math::Mod(float a, float b)
{
    return fmodf(a, b);
}

float Math::Pow(float a, float b)
{
    return powf(a, b);
}

float Math::Exp(float f)
{
    return expf(f);
}

float Math::Log(float f)
{
    return logf(f);
}

float Math::Log(float a, float b)
{
    return log2f(a) / log2f(b);
}

float Math::Log2(float f)
{
    return log2f(f);
}

float Math::Log10(float f)
{
    return log10f(f);
}

int Math::Abs(int i)
{
    return abs(i);
}

float Math::Fabs(float f)
{
    return fabsf(f);
}

float Math::Round(float f)
{
    return round(f);
}

float Math::Floor(float f)
{
    return floorf(f);
}

float Math::Ceil(float f)
{
    return ceilf(f);
}

float Math::Rint(float f)
{
    return floorf(f + 0.5);
}

float Math::Frac(float f)
{
    return f - floorf(f);
}

