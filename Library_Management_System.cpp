#include<iostream>
#include<string>
using namespace std;

struct Node {
    string title;
    string author;
    int ISBN;
    bool isAvailable;
    string borrower;
    int checkoutDay;
    Node* next;

    Node(string T, string A, int n) {
        title = T;
        author = A;
        ISBN = n;
        isAvailable = true;
        borrower = "";
        checkoutDay = 0;
        next = NULL;
    }
};

class Library {
    Node* head;

    public:

    Library() {
        head = NULL;
    }

    void Add_Book(string Ti, string Au, int num) {

        Node* nn = new Node(Ti, Au, num);
        if(head == NULL) {
            head = nn;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = nn;
        cout<<"BOOK Added Successfully"<<endl;
    }

    void search(string s) {

        Node* temp = head;
        while(temp != NULL) {
            if(temp->title == s || temp->author == s || to_string(temp->ISBN) == s) {
                   cout<<temp->title<<"--"<<temp->author<<"--"<<temp->ISBN<<"--"<<(temp->isAvailable ? "Available" : "Issued")<<endl;
                   return;
            }
            temp = temp->next;
        }

        cout<<"Book Not FOUND"<<endl;
    }

    void Chkout(int isbn, string borower, int day) {
          Node* temp = head;
          while(temp != NULL) {
            if(temp->ISBN == isbn) {
                if(temp->isAvailable) {
                    temp->isAvailable = false;
                    temp->borrower = borower;
                    temp->checkoutDay = day;
                    cout<<"Book checkout to the "<<temp->borrower<<" Successfully"<<endl;
                }
                else {
                    cout<<"Book issued to "<<temp->borrower<<endl;
                }

                return;
            }

            temp = temp->next;
          }

          cout<<"Book with isbn "<<isbn<<"not FOUND"<<endl;
    }

    void Return(int isbn, int returnday) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->ISBN == isbn && !temp->isAvailable) {
                int days = returnday - temp->checkoutDay;
                if(days > 7) {
                    int fine = (days-7)*10;
                    cout<<"Fine of Rs. "<<fine<<" for late number of days = "<<(days-7)<<endl;
                }
                else {
                    cout<<"Book returned on Time"<<endl;
                }

                temp->isAvailable = true;
                temp->borrower = "";
                temp->checkoutDay = 0;
                return;
            }
            temp = temp->next;
        }

        cout<<"Book with ISBN "<<isbn<<" Not FOUND"<<endl;
    }

    void Display() {

        if(head == NULL) {
            cout<<"Library is Empty"<<endl;
            return;
        }

        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->title<<"-"<<temp->author<<"-"<<temp->ISBN<<"-"<<(temp->isAvailable ? "Available" : "Issued to " + temp->borrower)<<"--->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }
};

int main() {

    Library Li;
    
    while(true) {
        cout<<"----------- Library Management System ------------------"<<endl;
        cout<<"A :  Add Book"<<endl;
        cout<<"S :  Search Book"<<endl;
        cout<<"D :  Display Book"<<endl;
        cout<<"C :  Checkout Book"<<endl;
        cout<<"R :  Returned Book"<<endl;
        cout<<"E :  Exit"<<endl;
        char ch;
        cin>>ch;

        if(ch == 'A') {
            string Ti, Au;
            getline(cin, Ti);
            getline(cin, Au);
            int num;

            cout<<"Enter he Title of the Book"<<endl;
            cin>>Ti;
            cout<<"Enter the author of the Book"<<endl;
            cin>>Au;
            cout<<"Enter the ISBN of the Book"<<endl;
            cin>>num;

            Li.Add_Book(Ti, Au, num);
        }
        else if(ch == 'S') {
            string s;
            getline(cin, s);

            cout<<"Enter the Title/Author/ISBN of the Book"<<endl;
            cin>>s;

            Li.search(s);
        }
        else if(ch == 'D') {
            Li.Display();
        }
        else if(ch == 'C') {
            int isbn, day;
            string borower;
            getline(cin, borower);

            cout<<"Enter the ISBN of the BOOK"<<endl;
            cin>>isbn;
            cout<<"Enter the borrower name for the Book"<<endl;
            cin>>borower;
            cout<<"Enter the day on which Book Borrowed"<<endl;
            cin>>day;
            Li.Chkout(isbn, borower, day);
        }
        else if(ch == 'R') {
            int isbn, returnday;
            cout<<"Enter the ISBN of the BOOK"<<endl;
            cin>>isbn;
            cout<<"Enter the return day"<<endl;
            cin>>returnday;
            Li.Return(isbn, returnday);
        }
        else {
            cout<<"-----------------  EXIT ----------------------"<<endl;
            break;
        }
    }


    return 0;
}