struct NodeLS {
    int data;
    NodeLS* next;
    NodeLS* previous;
};

void addHeadLS(NodeLS*& head, NodeLS*& tail, int value);
void addTailLS(NodeLS*& head, NodeLS*& tail, int value);
void deleteHeadLS(NodeLS*& head, NodeLS*& tail);
void deleteTailLS(NodeLS*& head, NodeLS*& tail);
bool deleteByValueLS(NodeLS*& head, NodeLS*& tail, int value);
NodeLS* searchLS(NodeLS* head, int value);
void printListLS(NodeLS* head);
void clearListLS(NodeLS*& head, NodeLS*& tail);