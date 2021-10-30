#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    pair<long int, long int> vec[100002];
    priority_queue<long int> pq;
    int t, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        for(int j=0; j<n; j++){
            scanf("%ld %ld", &vec[j].first, &vec[j].second);
        }
        if(n==1) {printf("%ld %ld\n", vec[0].first, vec[0].second); continue;}
        sort(vec, vec+n);
        for(int i=0; i<n-1; ){
            if (vec[i].first== vec[i+1].first){
                // print according to order of second element
                pq.push(vec[i].second);
                int j=i+1;
                while(j<n){
                    if(vec[i].first !=vec[j].first) break;
                    pq.push(vec[j].second);
                    j++;
                }
                while(!pq.empty()){
                    printf("%ld %ld\n", vec[i].first, pq.top());
                    pq.pop();
                }
                i+=(j-i);
                continue;
            }
            printf("%ld %ld\n", vec[i].first, vec[i].second);
            i++;
        }
        if(vec[n-2].first != vec[n-1].first) printf("%ld %ld\n", vec[n-1].first, vec[n-1].second);
    }
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            