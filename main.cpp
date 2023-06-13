#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <map>
#include "HashClosedStr.cpp"
#include "HashClosedLong.cpp"
#include "AVLTree.hpp"
#include "AVLTreeNode.hpp"
#include "HashOpenStr.hpp"
#include "HashOpenLong.hpp"
#include "handy_func.cpp"

using namespace std;

int main(int argc, char *argv[]){

    string selected_class = "HashClosedStr"; // estructura usada
    string outfile_name, column_names;
    int t_size = 30000; // tamaño fijo de la tabla hash 
    double mm_total_time; // medidor de tiempo total

    ofstream outfile;

switch (atoi(argv[1]))
    {
    default:
    //################## Medición de tiempo de inserción #########################

    outfile_name =  "insertion" + selected_class + "_results.csv";
    column_names = "n,time[ms]\n";
    outfile.open("./outputs/"+outfile_name);
    outfile << column_names;

    for(int n = 0; n < 25001; n+=2500){ // Realizamos lotes de insercion de n elementos a una tabla de tamaño t_size

        // Medimos el tiempo de insercion 20 veces y tomamos el promedio simple
        mm_total_time = 0;
        for(int k = 0; k < 20;k++){
            long long time = insertion_time_ms<HashClosedLong,long>(n,t_size); 
        }
        double avg_time = mm_total_time/20;
    outfile<<n<<","<<avg_time<<endl;
    cout<<"Saved in file: ./outputs/"<<outfile_name<<endl;

    }
    outfile.close();
    break;

    case 1:

    //################## Medición de tiempo de búsqueda ###########################

    int followers, n = 25000; // n = cantidad de elementos a insertar
    long index;
    string username;
    string table_data = "clean_str_id.csv"; // datos en la tabla
    string input_data = "_in_table.csv";
    outfile_name =  "search" + selected_class + input_data;
    column_names = "key,time[ms]\n";
    outfile.open("./outputs/"+outfile_name);
    outfile << column_names;

    // Cargamos los datos en la estructura
    // map<string,int> tree;
    HashClosedStr table(t_size); // Creamos la estructura
    ifstream ss(table_data);    // abrimos stream para rellenar la tabla

        while (n--){            // Insertamos datos en la tabla
            ss >> username >> followers;
            table.insert(username,followers);
            // tree[username] = followers;
        }

    int n_keys = 300;       // cantidad de elementos a buscar
    string key;

    // Ahora se realizan las búsquedas sobre la estructura ya creada
    while(n_keys--){

        cin >> key;
        long K = 20; // Numero de experimentos

        // Analogamente hacemos 20 veces cada busqueda y tomamos el promedio simple
        mm_total_time = 0;
            for(int k = 0; k < K;k++){
                long long time = search_time_ms(key,table);
                // float time = search_time_ms(key,tree); 
                mm_total_time += time;
            }
        float avg_time = mm_total_time/K;
        cout<<key<<" "<<avg_time<<endl;
        outfile<<key<<","<<avg_time<<endl;

         }
    outfile.close();
    cout<<"Saved in file: ./outputs/"<<outfile_name<<endl;
    break;

    }



return 0;
}