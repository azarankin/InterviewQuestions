struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* result = new Node(-1);
    Node* curr_result = result;
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

        
        curr_result->next = new Node(sum % 10);
        carry = sum / 10;

        curr_result = curr_result->next;
    }

    Node*temp=result->next;
    delete result;
    return temp;
}


Node* addTwoNumbersRec(Node* l1, Node* l2, int carry = 0) {
    if (!l1 && !l2 && carry == 0)
        return nullptr;

    int sum = carry;
    if (l1) sum += l1->val;
    if (l2) sum += l2->val;

    Node* result = new Node(sum % 10);

    if(l1) l1->next;
    if(l2) l2->next;

    result->next = addTwoNumbersRec(l1, l2, sum / 10);

    return result;
}