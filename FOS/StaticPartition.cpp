// Implememnting Fixed Partitioning of Memory

#include<iostream>
#include<vector>

using namespace std;



int main () {
    int mem_size, block_size;
    int n_blocks;
    int ex_frag;
    
    // Reading Memory Values
    cout<<"Enter Total Memory size in BYTES : ";
    cin>> mem_size;
    cout<<"\nEnter Size of each Block in BYTES : ";
    cin>> block_size;
    
    // Calculating number of Blocks and External fragmentation
    n_blocks = mem_size/block_size;
    ex_frag = mem_size % block_size;
    
    cout<<"\nNUmber of Blocks : "<< n_blocks;
    cout<<"\nExternal fragmentation : "<< ex_frag;
    
    // Reading Process Details
    int n;
    int p[20];  // storing required memeory by Process
    int iFrag[20];  // Storing Internal fragmentation of each Process
    int avail_blocks = n_blocks;    // available Blocks
    int TotalIFrag = 0; // Total internal Fragmentation
    
    cout<<"\n\nEnter Number of Processses : ";
    cin>>n;
    
    for (int i = 0;i<n;i++) {
        // Check if Memory Blocks Available
        if (avail_blocks == 0) {
            cout<<"\n\n All memory Blocks Occupied...";
            cout<<"\nCannot assign memory to remaining processes...";

            // Setting values for remaining processes
            for (int j = i;j<n;j++) {
                p[j] = 0;
                iFrag[j] = -1;
            }
            break;
        }
        
        cout<<"\nProcess "<< i ;
        cout<<"\nEnter required memeory : ";
        cin>> p[i];
        
        // Allocating Momory to Process
        if (p[i] > block_size) {
            cout<<"\nCould Not Assign Block since Process size larger than Block Size.....";
            iFrag[i] = -1;
        }
        // calculating Internal fragmentation if Memory Allocated
        else {
            iFrag[i] = block_size - p[i];
            TotalIFrag += iFrag[i];
            avail_blocks --;
            cout<<"\nMemory Allocated...";
            cout<<"\nInternal fragmentation : "<< iFrag[i];
        }
    }
    
    // Printing Details
    float mem_util = (float)(mem_size - (TotalIFrag + ex_frag) )/mem_size;
    cout<<"\n\n Process  MEM  ALLOC  IFrag ";
    for (int i = 0;i<n;i++) {
        cout<<"\nP"<< i <<"\t\t"<< p[i] <<"\t\t";
        
        if (iFrag[i] == -1) cout<<"NO";
        else cout<<"Yes";
        
        cout<<"\t\t"<< iFrag[i];
    }
    
    cout<<"\nTotal Internal fragmentation : "<< TotalIFrag;
    cout<<"\nMemory Utilistaion : "<< mem_util;
    
    
    return 0;
}
