#include <stdio.h>
#include <iostream>
#include <vector>
#include "HashClosedStr.cpp"
#include <functional>
#include <sstream>

using namespace std;

int main(){


int followers;
long index;
string username;

int t_size = 28000; // tamaño fijo de la tabla hash
int N = 2500; //cantidad de nodos a insertar


HashClosedStr table(t_size);

while (N--){
    cin >> username, followers;
    table.insert(username,followers);
}

cout<<"hi"<<endl;
return 0;
}