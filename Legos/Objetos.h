#include <iostream>


class cimiento{
    
    public:
       static bool ePiso; //Estado para validaciones posteriores
                                //Se usa static para que se pueda validar en otras clases
        void crearPiso(int cantidad, int piezas_piso, int cantPiso){

            while(cantidad != 0){
                if (piezas_piso - cantPiso > 0){
                    piezas_piso = piezas_piso - cantPiso;
                    cantidad--;
                    ePiso = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }
        }
};


class cuarto{
    public:
        static bool eCuarto;

        void crearCuarto(int cantidad, int piezas_paredes, int cantCuarto){
            
            if(cimiento::ePiso){
                while(cantidad != 0){
                    if (piezas_paredes-cantCuarto > 0){
                        piezas_paredes = piezas_paredes - cantCuarto;
                        cantidad--;
                        
                        eCuarto = true;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }
            }else{cout<<"No hay piso"<<endl;}
            
        } 
};

class cocina{
    public:
        static bool eCocina;

        void crearCocina(int cantidad, int piezas_paredes, int cantCocina){
            
            if(cimiento::ePiso){
                while(cantidad != 0){
                    if (piezas_paredes - cantCocina > 0){
                        piezas_paredes = piezas_paredes - cantCocina;
                        cantidad--;
                        
                        eCocina = true;
                    } else {
                        cout<<"No hay suficientes piezas"<<endl;
                    }
                }
            }else{cout<<"No hay piso"<<endl;}
            
        } 
};

class comedor{
    public:
        static bool eComedor;

        void crearComedor(int cantidad, int piezas_paredes, int cantComedor){
            
            if(cimiento::ePiso){
                while(cantidad != 0){
                    if (piezas_paredes - cantComedor > 0){
                        piezas_paredes = piezas_paredes - cantComedor;
                        cantidad--;
                        
                        eComedor = true;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }
            }else{cout<<"No hay piso"<<endl;}
            
        } 
};

class techo{
    public:
        static bool eTecho;

        void crearTecho(int piezas_techo, int cantTecho){
            
            if(comedor::eComedor || cuarto::eCuarto || cocina::eCocina){
                if(piezas_techo - cantTecho > 0){
                    piezas_techo = piezas_techo - cantTecho;
                    eTecho = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay paredes"<<endl;}
        }
        
};

class cielo{
    public:
        static bool eCielo;

        void crearCielo(int piezas_cielo, int cantCielo){
            if(techo::eTecho){
                if(piezas_cielo - cantCielo > 0){
                    piezas_cielo = piezas_cielo - cantCielo;
                    eCielo = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay techo"<<endl;}

        }
};

class terraza{
    public:

        void crearTerraza(int cantidad, int piezas_techo, int cantTerraza){
            
            if(comedor::eComedor || cuarto::eCuarto || cocina::eCocina){
                while(cantidad != 0){
                    if (piezas_techo - cantTerraza > 0){
                        piezas_techo = piezas_techo - cantTerraza;
                        cantidad--;
                        
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }
            }else{cout<<"No hay paredes"<<endl;}
            
        }
};

class piscina{
    public:

        void crearPiscina(int cantidad, int piezas_piso, int piezas_paredes, int cantPiscina){
           
            if(piezas_piso - cantPiscina/2 > 0 && piezas_paredes - cantPiscina/2 > 0){
                while(cantidad != 0){
                    piezas_piso = piezas_piso - cantPiscina/2;
                    piezas_paredes = piezas_paredes - cantPiscina/2;
                    cantidad--;
                    }
            }else{cout<<"No hay suficientes piezas"<<endl;}
        }
};