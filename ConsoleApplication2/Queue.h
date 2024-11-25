struct Node {
    int numbr;
    Node* next;
};

struct Q {
    Node* first;
    Node* last;
    Q() : first(nullptr), last(nullptr) {}
};

void AddQ(Q& queue, int number);
void DelQ(Q& queue);
void ShowQ(const Q& queue);
void ClearQueue(Q& queue);