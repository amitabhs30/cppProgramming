#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
} *head = NULL;

void createRandomLL(int n)
{
    if (head != NULL)
    {
        bool ans;
        cout << "\nLL is already created. Do you want to add the existing LL? \n 1 for yes \t 0 for no\n";
        cin >> ans;
        if (!ans)
            return;
        else
        {
            for (int i = 0; i < n; i++)
            {
                int random = rand() % 50 + 1;
                node *temp = new node(random);
                node *trav = head;
                while (trav->next != NULL)
                {
                    trav = trav->next;
                }
                trav->next = temp;
            }
        }
        cout << endl
             << "Random LL created after existing LL Check!" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int random = rand() % 50 + 1;
        node *temp = new node(random);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *trav = head;
            while (trav->next != NULL)
            {
                trav = trav->next;
            }
            trav->next = temp;
        }
    }
    cout << endl
         << "Random LL created Check!" << endl;
}
void createLLWithLoop()
{
    cout << "Enter size of the LL with loop";
    int n;
    cin >> n;
    createRandomLL(n);
    node *curr = head;
    node *loopNode = head;
    int x = rand() % n;
    for (int i = 0; i <= x; i++)
    {
        loopNode = loopNode->next;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = loopNode;
    cout << "\nLoop added in this random LL \n";
}

void traverse()
{
    if (head != NULL)
    {
        node *curr = head;
        cout<<"\n";
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout<<"\n";
    }
    else
    {
        cout << endl
             << "\nlinkList not present with this head pointer\n";
    }
}

void insert(int x)
{
    node *curr = new node(x);
    if (head == NULL)
    {
        head = curr;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = curr;
    }
}
void insertAt(int pos, int x)
{
    node *temp = new node(x);
    if (head == NULL && pos == 1)
    {
        head = temp;
    }
    else if (head == NULL && pos > 1)
    {
        cout << "LL is not created till now";
    }
    else if (head != NULL && pos == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        node *curr = head;
        for (int i = 1; i < pos - 1 && curr->next != NULL; i++)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

node *search(int x)
{
    node *curr = head;
    node *prev = head;
    if (head != NULL)
    {
        while (curr->data != x && curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return ((curr->data == x) ? prev : NULL);
}

void del(int x)
{

    node *prev = search(x);
    if (prev != NULL)
    {
        cout << "Successfully Deleted ";
        if (head->data == x)
        {
            prev = head;
            cout << head->data << endl;
            head = prev->next;
            delete (prev);
        }
        else
        {
            cout << prev->next->data << endl;
            node *temp = prev->next;
            prev->next = temp->next;
            delete (temp);
        }
    }
    else
    {
        cout << "Item Not present in the linkList";
    }
}

void findMiddleElement()
{
    if (head == NULL)
    {
        cout << "LL is not present";
    }
    else if (head->next == NULL)
    {
        cout << head->data << " is the middle element";
    }
    else
    {
        node *fast = head;
        node *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << slow->data << " is the middle element\n";
    }
}
void findNthElementFromEnd(int n)
{
    node *first = head;
    if (head == NULL)
        return;
    for (int i = 0; i < n; i++)
    {
        if (first == NULL)
            return;
        first = first->next;
    }
    node *second = head;
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    cout << endl
         << second->data << endl;
}
void reverseLL()
{
    if (head == NULL)
    {
        cout << "LL is not created\n";
        return;
    }
    node *prev, *curr, *forward;

    prev = head;
    curr = head->next;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head->next = NULL;
    head = prev;
    cout << "LL is reversed!\n";
}
void reverseKnodes(int k)
{
    node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while (curr != NULL)
    {
        node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
            prevFirst->next = prev;
        prevFirst = first;
    }
    cout << "\ncontigious k nodes of LL are reversed!\n";
}
bool checkForLoop() // implementation of floyd's cycle detection algorithm.
{
    if (head == NULL)
    {
        return false;
    }
    node *fast = head, *slow = head;
    while (fast != NULL&&fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
void removeLoop()
{
    node *fast = head, *slow = head;
    while (fast->next != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    slow=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
    cout<<"\nSuccessfully removed the loop!";
}
void segregadeEvenOdd()
{
    if(head==NULL)
    {
        cout<<"\nNo LL is created\n";
        return;
    }
    node *Es=NULL,*Ee=NULL,*Os=NULL,*Oe=NULL,*curr;
    curr=head;
    while(curr!=NULL)
    {
        if((curr->data)%2)
        {
           if(Os==NULL) 
           {
             Os=curr;
             Oe=curr;  
           }
           else
           {
               Oe->next=curr;
               Oe=Oe->next;
           }
        }
        else
        {
            if(Es==NULL)
            {
                Es=curr;
                Ee=curr;
            }
            else
            {
                Ee->next=curr;
                Ee=Ee->next;
            }
        }        
        curr=curr->next;
    }
    Ee->next=Os;
    if(Oe!=NULL)
    Oe->next=NULL;
    head=Es;
    cout<<"\nSuccessfully segregated in even and odd elements!\n";
}
int main()
{
    int choice;
    while (1)
    {
        cout << endl
             << "Enter the operation to perform:" << endl
             << "99:To create a random LL of n nodes" << endl
             << "98:To create a random LL with a loop" << endl
             << "1:To insert a value in LL" << endl
             << "2:To insert at a particular position" << endl
             << "3:To print elements of LL" << endl
             << "4:To search for an item in the linkList" << endl
             << "5:To Delete an item from the linkList" << endl
             << "6:To find the middle element of the linkList" << endl
             << "7:To find the Nth element from the end" << endl
             << "8:To reverse the LL" << endl
             << "9:To reverse k-k nodes of the LL" << endl
             << "10:To segregate LL in even odd elements"<<endl
             << "0:To exit" << endl;
        cin >> choice;
        if (checkForLoop())
        {   bool ans;
            cout << "Your LL contains a loop and thus no operations can be performed.\n"
                 << "Do you want to remove this loop?\n 1 for yes \t 0 for no";
                 cin>>ans;
                 if(!ans)
                 {
                     cout<<"No operations can be performed, Good Bye!";
                     return 0;
                 }
                 else
                 {
                     removeLoop();
                     goto jump;
                 }
        }
        else
        {
            jump:
            switch (choice)
            {
            case 0:
                return 0;
            case 1:
                int n;
                cout << "Enter the value to insert";
                cin >> n;
                insert(n);
                break;
            case 2:
                int pos;
                cout << "Enter the position to insert";
                cin >> pos;
                cout << "Enter the value to insert";
                cin >> n;
                insertAt(pos, n);
                break;
            case 3:
                traverse();
                break;
            case 4:
                cout << "Enter the element to search";
                cin >> n;
                node *temp;
                temp = search(n);
                if (temp != NULL)
                    cout << "Data " << n << "Found at location " << &temp->next;
                else
                    cout << "Not Found in the LL";
                break;
            case 5:
                cout << "Enter the element to delete";
                cin >> n;
                del(n);
                break;
            case 6:
                findMiddleElement();
                break;
            case 7:
                cout << "Enter the position from the end";
                cin >> n;
                findNthElementFromEnd(n);
                break;
            case 8:
                reverseLL();
                break;
            case 9:
                cout << "Enter the value of k";
                cin >> n;
                reverseKnodes(n);
                break;
            case 10:
                segregadeEvenOdd();
                break;    
            case 98:
                createLLWithLoop();
                break;
            case 99:
                cout << "Enter the no of nodes";
                cin >> n;
                createRandomLL(n);
                break;
            default:
                cout << "Wrong option";
                break;
            }
        }
    }
    return 0;
}
