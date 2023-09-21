#include <iostream>
#include <string>
#include "Lista.h"
#include <vector>



using namespace std;

class cimiento{
    
    public://Estado para validaciones posteriores
        //Se usa static para que se pueda validar en otras clases
        void crearPiso(int cantidad, int piezas_piso, int cantPiso, bool ePiso){

            while(cantidad != 0){
                if (piezas_piso - cantPiso > 0){
                    piezas_piso = piezas_piso - cantPiso;
                    cantidad--;
                    ePiso = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }
            return cantidad;
        }
        
}

class paredesExeternas{
    public: 

        int crearParedes(int piezas_paredes, int cantParedes, bool ePiso, bool ePared){
            
            if(cimiento::ePiso){
                if(piezas_paredes-cantParedes > 0){
                    piezas_paredes = piezas_paredes - cantParedes;
                    ePared = true
                }else{cout<<"No hay suficientes piezas"<<endl;}
            }
            return piezas_paredes, cantParedes, ePiso;
        } 
}

class cuarto{
    public:

        int crearCuarto(int cantidad, int piezas_paredes, int cantCuarto, bool ePiso, bool eCuarto){
            
            if(cimiento::ePiso){
                while(cantidad != 0){
                    if (piezas_paredes-cantCuarto > 0){
                        piezas_paredes = piezas_paredes - cantCuarto;
                        cantidad--;
                        cuarto_++;
                        eCuarto = true;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }else{cout<<"No hay piso"<<endl;}
            }
            return cantidad;
        } 
}

class cocina{
    public:
        

        int crearCocina(int cantidad, int piezas_paredes, int cantCocina, bool ePiso, bool eCocina){
            
            if(cimiento::ePiso){
                while(cantidad != 0){
                    if (piezas_paredes - cantCocina > 0){
                        piezas_paredes = piezas_paredes - cantCocina;
                        cantidad--;
                        cocina_++;
                        eCocina = true;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }else{cout<<"No hay piso"<<endl;}
            }
            return cantidad;
        } 
}

class comedor{
    public:

        int crearComedor(int cantidad, int piezas_paredes, int cantComedor, bool ePiso, bool ecomedor){
            
            if(cimiento::ePiso){
                while(cantidad != 0){
                    if (piezas_paredes - cantComedor > 0){
                        piezas_paredes = piezas_paredes - cantComedor;
                        cantidad--;
                        comedor_++;
                        eComedor = true;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }else{cout<<"No hay piso"<<endl;}
            }
            return cantidad;
        } 
}

class techo{
    public:

        int crearTecho(int piezas_techo, int cantTecho, bool ePared, bool eTecho){
            
            if(paredesExeternas::ePared){
                if(piezas_techo - cantTecho > 0){
                    piezas_techo = piezas_techo - cantTecho;
                    eTecho = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay paredes"<<endl;}

            return piezas_techo;
        }
        
}

class cielo{
    public:
        int crearCielo(int piezas_cielo, int cantCielo, bool eTecho, bool eCielo){
            if(techo::eTecho){
                if(piezas_cielo - cantCielo > 0){
                    piezas_cielo = piezas_cielo - cantCielo;
                    eCielo = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay techo"<<endl;}

            return piezas_cielo;
            
        }
}

class terraza{
    public:

        int crearTerraza(int cantidad, int piezas_techo, int cantTerraza, bool ePared, int terraza_){
            
            if(paredesExeternas::ePared){
                while(cantidad != 0){
                    if (piezas_techo - cantTerraza > 0){
                        piezas_techo = piezas_techo - cantTerraza;
                        cantidad--;
                        terraza_++;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }else{cout<<"No hay paredes"<<endl;}
            }
            return cantidad;
        }
}

class piscina{
    public:

        int crearPiscina(int cantidad, int piezas_piso, int piezas_paredes, int cantPiscina){

            if(piezas_piso - cantPiscina/2 > 0 && piezas_paredes - cantPiscina/2 > 0){
                while(cantidad != 0){
                    piezas_piso = piezas_piso - cantPiscina/2;
                    piezas_paredes = piezas_paredes - cantPiscina/2;
                    cantidad--;
                    piscina_++;
                }
            }else{cout<<"No hay suficientes piezas"<<endl;}

            return cantidad, piezas_piso, piezas_paredes, cantPiscina;

        }
}



int main(){
    //variables booleanas
    bool eCocina = false;
    bool eComedor = false;
    bool eCielo = false;
    bool eTecho = false;
    bool eCuarto = false;
    bool ePared = false;
    bool ePiso = false;

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

    //Cantidad de piezas por objeto, hay que poner una cantidad
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
    string objetos[6][3] = {{"cimiento", "piso", 5, 1}, {"cuartos","pieza_pared", 20, 2}, {"cocina", "pieza_pared" 20, 1},
     {"comedor", "pieza_pared" 20, 1}, {"techo", "piezas_techo", 20, 1},{"cielo", "piezas_cielo", 30, 1},
      {"terraza", "pieza_pared", 10, 1}, {"piscina","pizo", 1, 1}};
    //El nombre, tipo de pieza a utilizar, la cantidad de piezas a utilizar, la cantidad de objetos

    string orden[6] = {"cimiento", "cuartos", "cocina", "comedor", "cielo_raso", "techo", "terraza", "piscina"};
    //orden de la pila

    for (int i = 0; i < 6; i++)
    {
        if (objetos[i][0] == "cimiento")
        {
            cimiento cimiento_1 = new cimiento();
            cimiento_1.crearPiso(objetos[i][3], piezas_piso, cantPiso, ePiso);
            
        }
        if (objetos[i][0] == "cuartos")
        {
            cuarto cuarto_1 = new cuarto();
            cuarto_1.crearCuarto(objetos[i][3], piezas_paredes, cantCuarto, ePiso, eCuarto);
        }
        if (objetos[i][0] == "cocina")
        {
            cocina cocina_1 = new cocina();
            cocina_1.crearCocina(objetos[i][3], piezas_paredes, cantCocina, ePiso, eCocina);
        }
        if (objetos[i][0] == "comedor")
        {
            comedor comedor_1 = new comedor();
            comedor_1.crearComedor(objetos[i][3], piezas_paredes, cantComedor, ePiso, eComedor);
        }
        if (objetos[i][0] == "techo")
        {
            techo techo_1 = new techo();
            techo_1.crearTecho(piezas_techo, cantTecho, ePared, eTecho);
        }
        if (objetos[i][0] == "cielo")
        {
            cielo cielo_1 = new cielo();
            cielo_1.crearCielo(piezas_cielo, cantCielo, eTecho, eCielo);
        }
        
        if (objetos[i][0] == "terraza")
        {
            terraza terraza_1 = new terraza();
            terraza_1.crearTerraza(objetos[i][3], piezas_techo, cantTerraza, ePared, terraza_);
        }
        if (objetos[i][0] == "piscina")
        {
            piscina piscina_1 = new piscina();
            piscina_1.crearPiscina(objetos[i][3], piezas_piso, piezas_paredes, cantPiscina);
        }
    }
    



    
    //cada uno tiene una puerta y una ventana por eso no se pone
    //4 piezas_pared es una pared
    //5 piezas pizo es un cimiento
    //la cocina es un cuarto practicamente al igual que el comedor y los cuartos como tal


    
    /*
    //Creacion de la cola
    Queue<string> *cola_piezas = new List<string>();
    Queue<string> *cola_objetos = new List<string>();



    //ingreso a colas de piezas
    for (int i = 0; i < 6; i++)
    {
        cola_objetos->enqueue(&objetos[i][0]);
    }

    */


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


