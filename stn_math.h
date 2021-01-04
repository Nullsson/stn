#ifndef STN_MATH_H
#define STN_MATH_H

#define STN_PI                              (3.1415926535897f)
#define STN_PIf                             3.1415926535897f
#define STN_ONE_OVER_SQUARE_ROOT_OF_TWO_PI  0.3989422804
#define STN_ONE_OVER_SQUARE_ROOT_OF_TWO_PIf 0.3989422804f
#define STN_EULERS_NUMBER                   2.7182818284590452353602874713527
#define STN_EULERS_NUMBERf                  2.7182818284590452353602874713527f

inline r32
Sin(r32 Angle)
{
    r32 Result = sinf(Angle);

    return (Result);
}

inline r32
Cos(r32 Angle)
{
    r32 Result = cosf(Angle);

    return (Result);
}

inline r32
ATan2(r32 Y, r32 X)
{
    r32 Result = atan2f(Y, X);

    return (Result);
}

STN_INTERNAL r32
Square(r32 Value)
{
    r32 Result = Value * Value;

    return (Result);
}

inline r32
SquareRoot(r32 Value)
{
    r32 Result = sqrtf(Value);
    return (Result);
}

inline r32
AbsoluteValue(r32 Value)
{
    r32 Result = fabsf(Value);
    return(Result);
}

inline r32
Lerp(r32 A, r32 B, r32 t)
{
    r32 Result = A + (t * (B - A));

    return (Result);
}

STN_INTERNAL r32
Maximumr32(r32 A, r32 B)
{
    return A > B ? A : B;
}

union vector2
{
    struct
    {
        r32 X;
        r32 Y;
    };

    struct
    {
        r32 Width;
        r32 Height;
    };

    r32 Elements[2];
};

union vector3
{
    struct
    {
        r32 X;
        r32 Y;
        r32 Z;
    };

    struct
    {
        r32 R;
        r32 G;
        r32 B;
    };

    r32 Elements[3];
};

union vector4
{
    struct
    {
        r32 X;
        r32 Y;
        union
        {
            struct
            {
                r32 Z;

                union
                {
                    r32 W;
                    r32 Radius;
                };
            };
            struct
            {
                r32 Width;
                r32 Height;
            };
        };
    };

    struct
    {
        vector3 XYZ;
        r32 _Unused;
    };

    struct
    {
        r32 R;
        r32 G;
        r32 B;
        r32 A;
    };

    r32 Elements[4];
};

STN_INTERNAL vector2
Vector2Init(r32 X, r32 Y)
{
    vector2 Result = { X, Y };
    return (Result);
}

STN_INTERNAL vector2
Vector2Add(vector2 A, vector2 B)
{
    vector2 Result = {A.X + B.X, A.Y + B.Y };
    return (Result);
}

STN_INTERNAL vector2
Vector2Multiplyr32(vector2 V, r32 F)
{
    V.X *= F;
    V.Y *= F;
    return (V);
}

STN_INTERNAL r32
Vector2Dot(vector2 A, vector2 B)
{
    r32 Result = A.X * B.X + A.Y * B.Y;
    return (Result);
}

STN_INTERNAL r32
Vector2LengthSquared(vector2 V)
{
    r32 Result = V.X * V.X + V.Y * V.Y;
    return (Result);
}

STN_INTERNAL r32
Vector2Length(vector2 V)
{
    return SquareRoot(Vector2LengthSquared(V));
}


STN_INTERNAL vector2
Vector2Normalize(vector2 V)
{
    r32 Length = SquareRoot(Vector2LengthSquared(V));
    V.X /= Length;
    V.Y /= Length;

    return (V);
}

STN_INTERNAL vector3
Vector3Init(r32 X, r32 Y, r32 Z)
{
    vector3 Result = { X, Y, Z };
    return (Result);
}

STN_INTERNAL vector3
Vector3Add(vector3 A, vector3 B)
{
    vector3 Result = {A.X + B.X, A.Y + B.Y, A.Z + B.Z };
    return (Result);
}

STN_INTERNAL vector3
Vector3Minus(vector3 A, vector3 B)
{
    vector3 Result = {A.X - B.X, A.Y - B.Y, A.Z - B.Z };
    return (Result);
}

STN_INTERNAL vector3
Vector3Multiplyr32(vector3 V, r32 F)
{
    V.X *= F;
    V.Y *= F;
    V.Z *= F;
    return (V);
}

STN_INTERNAL r32
Vector3LengthSquared(vector3 V)
{
    r32 Result = V.X*V.X + V.Y * V.Y + V.Z * V.Z;
    return (Result);
}

STN_INTERNAL r32
Vector3Length(vector3 V)
{
    return SquareRoot(Vector3LengthSquared(V));
}

STN_INTERNAL vector3
Vector3Normalize(vector3 V)
{
    r32 Length = Vector3Length(V);
    vector3 Result = { V.X / Length, V.Y / Length, V.Z / Length };
    return (Result);
}

STN_INTERNAL r32
Vector3Dot(vector3 A, vector3 B)
{
    r32 Result = A.X * B.X + A.Y * B.Y + A.Z * B.Z;
    return (Result);
}

STN_INTERNAL vector3
Vector3Cross(vector3 A, vector3 B)
{
    vector3 Result = 
    {
        A.Y * B.Z - A.Z * B.Y,
        A.Z * B.X - A.X * B.Z,
        A.X * B.Y - A.Y * B.X,
    };

    return (Result);
}

