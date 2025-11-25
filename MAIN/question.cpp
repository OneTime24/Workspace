#include<bits/stdc++.h>

using namespace std;

int main(){

   freopen("input.txt","r",stdin);

    int t;
    cin>>t;

  int count=0;
    while (t--)
    {
     int arr[3];
        int chk = 0;
    for (int i = 0; i < 3; i++)
    {
        cin>>arr[i];

        if(arr[i]==1){
            chk++;
        }
    }

    if(chk>=2){
        count++;
    }
    
    }


    cout<<count;
    


   




}
