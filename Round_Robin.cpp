#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct process {
        int arrivalTime,burstTime,priority,startTime,endTime,index;
        bool popped,inserted,started;
    };

bool test(struct process p1, struct process p2){
    return p1.arrivalTime < p2.arrivalTime;
}

bool test2(struct process p1, struct process p2){
    return p1.burstTime > p2.burstTime;
}

bool test3(struct process p1, struct process p2){
    return p1.index < p2.index;
}
void pushtoqueue(process orig[], process queue[], int min){

}

int main(){

    int totalProcess,i,j=1,temp=1,time=1,process_count,process_data,data[50][50],quantum;
    

    ifstream inputFile;
    inputFile.open("input.dat");

    inputFile >> process_count;

    totalProcess= process_count;

    vector<process> CPU,queue1,queue2;

    process p[totalProcess];

    for(i=0;i<totalProcess;i++){
        inputFile >> p[i].arrivalTime;
        inputFile >> p[i].burstTime;
        inputFile >> p[i].priority;
        p[i].index=i;
        p[i].endTime=0;
        p[i].started=false;
        }
    sort(p,p+totalProcess,test);   
    inputFile >> quantum;

    // cout << "Size:*******************"<<queue2.size();
    
    while(temp<=1 || !queue1.empty()){
        
        
       
        for (i=0;i<totalProcess;i++){

            if(p[i].arrivalTime<=time && p[i].popped==false && p[i].inserted==false){
                queue1.push_back(p[i]);
                p[i].inserted=true;
            }
        }

        // sort(queue1.begin(),queue1.end(),test2);

        
        for(auto j: queue1){
            cout<<"Before List"<<j.index<<" ---"<<endl;
        }
        
        

        // time=time +queue1[queue1.size()-1].burstTime;
        // queue1[queue1.size()-1].popped=true;
        // queue2.push_back(queue1.back());
        // queue1.pop_back();



        if(!queue1.empty()){

        queue1.back().burstTime=max((queue1.back().burstTime)-quantum,0);

        if(!queue1.back().started){
            queue1.back().startTime=time;
            queue1.back().started=true;
        }

        if(queue1.back().burstTime==0){
            queue1[queue1.size()-1].popped=true;
            for(j=0;j<totalProcess;j++){
                if(queue1.back().index==p[j].index){
                    break;
                }
            }
            queue1.back().burstTime=p[j].burstTime;
            queue1[queue1.size()-1].endTime=time+1;

            queue2.push_back(queue1.back());
            queue1.pop_back();

            temp++;
        

        }else{
            queue1.insert(queue1.begin(),queue1.back());
            queue1.pop_back();
        }

        }
      

        for(auto j: queue1){
            cout<<"After List"<<j.index<<" ---"<<endl;
        }
        cout<<"**"<<time<<endl;    

      

        
 
        time=time+quantum;

        cout<<"------------------------------------------------------"<<endl;

        
        

    }
    sort(queue2.begin(),queue2.end(),test3);


    // for(i=0;i<totalProcess;i++){
    //     cout<<"End Time:"<<queue2[i].endTime<<endl;
    // }

       float turnaround_Avg=0,waiting_Avg=0,response_Avg=0;
    for(i=0;i<totalProcess;i++){
        turnaround_Avg=turnaround_Avg+(queue2[i].endTime-queue2[i].arrivalTime);
        waiting_Avg=waiting_Avg+(queue2[i].endTime-queue2[i].arrivalTime)-queue2[i].burstTime;
        response_Avg=response_Avg+queue2[i].startTime-queue2[i].arrivalTime;

   cout<<"P"<<i+1<< ":> Turnaround Time:"<<(queue2[i].endTime-queue2[i].arrivalTime)<<"\tWaiting Time:"<<(queue2[i].endTime-queue2[i].arrivalTime)-queue2[i].burstTime<<" Response Time:"<<queue2[i].startTime-queue2[i].arrivalTime<<endl;   
    }
    cout<<"Average Turnaround Time:"<<turnaround_Avg/totalProcess<<"\tAverage Wating:"<<waiting_Avg/totalProcess<<" Response Avg:"<<response_Avg/totalProcess<<endl;
        






}