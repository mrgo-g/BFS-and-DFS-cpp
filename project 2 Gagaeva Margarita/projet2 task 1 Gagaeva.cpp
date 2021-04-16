#include <vector>
#include <stack>
#include <iostream>
#include <list>
#include <queue>
#include <windows.h>
#include <bits/stdc++.h>
#include <stdexcept>
#include <vector>

using namespace std;

struct Node
{
    int coordinate;  // The cordinates of a node
    Node *prev;
};

class BFS
{// n number of vertices
    int n;
public:
    BFS(int n)
    {
        this->n = n;
        adjacency  = new list<int>[n];
    }
    ~BFS() {};
    int no;
// Pointer to an array containing adjacency lists
    list<int> *adjacency ;

    // function to add an edge to graph
    void AddEdge(int v, int w)
    {// Add w to v’s list.
        adjacency [v].push_back(w);
        adjacency [w].push_back(v);
    }

    int Path_counting(int Start = 0, int Finish = 0 )
    {
        if((Start!=Finish) && Finish<n && Start<n)
        {

        vector<int> path;
        vector<int> rightPath;
        //now make all nodes marked as non-visited
        bool *visited = new bool[n];
        int old[n];
        for(int i = 0; i < n; i++)
            visited[i] = false;
//create queue
        list<int> queue;

        visited[Start] = true;
        int start = Start;
        queue.push_back(Start);
        list<int>::iterator i;
        while(!queue.empty())
        {
            //dequeue v
            Start = queue.front();
            queue.pop_front();
            path.push_back(Start);
            if (Start==Finish)
            {
                rightPath.push_back(Start);
                int num=path.size()-1;
                while(old[path[num]]!=start)
                {
                    int element = path[num];
                    rightPath.push_back(old[element]);
                    for(int i=0; i<path.size(); i++)
                    {
                        if(path[i]==old[path[num]])
                        {
                            num=i;
                        }
                    }
                }

                cout  << "\nGood choice! Your way out : " << endl;
                rightPath.push_back(old[path[num]]);
                for(int i=rightPath.size()-1; i>=0; i--)
                {
                    cout << rightPath[i] << " \t ";
                }
                cout<<"\nNumber of ways  out: "<<rightPath.size();
                cout<<"\n__________________________________________";

                return rightPath.size();
            }

            for (i = adjacency [Start].begin(); i != adjacency [Start].end(); ++i)
            {
                if (!visited[*i])
                {
                    old[*i] =Start;
                    visited[*i] = true;
                    queue.push_back(*i);
                }

            }
        }
        }

        cout << "\nNot this time, wizard!  ";
        cout<<"__________________________";
        return -1;
    }
};
int main(){
    BFS Maze(10);
        Maze.AddEdge(0,1);
        Maze.AddEdge(1,2);
        Maze.AddEdge(2,3);
        Maze.AddEdge(3,4);
        Maze.AddEdge(4,5);
        Maze.AddEdge(5,6);
        Maze.AddEdge(6,7);
        Maze.AddEdge(7,4);
        Maze.AddEdge(7,8);

        int wizards_size = 3;
        vector<int> minimal_path;
        minimal_path.resize(wizards_size);
        int _start; int _finish;

        for (int i=0; i<wizards_size; i++){
            cout << "\n Where would you like to start your way? ";
            cin >> _start;
            cout << " \n And where are you going to finish ? ";
            cin >> _finish;
            minimal_path[i]=(Maze.Path_counting(_start, _finish));
        }
        int t;
         unsigned int winner=minimal_path[0];
        for (int  i=0;i<wizards_size; i++){
        if (minimal_path[i]<winner)
        {
            winner=minimal_path[i];
            t=i+1;
        }
        }
        cout <<endl<<"\n The path of a winner is   " << winner<<" ways long"<<endl;
        cout<<"Winner is ... wizard # "<<t<< " ! ";







    return 0;
}


