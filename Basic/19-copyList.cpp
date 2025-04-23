struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};


Node* copyList(Node* head) {
    if (!head) return nullptr;

    Node* newHead = new Node(head->val);
    Node* currOld = head->next;
    Node* currNew = newHead;

    while (currOld) {
        currNew->next = new Node(currOld->val);
        currNew = currNew->next;
        currOld = currOld->next;
    }

    return newHead;
}
