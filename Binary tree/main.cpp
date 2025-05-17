#include <iostream>

using namespace std;
struct node
{
    int data;
    node *left,*rigth;
};
node *root;
class binary_search_tree
{
    int size;
public:
    binary_search_tree();
    bool is_empty();
    void first_node(int value);
    void insert(int value);
    void remove(int value);
    void modifie(int value,int new_value);
    void pre_display(node *temp);
    void post_display(node *temp);
    void in_display(node *temp);
};
binary_search_tree::binary_search_tree()
{
    size=0; root=NULL;
}
bool binary_search_tree::is_empty()
{
    if(root == NULL)
         return true;
    return false;
}
void binary_search_tree::first_node(int value)
{
    root = new node;
    root->data = value;
    root->left = root->rigth = NULL;
    cout << "insert_first" << endl;
}
void binary_search_tree::insert(int value)
{                                       /*!The recursive way is the right way (you can found it in (AVL tree) project)!*/
    if(is_empty())
        first_node(value);
    else
    {
        node *temp=root;
        node *new_node = new node;
        new_node->data =value;
        new_node->left = new_node->rigth = NULL;
        while(1)
        {
            if(temp->data > value)
            {
                if(temp->left == NULL)
                {
                    temp->left = new_node;
                    cout << "insert_left" << endl;
                    break;
                }
                else
                {
                    temp= temp->left;
                }
            }
            else
            {
                if(temp->rigth == NULL)
                {
                    temp->rigth = new_node;
                    cout << "insert_rigth" << endl;
                    break;
                }
                else
                {
                    temp= temp->rigth;
                }
            }
        }
    }
}
void binary_search_tree::pre_display(node *temp)
{
    if(is_empty())
        return;
    else
    {
      if(temp != NULL)
      {
          cout<<temp->data<<" =>";
          pre_display(temp->left);
          pre_display(temp->rigth);
      }
    }
}
void binary_search_tree::post_display(node *temp)
{
    if(is_empty())
        return;
    else
    {
      if(temp != NULL)
      {
          post_display(temp->left);
          post_display(temp->rigth);
          cout<<temp->data<<" =>";
      }
    }
}
void binary_search_tree::in_display(node *temp)
{
    if(is_empty())
        return;
    else
    {
      if(temp != NULL)
      {
          in_display(temp->left);
          cout<<temp->data<<" =>";
          in_display(temp->rigth);
      }
    }
}
void binary_search_tree::remove(int value)
{
    if(is_empty())
        return;
    else
    {
        node *temp,*parent;
        temp =root;
        while(temp != NULL && temp->data != value)
        {
            parent = temp;
            if(value < temp->data)
                temp = temp->left;
            else
                temp = temp->rigth;
        }
        node *marker = temp;
        if(temp == NULL)
            cout<<"not found the value !!!";
        else
        {
            if(temp == root)
            {
                if(root->left == NULL && root->rigth == NULL)
                    root = NULL;
                else if (root->left == NULL)
                    root = root->rigth;
                else if (root->rigth == NULL)
                    root = root->left;
                else
                {
                    node *temp1 = temp->rigth;
                    while(temp1->left != NULL)
                    {
                        temp = temp1;
                        temp1 = temp1->left;
                    }
                    if(temp->rigth != temp1)
                    {
                        temp->left = temp1->rigth;
                        temp1->rigth = root->rigth;
                    }
                    temp1->left = root->left;
                    root = temp1;
                }
            }
            else
            {
                if(temp->left == NULL && temp->rigth == NULL)
                {
                    if(parent->left == temp)
                        parent->left = NULL;
                    else
                        parent->rigth = NULL;
                }
                else if(temp->left == NULL)
                {
                    if(parent->left == temp)
                        parent->left = temp->rigth;
                    else
                        parent->rigth = temp->rigth;
                }
                else if(temp->rigth == NULL)
                {
                    if(parent->left == temp)
                        parent->left = temp->left;
                    else
                        parent->rigth = temp->left;
                }
                else
                {
                    node *temp1 = temp->rigth;
                    node *parent = temp;
                    while(temp1->left != NULL)
                    {
                        temp = temp1;
                        temp1 = temp1->left;
                    }
                    if(temp->rigth != temp1)
                    {
                        temp->left = temp1->rigth;
                        parent->rigth = temp1->rigth;
                    }
                    temp1->left = parent->left;
                    parent=temp1;
                }
            }
        }
        delete marker;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    binary_search_tree bst;
    bst.insert(10); bst.insert(5); bst.insert(14);
    bst.insert(11); bst.insert(6); bst.insert(15);
    bst.insert(12); bst.insert(7); bst.insert(16);
    bst.insert(13); bst.insert(8); bst.insert(17);
    bst.remove(17);
    node *temp = root;
    bst.post_display(temp);

    return 0;
}













/*

void Binary_tree::Delete(int key)
{
    tree *temp = root,*parent = root, *marker;
    if (temp==NULL)//the tree is empty
        cout<<"The tree is empty"<<endl;
    else
    {
        while (temp!=NULL && temp->info!=key)//search the value
        {
            parent=temp;
            if (temp->info<key)
            {
                temp=temp->Right;
            }
            else
            {
                temp=temp->Left;
            }
        }
    }
    marker=temp;
    if (temp==NULL)// if the value not founded
        cout<<"No node present";
    else if (temp==root)//delete the root(the value in the root)
    {
        if (temp->Right == NULL && temp->Left ==NULL)//if the tree have the root only
        {
            root=NULL;
        }
        else if (temp->Left==NULL)//if the root have right children only
        {
            root=temp->Right;
        }
        else if (temp->Right==NULL)//if the root have left children only
        {
            root=temp->Left;
        }
        else // ....have tow children
        {
            tree *temp1;
            temp1 = temp->Right;
            while (temp1->Left!=NULL)
            {
                temp=temp1;
                temp1=temp1->Left; //search for the smallest value in the right side
            }
            if(temp1!=temp->Right)// if the smallest value is right children or root
            {
                temp->Left=temp1->Right;
                temp1->Right=root->Right;
            }
            temp1->Left=root->Left;
            root=temp1;
        }
    }
    else // delete another node
    {
        if (temp->Right==NULL && temp->Left==NULL)//if the node is leaf
        {
            if (parent->Right==temp)
                parent->Right=NULL;
            else
                parent->Left=NULL;
        }
        else if (temp->Left==NULL)//...have right children only
        {
            if (parent->Right==temp)
                parent->Right=temp->Right;
            else
                parent->Left=temp->Right;
        }
        else if (temp->Right==NULL)//..have left children only
        {
            if (parent->Right==temp)
                parent->Right=temp->Left;
            else
                parent->Left=temp->Left;
        }
        else // ..have tow children
        {
            tree *temp1;
            parent=temp;
            temp1=temp->Right;
            while (temp1->Left!=NULL)
            {
                parent=temp1;
                temp1=temp1->Left;
            }
            if(temp1!=temp->Right)
            {
                temp->Left=temp1->Right;
                temp1->Right=parent->Right;
            }
            temp1->Left=parent->Left;
            parent=temp1;
        }
    }
    delete marker;
}
*/
