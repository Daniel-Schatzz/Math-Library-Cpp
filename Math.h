#ifndef MATH_H
#define MATH_H

// ------------------------------------------ Types and Structures ----------------------------------------------

#if !defined(Vector2_type)
// Vector 2 Type
typedef struct Vector2{
    float x;
    float y;
}Vector2;
#define Vector2_type
#endif

#if!defined(Vector3_type)
// Vector 3 Type
typedef struct Vector3{
    float x;
    float y;
    float z;
}Vector3;
#define Vector3_type
#endif

#if!defined(Vector4_type)
// Vector 4 Type
typedef struct Vector4{
    float x;
    float y;
    float z;
    float w;
}Vector4;
#define Vector4_type
#endif

#if!defined(Quaternion_type)
// Quaternion type
typedef Vector4 Quaternion;
#define Quaternion_type
#endif

#include <math.h>

// ------------------------------------------ Vector2 and Vector3 Math ----------------------------------------------

// creates Vector with 0 as values
Vector2 Vector2Zero(void) {
    Vector2 result = {0.0f,0.0f};
    return result;
} 

Vector3 Vector3Zero(void) {
    Vector3 result = {0.0f,0.0f,0.0f};
    return result;
}

// creates Vector with 1 as values
Vector2 Vector2One(void) {
    Vector2 result = {1.0f,1.0f};
    return result;
}

Vector3 Vector3One(void) {
    Vector3 result = {1.0f,1.0f,1.0f};
    return result;
}

// Adds 2 Vectors
Vector2 Vector2Add(Vector2 a, Vector2 b) {
    Vector2 result = {a.x+b.x,a.y+b.y};
    return result;
}

Vector3 Vector3Add(Vector3 a, Vector3 b) {
    Vector3 result = {a.x+b.x,a.y+b.y,a.z+b.z};
    return result;
}

// Subtracts 2 Vectors
Vector2 Vector2Sub(Vector2 a, Vector2 b) {
    Vector2 result = {a.x-b.x,a.y-b.y};
    return result;
}

Vector3 Vector3Sub(Vector3 a, Vector3 b) {
    Vector3 result = {a.x-b.x,a.y-b.y,a.z-b.z};
    return result;
}

// Multiplies 2 Vectors
Vector2 Vector2Mul(Vector2 a, Vector2 b) {
    Vector2 result = {a.x*b.x,a.y*b.y};
    return result;
}

Vector3 Vector3Mul(Vector3 a, Vector3 b) {
    Vector3 result = {a.x*b.x,a.y*b.y,a.z*b.z};
    return result;
}

// Divides 2 Vectors
Vector2 Vector2Div(Vector2 a, Vector2 b) {
    Vector2 result = {a.x/b.x,a.y/b.y};
    return result;
}

Vector3 Vector3Div(Vector3 a, Vector3 b) {
    Vector3 result = {a.x/b.x,a.y/b.y,a.z/b.z};
    return result;
}

// Adds Value to Vector
Vector2 Vector2AddValue(Vector2 a, float value) {
    Vector2 result = {a.x+value,a.y+value};
    return result;
}

Vector3 Vector3AddValue(Vector3 a, float value) {
    Vector3 result = {a.x+value,a.y+value,a.z+value};
    return result;
}

// Subtracts Value from Vector
Vector2 Vector2SubValue(Vector2 a, float value) {
    Vector2 result = {a.x-value,a.y-value};
    return result;
}

Vector3 Vector3SubValue(Vector3 a, float value) {
    Vector3 result = {a.x-value,a.y-value,a.z-value};
    return result;
}

// Multiplies Value to Vector
Vector2 Vector2MulScalar(Vector2 a, float b) {
    Vector2 result = {a.x*b,a.y*b};
    return result;
}

Vector3 Vector3MulScalar(Vector3 a, float b) {
    Vector3 result = {a.x*b,a.y*b,a.z*b};
    return result;
}

// Divides Value from Vector
Vector2 Vector2DivScalar(Vector2 a, float b) {
    Vector2 result = {a.x/b,a.y/b};
    return result;
}

Vector3 Vector3DivScalar(Vector3 a, float b) {
    Vector3 result = {a.x/b,a.y/b,a.z/b};
    return result;
}

