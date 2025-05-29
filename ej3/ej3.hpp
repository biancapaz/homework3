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
        };

        tuple<string, string, string> procesar_vector();
        string vectDouble_ToString();
        string vectString_ToString();
        string vectVectInt_ToString();
    
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
        void mostrarJSON();
    
    private:
        string doubles;
        string palabras;
        string vectInts;
        string JSON;
};