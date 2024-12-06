#pragma once
#include "MathUtility.h"

class Vector2 {
public:

  Vector2(float x1 = 0, float y1 = 0) : x(x1), y(y1) {}

  ~Vector2() = default;

  //Suma
  Vector2
    operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
  }

  //Resta
  Vector2
    operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
  }

  //Muliplicacion
  Vector2
    operator*(float escalar) const {
    return Vector2(x * escalar, y * escalar);
  }

  Vector2& operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  // División por escalar
  Vector2 operator/(float escalar) const {
    return Vector2(x / escalar, y / escalar);
  }

  Vector2& operator/=(float escalar) {
    x /= escalar;
    y /= escalar;
    return *this;
  }

  //Magnitud
  float
    magnitud() const {
    return newtonSqrt(x * x + y * y);
  }

  //Normalizar
  Vector2
    normalize() {
    float mag = magnitud();
    if (mag == 0) {
      return Vector2(0, 0);
    }
    else {

      return Vector2(x / mag, y / mag);
    }
  }

  float*
    data() {
    return &x, & y;
  }

  const float*
    data() const {
    return &x, & y;
  }


  //Imprimir el vector
  void
    print() {
    //std::cout << " Vector: " << x << ", " << y << ", " << std::endl;
  }

  float x;
  float y;
};