#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class room  
{
public: 
int x1;
int y1;
int x2;
int y2;
bool visited;
  room(int w, int x, int y,int z)
  {
    this->x1 = w;
    this->y1 = x;
    this->x2 = y;
    this->y2 = z;
    this->visited = 0;
  }
};

class node
{
public:
int value;
string s;
bool IsChild;
bool IsVisited;
node(int x, string y, bool z)
  {
    this->value = x;
    this->s = y;
    this->IsChild = z;
    this->IsVisited = 0;
  }
};

struct compare
{
  bool operator()(node *a, node *b)
  {
    string s1 = a->s;
    string s2 = b->s;    
    return s1.size()< s2.size();
  }
};

// void checkOverlap(vector<room*> &test1, vector< vector<room*> > &building)
// {
//   int n = test1.size();
//   //vector< vector<room*> > building(n);

//   for(int i=0;i<n;i++)
//   {
//     test1[0]->visited = 1 ;
//     room *one = test1[i];
//     for(int j=0;j<n;j++)
//     {
//       if(i!=j &&  test1[j]->visited == 0)
//       {
//         room *two = test1[j];
//       if(one->y2 == two->y1)
//       {
//         if(one->x1 <= two->x1 && one->x2 >= two->x1)
//         {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//         else if(one->x1 <= two->x2 && one->x2 >= two->x1)
//           {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//       }
//       else if(one->y1 == two->y2)
//       {
//         if(one->x1 <= two->x1 && one->x2 >= two->x1)
//           {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//         else if(one->x1 <= two->x2 && one->x2 >= two->x2)
//            {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//       }
//       else if(one->x1 == two->x2)
//       {
//         if(one->y1 <= two->y1 && one->y2 >= two->y1)
//           {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//         else if(one->y1 <= two->y2 && one->y2 >= two->y2)
//            {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//       }
//       else if(one->x2 == two->x1)
//       {
//         if(one->y1 <= two->y2 && one->y2 >= two->y2)
//            {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//         else if(one->y1 <= two->y1 && one->y2 >= two->y1)            
//            {
//           two->visited = 1;
//           building[i].push_back(two);
//         }
//       }
//       }
      
//     }
//   } 
// }

void listInitialize(vector< vector<int> > &building, vector<node*> &list)
{
  for (int i = 0; i < list.size(); ++i)
      {
        bool IsChild = 0;
        if(i!=0)
        {
          if(building[i].size()>1)
            IsChild = 0;
          else 
            IsChild = 1;
        }
        node* temp  = new node(i,"",IsChild);
        list[i] = temp;
      } 
}

void checkOverlap(vector<room*> &test1, vector< vector<int> > &building)
{
  int n = test1.size();
  //vector< vector<room*> > building(n);
  for(int i=0;i<n;i++)
  {
    // test1[0]->visited = 1 ;
    room *one = test1[i];
    for(int j=0;j<n;j++)
    {
      // if(i!=j &&  test1[j]->visited == 0)
      // {
      room *two = test1[j];
      if(one->y2 == two->y1)
      {
        if(one->x1 <= two->x1 && one->x2 >= two->x1)
        {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->x1 <= two->x2 && one->x2 >= two->x1)
          {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->x1 > two->x1 && one->x2 < two->x2)
          {
          two->visited = 1;
          building[i].push_back(j);
        }
      }
      else if(one->y1 == two->y2)
      {
        if(one->x1 <= two->x1 && one->x2 >= two->x1)
          {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->x1 <= two->x2 && one->x2 >= two->x2)
           {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->x1 > two->x1 && one->x2 < two->x2)
        {
          two->visited = 1;
          building[i].push_back(j);
        }
      }
      else if(one->x1 == two->x2)
      {
        if(one->y1 <= two->y1 && one->y2 >= two->y1)
          {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->y1 <= two->y2 && one->y2 >= two->y2)
           {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->y1 > two->y1 && one->y2 < two->y2)
           {
          two->visited = 1;
          building[i].push_back(j);
        }
      }
      else if(one->x2 == two->x1)
      {
        if(one->y1 <= two->y2 && one->y2 >= two->y2)
           {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->y1 <= two->y1 && one->y2 >= two->y1)            
           {
          two->visited = 1;
          building[i].push_back(j);
        }
        else if(one->y1 > two->y1 && one->y2 < two->y2)
        {
          two->visited = 1;
          building[i].push_back(j);
        }
      }
      }   
    }
  // }
}

