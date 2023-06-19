#include <stdio.h>
#include "AVLTree.hpp"
#include"AVLTreeNode.hpp"
#include <list>

using namespace std;

int main(){

AVLTree<long> tree;
AVLTreeNode<long> node(3245654333);

tree.insert(980984080598);
tree.insert(84043843098443);
tree.insert(9809840804598);
tree.insert(840438343098443);
cout<<"El peso de un nodo es "<<sizeof(node)<<" Bytes"<<", y de 26101 nodos es "<<sizeof(node)*26101<<" Bytes"<<endl;

list<pair<long, int>> test;
test.push_front({23455423345,34});
test.push_front({23455423345,34});
test.push_front({23455423345,34});
test.push_front({23455423345,34});
test.push_front({23455423345,34});

cout<<"Peso de list of pairs of long,int: "<<sizeof(test.front())<<" y hay "<<test.size()<<" elementos"<<endl;


vector<pair<long, int> > test2;

cout<<"Peso de vector of pairs of long,int: "<<sizeof(test2.front())<<" y hay "<<test2.size()<<" elementos"<<endl;
return 0;
}