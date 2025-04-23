struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* newHead = new Node(-1);
    Node* curr = newHead;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int new_val = sum % 10;
        curr->next = new Node(new_val);
        curr = curr->next;
    }

    Node*temp=newHead->next;
    delete newHead;
    return temp;
}


Node* addTwoNumbersRec(Node* l1, Node* l2, int carry = 0) {
    if (!l1 && !l2 && carry == 0)
        return nullptr;

    int sum = carry;
    if (l1) sum += l1->val;
    if (l2) sum += l2->val;

    Node* result = new Node(sum % 10);

    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
    result->next = addTwoNumbersRec(l1, l2, sum / 10);

    return result;
}