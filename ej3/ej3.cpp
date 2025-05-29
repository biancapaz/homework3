#include "ej3.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Implementacion -> GeneradorVectores

GeneradorVectores::GeneradorVectores(){
    this->vectDouble = vector<double>();
    this->vectString = vector<string>();
    this->vectVectInt = vector<vector<int>>();
};

tuple<string, string, string> GeneradorVectores::procesar_vector() {
    return make_tuple(vectDouble_ToString(), vectString_ToString(), vectVectInt_ToString()); 
};
string GeneradorVectores::vectDouble_ToString() {
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
string GeneradorVectores::vectString_ToString(){
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
string GeneradorVectores::vectVectInt_ToString(){
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
    tuple t = v.procesar_vector();
    doubles = "\"vec_doubles\":" + get<0>(t);
    palabras = "\"palabras\":" + get<1>(t);
    vectInts = "\"listas\":" + get<2>(t);
};
void GeneradorJSON::mostrarJSON() {
    JSON = "{ " + doubles + "  " + palabras + "  " +  vectInts + '}';
    cout << JSON << endl;
};