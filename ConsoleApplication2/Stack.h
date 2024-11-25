struct Node {
    int numbr;
    Node* next;
};

struct S {
    Node* head = nullptr;
};

void AddS(S* stack, int data);
void DelS(S* stack);
void ShowS(S* stack);
void ClearStack(S* stack);