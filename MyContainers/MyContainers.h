#include <iostream>
#include <algorithm>

class SubSet {
private:
    struct subSetNode {
        int key;
        subSetNode* left;
        subSetNode* right;
        subSetNode* parent;
    };
    subSetNode* sNode;
    bool subInsert(subSetNode* sNode, subSetNode* newNode);
    subset_node* subMinimum(subSetNode* sNode);
    subset_node* subMaximum(subSetNode* sNode);
    bool subRemove(int k, bool* left);
    subDFS(int* array, int* counter);
    subDestructor();
public:
    SubSet();
    ~SubSet();
    bool insert(int k);
    int minimum();
    int maximum();
    bool remove(int k);
    unsigned int size();
    unsigned int height();
    int* DFS();
};
