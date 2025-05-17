#include <iostream>
using namespace std;
struct node
{
    int data;
    static node* sentnel;
    node *left = sentnel , *right =sentnel;
    int height = 0;//height
};
node* node::sentnel=new node;
class avl
{
    node *root;
public:
    avl();
    node* add(node *temp,int value);
    void remove (int value);
    node* balance(node *temp);
    void display(node *temp);
    bool is_empty();
    node* right_rotation(node *q);
    node* left_rotation(node *q);
    int calc_balance_factor(node *temp);
    int calc_height(node *temp);
    node* get_root();
    void test();
};
avl::avl()
{
    root = node::sentnel;
}
node* avl::add(node *temp,int value)
{
    if(is_empty())
    {
        root = new node;
        root->data = value;
        root->height=1;
        //root = temp;
    }
    else
    {
        if(temp == node::sentnel)
        {
            temp = new node;
            temp->data = value;
            temp->height=1;
        }
        else
        {
            if(value > temp->data)
                temp->right= add(temp->right,value);
            else
                temp->left=add(temp->left,value);
        }
        temp->height = calc_height(temp);
        temp=balance(temp);
     }
     return temp;
}
void avl::display(node *temp)
{
    if(temp != node::sentnel)
    {
        display(temp->left);
        cout<<"data :"<<temp->data
            <<" height : "<<temp->height
            <<" balance factor: "<<calc_balance_factor(temp)<<endl;
        display(temp->right);
    }
}
bool avl::is_empty()
{
    if(root == node::sentnel)
        return true;
    return false;
}
node* avl::get_root()
{
    return root;
}
node* avl::balance(node *temp)
{
    if(calc_balance_factor(temp) >= 2)
    {
        cout<<"the root is :"<<root->data<<endl<<endl;
        if(calc_balance_factor(temp->left) <= -1)
            temp->left = left_rotation(temp->left);
        temp=right_rotation(temp);
        display(root);
        cout<<"=======================================\n";
    }
    else if(calc_balance_factor(temp) <= -2)
    {
        cout<<"the root is :"<<root->data<<endl<<endl;
        if(calc_balance_factor(temp->right) >= 1)
            temp->right = right_rotation(temp->right);
        temp=left_rotation(temp);
        display(root);
        cout<<"=======================================\n";
    }
    return temp;
}
int avl::calc_balance_factor(node *temp)
{
    return (temp->left->height - temp->right->height);
}
node* avl::right_rotation(node *q)
{
    node *p =q->left;
    if(q==root)
        root=p;
    q->left=p->right;
    p->right=q;
    q->height=calc_height(q);
    p->height=calc_height(p);
    return p;
}
node* avl::left_rotation(node *p)
{
    node *q =p->right;
    if(p==root)
        root=q;
    p->right=q->left;
    q->left=p;
    //the sorting is very important //
    p->height=calc_height(p);
    q->height=calc_height(q);
    return q;
}
int avl::calc_height(node *temp)
{
  //  cout<<"heigth of "<<temp->data<<" is :"<<1+max(temp->right->height,temp->left->height)<<endl;
    return 1+max(temp->right->height,temp->left->height);
}
void avl::test()
{
    cout<<root->data<<" "<<root->right->data<<" "<<root->left->data<<endl;
}
int main()
{
    cout << "Hello world!" << endl;
    avl a;
    a.add(a.get_root(),1);
    cout<<endl;
    a.add(a.get_root(),2);
    cout<<endl;
    a.add(a.get_root(),3);
    cout<<endl;
    a.add(a.get_root(),4);
    cout<<endl;
    a.add(a.get_root(),5);
    cout<<endl;
    a.add(a.get_root(),6);
    cout<<endl;
    a.add(a.get_root(),7);
    cout<<endl;
    a.add(a.get_root(),8);
    cout<<endl;
    a.display(a.get_root());
    //a.test();
    return 0;
}
