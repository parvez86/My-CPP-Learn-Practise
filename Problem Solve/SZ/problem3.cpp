#include <iostream>

using namespace std;

int day[2], hr[2], mint[2];
int total_times_in_mint=0,total_cost;
int cost[] = {1, 2, 3 ,4};
int tks[] = {360, 720, 1080, 1440};
int times[] = {6, 12, 18, 24};

// convert string (time) to integer
int get_time(string time)
{
    int len = time.size();
    int result = 0;
    for(int i=0; i<len; i++){
        result = result*10+(time[i]-'0');
    }
    return result;
}

void get_bill(int hr, int mnt)
{
    int cnt=0, hrs = total_times_in_mint;
    // set flag for each period
    (hr<=6)?cnt=0:(hr<=12)?cnt=1:(hr<=18)?cnt=2:cnt=3;

    // if start time is 6:01(similar for 12 or 18 or 24th hr) then the time period should be the next
    // but the period should be same for rest of hrs
    if(mnt>0 && (hr==6 || hr==12 || hr==18|| hr==24)) cnt++;

    // 1st calculate the 1st period of start time
    // it might not be same for all time
    // suppose: start time: 00::02:40 or 00::03:40 or 00::00:00
    int temp_time = (times[cnt]-hr)*60-mnt;

    // 1st period
    if(temp_time>0){
        // store the bill
        total_cost+=temp_time*cost[cnt];
        // subtract the consumed time
        hrs-=temp_time;
    }

    // move the next period
    cnt++;

    // calculate the bill for rest of hrs
    while(hrs>0){
        // if remaining hrs is greater than ^hrs of 360 minutes we can directly subtract the whole cost stored in the tks array
        // otherwise calculate the bill for specific remaining hrs
        (hrs>=360)?total_cost+=tks[cnt]:total_cost+=(hrs*cost[cnt]);
        hrs-=360;
        // if no remaining hr is left, then stop
        if (hrs<0) return;

        // for 4 specific periods
        cnt=(cnt+1)%4;
    }
    return;
}

void get_consumed_time()
{
    // let's guess
    // start time-> 00::01:20
    // end time -> 01::02:10
    // to calculates(difference) consumed minutes carry is needed
    int carry=0;

    // calculates minitues
    int total_mint= mint[1]-mint[0];
    // if difference is negative than add carry value
    if(total_mint<0) {total_mint+=60;carry=1;}

    // if carry is 1 than add it the start hr's
    if(carry>0){hr[0]+=1;carry=0;}

    // similar for hr & day
    int total_hr = hr[1]-hr[0];
    if(total_hr<0){total_hr+=24;carry=1;}
    if(carry>0){day[0]+=1;carry=0;}

    int total_day = day[1]-day[0];

    // store the total consumed time in minutes
    total_times_in_mint = total_day*24*60+total_hr*60+total_mint;
}


void process_time(string time, int ser)
{
    // cnt= 0 for day, 1 for hr & 2 for minutes
    int cnt=0;
    string s="";
    int len=time.size();
    for(int i=0; i<len; i++){
        if(time[i]==':'){
            if(time[i+1]==':') i++;
            if(cnt==0){
                // process day
                day[ser] = get_time(s);
            }
            else if(cnt==1){
                // process hr
                hr[ser] = get_time(s);
            }
            s="";
            cnt++;
        }
        else s.push_back(time[i]);
    }

    // process minutes
    mint[ser] = get_time(s);
}

void print_bill(string time1, string time2)
{
    // process start time
    process_time(time1, 0);
    // process end time
    process_time(time2, 1);

    // calculate total consumed call time
    get_consumed_time();

    //
    if(total_times_in_mint<0) {cout<< "Input is invalid"<< endl;return;}

    // calculate total bill & print it
    get_bill(hr[0], mint[0]);
    cout<< "Total consumed minutes = "<<total_times_in_mint<< endl;
    cout<< "total bill = "<< total_cost<<" tk"<< endl;
    return;
}

int main()
{
    string time1,time2;
    cin>> time1>> time2;
    print_bill(time1, time2);
    return 0;
}
/*
00::01:10
01::02:20
*/
