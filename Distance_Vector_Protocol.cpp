#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Network = {
    {0, 1, 100000, 1, 100000, 100000},
    {1, 0, 2, 1, 100000, 100000},
    {100000, 2, 0, 1, 1, 1},
    {1, 1, 1, 0, 2, 15},
    {100000, 100000, 1, 2, 0, 1},
    {100000, 100000, 1, 15, 1, 0}
};

map<int, vector<int>> R0, R1, R2, R3, R4, R5;

map<int, vector<int>> swap_forward(int i)
{
    if(i==0) return R0;
    if(i==1) return R1;
    if(i==2) return R2;
    if(i==3) return R3;
    if(i==4) return R4;
    if(i==5) return R5;
}


void swap_back(int i, map<int, vector<int>> temp)
{
    if(i==0) R0 = temp;
    if(i==1) R1 = temp;
    if(i==2) R2 = temp;
    if(i==3) R3 = temp;
    if(i==4) R4 = temp;
    if(i==5) R5 = temp; 
}

void initial_states()
{
    for(int i=0; i<Network.size(); i++)
    {
        map<int, vector<int>> temp;

        for(int j=0; j<Network.size(); j++)
        {
            temp[j] = {Network[i][j], j};
        }

        swap_back(i, temp);
    
    }
}

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

void display()
{

    //cout<<"\n\nDVP: ";

    for(int i=0; i<6; i++)
    {
        cout<<"\n\nRouter "<<i<<": ";
        cout<<"\nRouter\t"<<"Dist\t"<<"Next";
        
        map<int, vector<int>> temp;
        temp = swap_forward(i);

        for(int j=0; j<6; j++)
        {
            cout<<"\n"<<j<<"\t"<<temp[j][0]<<"\t"<<temp[j][1];
        }
    }


}


void check_neighbours()
{   
    for(int t=0; t<6; t++)
    {
        for(int i=0; i<6; i++)
        {
            for(int j=0; j<6; j++)
            {
                map<int, vector<int>> temp1;
                temp1 = swap_forward(i);

                if(Network[i][j]!=100000 && i!=j)
                {
                    map<int, vector<int>> temp2;
                    temp2 = swap_forward(j);
                    

                    for(int k=0; k<6; k++)
                    {
                        if(temp1[k][0]>temp2[k][0]+Network[i][j])
                        {
                            temp1[k][0] = temp2[k][0]+Network[i][j];
                            temp1[k][1] = j;
                        }
                    }
                }

                swap_back(i, temp1);
            }
        }
    }
}



int main()
{   
    display_network();
    initial_states();
    
    cout<<"\n\n\n===============Initial Routing Tables=============== ";
    display();

    check_neighbours();

    cout<<"\n\n\n===============Final Routing Tables=============== ";
    display();
}