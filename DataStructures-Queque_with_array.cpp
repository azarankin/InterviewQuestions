#include <iostream>
namespace {
    class Queue
    {
    private:
        int* arr;
        int front;
        int rear;
        int capacity;
        int size;

    public:
        // Constructor
        Queue(int _capacity)
        {
            this->capacity = _capacity;
            arr = new int[_capacity];
            front = 0;
            rear = -1;
            size = 0;
        }

        // Destructor
        ~Queue() {
            delete[] arr;
        }

        // Function to check if the queue is full
        bool isFull()
        {
            return size == capacity;
        }

        // Function to check if the queue is empty
        bool isEmpty()
        {
            return size == 0;
        }

        // Function to add an element to the queue (enqueue)
        void enqueue(int value)
        {
            if (isFull())
            {
                std::cout << "Queue is full!\n";
                return;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            size++;
        }

        // Function to remove an element from the queue (dequeue)
        int dequeue() {
            if (isEmpty()) {
                std::cout << "Queue is empty!\n";
                return -1;
            }
            int value = arr[front];
            front = (front + 1) % capacity;
            size--;
            return value;
        }

        // Function to get the front element
        int peek()
        {
            if (isEmpty())
            {
                std::cout << "Queue is empty!\n";
                return -1;
            }
            return arr[front];
        }

        // Function to print queue elements
        void display() {
            if (isEmpty()) {
                std::cout << "Queue is empty!\n";
                return;
            }
            std::cout << "Queue elements: ";
            for (int i = 0; i < size; i++) 
            {
                std::cout << arr[(front + i) % capacity] << " ";
            }
            std::cout << "\n";
        }
    };
}

int main_queque_with_array()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    std::cout << "Dequeued: " << q.dequeue() << "\n";
    q.display();

    std::cout << "Front element: " << q.peek() << "\n";

    return 0;
}
