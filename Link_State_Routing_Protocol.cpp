#include<bits/stdc++.h>
using namespace std;

vector<int> final_dist;
vector<vector<int>> Network = {
    {0, 1, 100000, 1, 100000, 100000},
    {1, 0, 2, 1, 100000, 100000},
    {100000, 2, 0, 1, 1, 1},
    {1, 1, 1, 0, 2, 15},
    {100000, 100000, 1, 2, 0, 1},
    {100000, 100000, 1, 15, 1, 0}
};

void display_network()
{
    cout<<"\n===============Adjacency Matrix of given Network==============="<<endl;
    for(int i=0; i<6; i++)
    {   
        cout<<"\n";
        for(int j=0; j<6; j++)
        {
            cout<<Network[i][j]<<"\t";
        }
    }

    cout<<"\n\n";
}



void SSSP(int source)
{
    set<int> S;
    S.insert(source);

    final_dist = Network[source];

    for(int k=0; k<6; k++)
    {       
        int min_val = 100000;
        int min_index = 100000; 

        auto endVar = S.end();
        for(auto it=S.begin(); it!=endVar; it++)
        {
            int temp = *it;
        
            for(int i=0; i<6; i++)
            {   
                set<int>::iterator it = S.find(i);
                if (it != S.end())
                {
                    continue;
                }

                if(temp!=i && Network[temp][i]+Network[source][temp]<min_val )
                {
                    min_val = Network[temp][i] + Network[source][temp];
                    min_index = i;
                }
   
            }
        }

        /*
        cout<<"\n\nMin Val:"<<min_val;
        cout<<"\nMin Index:"<<min_index;
        cout<<"\nSet Size: "<<S.size();
        */

        if(min_val!=100000)
        {
            S.insert(min_index);
            final_dist[min_index] = min_val; 
        }

    }

    
    cout<<"\nDistances to all Nodes from Source "<<source<<": ";   
    for(int i=0; i<6; i++)
    {   
        cout<<final_dist[i]<<", ";
    }
    

}


int main()
{
    display_network();

    cout<<"\n\n==================Link State Routing Protocol===================\n";
    SSSP(0);
    SSSP(1);
    SSSP(2);
    SSSP(3);
    SSSP(4);
    SSSP(5);
    cout<<"\n\n";

}