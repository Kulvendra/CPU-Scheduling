#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
struct process {
            int arrivalTime,burstTime,priority,startTime,endTime,index;
        };

bool test(struct process p1, struct process p2){
    return p1.arrivalTime < p2.arrivalTime;
}
bool test2(struct process p1, struct process p2){
    return p1.index < p2.index;
}
int main(){

    int totalProcess,i,j=1,temp=0,process_count,process_data,data[50][50],time=0;

    ifstream inputFile;
    inputFile.open("input.dat");

    inputFile >> process_count;

    totalProcess= process_count;

    process p[totalProcess];

    for(i=0;i<totalProcess;i++){
        inputFile >> p[i].arrivalTime;
        inputFile >> p[i].burstTime;
        inputFile >> p[i].priority;
        p[i].index=i;
        }

    
    sort(p,p+totalProcess,test);


    p[0].startTime=p[0].arrivalTime;
    p[0].endTime=p[0].burstTime+p[0].startTime;

    for (i=1;i<totalProcess;i++){

        p[i].startTime=max(p[i].arrivalTime,p[i-1].endTime);
        p[i].endTime=p[i].startTime+p[i].burstTime;
        
    }

   sort(p,p+totalProcess,test2);
    float turnaround_Avg=0,waiting_Avg=0;
    for(i=0;i<totalProcess;i++){
        turnaround_Avg=turnaround_Avg+(p[i].endTime-p[i].arrivalTime);
        waiting_Avg=waiting_Avg+(p[i].endTime-p[i].arrivalTime)-p[i].burstTime;

   cout<<"P"<<i+1<< ":> Turnaround Time:"<<(p[i].endTime-p[i].arrivalTime)<<"\tWaiting Time and Response Time:"<<(p[i].endTime-p[i].arrivalTime)-p[i].burstTime<<endl;   
    }
    cout<<"Average Turnaround Time:"<<turnaround_Avg/totalProcess<<"\tAverage Wating and Response Time:"<<waiting_Avg/totalProcess<<endl;
        

}