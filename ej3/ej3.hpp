#pragma once
#include <vector>
#include <string>
using namespace std;

template<typename T>
class GeneradorVectores {
    public:
        // Constructor
        GeneradorVectores();

        // Metodos
        void agregar_valor(T value);
        string procesar_vector() {
            if constexpr(is_same_v<T, double>) {
                string res = '[';
                for (double value : datos) {
                    res += to_string(value) + ", ";
                }
                res += ']';
                return res;
            }
            else if constexpr(is_same_v<T, string>) {
                string res = '[';
                for (double value : datos) {
                    res += "\"" + value + "\", ";
                }
                res += ']';
                return res;
            }
            else if constexpr(is_same_v<T, vector<int>) {
                string res = '[\n';
                for (vector<int> vect : datos) {
                    res += '[';
                    for (int value : vect) {
                        res += to_string(value) + ", ";
                    }
                    res += '],\n';
                }
                res += ']';
                return res;
            }
        };
    
    private:
        vector<T> datos;
};