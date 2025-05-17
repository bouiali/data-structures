#include <iostream>
#define MAX 20
using namespace std;
class stack
{
    int arr[MAX] = {0};
    int top;
public:
    stack();
    void push(int value);
    int pop();
    bool is_empty();
    int top_value();
    int last_value();
};
stack::stack()
{
    top = -1;
}
void stack::push(int value)
{
    arr[++top] = value;
}
bool stack::is_empty()
{
    if(top == -1)
        return true;
    return false;
}
int stack::pop()
{
    return arr[--top];
}
int stack::last_value()
{
    return arr[top-1];
}
int stack::top_value()
{
    return arr[top];
}
struct vertex
{
    char data;
    bool visited = false;
};
class graph
{
    vertex arr[MAX];
    int eadg_matrix[MAX][MAX] = {0};
    int size;
public:
    graph();
    void add (char value);
    void add_eadg (int start , int end);
    void display_vertex(int index);
    void depth_first_();
    bool is_visited(int index);
    int unvisited_vertex(int index);
};
graph::graph()
{
    size = -1;
}
void graph::add(char value)
{
    arr[++size].data = value;
    arr[size].visited = false;
}
void graph::add_eadg(int start,int end)
{
    eadg_matrix[start][end] = 1;
    eadg_matrix[end][start] = 1;
}
void graph::display_vertex(int index)
{
    cout<<"\n"<<arr[index].data<<endl;
}
bool graph::is_visited(int index)
{
    if(arr[index].visited == true)
        return true;
    return false;
}
void graph::depth_first_()
{
    stack s;
    display_vertex(0);
    arr[0].visited= true;
    s.push(0);
    int i=0;
    while(!s.is_empty())
    {
        i=unvisited_vertex(i);
        if(i != -1)
        {
            display_vertex(i);
            arr[i].visited = true;
            s.push(i);
        }
        else
        {
            i=s.pop();
        }
    }
    for(int i=0;i<=size;++i)
        arr[i].visited = false;

}
int graph::unvisited_vertex(int index)
{
    for (int i=0;i<=size;++i)
    {
        if(eadg_matrix[index][i]== 1 && arr[i].visited == false)
            return i;
    }
    return -1;
}
int main()
{
    graph g;
    g.add('a');
    g.add('b');
    g.add('c');
    g.add('d');
    g.add('e');
    g.add('f');
    g.add('g');
    g.add('h');
    g.add_eadg(0,1);
    g.add_eadg(0,7);
    g.add_eadg(1,2);
    g.add_eadg(2,3);
    g.add_eadg(3,4);
    g.add_eadg(3,5);
    g.add_eadg(3,6);
    g.add_eadg(3,7);
    g.depth_first_();
    return 0;
}
