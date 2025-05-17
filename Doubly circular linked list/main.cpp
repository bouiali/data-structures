#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
    node *back;
};
class doubly_circular_linked_list
{
private:
    node *head;
    node *till;
    int size;
public:
    doubly_circular_linked_list();
    void first_node(int value);
    bool is_empty();
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
doubly_circular_linked_list::doubly_circular_linked_list()
{
    head=till=NULL;
    size = 0;
}
void doubly_circular_linked_list::first_node(int value)
{
    head = new node;
    head->data = value;
    head->next = head;
    till = head;
    head->back = till;
    size++;
}
bool doubly_circular_linked_list::is_empty()
{
    if(head == NULL)
        return true;
    return false;
}
void doubly_circular_linked_list::add_to_head(int value)
{
    if(is_empty())
        first_node(value);
    else
    {
        node *temp = new node;
        temp->next=head; temp->data=value; temp->back=till;
        head->back = temp; head=temp;
        till->next = head;
        size++;
    }
}
void doubly_circular_linked_list::add_to_till(int value)
{
    if(is_empty())
        first_node(value);
    else
    {
        node *temp = new node;
        temp->data=value; temp->back=till; temp->next=head;
        till->next=temp; till=temp;
        head->back=till;
        temp=NULL; free(temp);
        size++;
    }
}
void doubly_circular_linked_list::display()
{
    if(is_empty())
        return;
    else
    {
        node *temp = head;
        do
        {
            cout<<temp->data<<" ==>";
            temp = temp->next;
        }while(temp != head);
    }
}
void doubly_circular_linked_list::insert(int value,int pos)
{
    if(is_empty())
        first_node(value);
    else if(pos == 1)
        add_to_head(value);
    else if(pos >= size)
        add_to_till(value);
    else
    {
        node *temp = head;
        node *add = new node; add->data=value;
        for(int i=2;i<pos;i++)
            temp = temp->next;
        add->next=temp->next; add->back=temp;
        temp->next->back=add; temp->next=add;
        temp=NULL; free(temp);
        size++;
    }
}
void doubly_circular_linked_list::remove(int value)
{
    if(is_empty())
        return;
    else if(head->data == value)
    {
        head=head->next;
        head->back->next=head->back->back=NULL;
        head->back = till;
        till->next = head;
        size--;
    }
    else if (till->data == value)
    {
        till=till->back;
        till->next->next=till->next->back=NULL;
        till->next = head;
        head->back = till;
        size--;
    }
    else
    {
        node *temp1,*temp = head;
        while(temp->data != value)
            temp = temp->next;
        temp1=temp->next->next; temp1->back=temp;
        temp->next->next=temp->next->back=NULL;
        temp->next=temp1;
        temp=temp1=NULL; free(temp); free(temp1);
        size--;
    }
}
void doubly_circular_linked_list::reverse()
{
    if(is_empty() || size == 1)
        return;
    else
    {
        node *ptr1,*ptr2; ptr1=head; ptr2=ptr1->next;
        do
        {
            ptr1->next = ptr1->back;
            ptr1->back = ptr2;
            ptr1=ptr2; ptr2=ptr2->next;
        }while(ptr1 != head);
        head=till; till=ptr1;
        ptr1=ptr2=NULL; free(ptr1); free(ptr2);
    }
}
int main()
{
    cout << "Hello world!" << endl;
    doubly_circular_linked_list dcll;
    dcll.add_to_head(5);
    dcll.add_to_head(4);
    dcll.add_to_head(3);
    dcll.add_to_head(2);
    dcll.add_to_head(1);
    dcll.add_to_till(6);
    dcll.insert(0,1); dcll.insert(4,5); dcll.insert(7,9);
    dcll.remove(0); dcll.remove(4); dcll.remove(7);
    dcll.reverse();
    dcll.display();
    return 0;
}
