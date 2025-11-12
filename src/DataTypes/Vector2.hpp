#pragma once
struct Vector2
{
    float x, y;

    Vector2() : x(0), y(0) {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}

    void SetVector(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const
    {
        return x != other.x || y != other.y;
    }

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator/(const Vector2& other) const
    {
        return Vector2(x / other.x, y / other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2& v)
    {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

