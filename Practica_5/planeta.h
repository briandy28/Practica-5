#ifndef PLANETA_H
#define PLANETA_H

#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#define DT 1
#define G 1

class Planeta
{
private:
    double posX;
    double posY;
    double velX;
    double velY;
    double acelX;
    double acelY;
    double masa;
    double radio;


public:
    Planeta();
    Planeta(double _px, double _py, double _velx, double _vely, double _acx, double _acy, double _masa, double _radio);

    double getPosX() const;
    double getPosY() const;
    double getVelX() const;
    double getVelY() const;
    double getAcelX() const;
    double getAcelY() const;
    double getMasa() const;
    double getRadio() const;

    void setPosX(double value);
    void setPosY(double value);
    void setVelX(double value);
    void setVelY(double value);
    void setAcelX(double value);
    void setAcelY(double value);
    void setMasa(double value);
    void setRadio(double value);

    void calcularAceleracion(Planeta p);
    double distanciaCuerpos(Planeta p);
    double calcularAngulo(Planeta p);
    void calcularPosicion();
    void calcularVelocidad();
    void eliminaraceleracion();
};

#endif // PLANETA_H
