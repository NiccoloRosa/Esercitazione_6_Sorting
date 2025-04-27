//ESERCIZIO 2 

#pragma once

#include <iostream>
#include <vector> //libreria per i vettori

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) 
{
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(vector<T>& v) //prendo come parametro un riferimento ad un vettore di elementi di tipo T (che rispetta i requisiti del concetto Sortable)
{
    const unsigned int n = v.size(); //salvo la dimensione (costante) del vettore

    for (unsigned int i = 0; i < n - 1; i++) //itero i da 0 a n-2
    {
        for (unsigned int j=i+1; j<n; j++) 
        {
            if (v[j] < v[i])
            //swap
            {
                T tmp = v[i]; // salvo il valore di v[i] in tmp (la uso come variabile di appoggio)
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

template<Sortable T>
void heapify(vector<T>& v, unsigned int n, unsigned int i)
{
    unsigned int largest = i; //inizializzo largest come radice
    unsigned int left = 2 * i + 1; //figlio sinistro
    unsigned int right = 2 * i + 2; //figlio destro

    //Se il figlio sinistro esiste ed è maggiore della radice
    if (left < n && v[left] > v[largest]) 
        largest = left;

    //Se il figlio destro esiste ed è maggiore della radice
    if (right < n && v[right] > v[largest]) 
        largest = right;
    
     //Se largest non è la radice (ovvero se è cambiato)
     if (largest != i) 
     {
     //swap
     T tmp = v[i];
     v[i] = v[largest];
     v[largest] = tmp;
     //Ricorsione per heapify il sottoalbero
     heapify(v, n, largest);
     }
}

template<Sortable T>
void HeapSort(vector<T>& v)
{
   const unsigned int n = v.size(); //salvo la dimensione (costante) del vettore

   //Costruisco un max heap
   for (int i = n/2 -1; i >=0; i--) 
        heapify(v, n, i); 
   //Ora il vettore v ha come primo elemento (all'indice 0) il suo massimo (max heap)
   
   //Estraggo gli elementi uno alla volta dal max heap
   for (int i = n - 1; i > 0; i--) 
   {
       //swap (scambio l'ultimo elemento con la radice (cioé il primo e quindi il massimo))
       T tmp = v[0];
       v[0] = v[i];
       v[i] = tmp;
       //Heapify il max heap ridotto di uno (quindi escludo l'ultimo elemento che è già ordinato e trovo il massimo dei rimanenti mettendolo in prima posizione)
       heapify(v, i, 0); //itero finche l'ultimo elemento non è ordinato
   }
}

}


