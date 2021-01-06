#include "../HyperTest/code/hypertest.cpp"
#define STN_USE_MATH
#include "../stn.h"

TEST(STN_Math, Lerp)
{
    UNITTEST_ASSERT_EQUAL(Lerp(0.0f, 1.0f, 0.0f), 0.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(-25.0f, 50.0f, 1.0f), 50.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(-25.0f, 50.0f, 0.0f), -25.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(100.0f, 10.0f, 0.0f), 100.0f);
    UNITTEST_ASSERT_EQUAL(Lerp(0.0f, 100.0f, 0.5f), 50.0f);
}

TEST(STN_Math, VectorAdd)
{
    vector2 V21 = Vector2Init(1.0f, 1.0f);
    vector2 V22 = Vector2Init(2.0f, 2.0f);
    
    vector2 V2R = Vector2Add(V21, V22);
    UNITTEST_EXPECT_EQUAL(V2R.X, 3.0f);
    UNITTEST_EXPECT_EQUAL(V2R.Y, 3.0f);

    vector3 V31 = Vector3Init(1.0f, 1.0f, 1.0f);
    vector3 V32 = Vector3Init(1.0f, 1.0f, 1.0f);
    
    vector3 V3R = Vector3Add(V31, V32);
    UNITTEST_EXPECT_EQUAL(V3R.X, 2.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Y, 2.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Z, 2.0f);
}

TEST(STN_Math, VectorMinus)
{
    vector2 V21 = Vector2Init(1.0f, 1.0f);
    vector2 V22 = Vector2Init(2.0f, 60.0f);
    
    vector2 V2R = Vector2Minus(V21, V22);
    UNITTEST_EXPECT_EQUAL(V2R.X, -1.0f);
    UNITTEST_EXPECT_EQUAL(V2R.Y, -59.0f);

    vector3 V31 = Vector3Init(5.0f, 2.0f, 10.0f);
    vector3 V32 = Vector3Init(1.0f, 1.0f, 1.0f);
    
    vector3 V3R = Vector3Minus(V31, V32);
    UNITTEST_EXPECT_EQUAL(V3R.X, 4.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Y, 1.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Z, 9.0f);
}

TEST(STN_Math, VectorMultiplyF32)
{
    vector2 V2 = Vector2Init(2.0f, 1.0f);
    vector2 V2R = Vector2MultiplyF32(V2, 10.0f);

    UNITTEST_EXPECT_EQUAL(V2R.X, 20.0f);
    UNITTEST_EXPECT_EQUAL(V2R.Y, 10.0f);

    vector3 V3 = Vector3Init(1.0f, 2.0f, 56.0f);
    vector3 V3R = Vector3MultiplyF32(V3, 10.0f);

    UNITTEST_EXPECT_EQUAL(V3R.X, 10.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Y, 20.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Z, 560.0f);

    vector4 V4 = Vector4Init(1.0f, 2.0f, 56.0f, 100.0f);
    vector4 V4R = Vector4MultiplyF32(V4, 10.0f);

    UNITTEST_EXPECT_EQUAL(V4R.X, 10.0f);
    UNITTEST_EXPECT_EQUAL(V4R.Y, 20.0f);
    UNITTEST_EXPECT_EQUAL(V4R.Z, 560.0f);
    UNITTEST_EXPECT_EQUAL(V4R.W, 1000.0f);
}

TEST(STN_Math, VectorDot)
{
    vector2 V21 = Vector2Init(1.0f, 1.0f);
    vector2 V22 = Vector2Init(3.0f, 2.0f);
    
    f32 V2R = Vector2Dot(V21, V22);
    UNITTEST_EXPECT_EQUAL(V2R, 5.0f);

    vector3 V31 = Vector3Init(10.0f, 5.0f, 7.0f);
    vector3 V32 = Vector3Init(5.0f, 6.0f, 2.0f);
    
    f32 V3R = Vector3Dot(V31, V32);
    UNITTEST_EXPECT_EQUAL(V3R, 94.0f);
}

