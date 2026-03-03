#include<bits/stdc++.h>
using namespace std;

int main(){

       
        int t;
        cin>>t;

        while(t--){






            int n;
            cin>>n;
                                 vector<int>bit(30,0);

            vector<int>arr(n);
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<30;j++){
                    if(arr[i]&(1<<j)){
                        bit[j]++;
                    }
                }
            }

            int g = 0;
        for(int i = 0; i < 30; i++){
    g = __gcd(g, bit[i]);
}

       for(int i = 1; i <= n; i++){
    if(g % i == 0){
        cout<<i<<" ";
    }





        }





cout<<endl;
}
}