STN_INTERNAL float
MinimumInVector3(vector3 V)
{
    float Minimum = V.X;
    if(V.Y < Minimum) { Minimum = V.Y; }
    if(V.Z < Minimum) { Minimum = V.Z; }
    return Minimum;
}

STN_INTERNAL float
MaximumInVector3(vector3 V)
{
    float Maximum = V.X;
    if(V.Y > Maximum) { Maximum = V.Y; }
    if(V.Z > Maximum) { Maximum = V.Z; }
    return Maximum;
}

STN_INTERNAL r32
Clampr32(r32 V, r32 L, r32 H)
{
    return V < L ? L : V > H ? H : V;
}

STN_INTERNAL i32
ClampI32(i32 I, i32 L, i32 H)
{
    return I < L ? L : I > H ? H : I;
}

STN_INTERNAL vector4
Vector4Init(r32 X, r32 Y, r32 Z, r32 W)
{
    vector4 Result = { X, Y, Z, W };
    return (Result);
}

STN_INTERNAL b32
Vector4RectangleHasPoint(vector4 V, vector2 P)
{
    return(P.X >= V.X && P.X <= V.X + V.Width &&
           P.Y >= V.Y && P.Y <= V.Y + V.Height);
}

STN_INTERNAL vector4
Vector4Multiplyr32(vector4 A, r32 F)
{
    vector4 C = { A.X * F, A.Y * F, A.Z * F, A.W * F };
    return (C);
}

struct matrix4
{
    r32 Elements[4][4];
};

STN_INTERNAL vector4
Vector4MultiplyMatrix4(vector4 V, matrix4 M)
{
    vector4 Result = {};
    
    for(int i = 0; i < 4; ++i)
    {
        Result.Elements[i] = (V.Elements[0]*M.Elements[0][i] +
                              V.Elements[1]*M.Elements[1][i] +
                              V.Elements[2]*M.Elements[2][i] +
                              V.Elements[3]*M.Elements[3][i]);
    }
    
    return (Result);
}

STN_INTERNAL matrix4
Matrix4InitD(r32 Diagonal)
{
    matrix4 Result = 
    {
        {
            { Diagonal },
            { 0.0f, Diagonal },
            { 0.0f, 0.0f, Diagonal },
            { 0.0f, 0.0f, 0.0f, Diagonal }
        }
    };

    return (Result);
}

STN_INTERNAL matrix4
Matrix4MultiplyMatrix4(matrix4 A, matrix4 B)
{
    matrix4 Result = {};

    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            Result.Elements[i][j] = (A.Elements[0][j]*B.Elements[i][0] +
                                     A.Elements[1][j]*B.Elements[i][1] +
                                     A.Elements[2][j]*B.Elements[i][2] +
                                     A.Elements[3][j]*B.Elements[i][3]);
        }
    }

    return (Result);
}

STN_INTERNAL matrix4
Matrix4TranslateVector3(vector3 Translation)
{
    matrix4 Result = Matrix4InitD(1.f);
    
    Result.Elements[3][0] = Translation.X;
    Result.Elements[3][1] = Translation.Y;
    Result.Elements[3][2] = Translation.Z;
    
    return (Result);
}

STN_INTERNAL matrix4
Matrix4Rotate(r32 Angle, vector3 Axis)
{
    matrix4 Result = Matrix4InitD(1.f);
    
    Axis = Vector3Normalize(Axis);
    
    r32 sin_theta = sinf(Angle);
    r32 cos_theta = cosf(Angle);
    r32 cos_value = 1.0f - cos_theta;
    
    Result.Elements[0][0] = (Axis.X * Axis.X * cos_value) + cos_theta;
    Result.Elements[0][1] = (Axis.X * Axis.Y * cos_value) + (Axis.Z * sin_theta);
    Result.Elements[0][2] = (Axis.X * Axis.Z * cos_value) - (Axis.Y * sin_theta);
    
    Result.Elements[1][0] = (Axis.Y * Axis.X * cos_value) - (Axis.Z * sin_theta);
    Result.Elements[1][1] = (Axis.Y * Axis.Y * cos_value) + cos_theta;
    Result.Elements[1][2] = (Axis.Y * Axis.Z * cos_value) + (Axis.X * sin_theta);
    
    Result.Elements[2][0] = (Axis.Z * Axis.X * cos_value) + (Axis.Y * sin_theta);
    Result.Elements[2][1] = (Axis.Z * Axis.Y * cos_value) - (Axis.X * sin_theta);
    Result.Elements[2][2] = (Axis.Z * Axis.Z * cos_value) + cos_theta;
    
    return (Result);
}

STN_INTERNAL matrix4
Matrix4Orthographic(r32 Left, r32 Right, r32 Bottom, r32 Top, r32 Near, r32 Far)
{
    matrix4 Result = {};

    Result.Elements[0][0] = 2.f / (Right - Left);
    Result.Elements[1][1] = 2.f / (Top - Bottom);
    Result.Elements[2][2] = -2.f / (Far - Near);
    Result.Elements[3][3] = 1.f;
    Result.Elements[3][0] = (Left + Right) / (Left - Right);
    Result.Elements[3][1] = (Bottom + Top) / (Bottom - Top);
    Result.Elements[3][2] = (Far + Near) / (Near - Far);

    return (Result);
}


#endif // STN_MATH_H