void getSequence(vector< vector<int> > &building , vector<node*> &g, node* root)
  {
    root->IsVisited =1;
    // cout<<"getSequence["<<root->value<<"]-->\n";

    if(root->IsChild == 1)
    {
      // cout<<"Child\n";
      root->s = "10";
    }
    else
    {
      for(int i=0; i<building[root->value].size();i++)
      {
        node* temp = g[building[root->value][i]];
        if((temp->s).empty()  && temp->IsVisited == 0)
        {
          getSequence(building,g,temp);
        }
      }
    }
    if(root->IsChild == 0)
    {

    vector<int> x = building[root->value];
    vector<node*> y;
    // cout<<root->value<<x.size()<<endl;
    for (int j = 0; j < x.size(); ++j)
    {
      // cout<<x[j];
      node* t = g[x[j]];
      if((t->s).empty());
      else
      {
        //cout<<"here";
        y.push_back(t);
      }
    }
    sort(y.begin(), y.end(), compare());
    root->s = "1";
    for(vector<node*> :: iterator itr = y.begin();itr<y.end();itr++)
        root->s += (*itr)->s;
    root->s += "0";
  }
  // cout<<"["<<root->value<<"|"<<root->s<<"]\n";
  }

bool  IsCycle(int vertex, vector<bool> &visited, vector<int> &parent, vector< vector<int> > &building)
{
  visited[vertex] = 1;
  queue<int> q ;
  q.push(vertex);
  while(q.size() != 0)
  {
    vertex = q.front();
    q.pop();
    for (int i = building[vertex].size()-1; i > -1; --i)
    {
      int child = building[vertex][i]; 
      if(visited[child] == 0)
      {
        visited[child] = 1; 
        parent[child]  = vertex;
        q.push(child);
      }
      else if(visited[child] == 1 && parent[vertex] != child)
      {
        return true;
      }
    }
  }
    return false;
}

int main()
{
int n,x1,y1,x2,y2;
cin>>n;

vector< vector<int> > building1(n);
vector< vector<int> > building2(n);

vector<node*> list1(n);
vector<node*> list2(n);

vector<bool> visited1(n,0);
vector<bool> visited2(n,0);

vector<int> parent1(n,-1);
vector<int> parent2(n,-1);

vector <room*> test1;
vector <room*> test2;

    for(int i=0; i<n; i++)
    {
      cin>>x1>>y1>>x2>>y2;
      room *temp = new room(x1,y1,x2,y2);
      //test[i] = temp;
      test1.push_back(temp);
    }

    for(int i=0; i<n; i++)
    {
      cin>>x1>>y1>>x2>>y2;
      room *temp = new room(x1,y1,x2,y2);
      //test[i] = temp;
      test2.push_back(temp);
    }

    checkOverlap(test1, building1);



   //  for(int i=0;i<n;i++)
   //  {
   //    if(i==0)//root
   //      parent1[i] = -2;
   //    vector<int> adj1 = building1[i];
   //    for(int j=0;j<building1[i].size();j++)
   //    {
   //      if(parent1[adj1[j]] == -1)
   //        parent1[adj1[j]] = i;
   //    }
   //  }

   // cout<<"\nParent1\n";
   // for(int i=0;i<n;i++)
   //  {
   //    cout<<parent1[i]<<" ";
   //  }
   //  cout<<endl;

    for(int i=0;i<n;i++)
    {
      vector<int> adj1 = building1[i];
      cout<<"["<<i<<"]->";
      for(int j=0;j<building1[i].size();j++)
      {
      cout<<"["<<adj1[j]<<"]";
      }
      cout<<endl;
    }
    cout<<endl;

    if(IsCycle(0,visited1,parent1,building1))
    {
      cout<<"NA\n";
      return 0;
    }    

    checkOverlap(test2, building2);

   //  for(int i=0;i<n;i++)
   //  {
   //    if(i==0)//root
   //      parent2[i] = -2;
   //    vector<int> adj1 = building2[i];
   //    for(int j=0;j<building2[i].size();j++)
   //    {
   //      if(parent2[adj1[j]] == -1)
   //        parent2[adj1[j]] = i;
   //    }
   //  }

   //  cout<<"\nParent2\n";
   // for(int i=0;i<n;i++)
   //  {
   //    cout<<parent2[i]<<" ";
   //  }
   //  cout<<endl;

    for(int i=0;i<n;i++)
    {
      vector<int> adj2 = building2[i];
      cout<<"["<<i<<"]->";
      for(int j=0;j<building2[i].size();j++)
      {
      cout<<"["<<adj2[j]<<"]";
      }
      cout<<endl;
    }

    if(IsCycle(0,visited2,parent2,building2))
    {
      cout<<"NA\n";
      return 0;
    }
    
    listInitialize(building1, list1);
    getSequence(building1,list1,list1[0]);
    // cout<<endl;

    // for(vector<node*> :: iterator itr = list1.begin(); itr<list1.end();itr++)
    // {
    //   cout<<"["<<(*itr)->value<<"|"<<(*itr)->s<<"|"<<(*itr)->IsChild<<"]"<<endl;
    // }

    listInitialize(building2, list2);
    getSequence(building2,list2,list2[0]);
    // cout<<endl;

    // for(vector<node*> :: iterator itr = list2.begin(); itr<list2.end();itr++)
    // {
    //   cout<<"["<<(*itr)->value<<"|"<<(*itr)->s<<"|"<<(*itr)->IsChild<<"]"<<endl;
    // }


    

    string x = list1[0]->s;
    string y = list2[0]->s;

    if(x.compare(y)==0)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
     return 0;
}