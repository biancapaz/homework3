#include "headers/ej3.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Implementacion -> GeneradorVectores

GeneradorVectores::GeneradorVectores(){
    this->vectDouble = vector<double>();
    this->vectString = vector<string>();
    this->vectVectInt = vector<vector<int>>();
};

string GeneradorVectores::vectDouble_ToString() const{
    string res = "[";
    for (size_t i = 0; i < vectDouble.size(); i++){
        res += to_string(vectDouble[i]);
        if (i != vectDouble.size() - 1) {
            res += ", "; 
        }
    }
    res += "],\n";
    return res;
};
string GeneradorVectores::vectString_ToString() const {
    string res = "[";
    for (size_t i = 0; i < vectString.size(); i++){
        res += "\"" + vectString[i] + "\"";
        if (i != vectString.size() - 1) {
            res += ", "; 
        }
    }
    res += "],\n";
    return res;
};
string GeneradorVectores::vectVectInt_ToString() const {
    string res = "[";
    for (size_t i = 0; i < vectVectInt.size(); i++) {
        res += "\n\t[";
        for (size_t j = 0; j < vectVectInt[i].size(); j++) {
            res += to_string(vectVectInt[i][j]);
            if (j != vectVectInt[i].size() - 1) {
                res += ", "; 
            }   
        }
        res += "]";
        if (i != vectVectInt.size() - 1) {
            res += ", "; 
        } 
    }
    res += "\n\t]\n";
    return res;
};

// Implementacion -> GeneradorJSON

void GeneradorJSON::construirJSON(GeneradorVectores& v) {
    doubles = "\"vec_doubles\":" + v.procesar_vector<double>();
    palabras = "\"palabras\":" + v.procesar_vector<string>();
    vectInts = "\"listas\":" + v.procesar_vector<vector<int>>();
};
void GeneradorJSON::mostrarJSON() const {
    cout << "{ " + doubles + "  " + palabras + "  " +  vectInts + '}' << endl;
};