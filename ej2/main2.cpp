#include "ej2.hpp"
#include <iostream>
using namespace std;

int main() {
    Punto punto(1,1);
    Circulo circ(1,1,1);
    Elipse elipse(1,1,2,3);
    Rectangulo rect(1,1,2,3);

    cout << "Datos del punto:\nX = " << punto.getX() << "\nY = " << punto.getY() << endl;
    cout << endl;
    cout << "Datos del circulo:\nX = " << circ.getX() << "\nY = " << circ.getY() << "\nRadio = " << circ.getRadio()<< endl;
    cout << endl;
    cout << "Datos del elipse:\nX = " << elipse.getX() << "\nY = " << elipse.getY() << "\nSemieje Mayor = " << elipse.getSemiejeMayor() << "\nSemieje Menor = " << elipse.getSemiejeMenor() << endl;
    cout << endl;
    cout << "Datos del rectangulo:\nX = " <<  rect.getX() << "\nY = " << rect.getY() << "\nBase = " << rect.getBase()<< "\nAltura = " << rect.getAltura() << endl;
    cout << endl;

    cout << "Areas" << endl;
    ProcesadorFigura<Circulo> f1;
    cout << "Area del circulo: " << f1.calcularArea(circ) << endl;

    ProcesadorFigura<Elipse> f2;
    cout << "Area del elipse: " << f2.calcularArea(elipse) << endl;

    ProcesadorFigura<Rectangulo> f3;
    cout << "Area del rectangulo: " << f3.calcularArea(rect) << endl;

    return 0;
}