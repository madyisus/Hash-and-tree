#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;

template <typename indextype, typename my_class>
long long insertion_time_ms(int n) {
    
    int followers;
    indextype index;
    my_class tree(30000);

    auto start_time = std::chrono::high_resolution_clock::now();

        while (n--){
            cin >> index >> followers;
            tree.insert(index,followers);
            // tree.insert(index);
        }

    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
}

template <typename key_type,typename my_class>
long long search_time_ms(key_type&& key, my_class&& table) {


    auto start_time = std::chrono::high_resolution_clock::now();

           table.find(key);  
       
    auto end_time = std::chrono::high_resolution_clock::now();

    long long avg_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    return avg_time;
}

template<typename T>
void print_vector(vector<T> vec){
    for(auto it = vec.begin();it != vec.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template<typename T>
vector<T> vec_from_file(string path){ 
    // crea un vector a partir de un archivo
    ifstream stream(path);
    T var;
    vector<T> data;

    while(stream >> var && var){
        data.push_back(var);
    } 

    return data;
}


