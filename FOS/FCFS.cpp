// FCFS SImulation

#include<iostream>
#include<vector>

using namespace std;

struct Process {
    int no;    // Id
    int AT;    // Arrival time
    int BT;    // Burst Time
    int CT;    // Completion time
    int TAT;   // Turn Around Time
    int WT;    // Wait Time
    
    Process (int n) : no(n) {
        cout<<"\n\n Please Enter Details for Process "<< n <<" ......";
        cout<<"\nEnter Arrival Time (0 if not specified) : ";
        cin>> AT;
        
        cout<<"\nEnter Burst Time : ";
        cin>>BT;
    }
    
    Process (int n, int a, int b) : no(n), AT(a), BT(b) {}
    
};

void pDetails (vector<Process> p) {
    int sTAT = 0;
    int sWT = 0;
    
    cout<<"\n\nDisplaying Process Details.....";
    cout<<"\n P \tAT \tBT \tCT \tTAT \tWT";
    for (Process x : p) {
        cout<<"\n "<< x.no <<"\t"<< x.AT <<"\t"<< x.BT <<"\t"<< x.CT <<"\t"<< x.TAT <<"\t"<< x.WT;
        sTAT += x.TAT;
        sWT += x.WT;
    }
    
    // Displaying Average Waiting and TAT
    cout<<"\n\n Average Turn Around Time : "<< (float)sTAT/p.size() ;
    cout<<"\n Average Waiting Time : "<< (float)sWT/p.size() ;
}

int main () {
    cout<<"--------------FCFS Simulation------------------\n";
    // taking Process Data Input
    int n;
    cout<<"\nEnter Number of Processes : ";
    cin>> n;
    
    // Creating a list of Process to be executed
    vector<Process> p;
    
    for (int i = 0;i<n;i++) {
        Process x(i);
        p.push_back(x);
    }
    
    // Executing the Processes
    for (int i = 0;i<n;i++) {
        // Execution of the First Process
        if (i == 0) {
            p[i].CT = p[i].BT;
        }
        // Execution of Remainig Processes
        else {
            p[i].CT = p[i-1].CT + p[i].BT;
        }
        
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }
    
    // Displaying the Result
    pDetails(p);
    
    return 0;
}
