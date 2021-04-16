#include <stack>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <windows.h>
#include <vector>

using namespace std;

class Sitting
{
    int n;
public:
    vector<vector<int>> _vector;
    int _size(){return n;}

    int AddVertex(unsigned int m)
    {
        _vector.resize(n+m);
        return n+=m; }

    void AddEdge(int v, int w)
    {
        _vector[v].push_back(w);
        _vector[w].push_back(v);
    }
    Sitting()
    {
        n=0;
    }

    int Scheme()
    {
        int guests[n] = {0};

        stack<int> q;
        for (int v=0; v<_size(); v++)
        {
            if(guests[v]==0)
            {
                guests[v]=1;
                q.push(v);
                while (!q.empty())
                {
                    int w = q.top();
                    q.pop();
                    for (int i=0; i<_vector [w].size(); i++)
                    {
                        if(!guests[_vector[w][i]])
                        {
                            q.push(_vector[w][i]);
                            guests[_vector[w][i]]=((guests[w]==1)?2:1);
                        }
                        else
                        {
                            if(guests[_vector[w][i]]==guests[w])
                            {
                                cout<<"Aunty! There is no way we can sit our family like that!"<<endl;
                                return -1;
                            }
                        }

                    }
                }
            }
        }
        for (int i=0; i<n; i++)
        cout <<"\nFamily member "<< i <<" will sit at : " <<guests[i] << endl;
        return 0;
    }



};



int main (){

        Sitting G;
        int n=6;
        G.AddVertex(n);
 G.AddEdge(0,1);
  G.AddEdge(1,3);
  G.AddEdge(2,3);
  G.AddEdge(3,5);
  G.AddEdge(4,3);
  G.AddEdge(2,0);
        G.Scheme();



    return 0;
    }
