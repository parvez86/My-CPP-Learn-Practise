#include <iostream>
#include <vector>

using namespace std;

class BrowserHistory {
    struct page{
        string val;
        page* next;
        page* prev;

        page(string x) : val(x), prev(nullptr),next(nullptr) {}
        page(string x, page *prev) : val(x), prev(prev), next(nullptr) {}
        page(string x, page *prev, page* next) : val(x), prev(prev), next(next) {}
    }*head;

    vector<string> webpages;
    int curr_page;

    page* get_prev_node(page* curr, int steps){
        if(!curr || !curr->prev || steps==0) return curr;
        return get_prev_node(curr->prev, steps-1);
    }

    page* get_next_node(page* curr, int steps){
        if(!curr || !curr->next || steps==0) return curr;
        return get_next_node(curr->next, steps-1);
    }

    void make_empty(page*& head){
        if(head == NULL) return;
        make_empty(head->next);

        delete head;
        return;
    }

public:
    BrowserHistory(string homepage) {
        head = new page(homepage);
    }

    BrowserHistory2(string homepage) {
        // webpages.clear();
        webpages.push_back(homepage);
        curr_page = 0;
    }

    void visit(string url) {

        page* new_page = new page(url, head);

        // clear next nodes

        make_empty(head->next);
        head->next = new_page;
        head = head->next;
    }

    void visit2(string url) {
        webpages.erase(webpages.begin()+curr_page+1, webpages.end());
        webpages.push_back(url);
        curr_page++;
    }

    string back(int steps) {
        cout<< "The back nodes: ";
        display_prev(head->prev);
        cout<< "End"<< endl;
        head = get_prev_node(head, steps);
        return head->val;
    }

    string back2(int steps) {
        (steps<curr_page)? curr_page-=steps:curr_page=0;
        return webpages[curr_page];
    }

    string forward(int steps) {
        // if(head->next) cout<< "\t"<< head->next->val<< endl;
        cout<< "The forward nodes: ";
        display_next(head->next);
        cout<< "End"<< endl;
        head = get_next_node(head, steps);
        return head->val;
    }

    string forward2(int steps) {
        (curr_page+steps < webpages.size()-1)?curr_page+=steps:curr_page=webpages.size()-1;
        return webpages[curr_page];
    }

    void display_next(page* curr){
        if(!curr) {cout<<endl;return;}
        cout<< curr->val<< " ";
        display_next(curr->next);
    }

    void display_prev(page* curr){
        if(!curr) {cout<<endl;return;}
        cout<< curr->val<< " ";
        display_next(curr->prev);
    }
};

int main()
{
    BrowserHistory history ("zav.com");
    history.visit("kni.com");       // You are in "leetcode.com". Visit "google.com"
    cout<< history.back(7)<< endl;                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    cout<< history.back(7)<< endl;                   // You are in "facebook.com", move back to "google.com" return "google.com"
    cout<< history.forward(5)<< endl;                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    cout<< history.forward(1)<< endl;                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    history.visit("pwrrbnw.com");     // You are in "facebook.com". Visit "linkedin.com"
    history.visit("mosohif.com");     // You are in "facebook.com". Visit "linkedin.com"
    cout<< history.forward(2)<< endl;                // You are in "linkedin.com", you cannot move forward any steps.
    cout<< history.back(9)<< endl;                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    return 0;
}


/*

Input: ["BrowserHistory","visit","back","back","forward","forward","visit","visit","back"]
[["zav.com"],["kni.com"],[7],[7],[5],[1],["pwrrbnw.com"],["mosohif.com"],[9]]
Output: [null,null,"zav.com","zav.com","zav.com","kni.com",null,null,"zav.com"]
Expected: [null,null,"zav.com","zav.com","kni.com","kni.com",null,null,"zav.com"]



BrowserHistory history ("Leetcode.com");
    history.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    history.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    history.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    cout<< history.back(1)<< endl;                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    cout<< history.back(1)<< endl;                   // You are in "facebook.com", move back to "google.com" return "google.com"
    cout<< history.forward(1)<< endl;                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    history.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    cout<< history.forward(2)<< endl;                // You are in "linkedin.com", you cannot move forward any steps.
    cout<< history.back(2)<< endl;                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    cout<< history.back(7)<< endl;
*/
