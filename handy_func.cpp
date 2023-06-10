#include <chrono>
#include <iostream>

using namespace std;

template <typename my_class>
long long insertion_time_ms(int n, int table_size = 0) {
    
    int followers;
    long index;
    string username;

    auto start_time = std::chrono::high_resolution_clock::now();

    my_class table(table_size);
        while (n--){
            cin >> index >> followers;
            table.insert(index,followers);
        }

    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

template <typename my_class>
long long search_time_ms(long key, my_class table) {
    
    cin >> key;
    auto start_time = std::chrono::high_resolution_clock::now();

    table.find(key);

    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}
