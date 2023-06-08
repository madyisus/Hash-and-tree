#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <list>

class HashOpenStr {
private:
  int capacity;
  std::list<std::pair<long, int> > *table;

public:
  HashOpenStr(int V);
  void insertItem(long key, int data);
  void deleteItem(long key);
  int searchItem(long key);
  int checkPrime(int n);
  int getPrime(int n);
  int hashFunction(long key);
  void displayHash();
};

#endif
