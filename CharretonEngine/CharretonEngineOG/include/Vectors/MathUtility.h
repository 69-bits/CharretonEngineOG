#pragma once

// Constantes matemáticas
const float MY_PI = 3.14159265358979323846f;
const float MY_E = 2.71828182845904523536f;

/*
  * @brief Calcula el valor absoluto
  * @param num Valor para el cual se desea calcular el valor absoluto
  * @return El valor absoluto de num
  */
inline float
absoluteValue(float num) {
  return (num < 0) ? -num : num;
}

/*
  * @brief Aproxima la raíz cuadrada utilizando el método de Newton
  * @param num Valor para el cual se desea calcular la raíz cuadrada
  * @return La raíz cuadrada aproximada de num
  */
inline float
estimateSqrt(int num) {
  float errorMargin = 0.0001f; // Margen de error permitido
  float estimate = 1.0f; // Estimación inicial

  while (absoluteValue((estimate * estimate) - num) >= errorMargin) {
    float quotient = num / estimate; // Cociente del número y la estimación actual
    float avg = (quotient + estimate) / 2.0f; // Promedio de cociente y estimación
    estimate = avg;
  }
  return estimate;
}

/*
  * @brief Calcula la raíz cuadrada utilizando el método de Newton-Raphson
  * @param value Valor para el cual se desea calcular la raíz cuadrada
  * @return La raíz cuadrada de value
  */
inline float
newtonSqrt(float value) {
  if (value < 0) {
    return 0; // Valores negativos no permitidos
  }
  float approx = value;
  float betterGuess = 1.0f;
  float tolerance = 0.00001f;

  while (absoluteValue(approx - betterGuess) > tolerance) {
    approx = (approx + betterGuess) / 2.0f;
    betterGuess = value / approx;
  }
  return approx;
}

/**
   * @brief Calcula el seno de un ángulo en radianes utilizando la serie de Taylor
   * @param angle Ángulo en radianes
   * @return El seno de angle
   */
inline float
Sine(float angle) {
  float sineResult = 0.0f;
  float term = angle;
  float angleSquared = angle * angle;
  int n = 1;

  while (absoluteValue(term) > 0.000001f) {
    sineResult += term;
    term *= -angleSquared / ((2 * n) * (2 * n + 1));
    ++n;
  }
  return sineResult;
}

/**
   * @brief Calcula el coseno de un ángulo en radianes utilizando la serie de Taylor
   * @param angle Ángulo en radianes
   * @return El coseno de angle
   */
inline float
Cosine(float angle) {
  float cosineResult = 1.0f;
  float term = 1.0f;
  float angleSquared = angle * angle;
  int n = 1;

  while (absoluteValue(term) > 0.000001f) {
    term *= -angleSquared / ((2 * n - 1) * (2 * n));
    cosineResult += term;
    ++n;
  }
  return cosineResult;
}

/**
   * @brief Calcula la tangente de un ángulo en radianes, evitando la división por cero
   * @param angle Ángulo en radianes
   * @return La tangente de angle
   */
inline float
Tangent(float angle) {
  float sinVal = Sine(angle);
  float cosVal = Cosine(angle);
  return (cosVal != 0.0f) ? sinVal / cosVal : 0.0f;
}
