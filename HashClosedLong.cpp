#include <vector>

class HashClosedLong {
private:
  int size; 
  std::vector<std::pair<long, int>> table; 

  int hash(long key) const {
    return key % size;
  }

  int quadraticProbe(int index, int attempt) const {
    return (index + attempt * attempt) % size;
  }

public:
  HashClosedLong(int size): size(size), table(size) {}

  void insert(long key, int value) {
    int index = hash(key);
    int attempt = 0;
    while (table[index].first != 0 && table[index].first != key) {
      attempt++;
      index = quadraticProbe(index, attempt);
    }
    table[index] = {key, value};
  }

  int get(long key) const {
    int index = hash(key);
    int attempt = 0;
    while (table[index].first != 0 && table[index].first != key) {
      attempt++;
      index = quadraticProbe(index, attempt);
    }
    if (table[index].first == key)
      return table[index].second;
    return -1; 
  }

  void remove(long key) {
    int index = hash(key);
    int attempt = 0;
    while (table[index].first != 0 && table[index].first != key) {
      attempt++;
      index = quadraticProbe(index, attempt);
    }
    if (table[index].first == key) 
      table[index].first = 0; 
  }
};
