#include<iostream>
#include<list>
#include<stack>
#include<climits>
bool visited[100005];
int topSorted[100005];
int d[100005];
int k = 0;
using namespace std;
void topSortUtil(int i, list< pair<int,int> > *adjList,stack<int> & Stack)
{
	visited[i] = true;
	list<int>:: iterator it;
	for(list< pair<int,int> >::iterator it = adjList[i].begin() ; it!=adjList[i].end() ; it++)
	{
		if(!visited[it->first])
		{
			topSortUtil(it->first,adjList,Stack);
		}
	}
	Stack.push(i);
}
void topSort(list< pair<int,int> > *adjList, int v)
{
	stack<int> st;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			topSortUtil(i,adjList,st);
		}
	}

	while(!st.empty())
	{

		topSorted[k++] =  st.top();
		st.pop();
	}
}
int main()
{
	int v,e,r;
	cin >> v >> e >> r;
	list< pair<int,int> > *adjList = new list< pair<int,int> >[v];
	while(e--)
	{
		int x,y,di;
		cin >> x >> y >> di;
		adjList[x].push_back(make_pair(y,di));
		adjList[y].push_back(make_pair(x,di));
	}
	topSort(adjList,v);
	for(int i=0;i<=v;i++)
		d[i] = INT_MAX;
	d[r] = 0;
	for(int i=0;i<v;i++)
	{
			for(list< pair<int,int> >::iterator it = adjList[i].begin() ; it!=adjList[i].end(); it++)
			{
				if(d[it->first] > d[i] + it->second && d[i] !=INT_MAX)
					d[it->first] = d[i] + it->second;
			}
		}
	}
	cout << endl;
	for(int i=0;i<v;i++)
	{
		if(d[i] !=INT_MAX)
			cout << d[i] << endl;
		else
			cout << "INF" <<endl;
	}
	return 0;
}
