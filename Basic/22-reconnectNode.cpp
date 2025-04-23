struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};


void reconnectNode(Node* head, Node* missing) {
    if (!head || !missing) return;

    Node* prev = nullptr;
    Node* curr = head;

    while (curr && curr->next && curr->next->val < missing->val) {
        prev = curr;
        curr = curr->next;
    }

    // הכנסה של missing בין curr ל־curr->next
    missing->next = curr->next;
    curr->next = missing;
}
