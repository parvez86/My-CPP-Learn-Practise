#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};


// insert data at index 0
void push(Node** head, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}


// insert data in the end
void append(Node** header, int data)
{
    Node* new_node = new Node();

    Node* temp = *header;

    new_node->data = data;
    new_node->next = NULL;
    if(*header == NULL) {*header = new_node; return;}
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_node(Node*& head, int data)
{
    Node* temp;
    while(head != NULL && head->data != data) head = head->next;

    //
    temp = head;
    head = head->next;


    delete(temp);
    return;
}

void delete_list(Node** head)
{
    Node* current = *head;
    Node* next=NULL;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    return;
}

void print_list(Node* head)
{
    Node* temp = head;
    cout<< "The items of list are: ";
    while(temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    cout<< endl;
}

int main()
{
    Node* head = NULL;
    append(&head, 3);
    append(&head, 5);

    append(&head, 7);
    append(&head, 9);
    append(&head, 3);
    append(&head, 2);
    push(&head, 1);
    print_list(head);
    delete_node(head, 3);
    delete_node(head, 3);
    print_list(head);
    delete_list(&head);
    print_list(head);
    return 0;
}
