#include <string>

struct TNode {
    int key;
    TNode* parent;
    TNode* left;
    TNode* right;

    TNode(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

TNode* insert(TNode* root, int key);
TNode* search(TNode* root, int key);
TNode* minElem(TNode* root);
TNode* maxElem(TNode* root);
TNode* next(TNode* root);
TNode* del(TNode* root, int key);
void saveBinaryTreeToFile(TNode* root, const std::string& filename);
void loadBinaryTreeFromFile(TNode** root, const std::string& filename);
void printBinaryTree(TNode* root, int space = 0);
void clearTree(TNode* root);
int countNodes(TNode* root);
bool isCompleteBinaryTree(TNode* root);