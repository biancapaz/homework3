#include "ej2.hpp"
#include <iostream>
using namespace std;
#define PI 3.14159

// Implementacion -> Punto

Punto::Punto(int x, int y) : x(x), y(y) {};

void Punto::setX(int x) {
    this->x = x;
};
void Punto::setY(int y) {
    this->y = y;
};
int Punto::getX() const {
    return this->x;
};
int Punto::getY() const {
    return this->y;
};


// Implementacion -> Circulo

Circulo::Circulo(int x, int y, int radio) : Punto(x, y), radio(radio) {};

void Circulo::setRadio(int radio) {
    this->radio = radio;
};
int Circulo::getRadio() const {
    return this->radio;
};

// Implementacion -> Elipse

Elipse::Elipse(int x, int y, int semiejeMenor, int semiejeMayor) : Punto(x, y), semiejeMenor(semiejeMenor), semiejeMayor(semiejeMayor) {};

void Elipse::setSemiejeMenor(int semiejeMenor) {
    this->semiejeMenor = semiejeMenor;
};
void Elipse::setSemiejeMayor(int semiejeMayor) {
    this->semiejeMayor = semiejeMayor;
};
int Elipse::getSemiejeMenor() const {
    return this->semiejeMenor;
};
int Elipse::getSemiejeMayor() const {
    return this->semiejeMayor;
};


// Implementacion -> Rectangulo

Rectangulo::Rectangulo(int x, int y, int base, int altura) : Punto(x, y), base(base), altura(altura) {};

void Rectangulo::setBase(int base) {
    this->base = base;
};
void Rectangulo::setAltura(int altura) {
    this->altura = altura;
};
int Rectangulo::getBase() const {
    return this->base;
};
int Rectangulo::getAltura() const {
    return this->altura;
};

// implementacion -> ProcesadorArea
float ProcesadorFigura<Circulo>::calcularArea(const Circulo& circulo) {
    // area del círculo = pi * r^2
    return PI * (circulo.getRadio() * circulo.getRadio());
};
float ProcesadorFigura<Elipse>::calcularArea(const Elipse& elipse) {
    // area del elipse = pi * semieje mayor * semieje menor
    return PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
};
int ProcesadorFigura<Rectangulo>::calcularArea(const Rectangulo& rect) {
    // area del rectangulo = base * altura
    return rect.getBase() * rect.getAltura();
}