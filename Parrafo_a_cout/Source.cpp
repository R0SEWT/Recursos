#include<iostream>
#include<fstream>
#include<vector>
#include<string>


/**
* Si solo deseas hacer uso del programa: 
*   1) Crea un archivo llamado fuente.dat
*   2) Copia el texto en fuente.dat
*   3) Ejecuta el programa
*   4) Las lineas de codigo se encuentra como texto en procesado.dat
*   5) Copia y pega en tu programa
* 
**/


 /**
 * Para el siguiente codigo necesitamos leer, manipular y escribir
 * Usaremos fuente.dat como entrada
 * Usaremos procesado.dat como salida
 * 
 **/

using namespace std;

int main(){
   
    // Input
    ifstream fichero("fuente.dat");
    if (!fichero.is_open())
    {
        cout << "Error al abrir fuente.dat\n";
        exit(EXIT_FAILURE);
    }
    /**
   * leemos el contenido del fichero usando getline
   * y lo almacenemos linea a linea en contenido
   * 
   **/
    string linea; // aqui guardaremos la linea actual
    vector<string> contenido; // aqui guardaremos en memoria las lineas
   
    while (getline(fichero, linea) ) {
        contenido.push_back(linea);
    }
    /**
    * Manipulamos el contendio para agregar cout<<" y un "<<endl;
    * 
    **/

    for (int i = 0; i < contenido.size(); i++) {
        contenido[i] = "cout<< \"" + contenido[i] + "\" <<endl;";
    }
    fichero.close();
    /**
    * Finalmente almacenemos el contenido en procesado.dat
    * 
    **/

    ofstream fich("procesado.dat");

    if (!fich.is_open())
    {
        cout << "Error al abrir procesado.dat\n";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < contenido.size(); i++) {
        fich << contenido[i]<<endl;
    }
    cout << "Operacion exitosa" << endl;


   

    
    return 0;
}