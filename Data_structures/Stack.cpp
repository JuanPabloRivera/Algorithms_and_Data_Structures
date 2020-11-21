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

class Stack{
    private:
        Node *head{nullptr};
        int size{0};
    public:
        void push(int value){
            if (head == nullptr){
                head = new Node{value};
            }else{
                Node *newNode = new Node{value};
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        void pop(){
            if (head != nullptr){
                Node *temp{head};
                head = head->next;
                delete temp;
                size--;
            }
        }

        void flush(){
            while(!isEmpty()) pop();
        }

        int top(){
            if (head != nullptr) return head->value;
            else return -1;
        }

        bool isEmpty(){
            return head == nullptr;
        }

        void print(){
            Node *current{head};
            cout << "[ ";
            while(current != nullptr){
                cout << current->value << " ";
                current = current->next;
            }
            cout << "]\n";
        }
};

int main(){

    Stack myStack;
    cout <<  boolalpha;
    cout << myStack.isEmpty() << endl;
    myStack.push(5);
    myStack.push(8);
    myStack.push(3);
    myStack.print();
    cout << myStack.isEmpty() << endl;
    myStack.pop();
    myStack.pop();
    myStack.push(100);
    myStack.push(555);
    myStack.print();
    myStack.flush();
    myStack.print();

    return 0;
}