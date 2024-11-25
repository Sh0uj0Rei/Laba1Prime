struct NodeL {
    int data;
    NodeL* next;
};

void addHeadL(NodeL*& head, int value);
void addTailL(NodeL*& head, int value);
void deleteHeadL(NodeL*& head);
void deleteTailL(NodeL*& head);
bool deleteByValueL(NodeL*& head, int value);
NodeL* searchL(NodeL* head, int value);
void printListL(NodeL* head);
void clearListL(NodeL*& head);