#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>


using namespace std;

static int t = 0;
static int kount = 0;

class node
{
public:
  int dtime;
  int ftime;
  int value;
  node(int d,int f,int v)
  {
    this->value = v;
    this->dtime = d;
    this->ftime = f;
  }
};

struct compare
{
  bool operator()(node *a, node *b)
  {
    return a->ftime > b->ftime;
  }
};

void PrintGraph(vector< vector<node*> > &graph)
{
  for(int i=0;i<graph.size();i++)
  {
    cout<<"["<<i<<"]->";
    vector<node*> temp = graph[i];
    for(int j=0;j<temp.size();j++)
    { 
      cout<<" ["<<temp[j]->value<<"|"<<temp[j]->dtime<<"|"<<temp[j]->ftime<<"] ";
    }
    cout<<endl;
  }
  cout<<"================================\n"; 
}

bool path(int x, int y, vector< vector<int> > &graph, vector<int> &p)
{
    // cout<<"x, y:"<<x<<y<<endl;
    int n = graph.size();
    vector<int> visited(n,0);
    queue<int> q;
    visited[x] = 1;
    q.push(x);
    while(!q.empty())
    {
      x = q.front();
      q.pop();
      vector<int> temp  = graph[x];
      for(int i=0;i<graph[x].size();i++)
      {
        if(y==temp[i])
          return true;
        else
        {
          if(visited[temp[i]]==0)
          {
            p.push_back(temp[i]);
            visited[temp[i]]==1;
            q.push(temp[i]);
          }
        }
      }
    }
    return false;
}

void DFS_Visit(vector< vector<node*> > &graph, vector<int> &visited, node* newNode, vector<node*> &s)
{
  visited[newNode->value] = 1;
  t+=1;
  newNode->dtime = t;
  vector<node*> temp = graph[newNode->value];
  for (vector<node*>::iterator itr = temp.begin()+1; itr < temp.end(); ++itr) {
    if(visited[(*itr)->value] == 0)
    {
      DFS_Visit(graph,visited,(*itr),s);
    }  
  }
  t+=1;
  newNode->ftime = t;
  s.push_back(newNode);
  // cout<<" ["<<newNode->value<<"|"<<newNode->dtime<<"|"<<newNode->ftime<<"]\n";
}

void DFS(vector< vector<node*> > &graph, vector<node*> &s)
{
  vector<int> visited(2*graph.size(), 0);
  for(int i=0; i<graph.size();i++)
  {
    vector<node*> temp = graph[i];
    node *newNode = temp[0];
    if(visited[i] == 0)
    {
      DFS_Visit(graph,visited,newNode,s);
    }
  }
}

void ComplementGraph(vector< vector<node*> > &graph, vector< vector<node*> > &Rgraph)
{
  // for(auto it1 = graph.begin(); it1 < graph.end(); it1++){
  //   int temp = (*it1)[0]->value; // 
  //   // create a new node with value {temp}
  //   for(auto it2 = (*it1).begin()+1; it2 < (*it1).end(); it2++){
  //     cout << (*it2)->value <<  " ";
  //     // insert inside graph[(*it2)->value]
  //   }
  //   cout << endl;
  
  for (int i = 0; i < graph.size(); ++i)
  {
    vector<node*> temp  = graph[i];
    //Rgraph[i].push_back(temp[0]);
    for(auto itr = temp.begin()+1; itr < temp.end(); itr++)
    {
      Rgraph[(*itr)->value].push_back(temp[0]);
    }
  }
}

void graphSCC(vector<bool> &visited, vector<node*> &s, vector < vector<node*> > &Rgraph, 
  vector< vector<int> > &SCC, int temp)
{
  // cout<<"In fucntion\n";
  visited[temp] = 1;
  cout<<"["<<temp<<"]->"; 
  SCC[kount].push_back(temp);
  for (vector<node*> :: iterator itr = Rgraph[temp].begin(); itr < Rgraph[temp].end(); itr++)
  {
    if(visited[(*itr)->value] == 0)
      graphSCC(visited,s,Rgraph,SCC,(*itr)->value);
  }
}

// int main()
// {
//   /* code */
//   int n,m;
//   int x,y;
//   cin>>n;
//   cin>>m;
//   vector < vector<int> > graph(2*n);

//   for(int i=0;i<m;i++)
//   {
//     cin>>x>>y;
//     if(x%2==0 && y%2==0) //ee x || y => ~x||y ~y||x
//     {
//       graph[x+1].push_back(y);
//       graph[y+1].push_back(x);
//     }
//     else if(x%2==1 && y%2==0)//oe ~x||y => x||y ~y||~x
//     {
//       graph[x-1].push_back(y);
//       graph[y+1].push_back(x);
//     }
//     else if(x%2==0 && y%2==1)//x||~y => ~x||~y y||x
//     {
//       graph[x+1].push_back(y);
//       graph[y-1].push_back(x);
//     }
//     else if(x%2==1 && y%2==1)//~x||~y => x||~y y||~x
//     {
//       graph[x-1].push_back(y);
//       graph[y-1].push_back(x);
//     }
//   }

//   for(int i=0;i<2*n;i++)
//   {
//     cout<<"["<<i<<"]->";
//     vector<int> temp = graph[i];
//     for(int j=0;j<temp.size();j++)
//     { 
//       cout<<"["<<temp[j]<<"]";
//     }
//     cout<<endl;
//   }

