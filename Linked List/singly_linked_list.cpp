#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE *next;
};
NODE *head;
void insertAtBeg()
{
    NODE *new_node = new NODE;

    cout << "Enter the data to be inserted:";
    cin >> new_node->data;
    new_node->next = NULL;

    new_node->next = head;
    head = new_node;
}

void insertAtEnd()
{
    NODE *new_node = new NODE;
    cout << "Enter the data to be inserted:";
    cin >> new_node->data;
    new_node->next = NULL;

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
    }
}

void insertAtIndex()
{
    NODE *new_node = new NODE;
    cout << "Enter the data to be inserted:";
    cin >> new_node->data;
    new_node->next = NULL;

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
            cout << "Index is invalid!" << endl;
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
                cout << "Index is invalid!" << endl;
                return;
            }
        }
        new_node->next = temp->next;
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
        delete temp;
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "The list is empty!" << endl;
    }
    else if (head->next == NULL)
    {
        NODE *temp = head;
        head = NULL;
        delete temp;
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
        prev->next = temp->next;
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
        NODE *prev;
        for (int i = 0; i < index; i++)
        {
            prev = temp;
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Invalid index!" << endl;
                return;
            }
        }
        if (index == 0)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
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
        NODE *temp_head = head;
        while (temp_head != NULL)
        {
            cout << temp_head->data << " -> ";
            temp_head = temp_head->next;
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
