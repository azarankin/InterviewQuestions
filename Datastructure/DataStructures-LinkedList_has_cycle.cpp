
#include"pch"

namespace{
    struct Node 
    {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
}

bool hasCycle(Node* head) 
{
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) 
    {
        slow = slow->next;       // Tortoise moves one step
        fast = fast->next->next; // Hare moves two steps

        if (slow == fast) return true; // If they meet, there is a cycle
    }

    return false; // If we reach the end of the list, there is no cycle
}

int main_hasCycle() 
{
    // Creating a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 2 (loops back to 2)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    if (hasCycle(head)) 
    {
        cout << "The list contains a cycle!" << endl;
    }
    else 
    {
        cout << "No cycle in the list." << endl;
    }

    return 0;
}
