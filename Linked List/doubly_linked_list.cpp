#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE *next;
    NODE *prev;
};
NODE *head = NULL;
void insertAtBeg()
{
    NODE *new_node = new NODE;

    cout << "Enter the data to be inserted:";
    cin >> new_node->data;

    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL)
    {
        head->prev = new_node;
    }
    head = new_node;
}

void insertAtEnd()
{
    NODE *new_node = new NODE;
    cout << "Enter the data to be inserted:";
    cin >> new_node->data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        NODE *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insertAtIndex()
{
    NODE *new_node = new NODE;
    cout << "Enter the data to be inserted:";
    cin >> new_node->data;
    new_node->next = NULL;
    new_node->prev = NULL;

    cout << "Enter the index:";
    int index;
    cin >> index;
    if (head == NULL)
    {
        if (index == 0)
        {
            head = new_node;
            cout << "Added!" << endl;
        }
        else
        {
            cout << "Invalid index!" << endl;
        }
    }
    else
    {
        NODE *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Invalid Index!" << endl;
                return;
            }
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
        cout << "Added!" << endl;
    }
}

void deleteAtBeg()
{
    if (head == NULL)
    {
        cout << "The list is empty!" << endl;
    }

    else
    {
        NODE *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "The list is empty!" << endl;
    }

    else
    {
        NODE *temp = head;
        NODE *prev = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (head->next == NULL)
        {
            head = NULL;
        }
        prev->next = NULL;
        delete temp;
    }
}

void deleteAtIndex()
{
    if (head == NULL)
    {
        cout << "The list is empty!" << endl;
    }
    else if (head->next == NULL)
    {
        cout << "Enter the index:";
        int index;
        cin >> index;
        if (index == 0)
        {
            NODE *temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            cout << "Invalid index!" << endl;
            return;
        }
    }
    else
    {
        cout << "Enter the index:";
        int index;
        cin >> index;
        NODE *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Invalid index!" << endl;
                return;
            }
        }

        NODE *prev = temp->prev;
        NODE *next = temp->next;
        if (index == 0)
        {
            head = next;
        }
        else
        {
            prev->next = next;
        }
        if (next != NULL)
        {
            next->prev = prev;
        }
        delete temp;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        NODE *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }
}

int main()
{

    cout << "Menu:" << endl;
    cout << "1. Insert item at the beginning." << endl;
    cout << "2. Insert item at the end." << endl;
    cout << "3. Insert item at any index." << endl;
    cout << "4. Delete item at the beginning." << endl;
    cout << "5. Delete item at the end." << endl;
    cout << "6. Delete item at any index." << endl;
    cout << "7. Display the list." << endl;
    cout << "8. Exit." << endl;

    int menu;
    while (true)
    {
        cout << "Enter the menu choice:";
        cin >> menu;

        switch (menu)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtIndex();
            break;
        case 4:
            deleteAtBeg();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtIndex();
            break;
        case 7:
            display();
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "Invalid Choice! Choose again." << endl;
            break;
        }
    }
    return 0;
}
