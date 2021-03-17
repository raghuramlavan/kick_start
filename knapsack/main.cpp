#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int beu[50][30];
    int cal[50][1500];
    int t;                 //no of test cases
    int P;                 //no of plates required
    int N;       //no stake
    int K;       //plates per stake
    cin >>t;
    for (int i=0; i<t;i++)
    {
        int temp;
        cin>>N>>K>>P;
        for(int j=0;j<N;j++)
            for(int k=0;k<K;k++)
        {
            if(k>0){
            cin>>temp;
            beu[j][k]=beu[j][k-1]+temp;

            }else{
                cin>>temp;
            beu[j][k]=temp;
            }
            cout<<beu[j][k]<<" ";
        }
     /*   for(int k=0;k < K*N; k++){
        if(k<K) cal[0][k]=beu[0][k];
        else cal[0][k]=cal[0][K-1];
        }
*/




         for(int j=0;j<N;j++)
            for(int k=0;k<K*N;k++)
        {
            cal[j][k]=0;
            for(int x=0;x<max(k,K);x++)
            {
                cal[j][k]=max(cal[j][k],(cal[j-1][k-x]+beu[j][x]));
            }
        }

        cout<<"Case #"<<i+1<<":"<<cal[N-1][P-1]<<"\t";

        cout<<"\n";

    }
}

