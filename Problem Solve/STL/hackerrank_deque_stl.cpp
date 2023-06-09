void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> d;
    d.push_back(0);
    d.push_back(0);
    for(int i=0; i<k; i++){
        if(arr[i]>=d.front()){
            d.pop_back();
            d.push_front(arr[i]);
        }else if(arr[i]>d.back()){
            d.pop_back();
            d.push_back(arr[i]);
        }
    }
    cout<< d.front()<<" ";
    for(int i=1; i<=n-k; i++){
        if(arr[i-1]==d.front()) {d.pop_front();}
        else if(arr[i-1]==d.back()) {
            d.pop_back();
        }
        int mx=arr[i+k-1]>=d.back()?arr[i+k-1]:0;

        if(d.size()==1 && mx==0){
            int cnt=0;
            for(int j=i; j<i+k; j++){
                if(arr[j]==d.back() && cnt==0){
                    cnt++;
                    continue;
                }
                if(arr[j]>mx) {
                    mx=arr[j];
                }
            }
        }
        if(mx>=d.front()){
            if(d.size()==2) d.pop_back();
            d.push_front(mx);
        }else if(mx>=d.back() || d.size()==1){
            if(d.size()==2) d.pop_back();
            d.push_back(mx);
        }
       cout<< d.front()<< " ";
    }
    cout<< endl;
}
