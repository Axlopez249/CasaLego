#ifndef Objetos_h
#define Objetos_h
#include <iostream>





class cimiento{
    
    public:
       bool ePiso; 

        void crearPiso(int piezas_piso, int cantPiso){

           
                if (piezas_piso - cantPiso > 0){
                    piezas_piso = piezas_piso - cantPiso;
                    ePiso = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            
        }

        bool piso(){
            return ePiso;
        }
};


class cuarto{
    public:
        bool eCuarto;
        cimiento c;
        bool ePiso = c.piso();

        void crearCuarto(int cantidad, int piezas_paredes, int cantCuarto){


            if(ePiso){
                while(cantidad != 0){
                    if (piezas_paredes-cantCuarto > 0){
                        piezas_paredes = piezas_paredes - cantCuarto;
                        cantidad--;
                        
                        eCuarto = true;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }
            }else{cout<<"No hay piso"<<endl;}
        } 

        bool estCuarto(){
            return eCuarto;
        }
};

class cocina{
    public:
        bool eCocina;
        cimiento c;
        bool ePiso = c.piso();
        void crearCocina(int cantidad, int piezas_paredes, int cantCocina){

            
            if(ePiso){
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
        bool estCocina(){
            return eCocina;
        }
};

class comedor{
    public:
        bool eComedor;
        cimiento c;
        bool ePiso = c.piso();

        void crearComedor(int cantidad, int piezas_paredes, int cantComedor){
            
            

            if(ePiso){
                while(cantidad != 0){
                    if (piezas_paredes - cantComedor > 0){
                        piezas_paredes = piezas_paredes - cantComedor;
                        cantidad--;
                        
                        eComedor = true;
                    }else{cout<<"No hay suficientes piezas"<<endl;}

                }
            }else{cout<<"No hay piso"<<endl;}
            
        } 
        bool etsComedor(){
            return eComedor;
        }
};

class techo{
    public:
        bool eTecho;
        comedor come;
        cuarto cuar;
        cocina coci;

        bool eComedor = come.etsComedor();
        bool eCuarto = cuar.estCuarto();
        bool eCocina = coci.estCocina();

        void crearTecho(int piezas_techo, int cantTecho){
            

            if(eComedor || eCuarto || eCocina){
                if(piezas_techo - cantTecho > 0){
                    piezas_techo = piezas_techo - cantTecho;
                    eTecho = true;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay paredes"<<endl;}
        }

        bool estTecho(){
            return eTecho;
        }
};

class cielo{
    public:
        techo t;
        bool eTecho = t.estTecho();

        void crearCielo(int piezas_cielo, int cantCielo){
            

            if(eTecho){
                if(piezas_cielo - cantCielo > 0){
                    piezas_cielo = piezas_cielo - cantCielo;
                }else{cout<<"No hay suficientes piezas"<<endl;}

            }else{cout<<"No hay techo"<<endl;}

        }

};

class terraza{
    public:

        comedor come;
        cuarto cuar;
        cocina coci;

        bool eComedor = come.etsComedor();
        bool eCuarto = cuar.estCuarto();
        bool eCocina = coci.estCocina();
        
        void crearTerraza(int cantidad, int piezas_techo, int cantTerraza){
            

            if(eComedor || eCuarto || eCocina){
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

#endif 