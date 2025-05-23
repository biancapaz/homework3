#include "ej1.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);

    SaveFlightData fd1(posicion, presion);
    fd1.imprimir();

    // serealizamos fd1
    ofstream out("fd1.dat", ios::binary);
    if (out.is_open()) {
        fd1.serealizar(out);
        out.close();
    }

    Posicion pos2(0.0f, 0.0f, 0.0f, 0.0f);
    Presion pre2(0.0f, 0.0f, 0.0f);
    SaveFlightData fd2(pos2, pre2);

    ifstream in("fd1.dat", ios::binary);
    if (in.is_open()) {
        fd2.deserealizar(in);
        in.close();
    }

    cout << "\nimprimo fd2" << endl;
    fd2.imprimir();
    
    return 0;
}