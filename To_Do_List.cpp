//Description :- Create a simple inventory management system that allows users to add items, display the list of items and search for
//items by name or ID.
//Implement the necessary methods to handle these operations.

#include<iostream>
using namespace std;

struct Node {

    string item;
    bool status;
    Node* next;

    Node(string i, bool sta) {
        item = i;
        next = NULL;
        status = sta;
    }
};

class To_Do_List {
    public:

    Node* head;

    To_Do_List() {
        head = NULL;
    }

    void Add_Item(string s, bool st) {
       Node* nn = new Node(s, st);            //creating new node.
       if(head == NULL) {
         head = nn;                       //Adding node at head.
         return;
       }

       Node* temp = head;

       while(temp->next != NULL) {
         temp = temp->next;
       }

       temp->next = nn;                     //Adding node at the end.
       return;
    }

    void Display_List() {

        Node* temp = head;

        while(temp != NULL) {
            cout<<temp->item<<"---"<<(temp->status ? "Completed" : "Not Completed")<<"->";          //Display of nodes data.
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }

    void search(string s1) {
       
        Node* temp = head;

        while(temp != NULL) {
            if(temp->item == s1) {                           //Checking with node data "FOUND" OR "NOT FOUND"
                cout<<temp->item<<" item Found"<<endl;              
                return;
            }

            temp = temp->next;
        }

        cout<<s1<<" item not Found"<<endl;
    }

    void Delete(string s) {
        if(head == NULL) {
            cout<<"Nothing to Task the list is empty"<<endl;
            return;
        }

        if(head->item == s) {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete(temp);
            return;
        }

        Node* temp = head;
        
        while(temp != NULL) {
            if(temp->item == s) {
                
                    Node* tem = head;
                    while(tem->next != temp) {
                        tem = tem->next;
                    }

                    tem->next = tem->next->next;
                    delete(temp);
                    return;
                }

                temp = temp->next;
            }
        }
};

int main() {

    To_Do_List li;

    char choice;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "A: Add Task\n";
        cout << "D: Display All Tasks\n";
        cout << "S: Search Task by Name\n";
        cout << "Q: Delete Task by Name\n";
        cout << "E: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 'A' || choice == 'a') {
            int n;
            cout << "How many tasks do you want to add? ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                string task;
                bool status;
                cout << "Enter task name: ";
                cin >> task;
                cout << "Enter status (1 for Completed, 0 for Not Completed): ";
                cin >> status;
                li.Add_Item(task, status);
            }

        }
        else if(choice == 'D' || choice == 'd') {
            li.Display_List();

        }
        else if(choice == 'S' || choice == 's') {
            string name;
            cout << "Enter task name to search: ";
            cin >> name;
            li.search(name);

        }
        else if(choice == 'Q' || choice == 'q') {
            string name;
            cout << "Enter task name to delete: ";
            cin >> name;
            li.Delete(name);

        }
        else if(choice == 'E' || choice == 'e') {
            cout << "Exiting program.\n";
            break;

        }
        else {
            cout << "Invalid choice. Please enter A, D, S, Q, or E.\n";
        }
    }

    return 0;
}