#pragma once
#include "Vector3.h"
#include "MathUtility.h"

class Quaternion {
public:
  float x, y, z, w;

  // Constructor por defecto que inicializa los valores de x, y, z, w a 0
  Quaternion(float x1 = 0, float y1 = 0, float z1 = 0, float w1 = 0)
    : x(x1), y(y1), z(z1), w(w1) {}

  // Destructor por defecto
  ~Quaternion() = default;

  // Constructor que inicializa un cuaternión a partir de un ángulo y un eje de rotación
  static Quaternion fromAxisAngle(Vector3& _axis, float _angle) {
    float medioAngulo = _angle * 0.5f;
    float senoMedioAngulo = Sine(medioAngulo);

    return Quaternion(_axis.x * senoMedioAngulo, _axis.y * senoMedioAngulo, _axis.z * senoMedioAngulo, Cosine(medioAngulo));
  }

  // Suma, sobrecarga el operador unario
  Quaternion operator+(const Quaternion& other) const {
    return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
  }

  // Resta, sobrecarga el operador unario
  Quaternion operator-(const Quaternion& other) const {
    return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  // Multiplicación, sobrecarga el operador unario
  Quaternion operator*(const Quaternion& other) const {
    return Quaternion(
      w * other.w - x * other.x - y * other.y - z * other.z,
      w * other.x + x * other.w + y * other.z - z * other.y,
      w * other.y - x * other.z + y * other.w + z * other.x,
      w * other.z + x * other.y - y * other.x + z * other.w
    );
  }

  // Multiplicación por escalar
  Quaternion operator*(float escalar) const {
    return Quaternion(x * escalar, y * escalar, z * escalar, w * escalar);
  }

  // Método que devuelve la magnitud del cuaternión
  float magnitud() const {
    return newtonSqrt(w * w + x * x + y * y + z * z);
  }

  // Método que devuelve el cuaternión normalizado (de magnitud 1)
  Quaternion normalize() const {
    float mag = magnitud();
    if (mag == 0) {
      return Quaternion(0, 0, 0, 0);
    }
    else {
      return Quaternion(x / mag, y / mag, z / mag, w / mag);
    }
  }

  // Método que devuelve el conjugado del cuaternión
  Quaternion conjugate() const {
    return Quaternion(-x, -y, -z, w);
  }

  // Método que devuelve el cuaternión inverso
  Quaternion inverse() const {
    Quaternion conj = conjugate();
    float mag = magnitud();
    if (mag == 0) {
      return Quaternion(1, 0, 0, 0);
    }
    else {
      return Quaternion(conj.x / mag, conj.y / mag, conj.z / mag, conj.w / mag);
    }
  }

  // Método que utiliza el cuaternión para rotar un vector v
  Vector3 rotate(const Vector3& v) const {
    Quaternion vq(v.x, v.y, v.z, 0);
    Quaternion q = normalize();
    Quaternion rotated = q * vq * q.inverse();

    return Vector3(rotated.x, rotated.y, rotated.z);
  }

  // Método que devuelve un puntero a los componentes del cuaternión (x, y, z, w)
  float* data() {
    return &x;
  }

  // Método que devuelve una versión constante del método float* data()
  const float* data() const {
    return &x;
  }

  // Método para imprimir el cuaternión
  void print() const {
    //std::cout << "Vector: " << x << ", " << y << ", " << z << ", " << w << std::endl;
  }
};
