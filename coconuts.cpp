#include<bits/stdc++.h>
using namespace std;
#define int long long
bool pov(int k,int num,int ch){
    int ans = 1;
    for(int i=0;i<k;i++){
        ans*=num;
        if(ans>ch)
        return false;
    }
    if(ans <= ch)
    return true;
    else
    return false;
}
int func(int k,int num){
    int lo =1,hi = 1e9;
    while((hi-lo)>1){
        int mid = (hi+lo)/2;
        if(pov(k,mid,num)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    int a1=1,a2=1;
    for(int i=0;i<k;i++){
        a1*=lo;
        a2*=hi;
    }
    if(a1 == num)
    return lo;
    else if(a2 == num)
    return hi;
    else
    return -1;
}
signed main(){
    int t=1;
   // cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr (n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
            mp[1]+=1;
            continue;
            }
            for(int k = 1;k<=30;k++){
                mp[func(k,arr[i])]+=arr[i];                
            }
        }
        int ans = 0;
        for(auto val:mp){
            if(val.first != -1)
            ans = max(ans,val.second);
        }
        cout<<ans<<endl;
    }
    return 0;
}