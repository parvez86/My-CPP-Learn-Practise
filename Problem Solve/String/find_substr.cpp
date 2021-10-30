#include <iostream>

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

int FindSubStr(string text, string subtext)
{
    int len = text.size(), sub_len = subtext.size();
    for(int i=0; i<=len-sub_len;i++){
        if(IsSubStr(text, subtext, i)) return i;
    }
    return -1;
}

int FindSubStr2(string text, string subtext)
{
    int indx = text.find(subtext);
    return (indx==text.size())?-1:indx;
}

int main()
{
    string text = "Infuse your life with action. Don't wait for it to happen."
    " Make it happen. Make your own future. Make your own hope. Make your own love."
    " And whatever your beliefs, honor your creator, not by passively waiting for"
    " grace to come down from upon high, but by doing what you can to make grace happen..."
    " yourself, right now, right down here on Earth.";
    string text1 = "Don't wait for it to happen.";
    int indx = FindSubStr(text, text1);
    (indx != -1)? cout<< "Substring is found at index "<< indx<< endl:
        cout<< "Substring is not found"<< endl;
    if(indx != -1) cout<< "The substring is: "<< text.substr(indx, text1.size())<< endl;
    indx = FindSubStr2(text, text1);
    (indx != string::npos)? cout<< "Substring is found at index "<< indx<< endl:
        cout<< "Substring is not found"<< endl;
    if(indx != -1) cout<< "The substring is: "<< text.substr(indx, text1.size())<< endl;
    return 0;
}
