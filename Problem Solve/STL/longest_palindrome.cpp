#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int max_len=0, max_indx=0, count_len;
        if(len==1) return s;
        for(int i=0; i<len-(max_len-1)/2; i++){
        //    count_len = getPalindrome(s, i);
            count_len = max(getPalindrome(s, i, i), getPalindrome(s, i, i+1));
            if(count_len > max_len){
                max_len = count_len;
                max_indx = i;
            }
        }
        int left = max_indx-(max_len-2)*.5;
        return s.substr(left, max_len);
    }

    int getPalindrome(string s, int left, int right){
        int max_len = s.size();
        while(left>=0 && right<max_len){
            if(s[left]!=s[right]) break;
            left--; right++;
        }
        return (right-left-1);
    }
    /*
    int getPalindrome(string s, int center_indx){
        int count_len = 1, i=1;
        int max_len = s.size();
        while(i<=center_indx){
            if(s[center_indx-i]==s[center_indx+i] && center_indx+i<max_len){
                count_len+=2;
                i++;
                continue;
            }
            break;
        }
        if(s[center_indx]==s[center_indx+1]){
            int l = center_indx, r=center_indx+1;
            while(l>=0 && r<max_len){
                if(s[l]!=s[r]) break;
                l--; r++;
            }
            count_len = max(count_len, r-l-1);
        }

        return count_len;
    }*/
};


int main()
{
    Solution ob;
    string s="dababcdcdc";
    cout<< ob.longestPalindrome(s)<< endl;
    return 0;
}

