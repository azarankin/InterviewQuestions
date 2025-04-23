struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};


Node* copyList(Node* head) {
    if (!head) return nullptr;

    Node* newHead = new Node(-1);
    Node* copy = newHead;
    Node* curr = head;

    while (curr) {
        copy->next = new Node(curr->val);

        //newNode->prev = copy;
        curr=curr->next;
        copy=copy->next;
        
    }

    Node*temp  = newHead -> next;
    //if (temp) realHead->prev = nullptr;

    delete newHead;

    return temp;
}



bool isEqual(Node* l1, Node* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}