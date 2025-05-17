#include <iostream>
                    /*singly circular linked list*/
using namespace std;
struct node
{
    int data;
    node *next;
};
class circular_linked_list
{
    node *head;
    node *last;
    int size;
public:
    circular_linked_list();
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
circular_linked_list::circular_linked_list()
{
    head=last=NULL;
    size = 0;
}
void circular_linked_list::first_node(int value)
{
    head = new node;
    head->data = value;
    head->next = head;
    last = head;
    size++;
}
bool circular_linked_list::is_empty()
{
    if(head == NULL)
        return true;
    return false;
}
void circular_linked_list::add_to_head(int value)
{
    if(is_empty())
    {
        first_node(value);
    }
    else
    {
        node *temp = new node;
        temp->next = head;
        temp->data = value;
        head = temp;
        last->next = head;
        temp = NULL;
        free(temp);
        size++;
    }
}
void circular_linked_list::add_to_till(int value)
{
    if(is_empty())
    {
        first_node(value);
    }
    else
    {
        node *temp = new node;
        temp->next = head;
        temp->data = value;
        last->next = temp;
        last = temp;
        temp = NULL;
        free(temp);
        size++;
    }
}
void circular_linked_list::display()
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
        }while(temp != head );

    }
}
void circular_linked_list::insert(int value,int pos)
{
    if(is_empty() || pos == 1)
        first_node(value);
    else if(pos >= size)
        add_to_till(value);
    else
    {
        node *temp = head;
        node *neww = new node;
        neww->data = value;
        for(int i=1;i<pos;i++)
            temp = temp->next;
        neww->next = temp->next;
        temp->next = neww;
        temp = neww = NULL;free(temp);free(neww);
        size++;
    }
}
void circular_linked_list::remove(int value)
{
    if(is_empty())
        return;
    else if(head->data == value)
    {
        last->next = head->next;
        head->next = NULL;
        head = last->next;
        size--;
    }
    else
    {
        node *temp = head->next;
        node *pos = temp->next;
        while(pos!= head)
        {
            if(pos->data == value)
            {
                temp->next = pos->next;
                pos->next == head ? last = temp : last=last ;
                pos->next=temp= NULL;
                free(temp); free(pos);
                size--;
                return;
            }
            temp=temp->next;  pos = pos->next;
        }
    }
}
void circular_linked_list::reverse()
{
    if(is_empty())
        return;
    else
    {
        node *ptr1,*ptr2,*ptr3;
        ptr1=head; ptr2=ptr1->next; ptr3=ptr2->next;
        ptr1->next = last; last=ptr1;
        ptr2->next = ptr1;
        ptr1= ptr2;
        while(ptr3 != head)
        {
            ptr2= ptr3;
            ptr3 = ptr3->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
        }
        head = ptr2;
        ptr1=ptr2=ptr3 = NULL;
        free(ptr1);free(ptr2);free(ptr3);
    }
}
int main()
{
    cout << "Hello world!" << endl;
    circular_linked_list cll;
    cll.add_to_till(0);
    cll.add_to_till(1);
    cll.add_to_till(2);
    cll.add_to_till(3);
    cll.add_to_till(5);
    cll.insert(4,4);
    cll.remove(5);
    cll.reverse();
    cll.add_to_head(5);
    cll.display();
    return 0;
}
