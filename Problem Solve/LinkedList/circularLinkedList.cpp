#include <iostream>

using namespace std;

class CircularLinkedList{
private:
    struct node{
        int data;
        node* next;
    };
    node* tail;

    node* insertInEmpty(node* last, int data){
        if(last) return last;
        // create new node
        node* new_node = new node;
        new_node->data = data;

        // assign it in last node & link to itself
        last = new_node;
        last->next = last;

        return last;
    }

    node* insertInFront(node* last, int data){
        if(!last) return insertInEmpty(last, data);

        // create node
        node* new_node = new node;
        new_node->data = data;

        // link to the head
        new_node->next = last->next;

        // assign it as new head
        last->next = new_node;

        return last;
    }

    node* insertInEnd(node* last, int data){
        if(!last) return insertInEmpty(last,data);

        // create node
        node* new_node = new node;
        new_node->data = data;

        // link it to the last & head
        new_node->next = last->next;
        last->next = new_node;

        // make it new last
        last = new_node;

        return last;
    }

    node* makeEmpty(node* last, node* curr){
        if(curr == last){
            delete curr;
            last = NULL;
            return last;
        }
        makeEmpty(last, curr->next);

        delete curr;
        return NULL;
    }

    node* remove_node(node*& last, node* curr, node* prev, int data){

        if(curr == last){

            // if delete node is last
            if(curr->data == data){
                // set previous node as last
                last = prev;

                // copy the selected node
                // link the previous node to the next node
                //delete the selected node
                node* temp = curr;
                curr = curr->next;
                prev->next= curr;
                delete temp;
            }
            return last;
        }
        if(curr->data == data){
            // copy the selected node
            // link the previous node to the next node
            //delete the selected node
            node* temp = curr;
            curr = curr->next;
            prev->next = curr;
            delete temp;
        }
        return remove_node(last, curr->next, curr, data);
    }


    void display(node* last, node* curr){
        if(curr==last){
            cout<< curr->data;
            return;
        }
        cout<< curr->data<< " ";
        display(last, curr->next);
        return;
    }
    bool checkLoop(node* last, node* slow_curr, node* fast_curr){
        if(slow_curr==fast_curr) return true;
        if(slow_curr==last) return false;

        return checkLoop(last, slow_curr->next, fast_curr->next);
    }

public:
    CircularLinkedList(){
        tail = NULL;
    }
    ~CircularLinkedList(){
        if(tail){
            deleteList();
        }
    }
    void deleteNode(int data){
        tail = remove_node(tail, tail->next, tail, data);
    }
    void deleteList(){
        tail = makeEmpty(tail, tail->next);
    }
    void pushInFront(int data){
        tail = insertInFront(tail, data);
    }
    void pushInEnd(int data){
        tail = insertInEnd(tail, data);
    }
    void displayList(){
        cout<< "The items of list: ";
        if(tail) {
             display(tail, tail->next);
        }
        cout<< endl;
    }

    void hasLoop(){
        cout<<"Has loop: ";
        if(!tail) cout<<"False"<<endl;
        else if(tail && tail->next) cout<< "True"<< endl;
        else (checkLoop(tail, tail->next, tail->next->next))?cout<< "True"<<endl:cout<< "False"<< endl;
        return;
    }
};
int main()
{
    CircularLinkedList l_list;
    l_list.hasLoop();
    l_list.pushInFront(15);
    l_list.hasLoop();
    l_list.pushInFront(5);
    l_list.hasLoop();
    l_list.pushInEnd(25);
    l_list.pushInEnd(35);
    l_list.pushInEnd(45);
    l_list.displayList();

    l_list.hasLoop();
    cout<< "After deleting node 45"<< endl;
    l_list.deleteNode(45);
    l_list.displayList();
    l_list.hasLoop();

    cout<< "After deleting entire list"<< endl;
    l_list.deleteList();
    l_list.displayList();

    return 0;
}