// Negates Vector
Vector2 Vector2Negate(Vector2 a) {
    Vector2 result = {-a.x,-a.y};
    return result;
}

Vector3 Vector3Negate(Vector3 a) {
    Vector3 result = {-a.x,-a.y,-a.z};
    return result;
}

// Cross Product of 2 Vectors
Vector3 Vector3Cross(Vector3 a, Vector3 b) {
    Vector3 result = {a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
    return result;
}

// Normalize Vector
Vector2 Vector2Normalize(Vector2 a) {
    float length = Vector2Length(a);
    Vector2 result = {0,0};

    if (length > 0) {
        result = {a.x/length,a.y/length};
    }
    
    return result;
}

Vector3 Vector3Normalize(Vector3 a) {
    float length = Vector3Length(a);
    Vector3 result = {0,0};

    if (length > 0) {
        result = {a.x/length,a.y/length,a.z/length};
    }
    
    return result;
}

// Rotate vector by angle
Vector2 Vector2Rotate(Vector2 a, float angle) {
    Vector2 result = {a.x*cosf(angle) - a.y*sinf(angle),a.x*sinf(angle) + a.y*cosf(angle)};
    return result;
}

// Rotate vector3 by quaternion rotation
Vector3 Vector3RotateByQuaternion(Vector3 a, Quaternion q) {
    Vector3 result = { 0 };

    result.x = a.x*(q.x*q.x + q.w*q.w - q.y*q.y - q.z*q.z) + a.y*(2*q.x*q.y - 2*q.w*q.z) + a.z*(2*q.x*q.z + 2*q.w*q.y);
    result.y = a.x*(2*q.w*q.z + 2*q.x*q.y) + a.y*(q.w*q.w - q.x*q.x + q.y*q.y - q.z*q.z) + a.z*(-2*q.w*q.x + 2*q.y*q.z);
    result.z = a.x*(-2*q.w*q.y + 2*q.x*q.z) + a.y*(2*q.w*q.x + 2*q.y*q.z)+ a.z*(q.w*q.w - q.x*q.x - q.y*q.y + q.z*q.z);

    return result;
}

// Rotate Vector3 arround an axis
Vector3 Vector3RotateAxis(Vector3 a, Vector3 axis, float angle) {
    Vector3 result = a;

    Vector3Normalize(axis);

    angle /= 2.0f;
    float teta = sinf(angle);
    float b = axis.x * teta;
    float c = axis.y * teta;
    float d = axis.z * teta;
    teta = cosf(angle);
    Vector3 w = { b, c, d };

    Vector3 wa = Vector3Cross(w, a);
    Vector3 wwa = Vector3Cross(w, wa);

    Vector3MulScalar(wa, teta*=2);
    Vector3MulScalar(wwa, 2);

    result.x += wa.x;
    result.y += wa.y;
    result.z += wa.z;

    result.x += wwa.x;
    result.y += wwa.y;
    result.z += wwa.z;

    return result;
}

// Move Vector towards target
Vector2 Vector2MoveTowards(Vector2 a, Vector2 target, float maxDistance) {
    float distanceSqr = Vector2DistanceSquared(a, target);
    if ((distanceSqr == 0) || ((maxDistance >= 0) && (distanceSqr <= maxDistance*maxDistance))) return target;
    float distance = Vector2Distance(a, target);
    float dx = target.x - a.x;
    float dy = target.y - a.y;
    Vector2 result = {a.x + dx/distance*maxDistance, a.y + dy/distance*maxDistance};
    return result;
}

Vector3 Vector3MoveTowards(Vector3 a, Vector3 target, float maxDistance) {

}

// Inverse of Vector
Vector2 Vector2Invert(Vector2 a) {
    Vector2 result = {1.0f/a.x,1.0f/a.y};
    return result;
}

Vector3 Vector3Invert(Vector3 a) {
    Vector3 result = {1.0f/a.x,1.0f/a.y,1.0f/a.z};
    return result;
}

// Dot Produkt of Vectors
float Vector2Dot(Vector2 a, Vector2 b) {
    float result = a.x*b.x+a.y*b.y;
    return result;
}

float Vector3Dot(Vector3 a, Vector3 b) {
    float result = a.x*b.x+a.y*b.y+a.z*b.z;
    return result;
}

// Length of Vector
float Vector2Length(Vector2 a) {
    float result = sqrtf(a.x*a.x+a.y*a.y);
    return result;
}

float Vector3Length(Vector3 a) {
    float result = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
    return result;
}

// Length Squared of Vector
float Vector2LengthSquared(Vector2 a) {
    float result = a.x*a.x+a.y*a.y;
    return result;
}

float Vector3LengthSquared(Vector3 a) {
    float result = a.x*a.x+a.y*a.y+a.z*a.z;
    return result;
}

// Distance between 2 Vectors
float Vector2Distance(Vector2 a, Vector2 b) {
    float result = sqrtf((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
    return result;
}

float Vector3Distance(Vector3 a, Vector3 b) {
    float result = sqrtf((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y) + (a.z-b.z) * (a.z-b.z));
    return result;
}

// Calculate square distance between two vectors
float Vector2DistanceSquared(Vector2 a, Vector2 b) {
    float result = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return result;
}

float Vector3DistanceSquared(Vector3 a, Vector3 b) {
    float result = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
    return result;
}

// Calculate angle between 2 Vectors
float Vector2Angle(Vector2 a, Vector2 b) {
    float result = atan2f(a.y-b.y,a.x-b.x);
    return result;
}

float Vector3Angle(Vector3 a, Vector3 b) {
    Vector3 cross = Vector3Cross(a, b);
    float length = Vector3Length(cross);
    float dot = Vector3Dot(a, b);
    float result = atan2f(length, dot);
    return result;
}

// ------------------------------------------ Quaternion Math ----------------------------------------------

// Add two Quaternions
Quaternion QuaternionAdd(Quaternion a, Quaternion b) {
    Quaternion result = {a.x+b.x,a.y+b.y,a.z+b.z,a.w+b.w};
    return result;
}

// Substract two Quaternions
Quaternion QuaternionSubtract(Quaternion a, Quaternion b) {
    Quaternion result = {a.x-b.x,a.y-b.y,a.z-b.z,a.w-b.w};
    return result;
}

// Add Value to Quaternions
Quaternion QuaternionAddValue(Quaternion a, float value) {
    Quaternion result = {a.x+value,a.y+value,a.z+value,a.w+value};
    return result;
}

// Substract Value to Quaternions
Quaternion QuaternionSubtractValue(Quaternion a, float value) {
    Quaternion result = {a.x-value,a.y-value,a.z-value,a.w-value};
    return result;
}

// Get Identity Quaternion
Quaternion QuaternionIdentity(void) {
    Quaternion result = {0,0,0,1};
    return result;
}

// Length of Quaternion
float QuaternionLength(Quaternion a) {
    float result = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z+a.w*a.w);
    return result;
}

// Normalize Quaternion
Quaternion QuaternionNormalize(Quaternion a) {
float length = QuaternionLength(a);
    Quaternion result = { 0 };

    if (length > 0) {
        result = {a.x/length,a.y/length,a.z/length,a.w/length};
    }
    
    return result;
}

// Multiply Quaternion
Quaternion QuaternionMultiply(Quaternion a, Quaternion b) {
    Quaternion result = { 0 };

    result.x = a.x*b.w + a.w*b.x + a.y*b.z - a.z*b.y;
    result.y = a.y*b.w + a.w*b.y + a.z*b.x - a.x*b.z;
    result.z = a.z*b.w + a.w*b.z + a.x*b.y - a.y*b.x;
    result.w = a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z;

    return result;
}

// Scalar Quaternion
Quaternion QuaternionScalarMultiply(Quaternion a, float scalar) {
    Quaternion result = { 0 };

    result.x = a.x*scalar;
    result.y = a.y*scalar;
    result.z = a.z*scalar;
    result.w = a.w*scalar;

    return result;
}

// Divide two Quaternions
Quaternion QuaternionDivide(Quaternion a, Quaternion b) {
    Quaternion result = { 0 };

    result.x = a.x/b.x;
    result.y = a.y/b.y;
    result.z = a.z/b.z;
    result.w = a.w/b.w;

    return result;
}

#endif