#include "ej3.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    GeneradorVectores<vector<int>> g;
    vector<int> a = {1,2};
    vector<int> b = {3,4};
    vector<int> c = {5,6};

    g.agregar_valor(a);
    g.agregar_valor(b);
    g.agregar_valor(c);

    string s = g.procesar_vector();
    cout<< s;
    
}