long substrCount(int n, string s) {
    vector<int> counts(n, 0);
    int sum=0;

    // count palindromic
    // for similar character
    for(int i=0; i<n; ){
        int count=1;
        int j=i+1;
        for(; j<n && s[j]==s[i]; j++){
            count++;
        }
        counts[i] = count;
        sum += (count*(count+1))*0.5;
        i=j;
        // cout<< sum<< " ";
    }
    // cout<< endl;

    // for similar except mid
    for(int i=1; i<n-1; i++){
        if(s[i]==s[i-1]) counts[i]=counts[i-1];
        else if(s[i-1]==s[i+1]){
            sum+=min(counts[i-1], counts[i+1]);
            // cout<< sum<< " ";
        }
    }
    // cout<< endl;
    return sum;
}
