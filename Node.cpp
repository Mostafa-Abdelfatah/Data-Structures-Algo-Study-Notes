#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
    }
};

void print(Node *head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void print2(Node *head){
    if(head == nullptr){
        cout << endl;
        return;
    }
    else {
        cout << head->data << " ";
        print2(head -> next);
    }
}

void print_reversed(Node * head){
    if(head == nullptr){
        cout << endl;
        return;
    }
    print_reversed(head->next);
    cout << head->data << " ";
}

Node* search(Node* head, int target){
    while(head != nullptr){
        if(head->data == target){
            return head;
        }
        head = head->next;
    }
    return nullptr;
}
int main(){
    /**
    why Node *n2
     because this a pointer that hold a reference of Node object n the heap
     we use heap to make it dynamic I should delete it

     while "Node n2"
     this is an object in stack after main method return the object will be deallocate 
     from the memory

     if I am standing at the nullptr and try to print data I will get runtime error
     */
    Node* n1 = new Node(1);
    Node* n2 = new Node(4);
    Node* n3 = new Node(90);

    n1->next = n2;
    n2->next = n3;
    n3 -> next = nullptr;

    Node n4(13);
    n3->next = &n4;
    n4.next = nullptr;
    /**             traverse through list   */
    Node* temp = n1;
    while(temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    //runtime error
    /*

     cout << temp->next <<endl;

     */
    print(n1);
    print2(n1);
    print_reversed(n1);
    cout << endl;
    Node* searchTest = search(n1, 90);
    if(searchTest){
        cout << searchTest->data << endl;
    }
    else {
        cout << "not found" << endl;
    }
    return 0;
}
