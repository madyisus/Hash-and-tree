#include "HashOpenLong.hpp"
// from https://www.programiz.com/dsa/hash-table 

HashOpenLong::HashOpenLong(int c) {
  int size = getPrime(c);
  this->capacity = size;
  table = new std::list<std::pair<long, int>>[capacity];
}

void HashOpenLong::insert(long key, int data) {
  int index = hashFunction(key);
  table[index].push_back(std::make_pair(key, data));
}

void HashOpenLong::deleteItem(long key) {
  int index = hashFunction(key);

  std::list<std::pair<long, int>>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if ((*i).first == key) {
      break;
    }
  }

  if (i != table[index].end()) {
    table[index].erase(i);
  }
}

int HashOpenLong::find(long key) {
  int index = hashFunction(key);

  for (auto it = table[index].begin(); it != table[index].end(); it++) {
    if ((*it).first == key) {
      return (*it).second;
    }
  }

  return -1;
}

int HashOpenLong::checkPrime(int n) {
  int i;
  if (n == 1 || n == 0) {
    return 0;
  }
  for (i = 2; i < n / 2; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int HashOpenLong::getPrime(int n) {
  if (n % 2 == 0) {
    n++;
  }
  while (!checkPrime(n)) {
    n += 2;
  }
  return n;
}

int HashOpenLong::hashFunction(long key) {
  return (key % capacity);
}

void HashOpenLong::displayHash() {
  for (int i = 0; i < capacity; i++) {
    std::cout << "table[" << i << "]";
    for (auto x : table[i]) {
      std::cout << " --> (" << x.first << ", " << x.second << ")";
    }
    std::cout << std::endl;
  }
}

