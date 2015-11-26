#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=101000;
int a[N],mi[N],ma[N];
int q[N],id[N];
int main(){
    int n,q1;
    scanf("%d%d",&n,&q1);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    while(q1--){
        int l,r;long long ans=0,sum=0;
        scanf("%d%d",&l,&r);
        l--,r--;
        int c=0;
        for(int i=l+1;i<=r;i++){
            int t=abs(a[i]-a[i-1]);
            while(c>=1&&q[c-1]<=t){
                c--;    
                int lr=id[c]-1,ll=c==0?l:id[c-1];
                sum-=1ll*(lr-ll+1)*q[c];
            }
            q[c++]=t;
            id[c-1]=i;
            int lr=id[c-1]-1,ll=c==1?l:id[c-2];
            sum+=1ll*(lr-ll+1)*q[c-1];
            ans+=sum;
        }
        printf("%I64d\n",ans);
    }
}
