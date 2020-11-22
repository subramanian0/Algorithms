#include<iostream>
#include<list>
#include<stack>
bool visited[100005];
using namespace std;
void topSortUtil(int i, list<int> *adjList,stack<int> & Stack)
{
	visited[i] = true;
	list<int>:: iterator it;
	for(list<int>::iterator it = adjList[i].begin() ; it!=adjList[i].end() ; it++)
	{
		if(!visited[*it])
		{
			topSortUtil(*it,adjList,Stack);
		}
	}
	Stack.push(i);
}
void topSort(list<int>* adjList, int v)
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
		cout << st.top() << endl;
		st.pop();
	}
}
int main()
{
	int v,e;
	cin >> v >> e;
	list<int> *adjList = new list<int>[v];
	while(e--)
	{
		int x,y;
		cin >> x >> y;
		adjList[x].push_back(y);
	}
	topSort(adjList,v);
	return 0;
}
