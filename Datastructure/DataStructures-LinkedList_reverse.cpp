

namespace {
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
}
Node* reverseList(Node* head) {
    Node* p_prev = nullptr;
    Node* p_current = head;

    // Traverse the list and adjust pointers one by one
    while (p_current/* != nullptr*/) {
        Node* nextNode = p_current->next; // store next
        p_current->next = p_prev;               // reverse pointer
        p_prev = p_current;                     // move prev forward
        p_current = nextNode;                 // move current forward
    }

    // 'prev' will point to the new head of the reversed list
    return p_prev;
}