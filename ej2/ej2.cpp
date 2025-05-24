#include "ej2.hpp"
#include <iostream>
using namespace std;
#define PI 3.14159

// Implementacion -> Punto

Punto::Punto(float x, float y) : x(x), y(y) {};

void Punto::setX(float x) {
    this->x = x;
};
void Punto::setY(float y) {
    this->y = y;
};
float Punto::getX() const {
    return this->x;
};
float Punto::getY() const {
    return this->y;
};


// Implementacion -> Circulo

Circulo::Circulo(float x, float y, float radio) : Punto(x, y), radio(radio) {};

void Circulo::setRadio(float radio) {
    this->radio = radio;
};
float Circulo::getRadio() const {
    return this->radio;
};

// Implementacion -> Elipse

Elipse::Elipse(float x, float y, float semiejeMenor, float semiejeMayor) : Punto(x, y), semiejeMenor(semiejeMenor), semiejeMayor(semiejeMayor) {};

void Elipse::setSemiejeMenor(float semiejeMenor) {
    this->semiejeMenor = semiejeMenor;
};
void Elipse::setSemiejeMayor(float semiejeMayor) {
    this->semiejeMayor = semiejeMayor;
};
float Elipse::getSemiejeMenor() const {
    return this->semiejeMenor;
};
float Elipse::getSemiejeMayor() const {
    return this->semiejeMayor;
};


// Implementacion -> Rectangulo

Rectangulo::Rectangulo(float x, float y, float base, float altura) : Punto(x, y), base(base), altura(altura) {};

void Rectangulo::setBase(float base) {
    this->base = base;
};
void Rectangulo::setAltura(float altura) {
    this->altura = altura;
};
float Rectangulo::getBase() const {
    return this->base;
};
float Rectangulo::getAltura() const {
    return this->altura;
};

// implementacion -> ProcesadorArea
int ProcesadorFigura<Punto>::calcularArea(const Punto& punto) {
    // area del punto = 0
    return 0;
};
float ProcesadorFigura<Circulo>::calcularArea(const Circulo& circulo) {
    // area del círculo = pi * r^2
    return PI * (circulo.getRadio() * circulo.getRadio());
};
float ProcesadorFigura<Elipse>::calcularArea(const Elipse& elipse) {
    // area del elipse = pi * semieje mayor * semieje menor
    return PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
};
float ProcesadorFigura<Rectangulo>::calcularArea(const Rectangulo& rect) {
    // area del rectangulo = base * altura
    return rect.getBase() * rect.getAltura();
}