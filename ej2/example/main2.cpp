#include "headers/ej2.hpp"
#include <iostream>
using namespace std;

int main() {
    Punto punto(1.5,1);
    Circulo circ(1,1.7,1);
    Elipse elipse(1,1,2,3.4);
    Rectangulo rect(1,1.3,2,3);

    cout << "Mostar Datos Figuras:" << endl;
    punto.mostrarDatos();
    cout << endl;
    circ.mostrarDatos();
    cout << endl;
    elipse.mostrarDatos();
    cout << endl;
    rect.mostrarDatos();
    cout << endl;

    // Probar metodos de las figuras
    cout << "Probando funcionalidades:" << endl;
    cout << endl;

    cout << "X del punto: " << punto.getX() << endl;
    cout << "Cambio X del punto a 10..." << endl;
    punto.setX(10);
    cout << "Nuevo X del punto: " << punto.getX() << endl;
    cout << "Y del punto: " << punto.getY() << endl;
    cout << "Cambio Y del punto a 8..." << endl;
    punto.setY(8);
    cout << "Nuevo X del punto: " << punto.getY() << endl;

    cout << endl;

    cout << "Radio del circulo: " << circ.getRadio() << endl;
    cout << "Radio del circulo: " << circ.getRadio() << endl;
    cout << "Cambio Radio del circulo a 5..." << endl;
    circ.setRadio(5);
    cout << "Nuevo Radio del circulo: " << circ.getRadio() << endl;

    cout << endl;

    cout << "Semieje menor del elipse: " << elipse.getSemiejeMenor() << endl;
    cout << "Cambio Semieje menor del elipse a 4..." << endl;
    elipse.setSemiejeMenor(4);
    cout << "Nuevo Semieje menor del elipse: " << elipse.getSemiejeMenor() << endl;
    cout << "Semieje mayor del elipse: " << elipse.getSemiejeMayor() << endl;
    cout << "Cambio Semieje mayor del elipse a 6..." << endl;
    elipse.setSemiejeMayor(6);
    cout << "Nuevo Semieje mayor del elipse: " << elipse.getSemiejeMayor() << endl;
    
    cout << endl;
    
    cout << "Base del rectangulo: " << rect.getBase() << endl;
    cout << "Cambio Base del rectangulo a 4..." << endl;
    rect.setBase(4);
    cout << "Nuevo Base del rectangulo: " << rect.getBase() << endl;
    cout << "Altura del rectangulo: " << rect.getAltura() << endl;
    cout << "Cambio Altura del rectangulo a 5..." << endl;
    rect.setAltura(5);
    cout << "Nuevo Altura del rectangulo: " << rect.getAltura() << endl;
    
    cout << endl;

    // Calcular areas de las figuras
    cout << "Calcular Areas Figuras:" << endl;
    ProcesadorFigura<Punto> f0;
    cout << "Area del punto: " << f0.calcularArea(punto) << endl;

    ProcesadorFigura<Circulo> f1;
    cout << "Area del circulo: " << f1.calcularArea(circ) << endl;

    ProcesadorFigura<Elipse> f2;
    cout << "Area del elipse: " << f2.calcularArea(elipse) << endl;

    ProcesadorFigura<Rectangulo> f3;
    cout << "Area del rectangulo: " << f3.calcularArea(rect) << endl;

    return 0;
}