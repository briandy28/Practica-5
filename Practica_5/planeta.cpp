#include "planeta.h"

double Planeta::getPosX() const
{
    return posX;
}
double Planeta::getPosY() const
{
    return posY;
}
double Planeta::getVelX() const
{
    return velX;
}
double Planeta::getVelY() const
{
    return velY;
}
double Planeta::getAcelX() const
{
    return acelX;
}
double Planeta::getAcelY() const
{
    return acelY;
}
double Planeta::getMasa() const
{
    return masa;
}
double Planeta::getRadio() const
{
    return radio;
}

void Planeta::setPosX(double value)
{
    posX = value;
}
void Planeta::setPosY(double value)
{
    posY = value;
}
void Planeta::setVelX(double value)
{
    velX = value;
}
void Planeta::setVelY(double value)
{
    velY = value;
}
void Planeta::setAcelX(double value)
{
    acelX = value;
}
void Planeta::setAcelY(double value)
{
    acelY = value;
}
void Planeta::setMasa(double value)
{
    masa = value;
}
void Planeta::setRadio(double value)
{
    radio = value;
}

Planeta::Planeta()
{

}

Planeta::Planeta(double _px, double _py, double _velx, double _vely, double _acx, double _acy, double _masa, double _radio)
{
    posX = _px;
    posY = _py;
    velX = _velx;
    velY = _vely;
    acelX = _acx;
    acelY = _acy;
    masa = _masa;
    radio = _radio;
}



double Planeta::distanciaCuerpos(Planeta p)
{
    double r;
    r = sqrt(pow((this->posX - p.posX),2) + pow((this->posY - p.posY), 2));
    return r;
}

double Planeta::calcularAngulo(Planeta p)
{
    double ang;
    ang = atan2(p.posY - this->posY, p.posX - this->posX);
    return ang;
}


void Planeta::calcularAceleracion(Planeta p)
{
    double angulo;
    double r;

    angulo= this->calcularAngulo(p);
    r= this->distanciaCuerpos(p);

    acelX += ((G*p.masa) / pow(r,2)) * cos(angulo);
    acelY += ((G*p.masa) / pow(r,2)) * sin(angulo);
}

void Planeta::calcularPosicion()
{
     this->posX=  this->posX +  this->velX*DT +  (this->acelX * pow(DT,2))/2.0;
     this->posY=  this->posY +  this->velY*DT +  (this->acelY * pow(DT,2))/2.0;
}

void Planeta::calcularVelocidad()
{
    this->velX =  this->velX + acelX*DT;
     this->velY =  this->velY + acelY*DT;
}

void Planeta::eliminaraceleracion()
{
    this->acelX=0;
    this->acelY=0;
}
