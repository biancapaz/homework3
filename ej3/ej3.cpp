//#include "ej3.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Implementacion -> GeneradorVectores

template<typename T>
class GeneradorVectores {
    public:
        // Constructor
        GeneradorVectores() {
            this->datos = vector<T>();
        };

        // Metodos
        void agregar_valor(T value) {
            this->datos.push_back(value);
        };
        string procesar_vector() {
            string res = "[";

            if constexpr(is_same_v<T, double>) {
                for (size_t i = 0; i < datos.size(); i++){
                    res += to_string(datos[i]);
                    if (i != datos.size() - 1) {
                       res += ", "; 
                    }
                }
            }
            else if constexpr(is_same_v<T, string>) {
                for (size_t i = 0; i < datos.size(); i++){
                    res += "\"" + datos[i] + "\"";
                    if (i != datos.size() - 1) {
                       res += ", "; 
                    }
                }
            }
            else if constexpr(is_same_v<T, vector<int>>) {
                for (size_t i = 0; i < datos.size(); i++) {
                    res += "\n[";
                    for (size_t j = 0; j < datos[i].size(); j++) {
                        res += to_string(datos[i][j]);
                        if (j != datos[i].size() - 1) {
                            res += ", "; 
                        }   
                    }
                    res += "]";
                    if (i != datos.size() - 1) {
                            res += ", "; 
                        } 
                }
                res += '\n';
            }

            res += "]\n";
            return res;
        };
    
    private:
        vector<T> datos;
};

class JSON {
    public:
        
};