#include <iostream>
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int pil, value;
struct Node
{
    int data, value;
    struct Node *next;
}*head = NULL;

int main()
{
    cout<<"Masukkan data: "<<endl;
    cin>>value;
    cout<<"\n\n1. Mendambah data"<<endl;
    cout<<"2. Mendambah data"<<endl;
    cout<<"3. Keluar"<<endl;
    cout<<"masukkan pilihan :";
    cin>>pil;
    switch(pil)
    {
    /*--------------------------------------------------------------------------------*/
    case 1:
        cout<<"\nMendambah data"<<endl;
        cout<<"1. Depan"<<endl;
        cout<<"2. Belakang"<<endl;
        cout<<"masukkan pilihan :";
        cin>>pil;
        switch(pil)
        {
        case 1:
        {
            struct Node *newNode;
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            if(head == NULL)
            {
                newNode->next = NULL;
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        break;
        case 2:
        {
            struct Node *newNode;
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = NULL;
            if(head == NULL)
                head = newNode;
            else
            {
                struct Node *temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
        }
        break;
        default:
            break;
        }

        break;
    /*--------------------------------------------------------------------------------*/
    case 2:
    {
        cout<<"\nMenghapus data"<<endl;
        cout<<"1. Depan"<<endl;
        cout<<"2. Belakang"<<endl;
        cout<<"masukkan pilihan :";
        cin>>pil;
        switch(pil)
        {
        case 1:
        {
            if(head == NULL)
                cout<<"\n\nData Kosong\n";
            else
            {
                struct Node *temp = head;
                if(head->next == NULL)
                {
                    head = NULL;
                    free(temp);
                }
                else
                {
                    head = temp->next;
                    free(temp);
                }
            }
        }
        break;
        case 2:
        {
            if(head == NULL)
            {
                cout<<"\n\nData Kosong\n";
            }
            else
            {
                struct Node *temp1 = head,*temp2;
                if(head->next == NULL)
                    head = NULL;
                else
                {
                    while(temp1->next != NULL)
                    {
                        temp2 = temp1;
                        temp1 = temp1->next;
                    }
                    temp2->next = NULL;
                }
                free(temp1);
            }
        }
        break;
        default:
            break;
        }
    }
    break;
    case 3:
        return 0;
    default:
        return main();
        break;
    }
    {
        if(head == NULL)
        {
            cout<<"\nData Kosong\n";
        }
        else
        {
            struct Node *temp = head;
            cout<<"\n\n";
            while(temp->next != NULL)
            {
                cout<<" "<<temp->data;
                temp = temp->next;
            }
            cout<<" ",temp->data;
        }
    }
    return main();
}
