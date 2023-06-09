#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


DoublyLinkedListNode* insert(DoublyLinkedListNode* root, DoublyLinkedListNode* prev, int data) {
    if(!root){
        DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
        if(prev){
            prev->next=node;
            node->prev=prev;
        }
        return node;
    }else if(root->data >= data){
        DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
        node->next=root;
        root->prev=node;
        if(prev){
            prev->next=node;
            node->prev=prev;
        }
        root=node;
        return root;
    }
    root->next = insert(root->next, root, data);
    return root;
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    return insert(llist, NULL, data);
}
