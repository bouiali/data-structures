#include <iostream>
//This algorithm need some search and modifie
using namespace std;
struct node
{
    int data;
    int id;
};
class hash_table
{
    //fields
    int counter =0;
    node node[51];
    //methods
public:
    hash_table();
    void add(int value ,int id);
    int hash_count(int id);
    int searching(int id);
    void removing(int id);
    int hash_recount(int id);
    void display_table();
};
hash_table::hash_table()
{
    for(int i=0;i<51;i++)
    {
        node[i].data=0;
        node[i].id=-1;
    }
    cout<<"hash table is inisializ"<<endl;
}
void hash_table::add(int value , int id)
{
    if(counter<51)
    {
        int loc = hash_count(id);
        if(node[loc].id==-1)
        {
            node[loc].id=id;
            node[loc].data=value;
            counter++;
            cout<<"Add seccesffuly !!!"<<endl;
        }
        else
            cout<<"not available place in the table"<<endl;
    }
    else
        cout<<"not available place in the table"<<endl;
}
int hash_table::hash_count(int id)
{
    if(node[id%51].id==-1)
        return id%51;
    else
        return hash_recount(id);
}
int hash_table::hash_recount(int id)
{
    for(int i=1;i<=50;i++)
    {
        if(node[id+i%51].id==-1)
            return (id+i)%51;
    }
    return (id+1)%51;
}
void hash_table::removing(int value)
{
    //like add
}
int hash_table::searching(int value)
{
    //like add & removing
}
void hash_table::display_table()
{
    cout<<"==================================="<<endl;
    for(int i=0;i<51;i++)
    {
        cout<<node[i].id<<" <===> "<<node[i].data<<"\t\t\t ++"<<endl;
    }
    cout<<"==================================="<<endl;
}
int main()
{
    cout << "Hello world!" << endl;
    hash_table h1;
    h1.add(10,20);
    h1.add(20,51);
    h1.display_table();
    return 0;
}
