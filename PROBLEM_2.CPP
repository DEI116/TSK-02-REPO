#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long mod=1000000007;
 
set<int> badaSet;
 
void getDivs() {
    int primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int i, j, n, p, np = 9, nd;
    int divs[1 << 9];
    nd = 1 << np;
    for (i = 1; i < nd; i++) {
        divs[i] = 1;
        for (j = 0; j < np; j++) {
            if (i & (1 << j))
                divs[i] *= primes[j];
        }
    }
    for(int i=1;i<nd;i++) {
        badaSet.insert(divs[i]);
    }       
}
 
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    getDivs();
    while(t--) {
        ll n, tmp, mx=INT_MIN;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            cin>>tmp;
            v.push_back(tmp);
            // cout<<tmp<< " =======> ";
            // for(auto it: tp) {
            //     cout<<it<<" ";
            // }
            cout<<endl;
        }
        ll ans = 0, count = 0;
        for(auto it: badaSet) {
            int pp = it;
            // cout<<pp<<" ";
            ll cc = 0;
            for(int i=0;i<v.size();i++) {
                if(v[i]%pp==0) {
                    cc++;
                }
            }
            if(cc>ans) {
                ans=cc;
                count=1;
            } else if (ans==cc) {
                count++;
            }
        }
        
 
        cout<<ans<<" "<<count<<endl;
 
    }
    return 0;
}