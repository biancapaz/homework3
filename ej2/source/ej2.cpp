#include "headers/ej2.hpp"
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
void Punto::mostrarDatos() const {
    cout << "Datos del punto:" << endl;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
};


// Implementacion -> Circulo

Circulo::Circulo(float x, float y, float radio) : Punto(x, y), radio(radio) {};

void Circulo::setRadio(float radio) {
    this->radio = radio;
};
float Circulo::getRadio() const {
    return this->radio;
};
void Circulo::mostrarDatos() const {
    cout << "Datos del circulo:" << endl;
    cout << "X = " << this->getX() << endl;
    cout << "Y = " << this->getY() << endl;
    cout << "Radio = " << radio << endl;
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
void Elipse::mostrarDatos() const {
    cout << "Datos del elipse:" << endl;
    cout << "X = " << this->getX() << endl;
    cout << "Y = " << this->getY() << endl;
    cout << "Semieje Menor = " << semiejeMenor << endl;
    cout << "Semieje Mayor = " << semiejeMayor << endl;
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
void Rectangulo::mostrarDatos() const {
    cout << "Datos del rectangulo:" << endl;
    cout << "X = " << this->getX() << endl;
    cout << "Y = " << this->getY() << endl;
    cout << "Base = " << base << endl;
    cout << "Altura = " << altura << endl;
};

// implementacion -> ProcesadorArea
int ProcesadorFigura<Punto>::calcularArea(const Punto& punto) const {
    // area del punto = 0
    return 0;
};
float ProcesadorFigura<Circulo>::calcularArea(const Circulo& circulo) const {
    // area del círculo = pi * r^2
    return PI * (circulo.getRadio() * circulo.getRadio());
};
float ProcesadorFigura<Elipse>::calcularArea(const Elipse& elipse) const {
    // area del elipse = pi * semieje mayor * semieje menor
    return PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
};
float ProcesadorFigura<Rectangulo>::calcularArea(const Rectangulo& rect) const {
    // area del rectangulo = base * altura
    return rect.getBase() * rect.getAltura();
}