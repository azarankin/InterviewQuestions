#include"pch"
namespace {
    struct Node {
        int val;
        Node* next;
        Node(int _val) : val(_val), next(nullptr) {}
    };

    struct LinkedList {
        /*private:*/
        Node* head;

        LinkedList() : head(nullptr) {}

        Node* get_tail()
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            return temp;
        }

        void push(int val)  //in order
        {
            Node* newNode = new Node(val);

            // Case 1: Insert at the beginning (empty list or new value is the smallest)
            if (!head/* == nullptr*/)
            {
                //newNode->next = nullptr;
                head = newNode;
                return;
            }

            if (head->val >= val) {
                newNode->next = head;
                head = newNode;
                return;
            }

            // Case 2: Traverse the list to find the correct position
            Node* current = head;
            while (current->next /* != nullptr*/ && current->next->val < val)
            {
                current = current->next;
            }
            // Insert the new node
            newNode->next = current->next;
            current->next = newNode;

            /*
            Node* newNode = new Node(val);
            if (head == nullptr)
            {
                head = newNode;
                return;
            }

            Node* tail = get_tail();
            tail->next = newNode;
            */
        }

        void print() const
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                cout << temp->val << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }


        LinkedList(const LinkedList& other) : head{ nullptr }
        {
            Node* currentOriginal = other.head;
            while (currentOriginal != nullptr)
            {
                push(currentOriginal->val); // Add each node to the new list
                currentOriginal = currentOriginal->next;
            }
        }


        ~LinkedList()
        {
            Node* current = head;
            while (current != nullptr)
            {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }


        LinkedList copy() const
        {
            LinkedList newList;

            Node* currentOriginal = head;
            while (currentOriginal/* != nullptr*/)
            {
                newList.push(currentOriginal->val);
                currentOriginal = currentOriginal->next;
            }

            return newList;
        }

        LinkedList& operator=(LinkedList& other)
        {
            if (this == &other) return *this;

            //clear this LinkedList

            Node* cur = other.head;
            while (cur)
            {
                push(cur->val);
                cur = cur->next;
            }
            return *this;
        }


    };
}
int main_LinkedListOrdered() {
    LinkedList list;
    list.push(3);
    list.push(1);
    list.push(2);
    list.push(4);

    cout << "Original Linked List:" << endl;
    list.print();

    LinkedList copiedList = list;

    cout << "Copied Linked List:" << endl;
    copiedList.print();

    return 0;
}
