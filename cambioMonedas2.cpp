/*
En este código se introduce el total de una cuenta, el dinero que se entrego para pagar la cuenta y calcula 
el cambio más optimo que se debe entregar. 

Catch:
    En esta parte ya hay ciertas cantidades de denominaciones para el cambio.

Entrada:
    total de la cuenta
    monto entregado
    las denominaciones de cambio

Salida:
    Vector con las denominaciones de cambio
    La cantidad de monedas de cada denominaciones para el cambio
    Cantidad de monedas total
*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v, int size){
    for (int i=0;i<size;i++){
        cout<<v.at(i);
        if (i!=size-1){
            cout<<", ";
        }
    }
    cout<<endl;
}

int cambioTotal(int s, vector<int> monedas, vector<int>cantidades){
    int t = 0;
    for (int i=0;i<s;i++){
        t += monedas[i]*cantidades[i];
    }
    return t;
}

int main(){
    vector<int> monedasCambio, cantidades; //las denominaciones de monedas con las que se puede dar cambio
    int cuentaTotal, cambio, cambioAux, res, size, ent;
    int entregado = 0;
    int totalDev = 0;//monedas devueltas
    int totalCambio = 0;//monto total que se tiene para el cambio
    int i;

    cout<<"Ingrese el total de la cuenta: ";
    cin>>cuentaTotal;//20
    while (entregado<cuentaTotal){
        cout<<"Ingrese el monto entregado: ";
        cin>>entregado;//50
    }
    cambio = entregado - cuentaTotal;//30
    cout<<"Su cambio es de: "<<cambio<<" pesos."<<endl;
    cout<<"Ingrese la cantidad de denominaciones de cambio (el '1' ya esta considerado): ";
    cin>>size;

    monedasCambio.push_back(1);
    for (i=1; i<size;i++ ){
        cin>>ent;
        monedasCambio.push_back(ent);
    }

    for (i=0; i<size;i++ ){
        cout<<"Cantidad de monedas de "<<monedasCambio[i]<<" : ";
        cin>>ent;
        cantidades.push_back(ent);
    }
    
    printVector(monedasCambio, monedasCambio.size());
    printVector(cantidades, cantidades.size());

    cambioAux = cambio;
    totalCambio = cambioTotal(size, monedasCambio, cantidades);

    for (int i=monedasCambio.size()-1;cambio!=0; i--){
        if (cantidades[i] > 0){
            if (totalCambio >= cambio){
                while (cambioAux%monedasCambio[i] != 0){
                    cambioAux--;
                }
                res = (monedasCambio[i]*cantidades[i]);
                while (res > cambioAux){
                    cantidades[i]--;
                    res = (monedasCambio[i]*cantidades[i]);
                }
                if (cambioAux >= monedasCambio[i]*cantidades[i]){
                    cout<<cantidades[i]<<" moneda(s) de "<<monedasCambio[i]<<" pesos"<<endl;
                    cambio -= res;
                    cambioAux=cambio;
                    totalDev+=cantidades[i];
                }
            }
            else{
                cout<<"No se cuenta con el cambio suficiente."<<endl;
                exit(1);
            }
        }
    }

    cout<<totalDev<<" monedas."<<endl;

    return 0;
}
