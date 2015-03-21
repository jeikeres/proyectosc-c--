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


using namespace std;

/*
 * 
 */
int main(int argc,char *argv[]) {
    
    if (argc > 1){
          string uax = argv[1];
          string aux = "-g";
          if(!aux.compare(uax)){
          cout << "Los integrantes del grupo son : "  << endl << 
                  "Joaquín Astudillo"  << endl << 
                  "Roberto Esparza"    << endl << 
                  "Jonathan Sepúlveda" << endl ;
          }else{
          cout << "el argumento no es válido válido "  << endl;    
          }
          }else{
          cout << "El comando ingresado no lleva ningún argumento." << endl;
          }

  return 0;
    
}
    


