/*
En este código se introduce el total de una cuenta, el dinero que se entrego para pagar la cuenta y calcula 
el cambio más optimo que se debe entregar.

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

int main(){
    vector<int> monedasCambio; //las denominaciones de monedas con las que se puede dar cambio
    int cuentaTotal, cambio, cambioAux, res, size, ent;
    int entregado = 0;
    int total = 0;
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
    
    printVector(monedasCambio, monedasCambio.size());
   
    cambioAux = cambio;
    for (int i=monedasCambio.size()-1;cambio!=0; i--){
        while (cambioAux%monedasCambio[i] != 0){
            cambioAux--;
        }
        res = cambio/monedasCambio[i];
        if (res!=0){
            cout<<res<<" moneda(s) de: "<<monedasCambio[i]<<endl;
            total += res;
        }
        cambio = cambio - cambioAux;
        cambioAux = cambio;
    }

    cout<<total<<" monedas."<<endl;

    return 0;
}
