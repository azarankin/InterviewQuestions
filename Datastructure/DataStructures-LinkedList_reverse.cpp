

namespace {
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
}
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    // Traverse the list and adjust pointers one by one
    while (current/* != nullptr*/) {
        Node* nextNode = current->next; // store next
        current->next = prev;               // reverse pointer
        prev = current;                     // move prev forward
        current = nextNode;                 // move current forward
    }

    // 'prev' will point to the new head of the reversed list
    return prev;
}