struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

void deleteNode(Node* node) {
    if (!node || !node->next) return; // אי אפשר למחוק את האחרון

    Node* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}
