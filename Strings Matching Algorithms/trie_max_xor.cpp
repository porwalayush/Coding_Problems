#include<bits/stdc++.h>
using namespace std;
# define int long long
class node
{
public:
	node *left;
	node *right;
};

class trie
{
	node *root;
public:
	trie()
	{
		root= new node();
	}


	void insert(int n)
	{
		node *tmp =root;
		for(int i=31;i>=0;i--)
		{
			int bit=(n>>i)&1;
			if(bit==0)
			{
				if(tmp->left==NULL)
				{
					tmp->left=new node();
				}
				tmp=tmp->left;
			}
			else
			{
				if(tmp->right==NULL)
				{
					tmp->right=new node();
				}
				tmp=tmp->right;
			}
		}
	}

	int max_xor_helper(int val)
	{
		node *tmp =root;
		int cur_ans=0;
		for(int i=31;i>=0;i--)
		{
			int bit=(val>>i)&1;
			if(bit==1)
			{
				if(tmp->left!=NULL)
				{
					cur_ans+=(1<<i);
					tmp=tmp->left;
				}
				else
					tmp=tmp->right;
			}
			else
			{
				if(tmp->right!=NULL)
				{
					cur_ans+=(1<<i);
					tmp=tmp->right;
				}
				else
					tmp=tmp->left;
			}
		}
		return cur_ans;
	}
	int max_xor(int *arr,int n)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			insert(arr[i]);
			int cur= max_xor_helper(arr[i]);
			ans=max(ans,cur);
		}
		return ans;
	}
};
int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int a[]={25, 10, 2, 8, 5, 3};
  int n=sizeof(a)/sizeof(int);
  trie t;
  cout<<t.max_xor(a,n);
  return 0;
}