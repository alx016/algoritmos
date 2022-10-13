/*Manuel Alejandro Preciado Morán A01639643
Programa util para resolver el problema de las torres de hanoi con 
'n' discos. 
Condiciones:
    No se puede colocar un disco más grande sobre uno más pequeño
    Solo se puede mover un disco a la vez

Complejidad O((2^n)-1)
Cuando se tienen n cantidad de anillos, se generan cierta cantidad de movimientos. Con 
4 anillos = 15 movimientos
10 anillos = 1,023 movimientos
20 anillos = 1,048,575 movimientos
30 anillos = 1,073,741,823 movimientos
64 anillos = 18,446,744,073,709,551,615 movimientos
*/
#include <iostream>
using namespace std;


void torresHanoi(int n,  int init, int aux, int end, int &count){
    if (n==0){
        return;
    }
    count++;
    torresHanoi(n-1,init,end,aux,count);
    cout<<"Move disc "<<n<<" from tower "<<init<<" to tower "<<end<<endl;
    torresHanoi(n-1,aux,init,end,count);

}  

int main(){
    int num_disc;
    int moves = 0;
    cout<<"Enter the number of rings: ";
    cin>>num_disc;

    torresHanoi(num_disc,1,2,3, moves);//Complejidad (2^n)-1
    cout<<"Number of moves are: "<<moves<<endl;

    return 0;
}
