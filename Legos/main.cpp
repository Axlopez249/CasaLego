#include <iostream>
#include <string>
#include "Lista.h"
#include "Objetos.h"
#include <vector>



using namespace std;


int main(){
    //variables booleanas


    //Material
    int piezas_piso = 1000;
    int piezas_paredes = 1000;
    int piezas_techo = 1000;
    int piezas_cielo = 1000;

    //Cantidad de objetos
    int cuarto_ = 0;
    int cocina_ = 0;
    int comedor_ = 0;
    int terraza_ = 0;
    int piscina_ = 0;

    //Cantidad de piezas por objeto
    int cantPiso = 30;
    int cantParedes = 16;
    int cantCuarto = 4;
    int cantCocina = 4;
    int cantComedor = 4;
    int cantCielo = 20;
    int cantTecho = 5;
    int cantTerraza = 5;
    int cantPiscina = 20;

    //Reglas
    string piezas[7] = {"piso", "pieza_pared", "puerta", "ventana", "techo", "cielo razo", "hueco"};

    string objetos[8][4] = {{"cimiento", "piso", "5", "1"}, 
                            {"cuartos","pieza_pared", "20", "2"},
                            {"cocina", "pieza_pared", "20", "1"},
                            {"comedor", "pieza_pared", "20", "1"},
                            {"techo", "piezas_techo", "20", "1"},
                            {"cielo", "piezas_cielo", "30", "1"},
                            {"terraza", "pieza_pared", "10", "1"},
                            {"piscina","pizo", "1", "1"}};

    //El nombre, tipo de pieza a utilizar, la cantidad de piezas a utilizar, la cantidad de objetos

    string orden[8] = {"cimiento", "cuartos", "cocina", "comedor", "cielo_raso", "techo", "terraza", "piscina"};
    //orden de la pila
    
    //List<string> *stack;
    Stack<string> *pila = new List<string>();
    Queue<string> *cola = new List<string>();
    Stack<int> *pila_cant_mat = new List<int>();
    
    
    for (int i = 0; i < 8; i++)
    {
        if (objetos[i][0] == "cimiento")
        {
            cimiento cimiento_1;
            int cantidad = stoi(objetos[i][3]);
            cimiento_1.crearPiso(piezas_piso, cantPiso);
            cola->enqueue(&objetos[i][0]);
            
        }
        if (objetos[i][0] == "cuartos")
        {
            cuarto cuarto_1;
            int cantidad = stoi(objetos[i][3]);
            cuarto_1.crearCuarto(cantidad, piezas_paredes, cantCuarto);
            cola->enqueue(&objetos[i][3]);
            cuarto_++;

        }
        if (objetos[i][0] == "cocina")
        {
            cocina cocina_1;
            int cantidad = stoi(objetos[i][3]);
            cocina_1.crearCocina(cantidad, piezas_paredes, cantCocina);
            cola->enqueue(&objetos[i][3]);
            cocina_++;

        }
        if (objetos[i][0] == "comedor")
        {
            comedor comedor_1;
            int cantidad = stoi(objetos[i][3]);
            comedor_1.crearComedor(cantidad, piezas_paredes, cantComedor);
            cola->enqueue(&objetos[i][3]);
            comedor_++;

        }
        if (objetos[i][0] == "techo")
        {
            techo techo_1;
            techo_1.crearTecho(piezas_techo, cantTecho);
            cola->enqueue(&objetos[i][3]);

        }
        if (objetos[i][0] == "cielo")
        {
            cielo cielo_1;
            cielo_1.crearCielo(piezas_cielo, cantCielo);
            cola->enqueue(&objetos[i][3]);

        }
        
        if (objetos[i][0] == "terraza")
        {
            terraza terraza_1;
            int cantidad = stoi(objetos[i][3]);
            terraza_1.crearTerraza(cantidad, piezas_techo, cantTerraza);
            cola->enqueue(&objetos[i][3]);
            terraza_++;

        }
        if (objetos[i][0] == "piscina")
        {
            piscina piscina_1;
            int cantidad = stoi(objetos[i][3]);
            piscina_1.crearPiscina(cantidad, piezas_piso, piezas_paredes, cantPiscina);
            cola->enqueue(&objetos[i][3]);
            piscina_++;
        }
    };


    //Todos los nombres están dentro de la cola
    //se pasan a la pila segun el orden predeterminado

    int contador = 0;
    while (!cola->isEmpty())
    {
        string *objeto = cola->dequeue();
        //Se saca el objeto y se procede a comparar con el orden del arreglo
        //si el objeto no coincide con el orden se vuelve a encolar
        //para luego apilarlo posteriormente
        if (*objeto == orden[contador])
        {
            pila->push(objeto);
            contador ++;

            //se van apilando los materiales y las cantidades
            if (objetos[contador][0] == "cimiento"){pila_cant_mat->push(&cantPiso);}
            if (objetos[contador][0] == "cuartos"){pila_cant_mat->push(&cantCuarto);}
            if (objetos[contador][0] == "cocina"){pila_cant_mat->push(&cantCocina);}
            if (objetos[contador][0] == "comedor"){pila_cant_mat->push(&cantComedor);}
            if (objetos[contador][0] == "techo"){pila_cant_mat->push(&cantTecho);}
            if (objetos[contador][0] == "cielo"){pila_cant_mat->push(&cantCielo);}
            if (objetos[contador][0] == "terraza"){pila_cant_mat->push(&cantTerraza);}
            if (objetos[contador][0] == "piscina"){pila_cant_mat->push(&cantPiscina);}
            
            

        }else{
            cola->enqueue(objeto);
        }
        

    }
    
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


