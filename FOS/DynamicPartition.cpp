// Implememnting Dynamic Partitioning of Memory

#include<iostream>
#include<vector>

using namespace std;

struct Process {
    int req_mem;
    bool alloc;
    
    Process () : req_mem(0), alloc(false) {}
};

int main () {
    int mem_size;
    
    // Reading Memory Values
    cout<<"Enter Total Memory size in BYTES : ";
    cin>> mem_size;
    
    // Reading Process Details
    int n;
    Process p[20];  // storing required memeory by Process
    int avail_mem = mem_size;    // available memory
    
    cout<<"\n\nEnter Number of Processses : ";
    cin>>n;
    
    for (int i = 0;i<n;i++) {
        // Checking if memory Available 
        if (avail_mem < 1) {
            cout<<"\n Memory Full....";
            cout<<"\n No more Processes can be Allocated...";
            for (int j = i;j<n;j++) {
                p[i].req_mem = 0;
                p[i].alloc = false;
            }
            break;
        }
        
        cout<<"\nProcess "<< i ;
        cout<<"\nEnter required memeory : ";
        cin>> p[i].req_mem;
        
        // If memory available to allocate process
        if (avail_mem > p[i].req_mem ) {
            avail_mem -= p[i].req_mem;  // updating available memory
            p[i].alloc = true;
            cout<<"\nMemory Allocated...";
        }
        else {
            cout<<"\nInsufficient memory...";
            p[i].alloc = false;
        }
    }
    
    // Printing Details
    float mem_util = (float)(mem_size-avail_mem)/mem_size;
    cout<<"\n\n Process  MEM  Alloc";
    for (int i = 0;i<n;i++) {
        cout<<"\nP"<< i <<"\t\t"<< p[i].req_mem <<"\t\t";
        if (p[i].alloc) cout<<"YES";
        else cout<<"NO";
    }
    
    cout<<"\nMemory Utilistaion : "<< mem_util;
    
    
    return 0;
}
