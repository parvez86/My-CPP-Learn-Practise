#include <iostream>

using namespace std;

class LinkedList{
private:
    struct node{
        int data;
        node* next;
    };
    node* head;

    node* makeEmpty(node* head){
        if(head == NULL) return NULL;

        makeEmpty(head->next);

        delete head;
        return NULL;
    }

    node* insert_node_in_front(node* head, int data){
        // create new node
        node* new_node = new node;
        new_node->data = data;
        new_node->next = head;

        // set new node as head
        head = new_node;

        return head;
    }

    node* insert_node_in_end(node* head, int data){
        // if end is found
        if(head == NULL){
            // create new node
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            return new_node;
        }
        //
        head->next = insert_node_in_end(head->next, data);
        return head;
    }

    void insert_node_in_position(node* head, int data){

        node* prev_node = head;
        // get the previous node
        while(prev_node && prev_node->next && prev_node->next->data <= data) prev_node = prev_node->next;

        // create new node
        node* new_node = new node;
        new_node->data = data;

        // adjust new node
        new_node->next = prev_node->next;
        prev_node->next = new_node;

        return;
    }

    void display_linked_list(node* head){
        node* itr = head;
        cout<< "The items of linked list are: ";
        while(itr != NULL){
            cout<< itr->data<< " ";
            itr = itr->next;
        }
        cout<< endl;
    }

    node* remove_node(node* head, int data){
        if(head==NULL) return NULL;
        if(head->data == data){
            node* temp = head;
            head = head->next;
            delete temp;
        }
        // check the current node is not null
        if (head) head->next = remove_node(head->next, data);
        return head;
    }

    node* get_middle(node* slow_ptr, node* fast_ptr){
        if(fast_ptr == NULL || fast_ptr->next == NULL){
            return slow_ptr;
        }
        return get_middle(slow_ptr->next, fast_ptr->next->next);
    }

    void get_middle2(node* head){
        node* slow_ptr = head;
        node* fast_ptr = head;
        if(!head){
            while(fast_ptr != NULL && fast_ptr->next !=NULL){
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next->next;
            }
        }
        cout<< "Middle node2: ";
        (slow_ptr)? cout<< slow_ptr->data<<endl:cout<< " "<<endl;
        return;
    }

    node* reverse_list(node* head){
        node* prev = NULL;
        node* curr = head;
        while(curr){
            node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    node* reverse_list2(node* curr){
         if(curr == NULL) return NULL;
        if(curr->next == NULL) return curr;
        node* prev = reverse_list2(curr->next);

        //
        curr->next->next = curr;
        curr->next = NULL;

        return prev;
    }

    void swap_2_nodes(node* head, int x, int y){

        // if the 2 nodes are same
        // return unchanged

        if(x==y) return;
        // find node x
        node* ptrX = head;
        node* prevX = NULL;
        while(ptrX && ptrX->data != x){
            prevX = ptrX;
            ptrX = ptrX->next;
        }

        // find node y
        node* prevY = NULL;
        node* ptrY = head;
        while(ptrY && ptrY->data != y){
            prevY = ptrY;
            ptrY = ptrY->next;
        }

        // swap 2 nodes
        if(prevX){ // if node x is not head
            prevX->next = ptrY;
        }else{
            head = ptrY;
        }

        if(prevY){ // if node y is not head
            prevY->next = ptrX;
        }else{
            head = ptrX;
        }

        // swap
        node* temp = ptrX->next;
        ptrX->next = ptrY->next;
        ptrY->next = temp;
        return;
    }

public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        head = makeEmpty(head);
    }

    void push(int data){
        head = insert_node_in_front(head, data);
    }

    void insertInPos(int data){
        insert_node_in_position(head, data);
    }
    void append(int data){
        head = insert_node_in_end(head, data);
    }
    void delete_item(int data){
        head = remove_node(head, data);
    }

    void delete_list(){
        head = makeEmpty(head);
    }

    void getMiddleNode(){
        get_middle2(head);
        cout<< "Middle node: ";
        if(head==NULL) {cout<< " "<<endl;return;}
        if(head->next == NULL){cout<< head->data<< endl; return;}
        node* mid_node = get_middle(head->next, head->next->next);
        (mid_node->data)?cout<< mid_node->data<< endl:cout<< " "<< endl;
    }
    void printList(){
        display_linked_list(head);
    }
    void reverseList(){
        head = reverse_list2(head);
    }
    void swap_node(int x, int y){
        swap_2_nodes(head, x, y);
    }
};


int main()
{
    LinkedList l_list;
    // add node
    l_list.append(25);
    l_list.append(35);
    l_list.append(45);
    l_list.push(15);
    l_list.push(5);

    // display list
    l_list.printList();

    // get middle of the list
    cout<< endl<< "Middle node of the list "<< endl;
    l_list.getMiddleNode();

    // swap 2 nodes
    cout<< endl<< "After swaping node 25 & node 45 "<< endl;
    l_list.swap_node(25, 45);
    l_list.printList();

    cout<< endl<< "After deleting node 25 "<< endl;
    l_list.delete_item(25);

    l_list.printList();
    cout<< endl<< "Middle node of the list "<< endl;
    l_list.getMiddleNode();

    l_list.insertInPos(55);
    l_list.printList();

    // reverse link list
    cout<< endl<< "After reversing the list "<< endl;
    l_list.reverseList();
    l_list.printList();

    cout<< endl<< "After deleting the entire list: "<< endl;
    l_list.delete_list();
    l_list.printList();
    return 0;
}
