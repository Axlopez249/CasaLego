#include <iostream>
#include <string>
#include "Lista.h"
#include <vector>

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

//Cantidad de piezas por objeto, hay que poner una cantidad
int cantPiso = 0;
int cantParedes = 0;
int cantCuarto = 0;
int cantCocina = 0;
int cantComedor = 0;
int cantCielo = 0;
int cantTecho = 0;
int cantTerraza = 0;
int cantPiscina = 0;

class cimiento{
    
    public:
        static bool ePiso = false; //Estado para validaciones posteriores
                                //Se usa static para que se pueda validar en otras clases
        void crearPiso(int cantidad, int piezas_piso){

            while(cantidad != 0){
                if (piezas_piso - cantPiso > 0){
                    piezas_piso = piezas_piso - cantPiso;
                    cantidad--;
                    ePiso = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }
        }
}

class paredesExeternas{
    public:
        static bool ePared = false;

        void crearParedes(int piezas_paredes){
            
            if(cimiento::ePiso){
                if(piezas_paredes-cantParedes > 0){
                    piezas_paredes = piezas_paredes - cantParedes;
                    ePared = true
                }else{cout<<"No hay suficientes piezas"<<endl;}
            }

        } 
}

class cuarto{
    public:
        static bool eCuarto = false;

        void crearCuarto(int cantidad, int piezas_paredes){
            
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
        } 
}

class cocina{
    public:
        static bool eCocina = false;

        void crearCocina(int cantidad, int piezas_paredes){
            
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
        } 
}

class comedor{
    public:
        static bool eComedor = false;

        void crearComedor(int cantidad, int piezas_paredes){
            
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
        } 
}

class techo{
    public:
        static bool eTecho = false;

        void crearTecho(int piezas_techo){
            
            if(paredesExeternas::ePared){
                if(piezas_techo - cantTecho > 0){
                    piezas_techo = piezas_techo - cantTecho;
                    eTecho = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay paredes"<<endl;}
        }
        
}

class cielo{
    public:
        static bool eCielo = false;

        void crearCielo(int piezas_cielo){
            if(techo::eTecho){
                if(piezas_cielo - cantCielo > 0){
                    piezas_cielo = piezas_cielo - cantCielo;
                    eCielo = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay techo"<<endl;}

        }
}

class terraza{
    public:

        void crearTerraza(int cantidad, int piezas_techo){
            
            if(paredesExeternas::ePared){
                while(cantidad != 0){
                    if (piezas_techo - cantTerraza > 0){
                        piezas_techo = piezas_techo - cantTerraza;
                        cantidad--;
                        terraza_++;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }else{cout<<"No hay paredes"<<endl;}
            }
        }
}


class hueco{
    public:
        huecos = 0;
        static bool eHueco = false;

        void crearHueco(int cantidad){
            while(cantidad != 0){
                eHueco = true;
                huecos++;
            }

            crearPiscina(huecos, piezas_piso, piezas_paredes);
        }


}


class piscina{
    public:

        void crearPiscina(int cantidad, int piezas_piso, int piezas_paredes){

            if(eHueco){
                if(piezas_piso - cantPiscina/2 > 0 && piezas_paredes - cantPiscina/2 > 0){
                    while(cantidad != 0){
                        piezas_piso = piezas_piso - cantPiscina/2;
                        piezas_paredes = piezas_paredes - cantPiscina/2;
                        cantidad--;
                        piscina_++;
                    }
                }else{cout<<"No hay suficientes piezas"<<endl;}
            }else{cout<<"No hay hueco"<<endl;}
        }
}

using namespace std;

int main(){
    //Reglas
    string piezas[7] = {"piso", "pieza_pared", "puerta", "ventana", "techo", "cielo razo", "hueco"};
    string objetos[6][3] = {{"cimiento", "piso", 5, 1}, {"cuartos","pieza_pared", 20, 2}, {"cocina", "pieza_pared" 20, 1},
     {"comedor", "pieza_pared" 20, 1}, {"terraza", "pieza pared", 10, 1}, {"piscina","hueco", 1, 1}};
    //El nombre, tipo de pieza a utilizar, la cantidad de piezas a utilizar, la cantidad de objetos

    string orden[6] = {"cimiento", "cuartos", "cocina", "comedor", "cielo_raso", "techo", "terraza", "piscina"};
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


