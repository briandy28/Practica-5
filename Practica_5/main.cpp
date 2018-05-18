#include <iostream>
#include <vector>
#include <fstream>
# include "planeta.h"



using namespace std;

int main()
{
    int t,j,i,opc;
    fstream resultados;
    resultados.open("resultados.txt", ios::out);
    vector <Planeta> sistema1;
    vector <Planeta> sistema2;

    //Definicion del sistema 1
    Planeta p1_1(0,-7000,2,0,0,0,70,120), p1_2(0,0,0,0,0,0,70000,300), p1_3(4000,5000,-1.6,1.2,0,0,25,100);
    sistema1.push_back(p1_1);
    sistema1.push_back(p1_2);
    sistema1.push_back(p1_3);

    //Definicion del sistema 2

    Planeta p2_1(0,0,0,0,0,0,50000,200),
            p2_2(-5000,0,0,-2,0,0,70,70),
            p2_3(5000,0,0,2,0,0,70,70),
            p2_4(0,-5000,2,0,0,0,70,70),
            p2_5(0,5000,-2,0,0,0,70,70);

    sistema2.push_back(p2_1);
    sistema2.push_back(p2_2);
    sistema2.push_back(p2_3);
    sistema2.push_back(p2_4);
    sistema2.push_back(p2_5);

    cout<<"Ingrese el numero de sistema que desea ejecutar:";
    cin>>opc;

    switch (opc) {
    case 1:
        //Se guarda las posiciones iniciales en el txt
        for(i=0; i<int(sistema1.size()); i++)
        {
            resultados<<sistema1[i].getPosX()<<"\t"<<sistema1[i].getPosY()<<"\t\t";
        }
        resultados<<endl;
        //Generacion del sistema 1
        for(t=0; t<10000; t++){
            for(i=0; i<int(sistema1.size()); i++)
            {
                sistema1[i].eliminaraceleracion();

            }
            for(i=0; i<int(sistema1.size()); i++)
            {
                for(j=0; j<int(sistema1.size()); j++)
                {
                    if(j != i)
                    {
                        sistema1[i].calcularAceleracion(sistema1[j]);
                    }
                }
            }
            for(i=0; i<int(sistema1.size()); i++)
            {
                sistema1[i].calcularPosicion();
                sistema1[i].calcularVelocidad();
            }

            //Se guarda la posicion en un txt
            for(i=0; i<int(sistema1.size()); i++)
            {
                resultados<<sistema1[i].getPosX()<<"\t"<<sistema1[i].getPosY()<<"\t\t";
            }
            resultados<<endl;
        }
        break;
    case 2:
        //Se guarda las posiciones iniciales en el txt
        for( i=0; i<int(sistema2.size()); i++)
        {
            resultados<<sistema2[i].getPosX()<<"\t"<<sistema2[i].getPosY()<<"\t\t";
        }
        resultados<<endl;
        //Generacion del sistema 2
        for(t=0; t<10000; t++)
        {
            for(i=0; i<int(sistema2.size()); i++)
            {
                sistema2[i].eliminaraceleracion();

            }
            for(i=0; i<int(sistema2.size()); i++)
            {
                for(i=0; i<int(sistema1.size()); i++)
                {
                    sistema1[i].eliminaraceleracion();

                }
                for(j=0; j<int(sistema2.size()); j++)
                {
                    if(j != i)
                    {
                        sistema2[i].calcularAceleracion(sistema2[j]);
                    }
                }
            }
            for(i=0; i<int(sistema2.size()); i++)
            {
                sistema2[i].calcularPosicion();
                sistema2[i].calcularVelocidad();
            }

            //Se guarda la posicion en un txt
            for(i=0; i<int(sistema2.size()); i++)
            {
                resultados<<sistema2[i].getPosX()<<"\t"<<sistema2[i].getPosY()<<"\t\t";
            }
            resultados<<endl;
        }
        break;
    case 3:

        break;

    default:
        cout<<"Opcion Ingresada es Invalida"<<endl;
        break;
    }

    resultados.close();

    return 0;
}
