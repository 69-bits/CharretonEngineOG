#pragma once
#include "MathUtility.h"

class Vector3 {
public:
  Vector3(float x1 = 0, float y1 = 0, float z1 = 0)
    : x(x1), y(y1), z(z1) {}

  ~Vector3() = default;

  // Suma, sobrecarga del operador unario
  Vector3 operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
  }

  // Resta, sobrecarga del operador unario
  Vector3 operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
  }

  // Multiplicación, sobrecarga del operador unario y multiplicación por escalar
  Vector3 operator*(float escalar) const {
    return Vector3(x * escalar, y * escalar, z * escalar);
  }

  // Calcular magnitud
  float magnitud() const {
    return newtonSqrt(x * x + y * y + z * z);
  }

  // Normalizar vector
  Vector3 normalize() const {
    float mag = magnitud();
    if (mag == 0) {
      return Vector3(0, 0, 0);
    }
    else {
      return Vector3(x / mag, y / mag, z / mag);
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
    //std::cout << "Vector: " << x << ", " << y << ", " << z << std::endl;
  }

  float x, y, z;
};
