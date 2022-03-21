#include "MyContainers.h"

using namespace std;

SubSet::SubSet() {
    *sNode = nullptr;
}

bool SubSet::subInsert(subSetNode* sNode, subSetNode* newNode) {
    while (sNode != nullptr) {
        if (newNode->key > sNode->key) {
            if (sNode->right != nullptr)
                sNode = sNode->right;

            else {
                newNode->parent = sNode;
                sNode->right = newNode;
                return 1;
            }
        }

        else if (newNode->key < sNode->key) {
            if (sNode->left != nullptr)
                sNode = sNode->left;

            else {
                newNode->parent = sNode;
                sNode->left = newNode;
                return 1;
            }
        }

        else {
            delete newNode;
            break;
        }
    }

    return 0;
}

bool SubSet::insert(int k) {
    subSetNode* newNode = new subSetNode;
    newNode->key = k;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;

    if (sNode == nullptr) {
        sNode = newNode;
        return 1;
    }

    return subInsert(sNode, newNode);
}

subset_node* subMinimum(subSetNode* sNode) {
    if (sNode->left == nullptr)
        return sNode;

    return subMinimum(sn->left);
}

subset_node* subMaximum(subSetNode* sNode) {
    if (sNode->right == nullptr)
        return sNode;

    return subMinimum(sn->right);
}

bool subRemove(subSetNode* sNode, int k, bool* left) {
    if (sNode == nullptr)
        return 0;

    else if (k < sNode->key) {
        *left = 1;
        return subRemove(sNode->left, k, left);
    }

    else if (k > sNode->key) {
        *left = 0;
        return subRemove(sNode->right, k, left);
    }

    else if (sNode->left != nullptr && sNode->right != nullptr) {
        sNode->key = subMinimum(sNode->right)->key;
        *left = 0;
        return subRemove(sNode->right, sNode->key, left);
    }

    else {
        if (sNode->left != nullptr) {
            if (*left) {
                sNode->left->parent = sNode->parent;
                sNode->parent->left = sNode->left;
            }
            else {
                sNode->left->parent = sNode->parent;
                sNode->parent->right = sNode->left;
            }
            delete sNode;
        }

        else if (sNode->right != nullptr) {
            if (*left) {
                sNode->right->parent = sNode->parent;
                sNode->parent->left = sNode->right;
            }
            else {
                sNode->right->parent = sNode->parent;
                sNode->parent->right = sNode->right;
            }
            delete sNode;
        }

        else {
            subSetNode* temp = sNode;
            if (*left)
                sNode->parent->left = nullptr;
            else
                sNode->parent->right = nullptr;
            delete temp;
        }
    }

    return 1;
}

bool remove(int k) {
    if (sNode == nullptr) {
        return 0;
    }

    else if (sNode->left != nullptr && sNode->right == nullptr) {
        subSetNode* temp = sNode;
        sNode = sNode->left;
        sNode->parent = nullptr;
        delete temp;
        return 1;
    }

    else if ((*sn)->left == nullptr && (*sn)->right != nullptr) {
        subset_node* temp = (*sn);
        (*sn) = (*sn)->right;
        (*sn)->parent = nullptr;
        delete temp;
        return 1;
    }

    else if ((*sn)->left == nullptr && (*sn)->right == nullptr) {
        subset_node* temp = (*sn);
        (*sn) = nullptr;
        delete temp;
        return 1;
    }

    else {
        bool left;
        return subremove(sNode, k, &left);
    }
}

