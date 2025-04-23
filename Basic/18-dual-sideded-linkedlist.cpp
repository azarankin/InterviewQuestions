struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void removeFromHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    delete temp;
}
