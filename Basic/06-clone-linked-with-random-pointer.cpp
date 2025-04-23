struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* p_head) {
    if (!p_head) return nullptr;

    // 1. שיבוץ עותקים בין צמתים קיימים
    Node* p_curr = p_head;
    while (p_curr) {
        Node* copy = new Node(p_curr->val);
        //copy->value = curr->val;
        //copy->random = nullptr;
        copy->next = p_curr->next;
        p_curr->next = copy;
        p_curr = copy->next;
    }
    // ה random pointers שגויים

    // 2. קביעת random pointers
    p_curr = p_head;
    while (p_curr) {
        if (p_curr->random)
            p_curr->next->random = p_curr->random->next;
        p_curr = p_curr->next->next;
    }

    // 3. הפרדת הרשימות
    p_curr = p_head;
    Node* copy = p_head->next;
    Node* new_head = copy;
    
    while (p_curr) {
        
        if (copy->next)
            copy->next = copy->next->next;

        p_curr->next = p_curr->next->next;

        p_curr = p_curr->next;
        copy = copy->next;
    }

    return new_head;
}
