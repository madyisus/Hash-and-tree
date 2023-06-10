#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include "HashClosedStr.cpp"
#include "HashClosedLong.cpp"
#include "AVLTree.hpp"
#include "AVLTreeNode.hpp"
#include "HashOpenLong.hpp"
#include "HashOpenStr.hpp"
#include "handy_func.cpp"

using namespace std;

int main(int argc, char *argv[]){

    string selected_class = "HashOpenLong"; // estructura usada
    string outfile_name, column_names;
    int t_size = 25000; // tamaño fijo de la tabla hash 
    double mm_total_time; // medidor de tiempo total

    ofstream outfile;

switch (atoi(argv[1]))
    {
    default:
    //################## Medición de tiempo de inserción #########################

    outfile_name =  "insertion" + selected_class + "_results.csv";
    column_names = "n,time[ms]\n";
    outfile.open(outfile_name);
    outfile << column_names;

    for(int n = 0; n < 25001; n+=2500){ // Realizamos lotes de insercion de n elementos a una tabla de tamaño t_size

        mm_total_time = 0;
        for(int k = 0; k < 20;k++){
            long long time = insertion_time_ms<HashOpenLong>(n,t_size); // medimos el tiempo de insercion
            mm_total_time += time;
        }
        double avg_time = mm_total_time/20;
    outfile<<n<<","<<avg_time<<endl;

    }
    outfile.close();
    break;

    case 1:

    //################## Medición de tiempo de búsqueda ###########################

    int followers, n = 25000; // n = cantidad de elementos a insertar
    long index;
    string username;
    string table_data = "clean_int_id.csv"; // datos en la tabla
    string input_data = "_in_table.csv";
    outfile_name =  "search" + selected_class + input_data;
    column_names = "key,time[ms]\n";
    outfile.open(outfile_name);
    outfile << column_names;

    // Cargamos los datos en la estructura
    HashOpenLong table(t_size); // Creamos la estructura
    ifstream ss(table_data);    // abrimos stream para rellenar la tabla

        while (n--){            // Insertamos datos en la tabla
            ss >> index >> followers;
            table.insert(index,followers);
        }

    int n_keys = 30;       // cantidad de elementos a buscar
    long key;

    // Ahora se realizan las búsquedas sobre la estructura ya creada
    while(n_keys--){

        cin >> key;

        mm_total_time = 0;
            for(int k = 0; k < 20;k++){
                long long time = search_time_ms(key,table); // medimos el tiempo de insercion
                mm_total_time += time;
            }
            long long avg_time = mm_total_time/20;
            outfile<<key<<","<<avg_time<<endl;

        }
    outfile.close();
    break;

    }

// esta listo insertion para los hash, seguir con search para los dos hash







return 0;
}