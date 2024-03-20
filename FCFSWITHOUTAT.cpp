#include <stdio.h>
#include <iostream>

using namespace std;

float minimum(float arr[],int n){
    float low = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] < low){
            low = arr[i];
        }
    }
    return low;
}

double avg(float arr[],int n){
    double avg =0;
    for(int i=0 ; i<n;i++){
        avg += arr[i];
    }
    return (avg/n);
}

void input(float  arr[] , int n) {
    cout << "Enter the Elements:"<<endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

void copy(float a[],float b[],int n){

        for(int i=0;i<n;i++){
            b[i] = a[i];
        }
}
int main(){
    cout<<"Enter the number of processes: ";
    int num_pro;
    cin >> num_pro;
    float pro[num_pro];
    cout<<"Enter the Process Id's: "<<endl;
    input(pro,num_pro);
    float BT[num_pro];
    float AT[num_pro] ={0};
    cout<<"Enter the BT in order of the processes: "<<endl;
    input(BT,num_pro);
    // cout<<"Enter the AT in order of the processes: "<<endl;
    // input(AT,num_pro);
    float CT[num_pro];
    float ST[num_pro];
    float TAT[num_pro];
    float WT[num_pro];
    float Temp_BT[num_pro];
    copy(BT,Temp_BT,num_pro);
    float RT[num_pro];
    float curr_time = minimum(AT,num_pro);
    int n=0; int i=0;
   
   // For completion time and start time for all process
   
    while(n < num_pro){
        if(AT[i] <= curr_time && Temp_BT[i] != -1){
            ST[i]=curr_time;
            curr_time += BT[i];
            CT[i] = curr_time;
            Temp_BT[i]=-1;
            n++;
        }
        i = (i+1)%num_pro;
    }


// For Turn around time, Response time and  waiting time

    for(int i =0;i<num_pro;i++){
        TAT[i] = CT[i];
        WT[i] = TAT[i] - BT[i];
        RT[i] = ST[i];
    }

//Displaying the  results

    cout << "Process \tBT \tAT \tCT \tTAT \tWT \tST \tRT" <<endl;
    for(int i=0;i<num_pro;i++){
            cout << "   " << pro[i] << "   \t " << "\t"<< BT[i] << "\t" << AT[i] << "\t" << CT[i] 
                 << "\t" << TAT[i] << "\t"<< WT[i] << "\t" << ST[i] << "\t" << RT[i] <<endl;
    }
    cout <<endl <<"Average TAT: " << avg(TAT,num_pro) << endl;
    cout << "Average  WT: " << avg(WT,num_pro) << endl;
    cout << "Average  RT: " << avg(RT,num_pro) << endl;

}