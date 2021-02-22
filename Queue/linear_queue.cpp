#include <iostream>
#define size 4
using namespace std;

int queue[size], rear = -1, front = -1;

void enqueue()
{
    if (rear >= size - 1)
    {
        cout << "Overflow!" << endl;
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
        }
        rear++;
        cout << "Enter the data:";
        int data;
        cin >> data;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Underflow!" << endl;
    }
    else
    {

        int data = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        cout << data << " was removed from queue." << endl;
    }
}

void display()
{

    cout << "Current Content of Queue is: ";
    if (front == -1 || front > rear)
    {
        cout << "Empty." << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "MENU:" << endl
         << "1. Enqueue" << endl
         << "2. Dequeue" << endl
         << "3. Display" << endl
         << "4. Exit" << endl;
    int menu_choice;
    while (1)
    {
        cout << "Enter Choice: ";
        cin >> menu_choice;

        switch (menu_choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice! Enter again." << endl;
            break;
        }
    }
    return 0;
}