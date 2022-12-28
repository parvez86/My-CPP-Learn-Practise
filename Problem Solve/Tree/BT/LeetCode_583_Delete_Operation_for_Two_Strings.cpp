class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2=word2.size();
        vector<int> dp_lcs(len1, 0);

        for(int i=0; i<len2; i++){
            vector<int> temp(len1, 0);
            for(int j=0; j<len1; j++){
                if(j==0){
                    temp[j] = (word1[j]==word2[i])?1:dp_lcs[j];
                } else{
                    temp[j] = (word1[j]==word2[i])?dp_lcs[j-1]+1:max(dp_lcs[j], temp[j-1]);
                }
            }
            dp_lcs = temp;
        }
        return len1+len2-dp_lcs[len1-1]-dp_lcs[len1-1];
    }
};

