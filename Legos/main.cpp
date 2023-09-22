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
    int cuarto_ = 2;
    int cocina_ = 1;
    int comedor_ = 1;
    int terraza_ = 1;
    int piscina_ = 1;

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
                            {"cocina", "pieza_pared" "20", "1"},
                            {"comedor", "pieza_pared", "20", "1"},
                            {"techo", "piezas_techo", "20", "1"},
                            {"cielo", "piezas_cielo", "30", "1"},
                            {"terraza", "pieza_pared", "10", "1"},
                            {"piscina","pizo", "1", "1"}};

    //El nombre, tipo de pieza a utilizar, la cantidad de piezas a utilizar, la cantidad de objetos

    string orden[8] = {"cimiento", "cuartos", "cocina", "comedor", "cielo_raso", "techo", "terraza", "piscina"};
    //orden de la pila
    
    List<string> *stack;
    Stack<string> pila = stack;
    Queue<string> cola = stack;
    
    
    for (int i = 0; i < 6; i++)
    {
        if (objetos[i][0] == "cimiento")
        {
            cimiento cimiento_1;
            int cantidad = stoi(objetos[i][3]);
            cimiento_1.crearPiso(cantidad, piezas_piso, cantPiso);
            pila.push(new string("Cimiento"));
            
        }
        if (objetos[i][0] == "cuartos")
        {
            cuarto cuarto_1;
            int cantidad = stoi(objetos[i][3]);
            cuarto_1.crearCuarto(cantidad, piezas_paredes, cantCuarto);
            pila.push(new string("cuarto"));
            cuarto_++;

        }
        if (objetos[i][0] == "cocina")
        {
            cocina cocina_1;
            int cantidad = stoi(objetos[i][3]);
            cocina_1.crearCocina(cantidad, piezas_paredes, cantCocina);
            pila.push(new string("cocina"));
            cocina_++;

        }
        if (objetos[i][0] == "comedor")
        {
            comedor comedor_1;
            int cantidad = stoi(objetos[i][3]);
            comedor_1.crearComedor(cantidad, piezas_paredes, cantComedor);
            pila.push(new string("comedor"));
            comedor_++;

        }
        if (objetos[i][0] == "techo")
        {
            techo techo_1;
            techo_1.crearTecho(piezas_techo, cantTecho);
            pila.push(new string("techo"));

        }
        if (objetos[i][0] == "cielo")
        {
            cielo cielo_1;
            cielo_1.crearCielo(piezas_cielo, cantCielo);
            pila.push(new string("cielo"));

        }
        
        if (objetos[i][0] == "terraza")
        {
            terraza terraza_1;
            int cantidad = stoi(objetos[i][3]);
            terraza_1.crearTerraza(cantidad, piezas_techo);
            pila.push(new string("terraza"));
            terraza_++;

        }
        if (objetos[i][0] == "piscina")
        {
            piscina piscina_1;
            int cantidad = stoi(objetos[i][3]);
            piscina_1.crearPiscina(cantidad, piezas_piso, piezas_paredes, cantPiscina);
            pila.push(new string("piscina"));
            piscina_++;
        }
    };
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


