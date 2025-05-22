#pragma once
using namespace std;

class Punto {
    public:
        // Constructor
        Punto(int x, int y);

        // Metodos
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;

    private:
        // Atributos
        int x;
        int y;
};

class Circulo : public Punto {
    public:
        // Constructor
        Circulo(int x, int y, int radio);

        // Metodos
        void setRadio(int radio);
        int getRadio() const;

    private:
        // Atributos
        int radio;
};

class Elipse : public Punto {
    public:
        // Constructor
        Elipse(int x, int y, int semiejeMenor, int semiejeMayor);

        // Metodos
        void setSemiejeMenor(int semiejeMenor);
        void setSemiejeMayor(int semiejeMayor);
        int getSemiejeMenor() const;
        int getSemiejeMayor() const;

    private:
        // Atributos
        int semiejeMenor;
        int semiejeMayor;
        
};

class Rectangulo : public Punto {
    public:
        // Constructor
        Rectangulo(int x, int y, int base, int altura); // (x , y) es la poscicion de su vertice izquierdo inferior

        // Metodos
        void setBase(int base);
        void setAltura(int altura);
        int getBase() const;
        int getAltura() const;

    private:
        // Atributos
        int base;
        int altura;
};

// Declaración general del template
template<typename T>
class ProcesadorFigura;

// Especialización para Circulo
template<>
class ProcesadorFigura<Circulo> {
    public:
        float calcularArea(const Circulo& circulo);
};

// Especialización para Elipse
template<>
class ProcesadorFigura<Elipse> {
    public:
        float calcularArea(const Elipse& elipse);
};

// Especialización para Rectangulo
template<>
class ProcesadorFigura<Rectangulo> {
    public:
        int calcularArea(const Rectangulo& rect);
};