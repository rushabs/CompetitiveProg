#include<iostream>
using namespace std;
int n,arr[100][100],cache[100][100],ans,visited[100][100],opt[1000];
int solve(int i,int j)
{
	int t,t1,t2;
	if( i == n )
		return 0;
	if(visited[i][j] == 1)
		return cache[i][j];
	t1 = solve(i+1,j);
	t2 = solve(i+1,j+1);
	t = max(t1,t2) + arr[i][j];
	visited[i][j] = 1;
	cache[i][j] = t;
	return t;
	
	
}
int main(void)
{
	int k;
	cin>>k;
	for(int p = 0 ; p < k ; p++)
	{
		cin>>n;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j <= i ; j++)
			{
				cin>>arr[i][j];
				visited[i][j] = 0;
			}
		}
		opt[p] = solve(0,0);
	}
	for(int i = 0 ; i < k ; i++)
	{
		cout<<opt[i]<<endl;
	}
}
