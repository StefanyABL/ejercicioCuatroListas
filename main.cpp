/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 18 de septiembre de 2018, 10:57 PM
 */


#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
struct nodo{
 
       float nro;
 
       struct nodo *sgte;
 
};
 
typedef struct nodo *Tlista;
 
Tlista fin;
 
/*------------------Menu----------------------------------*/
void menu1()
 
{
 
    cout<<"\n\n\t\t[  EJERCICIOS LISTAS SIMPLES ]\n";
 
    cout<<"\t\t-----------------------------\n\n";
 
    cout<<" EJERCICIO 2: Almacenar una lista de reales y ordenarlos"<<endl<<endl;
 
    cout<<" 1. INSERTAR ELEMENTO                "<<endl;
 
    cout<<" 2. MOSTRAR LISTA ORDENADA           "<<endl;
 
    cout<<" 3. SALIR                            "<<endl;
 
 
 
    cout<<"\n INGRESE OPCION: ";
 
}
/*----------------------------insertar elemento al inicio ---------------------*/
 
void insertarInicio(Tlista &lista, float valor)
{
 
    Tlista q;
    q = new(struct nodo);
 
    q->nro = valor;
 
    q->sgte = lista;
 
    lista  = q;
 
}
 
/*-------------------- Insertar siguiente Elemento-------------------------*/
void insertarFinal(Tlista &lista, float valor)
 
{
 
    Tlista t, q = new(struct nodo);
 
    q->nro  = valor;
 
    q->sgte = NULL;
 
    fin=q;
 
    if(lista==NULL)
 
    {
        lista = q;
    }
 
    else
 
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
 
        t->sgte = q;
    }
 
}
 
/*------------------------- Funcio que inserta el elemento ordenado antes del mayor y despues del menor*/
void insertarElementoEn(Tlista lista, float n){
 
    Tlista t,r,q=new (struct nodo);
 
    q->nro=n;
 
    q->sgte=NULL;
 
    while(lista->sgte!=NULL){
 
            t=lista->sgte;
 
            if((n>=(lista->nro))&&(n<=t->nro)){
 
                q->sgte=lista->sgte;
 
                lista->sgte=q;
 
                return;
 
                }
 
            lista=lista->sgte;
 
            }
 
}
/*----------------------Mostrar Lista--------------------------------------*/
void reportarLista(Tlista lista)
 
{
 
     int i = 0;
 
     while(lista != NULL)
 
     {
 
          cout <<' '<< i+1 <<") " << lista->nro << endl;
 
          lista = lista->sgte;
 
          i++;
 
     }
 
}
 
 
 
/*------------------------- Funcion Principal ---------------------------*/
 
int main(void)
 
{
    Tlista lista = NULL;
 
    int op;
 
    float n;
 
    system("color 0a");
 
    do
 
    {
 
        menu1();  cin>> op;
 
         switch(op)
 
        {
 
            case 1:
 
                  cout<< "\n NUMERO A INSERTAR: "; cin>> n;
 
                  if(lista==NULL){
 
                    insertarFinal(lista,n);
 
                    }
                    else{
                            if(n<lista->nro)
 
                                insertarInicio(lista,n);
 
                            else if(n>fin->nro)
 
                                    insertarFinal(lista,n);
 
                                  else{ if((n>lista->nro)&&(n<fin->nro)){
 
                                            insertarElementoEn(lista,n);
 
                                            }
 
                                  }
 
 
                    }
 
                  break;
 
 
            case 2:
 
                  cout<<endl<<"La lista Ordenada es:"<<endl;
 
                  reportarLista(lista);
 
                  break;
 
            case 3: return 0;
 
            default: cout<<"Ingrese una Opcion Valida....!"<<endl;
 
 
                    }
 
 
 
        cout<<endl<<endl;
 
        system("pause");  system("cls");
 
 
 
    }while(op!=3);
 
 
 
    system("pause");
 
   return 0;
 
}