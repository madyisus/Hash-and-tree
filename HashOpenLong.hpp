#ifndef HASHTABLELONG_HPP
#define HASHTABLELONG_HPP

#include <iostream>
#include <list>

class HashOpenLong {
private:
  int capacity;
  std::list<std::pair<long, int> > *table;

public:
  HashOpenLong(int V);
  void insert(long key, int data);
  void deleteItem(long key);
  int find(long key);
  int checkPrime(int n);
  int getPrime(int n);
  int hashFunction(long key);
  void displayHash();
};

#endif