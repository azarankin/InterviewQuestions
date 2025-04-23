struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

void deleteNode(Node* node) {
    if (!node || !node->next) return; // אי אפשר למחוק את האחרון
     
    node->val = node->next->val;
    Node* temp = node->next;
    node->next = temp->next;
    delete temp;
}
