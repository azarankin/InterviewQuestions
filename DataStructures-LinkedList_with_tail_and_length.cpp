#include <iostream>

using namespace std;
namespace {
    class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
    };

    class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* current = head;
            while (head) {
                head = head->next;
                delete current;
                current = head;
            }
        }

        void printList() {
            Node* current = head;
            if (!current/* == nullptr*/)
            {
                cout << "empty";
            }
            else
            {
                while (current != nullptr)
                {
                    cout << current->value;
                    current = current->next;
                    if (current != nullptr)
                    {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead()
        {
            return head;
        }

        Node* getTail()
        {
            return tail;
        }

        int getLength()
        {
            return length;
        }

        // We will use this method to test append to an empty list
        void makeEmpty()
        {
            Node* current = head;
            while (head)
            {
                head = head->next;
                delete current;
                current = head;
            }
            tail = nullptr;
            length = 0;
        }


        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            ++length;
        }


    };


}