#include <string>
#include <vector>

using namespace std;

class HashClosedStr {
private:
  int size; 
  vector<pair<string, int>> table; 
  int hash(const string& key) const{
      int hashVal = 0;
      for(char ch : key) hashVal += ch;
      return hashVal % size;
  }
  int quadraticProbe(int index, int attempt) const {
    return (index + attempt * attempt) % size;
  }
public:
  HashClosedStr(int size): size(size), table(size) {}

  void insert(const string& key, int value) {
    int index = hash(key);
    int attempt = 0;
    while (table[index].first != "" && table[index].first != key) {
        attempt++;
        index = quadraticProbe(index, attempt);
    }
    table[index] = {key, value};
  }

  int find(const string& key) const {
    int index = hash(key);
    int attempt = 0;
    while (table[index].first != "" && table[index].first != key) {
        attempt++;
        index = quadraticProbe(index, attempt);
    }
    if (table[index].first == key)
        return table[index].second;
    return -1; 
  }

  void remove(const string& key) {
    int index = hash(key);
    int attempt = 0;
    while (table[index].first != "" && table[index].first != key) {
        attempt++;
        index = quadraticProbe(index, attempt);
    }
    if (table[index].first == key) 
        table[index].first = ""; 
  }
};
