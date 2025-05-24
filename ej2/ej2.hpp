#pragma once
using namespace std;

class Punto {
    public:
        // Constructor
        Punto(float x, float y);

        // Metodos
        void setX(float x);
        void setY(float y);
        float getX() const;
        float getY() const;

    private:
        // Atributos
        float x;
        float y;
};

class Circulo : public Punto {
    public:
        // Constructor
        Circulo(float x, float y, float radio);

        // Metodos
        void setRadio(float radio);
        float getRadio() const;

    private:
        // Atributos
        float radio;
};

class Elipse : public Punto {
    public:
        // Constructor
        Elipse(float x, float y, float semiejeMenor, float semiejeMayor);

        // Metodos
        void setSemiejeMenor(float semiejeMenor);
        void setSemiejeMayor(float semiejeMayor);
        float getSemiejeMenor() const;
        float getSemiejeMayor() const;

    private:
        // Atributos
        float semiejeMenor;
        float semiejeMayor;   
};

class Rectangulo : public Punto {
    public:
        // Constructor
        Rectangulo(float x, float y, float base, float altura); // (x , y) es la poscicion de su vertice izquierdo inferior

        // Metodos
        void setBase(float base);
        void setAltura(float altura);
        float getBase() const;
        float getAltura() const;

    private:
        // Atributos
        float base;
        float altura;
};

// Declaración general del template
template<typename T>
class ProcesadorFigura;

// Especialización para Circulo
template<>
class ProcesadorFigura<Punto> {
    public:
        int calcularArea(const Punto& punto);
};

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
        float calcularArea(const Rectangulo& rect);
};