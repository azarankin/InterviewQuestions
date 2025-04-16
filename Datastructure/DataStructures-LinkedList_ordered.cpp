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

            // if (!head)
            // {
            //     //newNode->next=nullptr;
            //     head = newNode;
            //     return;
            // }

            if (!head || head->val >= val) {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* p_current = head;
            while (p_current->next && p_current->next->val < val)
            {
                p_current = p_current->next;
            }
            // Insert the new node
            newNode->next = p_current->next;
            p_current->next = newNode;
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
