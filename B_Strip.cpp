#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n+5, INF);
    }

    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            tree[node]=val;
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid) update(node*2,l,mid,pos,val);
        else update(node*2+1,mid+1,r,pos,val);

        tree[node]=min(tree[node*2],tree[node*2+1]);
    }

    int query(int node,int l,int r,int ql,int qr){
        if(qr<l || ql>r) return INF;

        if(ql<=l && r<=qr) return tree[node];

        int mid=(l+r)/2;

        return min(query(node*2,l,mid,ql,qr),
                   query(node*2+1,mid+1,r,ql,qr));
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,l;
    long long s;

    cin>>n>>s>>l;

    vector<long long>a(n+1);

    for(int i=1;i<=n;i++) cin>>a[i];

    deque<int> mx,mn;

    vector<int> left(n+1);

    int start=1;

    for(int i=1;i<=n;i++){

        while(!mx.empty() && a[mx.back()]<=a[i]) mx.pop_back();
        while(!mn.empty() && a[mn.back()]>=a[i]) mn.pop_back();

        mx.push_back(i);
        mn.push_back(i);

        while(!mx.empty() && !mn.empty() &&
              a[mx.front()] - a[mn.front()] > s){

            if(mx.front()==start) mx.pop_front();
            if(mn.front()==start) mn.pop_front();

            start++;
        }

        left[i]=start;
    }

    vector<int> dp(n+1,INF);

    SegTree seg(n);

    dp[0]=0;
    seg.update(1,0,n,0,0);

    for(int i=1;i<=n;i++){

        int L = left[i]-1;
        int R = i-l;

        if(R>=L){

            int best = seg.query(1,0,n,L,R);

            if(best!=INF)
                dp[i]=best+1;
        }

        seg.update(1,0,n,i,dp[i]);
    }

    if(dp[n]==INF) cout<<-1<<"\n";
    else cout<<dp[n]<<"\n";

}