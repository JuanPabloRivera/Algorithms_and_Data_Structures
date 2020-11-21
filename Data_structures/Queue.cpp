#include <iostream>

using namespace std;

class Node{
    public:
        Node *next{nullptr};
        int value{};
        Node(){}
        Node(int data)
            : value{data}{}
};

class Queue{
    private:
        Node *first{nullptr};
        Node *last{nullptr};
        int size{0};
    public:
        void enqueue(int value){
            if (first == nullptr){
                first = new Node{value};
                last = first;
            }else{
                last->next = new Node{value};
                last = last->next;
            }
            size++;
        }

        void dequeue(){
            if (first != nullptr){
                Node *temp{first};
                first = first->next;
                delete temp;
                size--;
            }
        }

        int peek(){
            if (first != nullptr) return first->value;
            else return -1;
        }

        bool isEmpty(){
            return first == nullptr;
        }

        void print(){
            Node *current{first};
            cout << "[ ";
            while(current != nullptr){
                cout << current->value << " ";
                current = current->next;
            }
            cout << "]\n";
        }
};

int main(){

    Queue myQueue;

    cout << boolalpha;
    cout << myQueue.isEmpty() << endl;
    myQueue.enqueue(5);
    myQueue.enqueue(7);
    myQueue.enqueue(8);
    myQueue.print();
    cout << myQueue.isEmpty() << endl;
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue(50);
    myQueue.enqueue(333);
    myQueue.enqueue(1000);
    myQueue.print();

    return 0;
}