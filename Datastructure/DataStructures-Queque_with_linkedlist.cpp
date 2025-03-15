#include"pch"
namespace{
    struct Node 
    {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    struct Queue
    {
        Node* front;
        Node* rear;

        Queue() 
        {
            front = nullptr;
            rear = nullptr;
        }

        // Check if the queue is empty
        bool isEmpty() 
        {
            return front == nullptr;
        }

        // Enqueue operation
        void enqueue(int value) 
        {
            Node* newNode = new Node(value);
            if (!rear/* == nullptr*/)
            {
                front = newNode;
                rear = newNode;
                return;
            }
            rear->next = newNode;
            /*ptr*/rear = newNode;
        }

        // Dequeue operation
        int dequeue() 
        {
            if (isEmpty()) 
            {
                std::cout << "Queue is empty!\n";
                return -1;
            }
            Node* prv_front = front;
            int value = prv_front->data;
            front = front->next;
            if (!front/* == nullptr*/)
            {
                rear = nullptr;
            }
            delete prv_front;

            return value;
        }

        // Peek operation
        int peek() 
        {
            if (isEmpty()) 
            {
                std::cout << "Queue is empty!\n";
                return -1;
            }
            return front->data;
        }

        // Display queue
        void display() 
        {
            if (isEmpty()) 
            {
                std::cout << "Queue is empty!\n";
                return;
            }
            Node* temp = front;
            std::cout << "Queue elements: ";
            while (temp != nullptr) 
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
    };
}

int main_queque_with_linkedlist() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    std::cout << "Dequeued: " << q.dequeue() << "\n";
    q.display();

    std::cout << "Front element: " << q.peek() << "\n";

    return 0;
}