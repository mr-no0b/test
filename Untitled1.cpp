#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pairCtr(ll *arr, ll n){
    ll preSum[n];
    ll sum{0};
    for(ll i=0; i<n; i++){
        if(arr[i]==1){
            sum++;
        }
        preSum[i]=sum;
    }
    ll ans{0};
    for(ll i=n-1; i>=0; i--){
        if(arr[i]==0){
            ans+=preSum[i];
        }
    }
    return ans;
}
int main(){
    //cout<<'d'-'a'+1;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++){
            ll inp;
            cin>>inp;
            arr[i]=inp;
        }
        ll ans=pairCtr(arr, n);
        //cout<<ans;
        ll step{0};
        //ll j{-1};
        ll ansArr[n];
        for(ll i=n-1; i>=0; i--){
            if(arr[i]==1 && step!=1){
                ansArr[i]=0;
                step++;
                //break;
            }
            else{
                ansArr[i]=arr[i];
            }
        }
        ans=max(ans, pairCtr(ansArr,n));
        step=0;
        for(ll i=0; i<n; i++){
                if(arr[i]==0 && step!=1){
                    ansArr[i]=1;
                    step++;
                    //break;
                }
                else{
                    ansArr[i]=arr[i];
                }
        }
        ans=max(ans, pairCtr(ansArr,n));
        cout<<ans<<endl;
    }
}
