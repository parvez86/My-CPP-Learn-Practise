#include <iostream>
#include <string>


using namespace std;
bool IsSubStr(string text, string subtext, int indx)
{
    int len = subtext.size()-1;
    while(len>=0){
        if(text[indx+len] != subtext[len]) return false;
        len--;
    }
    return true;
}
// not modify original string
string delete_substr(string text, string subtext)
{
    string new_string = "";
    int len = text.size(), sub_len = subtext.size();
    int i=0;
    for( ; i<=len-sub_len; i++){
        if(IsSubStr(text, subtext, i)) {i+=sub_len;continue;}
        else new_string += text[i];
    }
    for(; i<len; i++) new_string += text[i];
    return new_string;
}

/*
// modify original string
void delete_substr2(string* text, string* subtext)
{
    string new_string = "";
    int len = sizeof(text)/sizeof(text[0]), sub_len = sizeof(subtext)/sizeof(subtext[0]);
    int i=0;
    for( ; i<=len-sub_len; i++){
        if(IsSubStr(*text, *subtext, i)) {cout<< "Hi "; i+=sub_len;continue;}
        else new_string += text[i];
    }
    for(; i<len; i++) new_string += text[i];
    text = &new_string;
}*/


// using built-in function
string delete_substr3(string text, string subtext)
{
    while(true){
        int indx = text.find(subtext);
        if(indx==string::npos) return text;
        text.erase(indx, subtext.size());
    }
    // return text;
}

int main()
{
    string text = "Infuse your life with action. Don't wait for it to happen."
    " Make it happen. Make your own future. Make your own hope. Make your own love."
    " And whatever your beliefs, honor your creator, not by passively waiting for"
    " grace to come down from upon high, but by doing what you can to make grace happen..."
    " yourself, right now, right down here on Earth. Don't wait for it to happen.";
    string text1 = "Don't wait for it to happen.";
    cout<<"Text:"<< endl<< text<< endl;
    cout<<"\nSub-text:"<< endl<< text1<< endl;
    cout<< "\nAfter removing subtext (normal): \n"<< delete_substr(text, text1)<< endl;
    cout<< "\nAfter removing subtext (built-in): \n"<< delete_substr3(text, text1)<< endl;
   // delete_substr2(&text, &text1);
    // cout<< text<< endl;
    return 0;
}