TEST(STN_Math, VectorLengthSquared)
{
    vector2 V2 = Vector2Init(3.0f, 2.0f);
    
    f32 V2R = Vector2LengthSquared(V2);
    UNITTEST_EXPECT_EQUAL(V2R, 13.0f);

    vector3 V3 = Vector3Init(10.0f, 5.0f, 7.0f);

    f32 V3R = Vector3LengthSquared(V3);
    UNITTEST_EXPECT_EQUAL(V3R, 174.0f);
}

TEST(STN_Math, VectorLength)
{
    vector2 V2 = Vector2Init(3.0f, 2.0f);
    
    f32 V2R = Vector2Length(V2);
    UNITTEST_EXPECT_EQUAL(V2R, SquareRoot(13.0f));

    vector3 V3 = Vector3Init(10.0f, 5.0f, 7.0f);

    f32 V3R = Vector3Length(V3);
    UNITTEST_EXPECT_EQUAL(V3R, SquareRoot(174.0f));
}

TEST(STN_Math, VectorNormalize)
{
    vector2 V2 = Vector2Init(0.0f, 10.0f);
    vector2 V2R = Vector2Normalize(V2);

    UNITTEST_EXPECT_EQUAL(V2R.X, 0.0f);
    UNITTEST_EXPECT_EQUAL(V2R.Y, 1.0f);

    vector3 V3 = Vector3Init(0.0f, 0.0f, 10.0f);
    vector3 V3R = Vector3Normalize(V3);

    UNITTEST_EXPECT_EQUAL(V3R.X, 0.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Y, 0.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Z, 1.0f);
}

TEST(STN_Math, VectorCross)
{
    vector3 V31 = Vector3Init(1.0f, 2.0f, 3.0f);
    vector3 V32 = Vector3Init(4.0f, 5.0f, 6.0f);

    vector3 V3R = Vector3Cross(V31, V32);

    UNITTEST_EXPECT_EQUAL(V3R.X, -3.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Y, 6.0f);
    UNITTEST_EXPECT_EQUAL(V3R.Z, -3.0f);
}

TEST(STN_Math, MinimumInVector)
{
    vector3 V3 = Vector3Init(4.0f, 5.0f, 6.0f);
    f32 V3R = MinimumInVector3(V3);

    UNITTEST_EXPECT_EQUAL(V3R, 4.0f);
}

TEST(STN_Math, MaximumInVector)
{
    vector3 V3 = Vector3Init(4.0f, 5.0f, 6.0f);
    f32 V3R = MaximumInVector3(V3);

    UNITTEST_EXPECT_EQUAL(V3R, 6.0f);
}

TEST(STN_Math, Vector4RectangleHasPoint)
{
    vector2 Point = Vector2Init(50.0f, 50.0f);
    vector4 Rectangle = Vector4Init(0.0f, 0.0f, 100.0f, 100.0f);

    vector2 PointOutside = Vector2Init(200.0f, 200.0f);

    UNITTEST_EXPECT_TRUE(Vector4RectangleHasPoint(Rectangle, Point));
    UNITTEST_EXPECT_FALSE(Vector4RectangleHasPoint(Rectangle, PointOutside));
}

TEST(STN_Math, Vector4MultiplyMatrix4)
{
    matrix4 M4 = Matrix4InitDiagonal(10.0f);
    vector4 V4 = Vector4Init(10.0f, 20.0f, 30.0f, 40.0f);
    vector4 V4R = Vector4MultiplyMatrix4(V4, M4);

    UNITTEST_EXPECT_EQUAL(V4R.X, 100.0f);
    UNITTEST_EXPECT_EQUAL(V4R.Y, 200.0f);
    UNITTEST_EXPECT_EQUAL(V4R.Z, 300.0f);
    UNITTEST_EXPECT_EQUAL(V4R.W, 400.0f);
}

