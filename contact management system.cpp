#include <iostream>
using namespace std;

class Contact{
public:
    string name;
    string email;
    int phone;
    Contact* next;
};

void addContact(Contact* &head, string name, string email, int phone){
    Contact* newContact=new Contact{name, email, phone, NULL};
    if(!head){
        head=newContact;
        cout<<"Contact added as the first entry.\n\n";
        return;
    }
    Contact* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newContact;
    cout<<"Contact added successfully.\n\n";
}

void display(Contact*& head){
    if(!head){
        cout<<"No contact was found.\n\n";
        return;
    }
    Contact* temp=head;
    cout<<"\n--- Contact List ---\n\n";
    while(temp){
        cout<<"Name : "<<temp->name<<endl;
        cout<<"Phone: "<<temp->phone<<endl;
        cout<<"Email: "<<temp->email<<endl<<endl;
        temp=temp->next;
    }
}

void search(Contact*& head, string name){
    Contact* temp=head;
    while(temp){
        if(temp->name==name){
            cout<<"\nContact Found:\n";
            cout<<"Name : "<<temp->name<<endl;
            cout<<"Phone: "<<temp->phone<<endl;
            cout<<"Email: "<<temp->email<<endl<<endl;
            return;
        }
        temp=temp->next;
    }

    cout<<"Contact not found.\n\n";
}

void deleteContact(Contact*& head, string name){
    if(!head){
        cout<<"No contacts to delete.\n\n";
        return;
    }
    if(head->name==name){
        Contact* toDelete=head;
        head=head->next;
        delete toDelete;
        cout<<"Contact deleted.\n\n";
        return;
    }
    Contact* temp=head;
    while(temp->next && temp->next->name != name){
        temp=temp->next;
    }
    if(temp->next){
        Contact* toDelete=temp->next;
        temp->next=temp->next->next;
        delete toDelete;
        cout<<"Contact deleted.\n\n";
    } 
	else{
        cout<<"Contact not found.\n\n";
    }
}

int main(){
    Contact* head=NULL;
    int choice;
    string name, email;
    int phone;

    do{
        cout<<"----------------------------\n";
        cout<<"1. Add Contact\n";
        cout<<"2. Display Contacts\n";
        cout<<"3. Search Contact\n";
        cout<<"4. Delete Contact\n";
        cout<<"5. Exit\n";
        cout<<"----------------------------\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout<<"\nEnter name : ";
                getline(cin, name);
                cout<<"Enter email: ";
                getline(cin, email);
                cout<<"Enter phone: ";
                cin >> phone;
                cin.ignore();
                addContact(head, name, email, phone);
                break;

            case 2:
                display(head);
                break;

            case 3:
                cout<<"\nEnter name to search: ";
                getline(cin, name);
                search(head, name);
                break;

            case 4:
                cout<<"\nEnter name to delete: ";
                getline(cin, name);
                deleteContact(head, name);
                break;

            case 5:
                cout<<"\nGoodbye!\n";
                break;

            default:
                cout<<"\nInvalid choice. Please try again.\n\n";
        }
    }
	while(choice!=5);
    return 0;
}
