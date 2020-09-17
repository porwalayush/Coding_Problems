#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
# define int long long
#define MAX 100008
#define INT_MI -10000000090

struct treeNode{
    int prefixSum;
    int suffixSum;
    int sum;
    int maxSum;
};

int arr[MAX+1];
treeNode tree[3*MAX+1];

void makeSegmentTree(int idx,int ss,int se){
if(ss==se){
    tree[idx]=((treeNode){arr[ss],arr[ss],arr[ss],arr[ss]});

    }

else{
    int mid=(ss+se)/2;
    makeSegmentTree(idx*2+1,ss,mid);
    makeSegmentTree(idx*2+2,mid+1,se);

    treeNode left = tree[idx*2+1];
    treeNode right = tree[idx*2+2];

    tree[idx].prefixSum = max(left.prefixSum , left.sum+right.prefixSum);
    tree[idx].suffixSum = max(right.suffixSum, left.suffixSum+right.sum);
    tree[idx].sum       = left.sum + right.sum;
    tree[idx].maxSum    = max(left.suffixSum+right.prefixSum,max(left.maxSum,right.maxSum));
    }
}


treeNode maxSumQuery(int idx,int ss,int se,int qs,int qe){

        if(ss>=qs&&se<=qe)
            {  return tree[idx];}
         if(qs>se||qe<ss)
        return ((treeNode){INT_MI,INT_MI,INT_MI,INT_MI});

        int mid = (ss+se)/2;

        treeNode left = maxSumQuery(2*idx+1,ss,mid,qs,qe);
        treeNode right = maxSumQuery(2*idx+2,mid+1,se,qs,qe);
        treeNode temp;

        temp.prefixSum = max(left.prefixSum,left.sum+right.prefixSum);
        temp.suffixSum = max(right.suffixSum,right.sum+left.suffixSum);
        temp.sum       = left.sum + right.sum;
        temp.maxSum    = max(left.suffixSum+right.prefixSum,max(left.maxSum,right.maxSum));

        return temp;
}

int32_t main(){

    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
int n,q,t,x,y,i;
scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

        makeSegmentTree(0,0,n-1);


        scanf("%lld",&q);
        while(q--){
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",maxSumQuery(0,0,n-1,x-1,y-1).maxSum);
        }

return 0;
}