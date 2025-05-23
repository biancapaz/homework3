#pragma once
#include <memory>
using namespace std;

class IMediciones {
    public:
        // Destructor
        virtual ~IMediciones();

        // Metodos
        virtual void serealizar(ofstream& out) const = 0;
        virtual void deserealizar(ifstream& in) = 0;
};

class MedicionBase : public IMediciones {
    public:
        // Constructor
        MedicionBase(float tiempo);

        // Metodos
        void serealizar(ofstream& out) const override;
        void deserealizar(ifstream& in) override;
        float getTiempo();
        virtual void imprimir();
    
    protected:
        unique_ptr<float> tiempoMedicion;
};

class Presion : public MedicionBase {
    public:
        // Constructor
        Presion(float tiempo, float estatica, float dinamica);
        Presion(const Presion& other);

        // Metodos
        void serealizar(ofstream& out) const;
        void deserealizar(ifstream& in);
        void imprimir() override;

        // Atributos
        float estatica;
        float dinamica;
};

class Posicion : public MedicionBase {
    public:
        // Constructor
        Posicion(float tiempo, float latitud, float longitud, float altitud);
        Posicion(const Posicion& other);

        // Metodos
        void serealizar(ofstream& out) const;
        void deserealizar(ifstream& in);
        void imprimir() override;

        // Atributos
        float latitud;
        float longitud;
        float altitud;
};

class SaveFlightData {
    public:
        // Constructor
        SaveFlightData(const Posicion& posicion, const Presion& presion);

        // Metodos
        void serealizar(ofstream& out) const;
        void deserealizar(ifstream& in);
        void imprimir();

        // Atributos
        Posicion posicion;
        Presion presion;
};