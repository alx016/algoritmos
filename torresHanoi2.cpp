/*
Manuel Alejandro Preciado Morán A01639643
Programa util para resolver el problema de las torres de hanoi con 
'n' discos. El programa le solicitará el número de discos con los que desea trabajar
para después mostrarle los movimientos y el número de movimientos necesarios para pasar 
los discos de la torre 1 a la torre 3.
Condiciones:
    Solo se puede mover un disco a la vez
    No se puede colocar un disco más grande sobre uno más pequeño
    Los discos no pueden pasar de la torre '1' a la torre '3', o viceversa, sin antes
    pasar por la torre '2'. 

Complejidad O((3^n)-1)
Cuando se tienen n cantidad de anillos, se generan cierta cantidad de movimientos. Con 
1 anillo  = 2 movimientos
2 anillos = 8 movimientos
3 anillos = 26 movimientos
4 anillos = 80 movimientos
5 anillos = 242 movimientos
6 anillos = 728 movimientos
10 anillos = 59,048 movimientos
64 anillos = 3.43368382*10^30 movimientos
*/
#include <iostream>
using namespace std;


void torresHanoi(int n,  int init, int aux, int end, int &count){
    if (n==0){
        return;
    }
    count++;
    torresHanoi(n-1,init,aux,end,count);
    cout<<"Move disc "<<n<<" from tower "<<init<<" to tower "<<aux<<endl;
    count++;
    torresHanoi(n-1,end,aux,init,count);
    cout<<"Move disc "<<n<<" from tower "<<aux<<" to tower "<<end<<endl;
    torresHanoi(n-1,init,aux,end,count);
    
}  

int main(){
    int num_disc;
    int moves = 0;
    cout<<"Enter the number of rings: ";
    cin>>num_disc;

    torresHanoi(num_disc,1, 2, 3, moves);//Complejidad (3^n)-1
    cout<<"Number of moves are: "<<moves<<endl;

    return 0;
}
