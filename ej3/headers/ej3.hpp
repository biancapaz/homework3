#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

class GeneradorVectores {
    public:
        // Constructor
        GeneradorVectores();

        // Metodos
        template<typename T>
        void agregar_valor(T value) {
            if constexpr(is_same_v<T, double>) {
                this->vectDouble.push_back(value);
            }
            else if constexpr(is_same_v<T, string>) {
                this->vectString.push_back(value);
            }
            else if constexpr(is_same_v<T, vector<int>>) {
                this->vectVectInt.push_back(value);
            }
            else {
                cout << "no es double, string ni vector de ints" << endl;
            }
        }

        template<typename T>
        string procesar_vector() const {
            if constexpr(is_same_v<T, double>) {
                return vectDouble_ToString();
            }
            else if constexpr(is_same_v<T, string>) {
                return vectString_ToString();
            }
            else if constexpr(is_same_v<T, vector<int>>) {
                return vectVectInt_ToString();
            }
            else {
                return "Tipo no soportado";
            }
        }

        string vectDouble_ToString() const;
        string vectString_ToString() const;
        string vectVectInt_ToString() const;
    
    private:
        vector<double> vectDouble;
        vector<string> vectString;
        vector<vector<int>> vectVectInt;
};

class GeneradorJSON {
    public:
        // Constructor
        GeneradorJSON(){};

        //Metodos
        void construirJSON(GeneradorVectores& v);
        void mostrarJSON() const;
    
    private:
        string doubles;
        string palabras;
        string vectInts;
};