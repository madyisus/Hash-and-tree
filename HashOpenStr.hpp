
#define HASHTABLE_HPP

#include <iostream>
#include <string>
#include <list>

class HashOpenStr {
private:
  int capacity;
  std::list<std::pair<std::string, int> > *table;

public:
  HashOpenStr(int V);
  void insert(std::string key, int data);
  void deleteItem(std::string key);
  int find(std::string key);
  int checkPrime(int n);
  int getPrime(int n);
  int hashFunction(std::string key);
  void displayHash();
};

