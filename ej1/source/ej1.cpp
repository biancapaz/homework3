#include "headers/ej1.hpp"
#include <iostream>
#include <fstream>
using namespace std;

// Implementacion -> Imediciones
IMediciones::~IMediciones() = default;

// Implemetacion -> MedicionBase

MedicionBase::MedicionBase(float tiempo) {
    tiempoMedicion = make_unique<float>(tiempo); 
    if (tiempoMedicion == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
    }
};

void MedicionBase::serealizar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
};
void MedicionBase::deserealizar(ifstream& in) {
    tiempoMedicion = make_unique<float>(0.0f);
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
};
float MedicionBase::getTiempo() const {
    return *tiempoMedicion;
};
void MedicionBase::imprimir() const {
    cout << "Tiempo de medicion:" << *tiempoMedicion << endl;
};

// Implementacion -> Presion

Presion::Presion(float tiempo, float estatica, float dinamica) : MedicionBase(tiempo), estatica(estatica), dinamica(dinamica) {};
Presion::Presion(const Presion& other) : MedicionBase(*other.tiempoMedicion), estatica(other.estatica), dinamica(other.dinamica) {};

void Presion::serealizar(ofstream& out) const {
    MedicionBase::serealizar(out);
    out.write(reinterpret_cast<const char*>(&estatica), sizeof(estatica));
    out.write(reinterpret_cast<const char*>(&dinamica), sizeof(dinamica));
};
void Presion::deserealizar(ifstream& in) {
    MedicionBase::deserealizar(in);
    in.read(reinterpret_cast<char*>(&estatica), sizeof(estatica));
    in.read(reinterpret_cast<char*>(&dinamica), sizeof(dinamica));
};
void Presion::imprimir() const {
    MedicionBase::imprimir();
    cout << "Presion estatica: " << estatica << endl;
    cout << "Presion dinamica: " << dinamica << endl;
};

// Implementacion -> Posicion

Posicion::Posicion(float tiempo, float latitud, float longitud, float altitud) : MedicionBase(tiempo), latitud(latitud), longitud(longitud), altitud(altitud) {};
Posicion::Posicion(const Posicion& other) : MedicionBase(*other.tiempoMedicion), latitud(other.latitud), longitud(other.longitud), altitud(other.altitud) {};

void Posicion::serealizar(ofstream& out) const {
    MedicionBase::serealizar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
};
void Posicion::deserealizar(ifstream& in) {
    MedicionBase::deserealizar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
};
void Posicion::imprimir() const {
    MedicionBase::imprimir();
    cout << "Latitud: " << latitud << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Altitud: " << altitud << endl;
};

// Implementacion -> SaveFlightData

SaveFlightData::SaveFlightData(const Posicion& posicion, const Presion& presion) : posicion(posicion), presion(presion) {};

void SaveFlightData::serealizar(ofstream& out) const {
    posicion.serealizar(out);
    presion.serealizar(out);
};
void SaveFlightData::deserealizar(ifstream& in) {
    posicion.deserealizar(in);
    presion.deserealizar(in);
};
void SaveFlightData::imprimir() const {
    cout << "Posicion ->" << endl;
    posicion.imprimir();

    cout << "Presion ->" << endl;
    presion.imprimir();
};