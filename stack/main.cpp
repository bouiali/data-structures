#include <iostream>
//static stack
using namespace std;
string convert_infix_to_postfix(string input[],int length);
void calculate_postfix_value(string post);
int get_length(string s);
class int_stack
{
    //fields
private:
    int data[10];
    int top;
    //methods
public:
    int_stack();//constructor
    void push(int value);//add
    void pop();//remove
    void display();//show data
    int last_value();
};
int_stack::int_stack()
{
    top=-1;
}
void int_stack::push(int value)
{
    if(top==9)
    {
        cout<<"stack overflow !!!"<<endl;
    }
    else
    {
        data[top+1]=value;
        top++;
    }
}
void int_stack::pop()
{
    if(top==-1)
    {
        cout<<"stack underflow !!!"<<endl;
    }
    else
    {
        top--;
    }
}
void int_stack::display()
{
    cout<<endl;
    for(int i=0;i<=top;i++)
    {
        cout<<data[i]<<endl;
    }
}
int int_stack::last_value()
{
    if(top > -1)
        return data[top];
}
class string_stack
{
    //fields
private:
    public :string data[30];
    int top;
    //methods
public:
    string_stack();//constructor
    void push(string value);//add
    void pop();//remove
    void display();//show data
    string last_value();
};
string_stack::string_stack()
{
    top=-1;
}
void string_stack::push(string value)
{
    if(top==29)
    {
        cout<<"stack overflow !!!"<<endl;
    }
    else
    {
        data[top+1]=value;
        top++;
    }
}
void string_stack::pop()
{
    if(top==-1)
    {
        cout<<"stack underflow !!!"<<endl;
    }
    else
    {
        top--;
    }
}
void string_stack::display()
{
    //cout<<endl;
    for(int i=0;i<=top;i++)
    {
        cout<<data[i];
    }
}
string string_stack::last_value()
{
    if(top > -1)
        return data[top];
        else
            return "";
}
class char_stack
{
    //fields
private:
    public :char data[30];
    int top;
    //methods
public:
    char_stack();//constructor
    void push(char value);//add
    void pop();//remove
    void display();//show data
    char last_value();
};
char_stack::char_stack()
{
    top=-1;
}
void char_stack::push(char value)
{
    if(top==29)
    {
        cout<<"stack overflow !!!"<<endl;
    }
    else
    {
        data[top+1]=value;
        top++;
    }
}
void char_stack::pop()
{
    if(top==-1)
    {
        cout<<"stack underflow !!!"<<endl;
    }
    else
    {
        top--;
    }
}
void char_stack::display()
{
    //cout<<endl;
    for(int i=0;i<=top;i++)
    {
        cout<<data[i];
    }
}
char char_stack::last_value()
{
    if(top > -1)
        return data[top];
}
int main()
{
   string input[30];
   string result;
   int i=0;
   cout<<"Enter mathimatic operation (press q to continue) :"<<endl;
   //reading input from user
   for(;i<30;i++)
   {
       cin>>input[i];
       if(input[i]=="q")
       {
           i--;
           break;
       }

   }
   //display (input)
   for(int j=0;j<=i;j++)
        cout<<input[j];
   cout<<endl;
   result = convert_infix_to_postfix(input,i);
   cout<<result;
   calculate_postfix_value(result);
   return 0;

}
string convert_infix_to_postfix(string input[],int length)
{
    //variable declaration
    string_stack ss;
    string result;
    for(int i=0;i<=length;i++)
    {
        string input_va= input[i];
        if(input_va=="*"||input_va=="/")
        {
            while(ss.last_value()=="*"||ss.last_value()=="/"||ss.last_value()=="^")
            {
                result += ss.last_value();
                ss.pop();
            }
            ss.push(input_va);
        }
        else if (input_va=="^")
        {
            ss.push(input_va);
        }
        else if (input_va=="(")
        {
            ss.push(input_va);
        }
        else if(input_va=="+"||input_va=="-")
        {
            while(ss.top > -1 && ss.last_value() != "(")
            {
                result +=ss.last_value();
                ss.pop();
            }
            ss.push(input_va);

        }
        else if(input_va==")")
        {
            while(ss.last_value()!="(" && ss.top >= 0)
            {
                result +=ss.last_value();
                ss.pop();
            }
            if(ss.last_value() == "(")
                ss.pop();
        }
        else
        {
           result +=input_va;
        }
    }
    while(ss.top >= 0)
    {
        result +=ss.last_value();
        ss.pop();
    }
    return result;
}
void calculate_postfix_value(string post)
{
    int_stack values;
    float a,b,result;
    int sizee = get_length(post);
    for(int i=0;i<sizee;i++)
    {
        if(post[i]== '+' || post[i]=='-' || post[i]=='/' || post[i]=='*' ||post[i]=='^')
        {
            switch(post[i])
            {
            case '+':
                a=values.last_value();
                values.pop();
                b=values.last_value();
                values.pop();
                result = a+b;
                values.push(result);
                break;
            case '-':
                a=values.last_value();
                values.pop();
                b=values.last_value();
                values.pop();
                result = b-a;
                values.push(result);
                break;
            case '*':
                a=values.last_value();
                values.pop();
                b=values.last_value();
                values.pop();
                result = b*a;
                values.push(result);
                break;
            case '/':
                a=values.last_value();
                values.pop();
                b=values.last_value();
                values.pop();
                result = b/a;
                values.push(result);
                break;
            case '^':
                a=values.last_value();
                values.pop();
                b=values.last_value();
                values.pop();
                //result = b^a;
                values.push(result);
                break;
            }
        }
        else
        {
            values.push(post[i]-48);
        }
    }
    cout<<"\n*** "<<result<<" ***"<<endl;
}
int get_length(string s)
{
    int i;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
}
