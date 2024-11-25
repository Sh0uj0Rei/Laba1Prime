#include "BinaryTree.h"
#include <iostream>
#include <fstream>

TNode* insert(TNode* root, int key) {
    if (!root) return new TNode(key);

    TNode* current = root;
    TNode* parent = nullptr;
    while (current) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    TNode* newNode = new TNode(key);
    newNode->parent = parent;
    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

TNode* search(TNode* root, int key) {
    if (!root || root->key == key) return root;
    return (key < root->key) ? search(root->left, key) : search(root->right, key);
}

TNode* minElem(TNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

TNode* maxElem(TNode* root) {
    while (root && root->right) root = root->right;
    return root;
}

TNode* next(TNode* root) {
    if (root->right) return minElem(root->right);
    TNode* parent = root->parent;
    while (parent && root == parent->right) {
        root = parent;
        parent = parent->parent;
    }
    return parent;
}

TNode* del(TNode* root, int key) {
    TNode* node = search(root, key);
    if (!node) return root;

    if (!node->left && !node->right) {
        if (node->parent) {
            if (node == node->parent->left) node->parent->left = nullptr;
            else node->parent->right = nullptr;
        }
        else root = nullptr;
        delete node;
    }
    else if (!node->left || !node->right) {
        TNode* child = (node->left) ? node->left : node->right;
        if (node->parent) {
            if (node == node->parent->left) node->parent->left = child;
            else node->parent->right = child;
        }
        else root = child;
        child->parent = node->parent;
        delete node;
    }
    else {
        TNode* successor = minElem(node->right);
        node->key = successor->key;
        root = del(root, successor->key);
    }
    return root;
}

void saveBinaryTreeToFile(TNode* root, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error: Could not open file\n";
        return;
    }
    if (root) {
        file << root->key << std::endl;
        saveBinaryTreeToFile(root->left, filename);
        saveBinaryTreeToFile(root->right, filename);
    }
}

void loadBinaryTreeFromFile(TNode** root, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file\n";
        return;
    }
    int key;
    while (file >> key) {
        *root = insert(*root, key);
    }
}

void printBinaryTree(TNode* root, int space) {
    if (!root) return;
    space += 5;
    printBinaryTree(root->right, space);
    for (int i = 5; i < space; i++) std::cout << " ";
    std::cout << root->key << std::endl;
    printBinaryTree(root->left, space);
}

void clearTree(TNode* root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int countNodes(TNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCompleteBinaryTreeUtil(TNode* root, int index, int numberNodes) {
    if (!root) return true;
    if (index >= numberNodes) return false;
    return isCompleteBinaryTreeUtil(root->left, 2 * index + 1, numberNodes) &&
        isCompleteBinaryTreeUtil(root->right, 2 * index + 2, numberNodes);
}

bool isCompleteBinaryTree(TNode* root) {
    int numberNodes = countNodes(root);
    return isCompleteBinaryTreeUtil(root, 0, numberNodes);
}
