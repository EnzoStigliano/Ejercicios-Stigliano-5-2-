//Enzo Stigliano 5° 2°
//Hecho en OnlineGDB

#include <iostream>
#include <vector>

using namespace std;

int entregasError(int alfajores, vector<int> &acumCajas, int tipo, int numOperario, vector<int> &alfinvalidos){
    int cajas = alfajores / 6;
    
    acumCajas[tipo-1] += cajas;
    
    alfinvalidos[numOperario-1] = alfajores%6;
        
    return alfajores%6;
}

//Ingresar precio de cajas de alfajores por tipo
void cajasAlfajores(vector<int> &precioCajas){
    int i;
    
    for(i=0;i<4;i++){
        cout<<"Ingrese el precio de la caja de alfajores ";
        switch(i){
            case 0: 
                cout<<"de chocolate: ";
                break;
            case 1: 
                cout<<"de dulce de leche: ";
                break;
            case 2: 
                cout<<"de fruta: ";
                break;
            case 3: 
                cout<<"mixtos: ";
                break;
        }
        cin>>precioCajas[i];
    }
}

int main()
{
    vector<int> precioCajas(4); //Orden de precios: chocolate, dulce de leche, fruta, mixto
    int i;
    int j;
    int seguir = 1;
    int tipo;
    int cant;
    int numOperario;
    int acumGanancias = 0;
    int acumErrores = 0;
    vector<int> acumCajas(4, 0);
    int alfajxEmpleado[5][5];
    vector<int> alfinvalidos(6);
    
    cajasAlfajores(precioCajas);
    
    //Bucle principal
    while(seguir != 0){
        do{
            cout<<"Ingrese el numero del operario (del 1 al 6): ";
            cin>>numOperario;
            
            if(numOperario != 1 && numOperario != 2 && numOperario != 3 && numOperario != 4 && numOperario != 5 && numOperario != 6){
                cout<<"\033[0;31mEl numero de operario ingresado no se encuentra registrado, por favor, ingrese otro\033[0m\n";
            }
        } while(numOperario != 1 && numOperario != 2 && numOperario != 3 && numOperario != 4 && numOperario != 5 && numOperario != 6);
        
        do{
            cout<<"\nIngrese el tipo de alfajor que elaboro (1 = chocolate, 2 = dulce de leche, 3 = fruta, 4 = mixto): ";
            cin>>tipo;
            
            if(numOperario != 1 && numOperario != 2 && numOperario != 3 && numOperario != 4){
                cout<<"\033[0;31mEl tipo de alfajor ingresado no se encuentra registrado, por favor, ingrese otro\033[0m\n";
            }
        } while(numOperario != 1 && numOperario != 2 && numOperario != 3 && numOperario != 4);
        
        cout<<"Ingrese la cantidad de alfajores elaborados: ";
        cin>>cant;
        
        alfajxEmpleado[tipo-1][numOperario-1] = cant;
        
        acumErrores += entregasError(cant, acumCajas, tipo, numOperario, alfinvalidos);
        
        cout<<"\nQuiere serguir ingresando producciones? (1 = si, 0 = no): ";
        cin>>seguir;
    }
    
    cout<<"\n\nLa cantidad total de entregas con error fue de "<<acumErrores<<"\n";
    
    //Ganancias por tipo de alfajor
    for(i=0;i<4;i++){
        cout<<"\nLa ganancia total de los alfajores ";
        switch(i){
            case 0: 
                cout<<"de chocolate ";
                break;
            case 1: 
                cout<<"de dulce de leche ";
                break;
            case 2: 
                cout<<"de fruta ";
                break;
            case 3: 
                cout<<"mixtos ";
                break;
        }
        cout<<"fue de "<<acumCajas[i]*precioCajas[i];
        acumGanancias += acumCajas[i]*precioCajas[i];
    }
    
    //Cantidad de alfajores por tipo por empleado 
    for(j=0;j<4;j++){
        for(i=0;i<4;i++){
            cout<<"\nLa cantidad de alfajores ";
            switch(i){
            case 0: 
                cout<<"de chocolate ";
                break;
            case 1: 
                cout<<"de dulce de leche ";
                break;
            case 2: 
                cout<<"de fruta ";
                break;
            case 3: 
                cout<<"mixtos ";
                break;
            }
        }
        cout<<"del empleado n"<<j+1<<" fue de "<<alfajxEmpleado[i][j]<<"\n";
    }
    
    //Ganancoia total del mes
    cout<<"\n\nLa ganancia total del mes fue de "<<acumGanancias;
    
    //Cantidad de alfajores fuera de producción por empleado
    for(i=0;i<6;i++){
        cout<<"\nLa cantidad de alfajores fuera de produccion del operario n"<<i+1<<" fue de "<<alfinvalidos[i];
    }
    return 0;
}