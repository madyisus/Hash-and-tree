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
#include "arbolBinarioBusqueda.hpp"

using namespace std;

int main(){

AVLTree<string> tree;

int n = 26101; // cantidad de elementos a insertar
string table_data = "clean_str_id.csv"; // datos en la tabla
string followers;
string index;


ifstream ss(table_data);    // abrimos stream para rellenar la tabla

    while (n--){            // Insertamos datos en la tabla
        ss >> index >> followers;
        tree.insert(index);
        }

string path = "in_search_str.csv";
vector<string> numbers = vec_from_file<string>(path);

for(auto number:numbers){

    float total_time = 0;
    for(int k = 0; k < 20;k++){
        float time = search_time_ms(number,tree);
        total_time += time;
    }
    
    float avg_time = total_time/20;
    cout<<avg_time<<endl;
}



return 0;
}