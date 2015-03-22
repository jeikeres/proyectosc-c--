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
#include <stdlib.h> // libreria para el uso de rand( )    
#include <time.h>   // libreria para el uso de time( )
#include <unistd.h>


using namespace std;

/*
 * 
 */

string ObtenerFecha(){
         char buffer[MAXLINEA];
         time_t curtime;
         struct tm *loctime;
         curtime = time (NULL);
         loctime = localtime (&curtime);
         strftime (buffer, MAXLINEA, "%Y-%m-%d %H:%M;", loctime);
         return buffer;
}

int main(int argc,char *argv[]) {
    
    if (argc > 1){
          string uax = argv[1];
          string aux = "-v";
          string generar = "-g";
          FILE *fichero;
          if(!aux.compare(uax)){   
          cout << "Los integrantes del grupo son : "  << endl;
          sleep(1);
          cout << "Joaquín Astudillo"  << endl;
          sleep(1);
          cout << "Roberto Esparza"    << endl;
          sleep(1);
          cout << "Jonathan Sepúlveda" << endl;
                  
          }   
          if(!generar.compare(uax)){
              fichero = fopen("qno.csv", "a+" );
              int n = 0, c = 0;
	
	int random[14];
	for(int i = 0; i < 14; i++)  // dejo la cadena vacía
		random[i] = 0;
        
	srand( time(NULL) );

	while( c != 14 )
	{
		n = (rand()%25)+1;

		for( int i = 0; i < 14; i++)
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
        
        string buffer = ObtenerFecha();
        
        fprintf(fichero,"%s",buffer.c_str());
        
        for(int i = 0 ; i < 14 ; i++){
        int au = random[i];
        fprintf(fichero,"%d;",au);
        }
          
          fprintf(fichero,"\n");
              fclose(fichero);
              cout << "sorteando los números..." << endl;
              sleep(1);
              cout << "..." << endl;
              sleep(1);
              cout << "..." << endl;
              sleep(1);
              cout << "listo hemos generado el ganador! " << endl;
          }
          }else{
          cout << "El comando ingresado no lleva ningún argumento." << endl;
          }         

  return 0;
    
}
    