TEST(STN_Math, MatrixMultiplyMatrix)
{
    matrix4 M4 = 
    {
        {
            { 11, 12, 13, 14 },
            { 21, 22, 23, 24 },
            { 31, 32, 33, 34 },
            { 41, 42, 43, 44 }
        }
    };

    matrix4 M4R = Matrix4MultiplyMatrix4(M4, M4);

    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][0], 1350.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][1], 1400.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][2], 1450.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][3], 1500.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][0], 2390.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][1], 2480.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][2], 2570.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][3], 2660.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][0], 3430.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][1], 3560.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][2], 3690.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][3], 3820.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][0], 4470.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][1], 4640.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][2], 4810.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][3], 4980.0f);
}

TEST(STN_Math, MatrixTranslateVector)
{
    vector3 V3 = Vector3Init(4.0f, 3.0f, 5.0f);
    matrix4 M4R = Matrix4TranslateVector3(V3);

    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][0], V3.X);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][1], V3.Y);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][2], V3.Z);
}

TEST(STN_Math, MatrixScaleVector)
{
    vector3 V3 = Vector3Init(4.0f, 3.0f, 5.0f);
    matrix4 M4R = Matrix4ScaleVector3(V3);

    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][0], V3.X);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][1], V3.Y);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][2], V3.Z);
}

TEST(STN_Math, MatrixRotate)
{
    f32 Angle = STN_PIF;
    vector3 Axis = Vector3Init(1.0f, 1.0f, 1.0f);
    matrix4 HelperMatrix = 
    {
        {
            { 1,  2,  3,  4 },
            { 5,  6,  7,  8 },
            { 9,  10, 11, 12 },
            { 13, 14, 15, 16 }
        }
    };

    matrix4 M4R = Matrix4MultiplyMatrix4(HelperMatrix, Matrix4Rotate(Angle, Axis));
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][0], 9.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][1], 10.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][2], 11.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[0][3]), 12.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[1][0]), 5.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[1][1]), 6.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[1][2]), 7.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[1][3]), 8.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[2][0]), 1.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[2][1]), 2.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][2], 3.0f);
    UNITTEST_EXPECT_EQUAL(roundf(M4R.Elements[2][3]), 4.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][0], 13.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][1], 14.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][2], 15.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][3], 16.0f);
}

TEST(STN_Math, MatrixOrthographic)
{
    matrix4 M4R = Matrix4Orthographic(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);

    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][0], 2.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][1], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][2], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[0][3], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][0], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][1], 2.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][2], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[1][3], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][0], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][1], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][2], -2.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[2][3], 0.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][0], -1.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][1], -1.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][2], -1.0f);
    UNITTEST_EXPECT_EQUAL(M4R.Elements[3][3], 1.0f);
}

TEST(STN_Math, Clamp)
{
    f32 ClampedHighF32 = ClampF32(120.0f, 50.0f, 100.0f);
    f32 ClampedLowF32  = ClampF32(15.0f, 50.0f, 100.0f);
    f32 NotClampedF32  = ClampF32(75.0f, 50.0f, 100.0f);
    
    UNITTEST_EXPECT_EQUAL(ClampedHighF32, 100.0f);
    UNITTEST_EXPECT_EQUAL(ClampedLowF32, 50.0f);
    UNITTEST_EXPECT_EQUAL(NotClampedF32, 75.0f);

    i32 ClampedHighI32 = ClampI32(120, 50, 100);
    i32 ClampedLowI32  = ClampI32(15, 50, 100);
    i32 NotClampedI32  = ClampF32(75, 50, 100);
    
    UNITTEST_EXPECT_EQUAL(ClampedHighI32, 100);
    UNITTEST_EXPECT_EQUAL(ClampedLowI32, 50);
    UNITTEST_EXPECT_EQUAL(NotClampedI32, 75);
}