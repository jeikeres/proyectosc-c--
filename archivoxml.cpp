/*
 * File:   main.cpp
 * Author: Jake
 *
 * Created on 16 de abril de 2015, 17:13
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h> // libreria para el uso de rand( )
#include <time.h>   // libreria para el uso de time( )
#include <unistd.h>
#include <string>
#include "pugiconfig.hpp"
#include "pugixml.hpp"

/*
 *
 */

int main(int argc, char** argv)
{
    std::vector<std::string> sistemas;
    pugi::xml_document doc;
    if (!doc.load_file("browscap.xml"))
    {
        std::cerr << "Error al cargar el documento XML." << std::endl;
        return -1;
    }
    // Creamos un objeto nodo
    pugi::xml_node root_node;
    pugi::xml_node nodo_dos = root_node.first_child();
    pugi::xml_node nodo_tres = nodo_dos.first_child();
    
    // Le asignamos el nodo principal comprobando que sea correcto
    if (!(root_node = doc.child("browsercaps")))
    {
        std::cerr << "El documento no es un mapa valido." << std::endl;
        return -2;
    }
    
    // Recorremos todos los nodos hijos de root_node
    for (pugi::xml_node node = root_node.first_child(); node; node = node.next_sibling())
    {
        for (pugi::xml_node node = root_node.first_child().first_child(); node; node = node.next_sibling()){
            for (pugi::xml_node node = root_node.first_child(); node; node = node.next_sibling()){
                std::string aux = node.name();
                if(aux == "browsercapitems"){
                    root_node = node;
                    for (pugi::xml_node node = root_node.first_child(); node; node = node.next_sibling()){
                        std::string aux2 = node.name();
                        if(aux2 == "browscapitem"){
                            root_node = node;
                            for (pugi::xml_node node = root_node.first_child(); node; node = node.next_sibling()){
                                //std::cout << node.name() << std::endl;
                                std::string name = node.attribute("name").value();
                                std::string value = node.attribute("value").value();
                                if(name == "Platform"){
                                    sistemas.push_back(value);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    // Evitamos el cierre de la aplicacion en entornos
    
    //std::sort(sistemas.begin(), sistemas.end());
    
    std::sort(sistemas.begin(), sistemas.end());
    sistemas.erase(std::unique(sistemas.begin(), sistemas.end()), sistemas.end());
    
    
    int conteo = 0;
    
    for(int i = 0; i < sistemas.size(); i++){
        std::cout << sistemas.at(i)  << std::endl;
        conteo++;
    }
    std::cout << "Cantidad de S.O : " << conteo;
    std::cin.get();
    
    return 0;
}
