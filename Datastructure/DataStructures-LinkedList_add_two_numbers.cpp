#include"pch"

namespace{
    struct Node;


    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    struct LinkedList {
        Node* head;
        LinkedList() : head(nullptr) {}
        LinkedList(int _val) : head(new Node(_val)) {}
        LinkedList(Node* _head) : head(_head) {}

    };


    Node* addTwoNumbers(Node* l1, Node* l2);

    LinkedList* addTwoNumbers(LinkedList* l1, LinkedList* l2) {

        Node* newNode = addTwoNumbers(l1->head, l2->head);
        LinkedList* newLinkedList = new LinkedList(newNode);
        //return new LinkedList(newNode);
        return newLinkedList;
    }


    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* newNode = new Node(0);    //first node

        int sum1 = 0;
        while (l1)
        {
            sum1 = sum1 * 10 + l1->val;
            l1 = l1->next;
        }

        int sum2 = 0;
        while (l2)
        {
            sum2 = sum2 * 10 + l2->val;
            l2 = l2->next;
        }

        int total_sum = sum1 + sum2;

        while (total_sum <= 0)
        {
            newNode->val = total_sum % 10;
            newNode = newNode->next;
            total_sum /= 10;
        }

        /*
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new Node(sum % 10);
            current = current->next;
        }
        return newNode->next;
        */

        return newNode;
    }


    void printList(Node* node) {
        while (node) 
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
}

int main_addTwoNumbers() {
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3); // 342

    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4); // 465

    Node* result = addTwoNumbers(l1, l2);
    printList(result); // 7 -> 0 -> 8 (807)
    return 0;
}
