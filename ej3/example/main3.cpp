#include "headers/ej3.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    GeneradorVectores g;
    vector<int> a = {1,2};
    vector<int> b = {3,4};

    g.agregar_valor(a);
    g.agregar_valor(b);

    string s1 = "Hola";
    string s2 = "Mundo";

    g.agregar_valor(s1);
    g.agregar_valor(s2);

    g.agregar_valor(1.3);
    g.agregar_valor(2.1);
    g.agregar_valor(3.2);

    GeneradorJSON j;
    j.construirJSON(g);
    j.mostrarJSON();
}