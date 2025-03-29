#pragma once
#include "MathUtility.h"

class Vector4 {
public:
  Vector4(float x1 = 0, float y1 = 0, float z1 = 0, float w1 = 0)
    : x(x1), y(y1), z(z1), w(w1) {}

  ~Vector4() = default;

  // Suma, sobrecarga el operador de operador unario
  Vector4 operator+(const Vector4& other) const {
    return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
  }

  // Resta, sobrecarga el operador de operador unario
  Vector4 operator-(const Vector4& other) const {
    return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  // Multiplicación, sobrecarga el operador de operador unario
  // y multiplicación por escalar
  Vector4 operator*(float escalar) const {
    return Vector4(x * escalar, y * escalar, z * escalar, w * escalar);
  }

  // Calcular magnitud
  float magnitud() const {
    return newtonSqrt(x * x + y * y + z * z + w * w);
  }

  // Normalizar vector
  Vector4 normalize() const {
    float mag = magnitud();
    if (mag == 0) {
      return Vector4(0, 0, 0, 0);
    }
    else {
      return Vector4(x / mag, y / mag, z / mag, w / mag);
    }
  }

  float* data() {
    return &x;
  }

  const float* data() const {
    return &x;
  }

  // Método para imprimir el vector
  void print() const {
    //std::cout << "Vector: " << x << ", " << y << ", " << z << ", " << w << std::endl;
  }

  float x, y, z, w;
};
