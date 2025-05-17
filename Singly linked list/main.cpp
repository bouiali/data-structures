#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
    private:
        node *head;
        node *till;
        int size;
    public:
        linked_list();
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

linked_list::linked_list()
{
    head = NULL;
    size =0;
}

void linked_list::add_to_till(int value)
{
    if(head == NULL)//if is empty
    {
        head = new node;
        head->data=value;
        head->next=NULL;
        till=head;
        size ++;
    }
    else
    {
        till->next = new node;
        till=till->next;
        till->data = value;
        till->next = NULL;
        size ++;
    }
}

void linked_list::remove(int value)
{
    if(head == NULL)//if is empty
    {
        cout<<"Linked list is empty !!!"<<endl;
        return;
    }
    else if(head->data == value)//if the value in the head
    {
        head = head->next;
        cout<<"\nRemoved succesfuly !!!"<<endl;
        size--;
        return;
    }

    else
    {
        node *temp = head;
        while(temp->next != NULL)
        {
            if(temp->next->data == value)
            {
                temp->next = temp->next->next;
                cout<<"\nRemoved succesfuly !!!"<<endl;
                size--;
                return;
            }
            temp = temp->next;
        }
        cout<<"\nThis value don't exist in the list !!!"<<endl;//if the value don't found
    }
}

void linked_list::display()
{
    if(head == NULL)
    {
        cout<<"Linked list is empty !!!"<<endl;
        return;
    }
    else
    {
        cout<<endl;
        node *temp = head;
        while(temp ->next != NULL)
        {
            cout<<temp->data<<"   ==>";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
}

void linked_list::update(int value,int new_value)
{
    if(head == NULL)
    {
        cout<<"Linked list is empty !!!"<<endl;
        return;
    }
    else
    {
        node *temp = head;
        while(temp ->next != NULL)
        {
            if(temp->data == value)
            {
                temp->data = new_value;
                cout<<"\nUpdate succesfuly !!!"<<endl;
                return;
            }
            temp = temp->next;
        }
        if(temp->data == value)
        {
            temp->data = new_value;
            cout<<"\nUpdate succesfuly !!!"<<endl;
            return;
        }
        cout<<"\nThis value don't exist in list!!!"<<endl;
    }
}

void linked_list::add_to_head(int value)
{
    if(head == NULL)
    {
        head = new node;
        head->data=value;
        head->next=NULL;
        till=head;
        size ++;
    }
    else
    {
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
        size ++;
    }
}

void linked_list::sorting()
{
    if(head == NULL)
    {
       cout<<"List is empty !!!"<<endl;
       return;
    }
    else
    {
       node *place= head;
       node *value;
       int temp;
       while(place->next != NULL)
       {
           value = place->next;
           while(value != NULL)
           {
               if(value->data < place->data)
               {
                    temp = place->data;
                    place->data = value->data;
                    value->data = temp;
               }
               value = value->next;
           }
           place= place->next;
       }
    }
}

void linked_list::insert(int value , int pos)
{
    if(head == NULL)
    {
       cout<<"List is empty !!!"<<endl;
       return;
    }
    else if(pos >= size)
    {
        add_to_till(value);
        cout<<"\nInsert seccesfuly !!!"<<endl;
    }

    else if(pos == 1)
    {
        add_to_head(value);
        cout<<"\nInsert seccesfuly !!!"<<endl;
    }

    else
    {
       node *last= head;
       node *next=last->next;
       node *temp= new node;
       temp->data = value;
       for (int i=2;i<pos;i++)
       {
           last= last->next;
           next= next->next;
       }
       last->next = temp;
       temp->next = next;
       size++;
       cout<<"\nInsert seccesfuly !!!"<<endl;
    }
}

void linked_list::search(int value)
{
    if(head == NULL)
    {
        cout<<"The list is empty !!!"<<endl;
        return;
    }
    else
    {
        node *temp = head;
        int pos=1;
        while(temp != NULL)
        {
            if(temp->data == value)
            {
                cout<<"\nThe value is found in position :"<<pos<<endl;
                return;
            }
            pos++;
            temp= temp->next;
        }
        cout<<"\nThe value don't found !!!"<<endl;
    }
}

void linked_list::reverse()
{
    if(head==NULL)
    {
        cout<<"\nThe list is empty !!!"<<endl;
        return;
    }
    else
    {
        node *ptr1=head;
        node *ptr2=ptr1->next;
        node *ptr3=ptr2->next;
        ptr1->next=NULL;
        ptr2->next=ptr1;
        while(ptr3->next != NULL)
        {
            ptr1=ptr2;
            ptr2=ptr3;
            ptr3=ptr3->next;
            ptr2->next=ptr1;
        }
        ptr3->next=ptr2;
        head= ptr3;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    cout<<endl;
    //tests
    linked_list ll;
    ll.display();
    ll.add_to_till(1);
    ll.add_to_till(2);
    ll.add_to_till(3);
    ll.add_to_till(4);
    ll.add_to_till(5);
    ll.add_to_till(6);
    ll.add_to_till(7);
    ll.add_to_till(0);
    ll.update(7,8);
    ll.update(4,10);
    ll.insert(4,4);
    ll.insert(0,1);
    ll.insert(11,11);
    ll.insert(7,9);
    ll.insert(9,11);
    ll.remove(0);
    ll.sorting();
    ll.search(10);
    ll.insert(12,12);
    ll.reverse();
    ll.display();
    return 0;
}
