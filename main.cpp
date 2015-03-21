/* 
 * File:   main.cpp
 * Author: Jake
 *
 * Created on 21 de marzo de 2015, 10:24
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#define  MAXLINEA 225
#include <vector>
#include <stdio.h> 
#include<stdlib.h> // libreria para el uso de rand( )    
#include<time.h>   // libreria para el uso de time( )  


using namespace std;

/*
 * 
 */
int main(int argc,char *argv[]) {
    
    if (argc > 1){
          string uax = argv[1];
          string aux = "-v";
          string generar = "-g";
          FILE *fichero;
          if(!aux.compare(uax)){
          cout << "Los integrantes del grupo son : "  << endl << 
                  "Joaquín Astudillo"  << endl << 
                  "Roberto Esparza"    << endl << 
                  "Jonathan Sepúlveda" << endl ;
          }
          if(!generar.compare(uax)){
              fichero = fopen("qno.csv", "a+" );
              /////////////
              
              
              int n = 0, c = 0;
	
	int random[25];
	for(int i = 0; i < 25; i++)
		random[i] = 0;

	srand( time(NULL) );

	while( c != 25 )
	{
		n = (rand()%25)+1;

		for( int i = 0; i < 25; i++)
		{
			if(random[i] == n)
				break;

			if(random[i] == 0)
			{
				random[i] = n;
				c++;
				break;
			}
		}
	}
        
        for(int i = 0 ; i < 25 ; i++){
        int au = random[i];
        fprintf(fichero,"%d;",au);
        //fputs(au, fichero );
        }
        
        fprintf(fichero,"\n");
              
              
              
              ////////////
              fclose(fichero);
              cout << "el archivo ha sido generado" << endl;
          }
          else{
          cout << "el argumento no es válido intentelo nuevamente."  << endl;    
          }
          }else{
          cout << "El comando ingresado no lleva ningún argumento." << endl;
          }
    
         
    
         
          
          

  return 0;
    
}
    


