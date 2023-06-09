#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void mirror_clock(int times[])
{
    cout<< times[0]<< times[1]<< endl;
    times[0] = (12-times[0]);
    if(times[0]<12) times[0]+=12;
    if(times[1]>0) {
            times[0]-=1;
     }
    times[1] = 60-times[1];
    cout<< times[0]<< ":"<< times[1]<< endl;
}

int get_time(string time)
{
    int len = time.size();
    int result = 0;
    for(int i=0; i<len; i++){
        result = result*10+(time[i]-'0');
    }
    return result;
}

void process_time(string time)
{
    int times[2]={0}, indx=0;
    // int times[3]={0}, indx=2;
    string s;
    int len = time.size();
    for(int i=0; i<len; i++){
        if(time[i]==':'){
         //   cout<< s<< endl;
            times[indx]= get_time(s);
            indx++;
            s="";
            continue;
        }
        s.push_back(time[i]);
    }
    times[indx] = get_time(s);
    //cout<< times[0]<< " "<<times[1]<<endl;
    mirror_clock(times);
}
int main()
{
    string time;
    cin>> time;
    process_time(time);
    return 0;
}
