#include <iostream>
using namespace std;


class Linked_List {

private:
    
    struct Node {
        int data;
        Node *next;
    };
    Node* head = NULL;
    int size;

    void addNode(int new_data) {
        Node* current = head;
        Node* node = (Node*) malloc(sizeof(Node));
        node->data = new_data;
        node->next = NULL;
    
        // special case for length 0
        if (current == NULL) {
            this->head = node;
        }
        else {
            // locate the last node
            while (current->next != NULL) {
                current = current->next;
            }
    
            current->next = node;
        }


    }

public:
    
    Linked_List() {



    }

    
    Linked_List(int data[], int size) {

        for (int i = 0; i < size-1; i++) {

            addNode(data[i]);

        }

    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = NULL;
        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete(temp);
            return;
        }
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return;
        prev->next = temp->next;
        delete(temp);
    }

    void print() {
        Node* ptr;
        ptr = head;
        while (ptr != NULL) {
            cout<< ptr->data <<" ";
            ptr = ptr->next;
        }
    }

    Node* getHead() {
        return head;
    }

    Linked_List immutable_add(Linked_List list, int data, int index) {
        
        Linked_List new_list = Linked_List();
        Node* temp = (Node*) malloc(sizeof(Node));
        temp = list.getHead();
        int currentIndex = 0;
        
        while (temp != NULL && currentIndex != index-1) {
            new_list.addNode(temp->data);
            temp = temp->next;
            currentIndex++;
        }

        Node* newTemp = (Node*) malloc(sizeof(Node));
        newTemp->data = temp->data;
        newTemp->next = temp->next;
        
        Node* newNode = (Node*) malloc(sizeof(Node));
        
        newNode->data = data;
        newNode->next = newTemp->next;
        newTemp->next = newNode;

        while (newTemp != NULL) {
            new_list.addNode(newTemp->data);
            newTemp = newTemp->next;
        }

        return new_list;

    }
        


};

int main() {


    int arr[10] = { 1,2,3,5,6,7,8,9,10 };
    Linked_List list = Linked_List(arr,10);
    Linked_List list2 = list2.immutable_add(list, 4, 3);
    list.print();
    cout<<endl;
    list2.print();
    
    
}