//   //check if there exists a path between x --> ~x and ~x-->x
//   // cout<<"x, y:"<<x<<y<<endl;
//   vector<int> p;
//   for(int i=0;i<2*n;i+=2)
//   {
//     bool t1 = path(i,i+1,graph,p);
//     bool t2 = path(i+1,i,graph,p);
//     if(t1 && t2)
//     {
//       cout<<"Unsatisfiable";
//       return 0;
//     }
//   }
  
//   cout<<"Satisfiable"<<endl;
//   // for(int i=0;i<p.size();i++)
//   //   cout<<p[i]<<"->";
//   // cout<<endl;

//   return 0;
// }

int main()
{
  /* code */
  int n,m;
  int x,y;

  //number of literals
  cin>>n;
  //number of clauses
  cin>>m;

  vector < vector<node*> > graph(2*n); //holds graph
  vector < vector<node*> > Rgraph(2*n); // holds complement of graph

  vector<node*> s;
  vector<bool> visited(2*n,0);

  vector< vector<int> > SCC; //holds strongly connected component
  
  //put each node into graph
  for (int i = 0; i < graph.size(); ++i)
  {
    node * temp = new node(0,0,i);
    graph[i].push_back(temp);
  }



  //create adjacency list 
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    node * temp1  = new node(0,0,x);
    node * temp2  = new node(0,0,y);
    if(x%2==0 && y%2==0) //ee x || y => ~x||y ~y||x
    {
      graph[x+1].push_back(temp2);
      graph[y+1].push_back(temp1);
    }
    else if(x%2==1 && y%2==0)//oe ~x||y => x||y ~y||~x
    {
      graph[x-1].push_back(temp2);
      graph[y+1].push_back(temp1);
    }
    else if(x%2==0 && y%2==1)//x||~y => ~x||~y y||x
    {
      graph[x+1].push_back(temp2);
      graph[y-1].push_back(temp1);
    }
    else if(x%2==1 && y%2==1)//~x||~y => x||~y y||~x
    {
      graph[x-1].push_back(temp2);
      graph[y-1].push_back(temp1);
    }
  }

  cout<<"Graph of above formula is\n";
  PrintGraph(graph);

  DFS(graph,s);
  ComplementGraph(graph, Rgraph);

  cout<<"Graph with DFS applied\n";
  PrintGraph(graph);

  cout<<"Complement of a Graph\n";
  PrintGraph(Rgraph);

  sort(s.begin(), s.end(), compare());

  for (int i = 0; i < s.size(); ++i)
  {
  cout<<"\n["<<s[i]->value<<"|"<<s[i]->dtime<<"|"<<s[i]->ftime<<"]\n";
  }

  for (int i = 0; i < s.size(); ++i)
  {
    int temp  = s[i]->value;
    if(visited[temp] == 0)
    {
      // cout<<"function called\n";
      SCC.push_back(vector <int> ());
      graphSCC(visited, s, Rgraph, SCC, temp);
      kount++;
      // cout<<"kount:"<<kount<<"\n";
    }
  }

  // cout<<"graphSCC Done\n";
  for (int i = 0; i < SCC.size(); ++i)
  {
    cout<<"\nSCC["<<i<<"]->";
    for (vector<int> ::iterator itr = SCC[i].begin(); itr<SCC[i].end();itr++)
    {
      cout<<"["<<*itr<<"]";
    }
  }

  bool IsSatisfiable = true;
  for (int i = 0; i < SCC.size(); ++i)
  {
    // cout<<"\nSCC["<<i<<"]->";
    for (int j = 0;j<SCC[i].size();j++)
    {
        for(int k = j+1; k<SCC[i].size();k++)      
        {
        if(SCC[i][j]%2 == 1 && SCC[i][k] == SCC[i][j]-1)
        {
         cout <<"\n1st:" <<SCC[i][j] <<"\t"<< SCC[i][k]<<"\n";
          IsSatisfiable = false;
        }
        else if(SCC[i][j]%2 == 0 && SCC[i][j] == SCC[i][k]+1)  
        {
          cout <<"\n2nd:" <<SCC[i][j] <<"\t"<< SCC[i][k]<<"\n";
          IsSatisfiable = false;
        }
        }
    }
  }

  if(IsSatisfiable)
  {    
  cout<<"\nSatisfiable\n";
  cout << "\nSatisfying assignnments\n" << endl;
  for (int i = 0; i < SCC.size(); ++i)
  {
   for (vector<int> ::iterator itr = SCC[i].begin(); itr<SCC[i].end();itr++)
    {
        if(*itr%2 == 1)
          cout<<"x"<<*itr/2<<"=F\t";
        else
          cout<<"x"<<*itr/2<<"=T\t";
    } 
    cout<<"\n";
  }
}
else
  cout<<"\nNot Satisfiable\n";
  //check if there exists a path between x --> ~x and ~x-->x
  // cout<<"x, y:"<<x<<y<<endl;
  // vector<int> p;
  // for(int i=0;i<2*n;i+=2)
  // {
  //   bool t1 = path(i,i+1,graph,p);
  //   bool t2 = path(i+1,i,graph,p);
  //   if(t1 && t2)
  //   {
  //     cout<<"Unsatisfiable";
  //     return 0;
  //   }
  // }
  // cout<<"Satisfiable"<<endl;
  // for(int i=0;i<p.size();i++)
  //   cout<<p[i]<<"->";
  // cout<<endl;

  return 0;
}