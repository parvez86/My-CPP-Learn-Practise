#include <iostream>
using namespace std;


using namespace std;

class DoublyLinkedList{
private:
    struct node{

        int data;
        node* prev;
        node* next;
    };
    node* head;

    node* make_empty(node* head){
        if(head == NULL) return NULL;
        head->next = make_empty(head->next);

        delete head;
        return NULL;
    }

    node* get_tail(node* curr){
        if(!curr || !curr->next) return curr;

        return get_tail(curr->next);
    }

    node* insert_node_in_front(node* head, int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->prev = NULL;

        if(head == NULL){
            new_node->next = NULL;
        }else{
            new_node->next = head;
        }
        head->prev = new_node;
        head = new_node;
        return head;
    }

    node* insert_node_in_pos(node* head, node* curr, node* prev, int data, bool flag){
        // if curent node is end node & new node is already inserted
        // return NULL
        if(!curr && flag) return NULL;

        // current node is grater or current node is end-node & new node not inserted yet
        // create new node & insert
        if(!curr || curr->data > data && !flag){
            node* new_node = new node;
            new_node->data = data;

            // list is empty
            if(!head || !curr){
                (prev)? new_node->prev = prev: new_node->prev = NULL;
                new_node->next = NULL;
            }else{
                new_node->prev = prev;
                new_node->next = curr;
            }
            // whether new node is inserted or not
            flag = true;

            // assign new node as current node
            if(curr) curr->prev = new_node;

            curr = new_node;
            if (prev) prev->next = curr;
        }
        curr->next = insert_node_in_pos(head, curr->next, curr, data, flag);
        return curr;
    }

    node* insert_node_in_end(node* head, node* prev, int data){
        if(head==NULL ){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;

            (prev)? new_node->prev = prev:new_node->prev = NULL;
            return new_node;
        }

        head->next = insert_node_in_end(head->next, head, data);
        return head;
    }

    node* delete_item(node* head, int data){
        if(!head) return NULL;
        if(head->data == data){
            node* temp = head;
            if (head->next) {
                head->next->prev = head->prev;
            }
            else if (head->prev){
                head->prev->next = NULL;
            }
            delete temp;

            (head->next)? head = head->next:head = NULL;
        }
        if (head) head->next = delete_item(head->next, data);

        return head;
    }

    node* reverse_list(node* head){
        node* tail = get_tail(head);
        (tail->prev)?cout<< tail->prev->data<< "\t": cout<<"\t";
        if (tail) cout<< tail->data<< "\t";
        (tail->next)? cout<< tail->next->data<< endl: cout<<endl;

        if(!tail || !tail->prev) return tail;

        node* curr = tail->prev;
        //
        tail->prev  = NULL;
        tail->next = curr;

        node* prev = curr->prev;

        while(curr){
            node* temp = curr->prev;

            // swap node
            if(prev) prev->next = curr;
            curr->prev = prev;

            prev = curr;
            curr = temp;
        }
        tail->next->prev = tail;
        prev->next = curr;
        return tail;
    }

    node* reverse_list2(node* head){
        if(!head) return NULL;
     //   if(!head->next) return head;

        node* temp = reverse_list2(head->next);

        head->next->next = head;
        (temp)? head->prev->prev = temp:head->prev->prev= NULL;

        head->next = NULL;


        return temp;
    }

    void display(node* head){
        if(head == NULL) return;
        cout<< head->data<< " ";
        display(head->next);
        return;
    }
public:
    DoublyLinkedList(){
        head = NULL;
    }

    ~DoublyLinkedList(){
        if(head) head = make_empty(head);
    }

    void pushFront(int data){
        head = insert_node_in_front(head, data);
    }

    void pushEnd(int data){
        head = insert_node_in_end(head, NULL, data);
    }

    void pushInPos(int data){
        head = insert_node_in_pos(head, head, NULL, data, false);
    }

    void deleteNode(int data){
        head = delete_item(head, data);
    }

    void deleteList(){
        if(head) head = make_empty(head);
    }

    void displayList(){
        cout<< "The items of list are: "<< endl;
        display(head);
        cout<< endl;
    }

    void reverseList(){
        head = reverse_list(head);
    }

    void displayListReverse(){
        node* tail =  get_tail(head);

        cout<< "The items of list are in reverse order: "<< endl;
        while(tail){

            // (tail->prev)?cout<< tail->prev->data<< "\t": cout<<"\t";
            cout<< tail->data<< "\t";
            // (tail->next)? cout<< tail->next->data<< endl: cout<<endl;
            tail = tail->prev;
        }
        cout<< endl;
    }

};


int main()
{
    DoublyLinkedList l_list;
    l_list.pushEnd(25);
    l_list.pushFront(15);
    l_list.pushFront(5);
    l_list.pushEnd(35);
    l_list.pushInPos(0);
    l_list.pushInPos(10);
    l_list.pushInPos(40);


    l_list.displayList();
    l_list.displayListReverse();

    cout<< "After deleting mid node (10): "<< endl;
    l_list.deleteNode(10);
    l_list.displayList();
    l_list.displayListReverse();

    cout<< "After deleting first node (0): "<< endl;
    l_list.deleteNode(0);
    l_list.displayList();
    l_list.displayListReverse();

    cout<< "After deleting last node (40): "<< endl;
    l_list.deleteNode(40);
    l_list.displayList();

    l_list.displayListReverse();

    cout<< "After reversing list: "<< endl;
    l_list.reverseList();
    l_list.displayList();
    l_list.displayListReverse();

    cout<< "After deleting list: "<< endl;
    l_list.deleteList();
    l_list.displayList();


    return 0;
}
