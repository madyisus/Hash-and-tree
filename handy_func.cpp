#include <chrono>
#include <iostream>

using namespace std;

template <typename my_class, typename indextype>
long long insertion_time_ms(int n, int table_size) {
    
    int followers;
    indextype index;

    auto start_time = std::chrono::high_resolution_clock::now();

    AVLTree<indextype> tree;
    // my_class table(table_size);
        while (n--){
            cin >> index >> followers;
            // table.insert(index,followers);
            tree.insert(index);
        }

    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

template <typename key_type,typename my_class>
long long search_time_ms(key_type key, my_class table) {

    auto start_time = std::chrono::high_resolution_clock::now();

    table.find(key);

    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}
