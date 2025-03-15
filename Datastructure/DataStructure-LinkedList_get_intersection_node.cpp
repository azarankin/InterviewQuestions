namespace {
    struct Node {
        int data;
        Node* next;  // Allowed: Pointer to an incomplete type
    };
}

Node* getIntersectionNode(Node* headA, Node* headB) 
{
    if (!headA || !headB) return nullptr;

    Node* ptrA = headA;
    Node* ptrB = headB;

    while (ptrA != ptrB) 
    {
        ptrA = (ptrA == nullptr) ? headB : ptrA->next;
        ptrB = (ptrB == nullptr) ? headA : ptrB->next;
    }

    return ptrA; //if nullptr there is not intersection
}