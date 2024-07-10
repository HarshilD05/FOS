// Sjf Implementation
// Pre Emptive

#include<iostream>
#include<vector>

using namespace std;

struct Process {
    int no;    // Id
    int AT;    // Arrival Time
    int BT;    // Burst Time
    int remT;  // Remaining Time
    int CT;    // Completion Time
    int TAT;   // Turn Around Time
    int WT;    // Wait Time
    
    Process (int n, int a, int b) : no(n), AT(a), BT(b), remT(b), CT(0), TAT(0), WT(0) {}
    
    Process (int n) : no(n), CT(0), TAT(0), WT(0) {
        cout<<"\n\n Please Enter Details for Process "<< n <<" ......";
        cout<<"\nEnter Arrival Time (0 if not specified) : ";
        cin>> AT;
        
        cout<<"\nEnter Burst Time : ";
        cin>>BT;

        remT = BT;
    }
};

bool over (vector<Process> p) {
    for (Process x : p) {
        if (x.remT) return false;
    }
    return true;
}

void addInExec (Process p,vector<Process> PS,vector<int> &exec) {
    cout<<"\nProcess "<< p.no <<" has arrived...";

    // Adding the first Process in list
    if (exec.size() == 0) {
        cout<<"\nAdding process to the Start";
        exec.push_back(p.no);
        return;
    }
    
    // Adding the Process according to the remaining Time
    bool added = false;
    for (int i = 0;i<exec.size();i++) {
        if (PS[ exec[i] ].remT > p.remT) {
            exec.insert( exec.begin()+i,p.no);
            added = true;
            cout<<"\nProcess Added at pos "<< i;
            break;
        }
    }
    
    if (!added) {
        exec.push_back(p.no);
        cout<<"\n Process Added at the end of Que";
    }
}

void pDetails (vector<Process> p) {
    // Sum of TAT and Waiting for AVG
    int sWT= 0;
    int sTAT = 0;
    
    cout<<"\n\nProcess Details------------";
    cout<<"\n P \tAT \tBT \tCT \tTAT \tWT";
    for (Process x : p) {
        cout<<"\n"<< x.no <<"\t"<< x.AT <<"\t"<< x.BT <<"\t"<< x.CT <<"\t"<< x.TAT <<"\t"<< x.WT ;
        
        sWT += x.WT;
        sTAT += x.TAT;
    }
    
    // Average Waiting and TAT
    cout<<"\n\nAverage Waiting Time : "<<(float) sWT/p.size();
    cout<<"\nAverage TAT : "<<(float) sTAT/p.size();
    
}

int main () {
    vector<Process> p;
    
    // Taking Inputs of Processes
    int n;
    cout<<"\nEnter Number of Processes : ";
    cin >> n;
    
    for (int i = 0;i<n;i++) {
        Process x(i);        ;
        
        p.push_back(x);
    }
    
    
    // Executing the Processes
    vector<int> exeQ;
    int tStamp = 0;
    
    cout<<"\nExecution Started...";
    while (!over(p) ) {

        cout<<"\n\nTStamp : "<<tStamp;
        // Adding any newly Arrived Process in Que
        for (Process x : p) {
            if (tStamp == x.AT) {
                addInExec(x,p,exeQ);
            }
        }
        
        
        tStamp++;

        // Executing the first process in the ExecQ
        p[ exeQ[0] ].remT --;
        cout<<"\nExecuting Process "<< exeQ[0] ;
        cout<<"\nRemT : "<< p[ exeQ[0] ].remT;
        
        // Removing the Process from Que if Process Completed
        if (p[ exeQ[0] ].remT == 0) {
            cout<<"\nProcess Completed...";
            int i = exeQ[0];    // Storing the Process Number
            exeQ.erase(exeQ.begin() );
            // Calculating the TAT and Waiting Times
            p[i].CT = tStamp;
            p[i].TAT = p[i].CT - p[i].AT;
            p[i].WT = p[i].TAT - p[i].BT;
        }
        
    }
    cout<<"\nExecution Finished....";
    
    // Printing Process Details
    pDetails(p);
    
    return 0;
}
