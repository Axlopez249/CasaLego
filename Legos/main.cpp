#include <iostream>
#include <string>
#include "Lista.h"
#include <vector>

using namespace std;

int main(){
    //Reglas
    string piezas[7] = {"pizo", "pieza_pared", "puerta", "ventana", "techo", "cielo razo", "hueco"};
    string objetos[6][3] = {{"cimiento", "pizo", 5, 1}, {"cuartos","pieza_pared", 20, 2}, {"cocina", "pieza_pared" 20, 1},
     {"comedor", "pieza_pared" 20, 1}, {"terraza", "pieza pared", 10, 1}, {"piscina","hueco", 1, 1}};
    //El nombre, tipo de pieza a utilizar, la cantidad de piezas a utilizar, la cantidad de objetos

    string orden[6] = {"cimiento", "cuartos", "cocina", "comedor", "terraza", "piscina"};
    //orden de la pila
    
    //cada uno tiene una puerta y una ventana por eso no se pone
    //4 piezas_pared es una pared
    //5 piezas pizo es un cimiento
    //la cocina es un cuarto practicamente al igual que el comedor y los cuartos como tal


    

    //Creacion de la cola
    Queue<string> *cola_piezas = new List<string>();
    Queue<string> *cola_objetos = new List<string>();



    //ingreso a colas de piezas
    for (int i = 0; i < 6; i++)
    {
        cola_objetos->enqueue(&objetos[i][0]);
    }


    //Futura Impresion se está implementando mientras se crean las reglas jajsjja
    /*int contador = 0;
    while (!cola_objetos->isEmpty()){
        string *objeto = cola_objetos->dequeue();

        for (int i = 0; i < 6; i++){
            if (*objeto == objetos[i][0]){
                int cantidad_piezas = objetos[i][1];

                
                

            }
        }
                
    }*/

    






    

   
}

//Reglas y orden para construir una casa
/*
    2 cuartos cada cuarto con 4 paredes
    sala 4 paredes
    comedor 4 paredes
    cocina 4 paredes
    terraza 4 paredes
    piscina hueco
*/

//Se va a crear una cola para meter la informacion en orden de prioridad
//Se pondrá en una pila para asimilar la construccion de la casa


