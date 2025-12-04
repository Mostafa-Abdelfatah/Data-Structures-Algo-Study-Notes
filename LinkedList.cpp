#include <iostream>

using namespace std;

struct Node{
    int data = 0;
    Node* next = nullptr;
    Node(int d) {
        data = d;
    }
};

class LinkedList{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    void print(){
        Node* temp = head;
        for(; temp != nullptr; temp = temp->next){
            cout << temp->data << " ";
        }
        cout << endl;
    }
    void insert_end(int d){
        Node * newDate = new Node(d);
        if(head == nullptr) {
            head = newDate;
            tail = head;
        }
        else {
            tail->next = newDate;
            tail = newDate;
        }
    }

    void insert_front(int d){
        Node *newNode = new Node(d);
        if(head == nullptr){
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void delete_front(){
        Node*temp = head;
        head = head->next;
        delete temp;
    }

    //this code is good with dealing only with head not for tail
    // if I searched for te last element like 6 -> 10 -> 8 -> 15
    // if I search(15) the list 6 -> 10 -> 15 -> 8
    // but the tail -> 15  not 8
    Node* search_improved(int target){
        //I need 3 nodes to swap 2 nodes like swap 2 vars
        Node *temp = head, *perv = head, *pervPerv = head;
        for(;temp != nullptr; temp = temp->next){
            if(temp->data == target){
                if(temp != head) {
                  perv->next = temp->next;
                  temp->next = perv;
                  pervPerv->next = temp;
                }
                cout << tail->data << endl;
                return temp;
            }
            pervPerv = perv;
            perv = temp;
        }
        return nullptr;
    }
    Node* search_improved_deal_with_tail(int target){
        Node *temp = head, *perv = head, *pervPerv = head;
        for(;temp != nullptr; temp = temp->next){
            if(temp->data == target){
                // I need to add another condition for if temp == tail
                // and edit the 1st condition
                if(temp != head && temp != tail) {
                    perv->next = temp->next;
                    temp->next = perv;
                    pervPerv->next = temp;
                }
                else if(temp == tail){
                    // it is the same code but just make the tail->perv
                    perv->next = temp->next;
                    tail = perv;
                    temp->next = perv;
                    pervPerv->next = temp;

                }
                return temp;
            }
            pervPerv = perv;
            perv = temp;
        }
        return nullptr;
    }

    ~LinkedList(){
        Node *perv, *temp = head;
        while (temp){
            perv = temp;
            temp = temp->next;
            delete perv;
        }
        delete perv;
        delete temp;
    }
};

int main() {

    LinkedList list;

    list.insert_end(6);
    list.insert_end(10);
    list.insert_end(8);
    list.insert_end(15);
    list.print();

//    list.search_improved(15);
//    list.print();
    list.search_improved_deal_with_tail(15);
    list.print();

    return 0;
}