#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        //Attributes
        Node *next{nullptr};
        int value{};
        //Constructors
        Node(){};
        Node(int value){
            this->value = value;
        }
};

class SinglyLinkedList{
    private:
        Node *head{nullptr};
        int size{0};
    public:
        void append(int value){
            if (head == nullptr){
                head = new Node{value};
            }
            else{
                Node *current{head};
                while (current->next != nullptr) current = current->next;
                current->next = new Node{value};
            }
            size++;
        }

        void prepend(int value){
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            size++;
        }

        void deleteByValue(int value){
            if (head == nullptr) return;
            if (head->value == value) head = head->next;
            else{
                Node *current{head};
                while(current->next != nullptr){
                    if (current->next->value == value){
                        current->next = current->next->next;
                        break;
                    }
                    else{
                        current = current->next;
                    }
                }
            }
            size--;
        }

        void deleteByIndex(int index){
            if (index >= size) return;
            if (index == 0) head = head->next;
            else{
                Node *current{head};
                for (int i{0}; i < index-1; i++){
                    current = current->next;
                }
                current->next = current->next->next;
            }
            size--;
        }

        void print(){
            Node *current{head};
            cout << "[ ";
            while(current != nullptr){
                cout << current->value << " ";
                current = current->next;
            }
            cout << "]" << endl;
        }  
};

int main(){

    SinglyLinkedList list;
    list.append(5);
    list.append(7);
    list.append(10);
    list.append(8);
    list.print();
    list.prepend(3);
    list.prepend(9);
    list.print();
    list.append(21);
    list.append(1);
    list.print();
    list.deleteByValue(8);    //Deleting 8
    list.print();
    list.deleteByIndex(2);    //Deleting 5
    list.print();
    list.deleteByIndex(6);    //Nothing happens, index out of bounds
    list.print();

    return 0;
}