#include <iostream>


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

class piscina{
    public:

        void crearPiscina(int cantidad, int piezas_piso, int piezas_paredes){

            if(piezas_piso - cantPiscina/2 > 0 && piezas_paredes - cantPiscina/2 > 0){
                while(cantidad != 0){
                    piezas_piso = piezas_piso - cantPiscina/2;
                    piezas_paredes = piezas_paredes - cantPiscina/2;
                    cantidad--;
                    piscina_++;
                }
            }else{cout<<"No hay suficientes piezas"<<endl;}

        }
}