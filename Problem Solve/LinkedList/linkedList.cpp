#include <iostream>
#include <stack>

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
        if(head){
            while(fast_ptr  && fast_ptr->next){
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

    bool has_loop(node* slow_pntr, node* fast_pntr){
        if(!slow_pntr || !fast_pntr || !fast_pntr->next) return false;
        if(slow_pntr == fast_pntr) return true;
        return has_loop(slow_pntr->next, fast_pntr->next->next);
    }

    bool check_palindrome(node* head){
        // stack<int> st;

        node* pntr = head;
        string str = "";
        //
        while(pntr){
           // st.push(pntr->data);
           str += (pntr->data+'0');
            pntr = pntr->next;
        }

        /*
        // reverse
        pntr = head;
        while(pntr){
            if(st.empty() || st.top() != pntr->data) return false;
            st.pop();
            pntr = pntr->next;
        }*/

        int len = str.size()-1;
        int mid = 0.5*(str.size()+1);
        for(int i=0; i<=mid; i++){
            if(str[i]!=str[len-i]) return false;
        }
        return true;
    }

    bool check_palindrome2(node* slow_pntr, node* fast_pntr, stack<int>& st){
        // if list is empty return true
        // else return false
        if(!slow_pntr) return st.empty();

        // if slow pointer points second half nodes
        if(!fast_pntr){
            // if list is not empty & list is not palindrome
            // return false
            // else pop a node from stack
            if(!st.empty() && slow_pntr->data != st.top()) return false;
            st.pop();
            return check_palindrome2(slow_pntr->next, fast_pntr, st);
        }else if(!fast_pntr->next) return check_palindrome2(slow_pntr->next, fast_pntr->next, st);   // for odd length. skip the middle node
        else{   //if slow pointer points first half nodes
            st.push(slow_pntr->data);
            return check_palindrome2(slow_pntr->next, fast_pntr->next->next, st);
        }
    }

    void create_loop(node* head, node* curr, bool flag){
        if(curr->next==NULL || curr->next==head){
            (flag)? curr->next = head:curr->next = NULL;
            return;

        }
        create_loop(head, curr->next, flag);
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
        node* mid_node = get_middle(head, head);
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

    void hasLoop(){
        cout<< "Has loop: ";
        if(!head) cout<< "False"<< endl;
        else if(head && head->next)(has_loop(head->next, head->next->next))? cout<< "True"<< endl:
            cout<< "False"<< endl;
        else cout<< "False"<< endl;
        return;
    }

    void createLoop(bool flag){
        if(head){
            create_loop(head, head, flag);
        }
        return;
    }

    void hasPalindrome(){
        stack<int> st;
        cout<< "Has palindrome: ";
        if(!head) cout<< "False"<< endl;
       // else if(head && !head->next) cout<< "True"<< endl;
        else {
                // 1st method: iterative
                (check_palindrome(head))?cout<< "True"<<endl:cout<< "False"<< endl;

                // while(!st.empty()) st.pop();
                // 2nd method: recursive
                (check_palindrome2(head, head, st))?cout<< "Has Palindrome2: True"<< endl:   // for even length list
                    (check_palindrome2(head, head->next, st))?cout<< "Has Palindrome2: True"<< endl:cout<< "Has Palindrome2: False"<<endl;  // for odd length list

        }
        return;
    }
};


int main()
{
    LinkedList l_list;
    l_list.hasLoop();
    // add node
    l_list.append(25);
    // l_list.hasLoop();

    l_list.append(35);
   // l_list.hasLoop();

    l_list.append(45);
    l_list.push(15);

    l_list.push(5);
    // display list
    l_list.printList();

    l_list.hasLoop();
    cout<< "After creating loop: "<< endl;
    l_list.createLoop(true);
    l_list.hasLoop();

    cout<< "After removing loop: "<< endl;
    l_list.createLoop(false);
    l_list.hasLoop();
    l_list.printList();

    l_list.hasPalindrome();

    // get middle of the list
    cout<< endl<< "Middle node of the list "<< endl;
    l_list.getMiddleNode();

    // swap 2 nodes
    cout<< endl<< "After swaping node 25 & node 45 "<< endl;
   // l_list.swap_node(25, 45);
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
