#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

//en un abb no existen elementos repetidos
typedef struct _nodo {
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;




//mostrar en orden
void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}

/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}

/* Buscar un valor en el árbol */
int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; /* dato encontrado */
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; /* No está en árbol */
}

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{  
   printf("%d, ", *d);
}


int main (int argc, char *argv[])
 {
      char c[5];
      char aux[] ="-g";
      char aux2[]= "-v";
      Arbol ArbolInt=NULL;
      int aleatorio;
      int i;
      char nombre[80];
      
      time_t tiempo = time(0);
      struct tm *tlocal = localtime(&tiempo);
      char output[128];
      char output2[128];
      strftime(output,128,"%Y-%m-%d %H:%M:%S",tlocal);
      strftime(output2,128,"%d-%m-%Y",tlocal);


        if (argc > 1)
         {
		    strcpy(c,argv[1]);

		    if(strcmp(c,aux)==0)
		      {
			    FILE *archivo;
			    char *nombrearchivo="kino.csv";
			    archivo=fopen(nombrearchivo,"a");//agrega al final
		        
		           fprintf(archivo, "%s; ",output);
		           srand (time(NULL)); 
	   
			    for( i=0; i<14; i++)
			    { 
			      do{
				aleatorio = (1+rand()%(25-1+1));
				//printf( " %d aleatorio  %d \n ",i,aleatorio);
			      }while(Buscar(ArbolInt,aleatorio)); 
				 
			    Insertar(&ArbolInt, aleatorio);
			    fprintf(archivo, "%d;",aleatorio);
			      
			    }

			    fprintf(archivo, "\n"); 
			    fclose(archivo);
			  
			 
		      
		   }
		
                     if(strcmp(c,aux2)==0)
   		      {
                        printf("Los integrantes del grupo son: \n");
                        printf("Roberto Esparza \n");
                        printf("Joaquin Astudillo \n");
                        printf("Jonathan Sepulveda \n");
                        printf("Fecha de compilacion %s\n",output2);
                        
                       
                         
                      }
		


         
       
         }

 


  
    return 0;
  } 



