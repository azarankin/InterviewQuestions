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

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    Node*curr = head;
    while(curr->next)
    {
        curr = curr->next;
    }
    
    curr->next = newNode;
    newNode->prev = curr;
}

void removeFromHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    if (head->next)
        head->next->prev = nullptr;
    head = head->next;
    
        
    delete temp;
}

void removeFromEnd(Node*& head) {
    if (!head) return;
    Node*curr = head;
    while(curr->next)
    {
        curr = curr->next;
    }
    if(curr->prev)
        curr->prev->next = nullptr;
    else
        head = nullptr;
        
    delete curr;
}
