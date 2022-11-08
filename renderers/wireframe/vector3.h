#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
private:
    /* data */
public:
    Vector3(float xCoordinate, float yCoordinate, float zCoordinate);
    ~Vector3();
    float x;
    float y;
    float z;
    Vector3 operator+();
    Vector3 operator-();
    Vector3 operator*(const float num);
    Vector3 operator*(const Vector3 vec);
    Vector3 operator+(const float num);
    Vector3 operator+(const Vector3 vec);
    Vector3 operator-(const float num);
    Vector3 operator-(const Vector3 vec);
    void operator*=(const float num);
    void operator*=(const Vector3 vec);
    void operator+=(const float num);
    void operator+=(const Vector3 vec);
    void operator-=(const float num);
    void operator-=(const Vector3 vec);
};

Vector3::Vector3(float xCoordinate = 0.0f, float yCoordinate = 0.0f, float zCoordinate = 0.0f)
{
    x = xCoordinate;
    y = yCoordinate;
    z = zCoordinate;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator+()
{
    return {
        +x,
        +y,
        +z
    };
}

Vector3 Vector3::operator-()
{
    return {
        -x,
        -y,
        -z
    };
}

Vector3 Vector3::operator*(const float num)
{
    return {
        x * num,
        y * num, 
        z * num
    };
}

Vector3 Vector3::operator*(const Vector3 vec)
{
    return {
        x * vec.x,
        y * vec.y, 
        z * vec.z
    };
}

Vector3 Vector3::operator+(const float num)
{
    return {
        x + num,
        y + num, 
        z + num
    };
}

Vector3 Vector3::operator+(const Vector3 vec)
{
    return {
        x + vec.x,
        y + vec.y, 
        z + vec.z
    };
}

Vector3 Vector3::operator-(const float num)
{
    return {
        x - num,
        y - num, 
        z - num
    };
}

Vector3 Vector3::operator-(const Vector3 vec)
{
    return {
        x - vec.x,
        y - vec.y, 
        z - vec.z
    };
}

void Vector3::operator*=(const float num)
{
    x *= num;
    y *= num;
    z *= num;
}

void Vector3::operator*=(const Vector3 vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
}

void Vector3::operator+=(const float num)
{
    x += num;
    y += num;
    z += num;
}

void Vector3::operator+=(const Vector3 vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
}

void Vector3::operator-=(const float num)
{
    x -= num;
    y -= num;
    z -= num;
}

void Vector3::operator-=(const Vector3 vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}

#endif