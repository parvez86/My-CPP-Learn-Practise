int commonChild(string s1, string s2) {
    // dp_lcs
    vector<int> child(s2.size(), 0);
    for(int i=0; i<s1.size(); i++){
        vector<int> temp(s2.size(), 0);
        for(int j=0; j<s2.size(); j++){
            if(j==0 && s2[j]==s1[i]) temp[j]=1;
            else if(s2[j]==s1[i]) temp[j] = max(child[j-1]+1, child[j]);
            else if(j!=0) temp[j]=max(child[j], temp[j-1]);
        }
        // cout<< i<< ": ";
        for(int j=0; j<s2.size(); j++){
            child[j]=temp[j];
           // cout<< child[j]<< " ";
        }
        // cout<< endl;
    }
    return child[s2.size()-1];
}
