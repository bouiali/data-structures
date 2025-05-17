#include <iostream>

using namespace std;
struct node
{
    int data;
    node *back;
    node *next;
};
class doubly_linked_list
{
private:
    node *head;
    node *till;
    int size;
public:
    doubly_linked_list();
    void add_to_till(int value);
    void add_to_head(int value);
    void remove(int value);
    void insert(int value ,int pos);
    void update(int value,int new_value);
    void sorting();
    void search(int value);
    void reverse();
    void display();
};
doubly_linked_list::doubly_linked_list()
{
    head = NULL;
    till = NULL;
    size=0;
}
void doubly_linked_list::add_to_head(int value)
{
    if(head==NULL)
    {
        head = new node;
        till= head;
        head->back=NULL;
        head->data= value;
        head->next=NULL;
        size++;
    }
    else
    {
        node *temp = new node;
        temp->data= value;
        temp->next= head;
        temp->back=NULL;
        head->back = temp;
        head=temp;
        size++;
    }
}
void doubly_linked_list::add_to_till(int value)
{
    if(head==NULL)
    {
        head = new node;
        till= head;
        head->back=NULL;
        head->data= value;
        head->next=NULL;
        size++;
    }
    else
    {
        node *temp = new node;
        temp->data= value;
        temp->next= NULL;
        temp->back= till;
        till->next = temp;
        till=temp;
        size++;
    }
}
void doubly_linked_list::display()
{
    if(head==NULL)
    {
        cout<<"The list is empty !!!"<<endl;
        return;
    }
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            cout<< temp->data<<"  ==>";
            temp= temp->next;
        }

    }
}
void doubly_linked_list::insert(int value , int pos)
{
    if(head == NULL)
    {
       cout<<"List is empty !!!"<<endl;
       return;
    }
    else if(pos >= size)
    {
        add_to_till(value);
        cout<<"\nInsert successfully !!!"<<endl;
    }

    else if(pos == 1)
    {
        add_to_head(value);
        cout<<"\nInsert successfully !!!"<<endl;
    }

    else
    {
        node *temp = head;
        node *new_node =new node;
        new_node->data=value;
        for(int i=1;i<pos;i++)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next->back = new_node;
        temp->next = new_node;
        new_node->back = temp;
        size++;
    }
}
void doubly_linked_list::remove(int value)
{
    if(head==NULL)
    {
        cout<<"The list is empty !!!"<<endl;
        return;
    }
    else if (till->data == value)
    {
        till = till->back;
        till->next->back= NULL;
        till->next= NULL;
        size--;
    }
    else if (head->data == value)
    {
        head=head->next;
        head->back->next = NULL;
        head->back = NULL;
        size--;
    }
    else
    {
        node *temp = head;
        while(temp->next->data != value)
        {
            temp= temp->next;
        }
        node *remove = temp->next;
        temp->next = remove->next;
        remove->next->back = temp;
        free(remove);
        size--;

    }
}
void doubly_linked_list::reverse()
{
    if(head==NULL)
    {
        cout<<"The list is empty !!!"<<endl;
        return;
    }
    else
    {
                 /*first way*/
        node *temp =head;
        temp->back = temp->next;
        temp->next = NULL;
        while(temp->back->next != NULL)
        {
            temp->back->back=temp->back->next;
            temp->back->next= temp;
            temp = temp->back;
        }
        temp->back->next=temp;
        temp->back->back = NULL;
        till= head;
        head = temp->back;
                    /*second way (book way) */
        /*node *p1,*p2;
        p1=head;
        p2=head->next;
        p1->back =p1->next;
        p1->next = NULL;
        p2=p1->back;
        while(p2->next!=NULL)
        {
            p2->back =p2->next;
            p2->next =p1;
            p1=p2;
            p2 = p2->back;
        }
        p2->next=p2->back;
        p2->back =NULL;
        till=head;
        head=p2;*/
    }
}
int main()
{
    cout << "Hello world!" << endl;
    doubly_linked_list dll;
    dll.add_to_head(0);
    dll.add_to_till(1);
    dll.add_to_till(2);
    dll.add_to_till(3);
    dll.add_to_till(5);
    dll.insert(4,4);
    dll.remove(5);
    dll.insert(5,5);
    dll.reverse();
    dll.display();
    return 0;
}
