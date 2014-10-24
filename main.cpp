// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, list<Cumpleanios*>cumpleanios)
{

    ofstream out(nombre_archivo.c_str());//Abrimos el archivo en modo escritura
    if (out.is_open())//verificamos que este abierto
    for(list<Cumpleanios*>::iterator i=cumpleanios.begin();
            i!=cumpleanios.end();
            i++)                           //Recorremos la lista
{
        out<<(*i)->cumpleaniero,out<<" ",out<<(*i)->dia,out<<" ",out<<(*i)->mes,out<<"\n";//Escribimos en el archivo el cumpleañiero,el dia y el mes
    }
    out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
list<Cumpleanios*> leer(string nombre_archivo)
{
    list<Cumpleanios*>cumpleanios;
    cumpleanios.clear();//limpiamos la lista para volver a usarla
    ifstream in(nombre_archivo.c_str());//abrimos el archivo
    string cumpleanero;//guardamos el nombre del cumpleañiero
    int dia, mes;//guardamos el dia y el mes del cumpleañiero

    while(in>>cumpleanero) //mientras el archivo tenga cumpleañieros
    {
        in>>dia,in>>mes; // asignagmos el dia y el mes del cumpleañiero
        cumpleanios.push_back(new Cumpleanios(cumpleanero,dia,mes)); // agregamos el cumpleañiero a la lista
    }
    in.close();//cerramos el archivo

    return cumpleanios;// retornamos al cumpleañiero
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
