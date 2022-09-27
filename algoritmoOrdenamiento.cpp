#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

//BUBBLE SORT
int bubbleSortFalling(vector<int> &v1){//Complejidad mejor caso O(n), peor caso O(n2)
  bool ordenado=false;
  int cont1=0;
  for (int i=0; i<v1.size() && !ordenado;i++){//ciclo para las iteraciones necesarias
    ordenado=true;
    for (int j=0;j<v1.size()-1-i; j++){
      cont1++;
      if (v1[j]<v1[j+1]){
        swap(v1[j], v1[j+1]);
        ordenado= false;
      }
    }
  }
  return cont1;
}

int bubbleSortRising(vector<int> &v1){//Complejidad mejor caso O(n), peor caso O(n2)
  bool ordenado=false;
  int cont1=0;
  for (int i=0; i<v1.size() && !ordenado;i++){//ciclo para las iteraciones necesarias
    ordenado=true;
    for (int j=0;j<v1.size()-1-i; j++){
      cont1++;
      if (v1[j]>v1[j+1]){
        swap(v1[j], v1[j+1]);
        ordenado= false;
      }
    }
  }
  return cont1;
}

//MERGE SORT
int mezcla(vector<int> &v2,int inicio, int fin){//Complejidad O(n)
  //calcular punto medio y van a ordenar sobre un nuevo arreglo
  int cont2=0;
  int centro=(inicio+fin)/2;
  int j=inicio;
  int k=centro + 1;
  int tamanio = fin - inicio + 1;
  int temporales[tamanio];
  for (int i=0; i<tamanio ;i++){
    if (j<=centro && k<=fin){
      cont2++;
      if (v2[j]<v2[k]){
        temporales[i]=v2[j++];
      }
      else{
        temporales[i]=v2[k++];
      }
    }
    else if (j<=centro){
        temporales[i]=v2[j++];
      }
      else{
        temporales[i]=v2[k++];
      }
    }
  for (int m=0; m<tamanio;m++){
    v2[inicio+m]=temporales[m];
  }
  return cont2;
}
int mergeSort( vector<int> &v2, int inicio, int fin){ //funcion recursiva
  int cont2=0;
  if (inicio<fin){
    int centro=(inicio+fin)/2;
    mergeSort(v2,inicio, centro);
    mergeSort(v2,centro+1,fin);
    mezcla(v2,inicio, fin);//Complejidad O(n)
    cont2= mergeSort(v2,inicio, centro) + mergeSort(v2, centro+1, fin) + mezcla(v2,inicio, fin);
  }
  return cont2;
}
int ordenaMerge(vector<int> &v2){//funcion de preparación / Complejidad O(nlog2(n))
  int inicio=0;
  int fin=v2.size();
  mergeSort(v2,inicio,fin-1);
  return mergeSort(v2,inicio,fin-1);
}

//QUICK SORT
void exchange (vector<int> &v3, int i, int j){
    swap(v3[i],v3[j]);
}
int partition(vector<int> &v3, int first, int last){
    int pivot = v3[first];
    int i = first + 1;
    for (int j=i; j<last; j++){
        if (v3[j]<pivot){
            exchange(v3, i++, j);
        }
    }
    exchange(v3, first, i-1);
    return i-1;
}
void quickSort(vector<int> &v3, int first, int last){
    if (first<last){
        int posPiv = partition(v3, first, last);
        quickSort(v3, first, posPiv-1);
        quickSort(v3, posPiv+1, last);
    }
}
void quickSort(vector<int> &v3){
    quickSort(v3, 0, v3.size());
}

//PRINT VECTORS
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
    int size, data;
    vector<int> v1,v2,v3;

    cout<<"Ingrese el tamaño del arreglo: ";
    cin>>size;

    //Entry of data into the array
    for (int i=0;i<size;i++){
        //cout<<"Ingrese el dato "<<i+1<<" del arreglo: ";
        //cin>>data;
        data = rand()% size;//Ingresa valores aleatorios 
        v1.push_back(data);
        v2.push_back(data);
        v3.push_back(data);
    }

    printVector(v3,size);

    //Prints Array
    bubbleSortRising(v1);
    ordenaMerge(v2);
    quickSort(v3);
    
    cout<<"Vector arreglado con Bubble Sort: "<<endl;
    printVector(v1, size);
    cout<<"Vector arreglado con Merge Sort: "<<endl;
    printVector(v2, size);
    cout<<"Vector arreglado con Quick Sort: "<<endl;
    printVector(v3, size);

    return 0;
}
