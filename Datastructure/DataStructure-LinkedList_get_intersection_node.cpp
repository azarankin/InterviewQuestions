namespace {
    struct Node {
        int data;
        Node* next;  // Allowed: Pointer to an incomplete type
    };
}
//Intersectio between different linkedlist
Node* getIntersectionNode(Node* p_headA, Node* p_headB) 
{
    if (!p_headA || !p_headB) return nullptr;

    Node* p_listA = p_headA;
    Node* p_listB = p_headB;

    while (p_listA != p_listB) 
    {
        p_listA = (p_listA == nullptr) ? p_headB : p_listA->next;
        p_listB = (p_listB == nullptr) ? p_headA : p_listB->next;
    }

    return p_listA; //if nullptr there is not intersection
}


bool isIntersectionNode(Node* p_headA, Node* p_headB) 
{
    Node* p_listA = getIntersectionNode(p_headA, p_headB);
    return p_listA != nullptr;
}