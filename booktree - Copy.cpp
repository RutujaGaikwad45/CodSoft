#include<iostream>
using namespace std;
struct node {
    char label[50];
    int chcount;
    node *child[15];
    
};

class Booktree{
    
    node *root;
   public:
    Booktree() {
        root = NULL;
    }
    void create();
    void display();
};

void Booktree :: create() {
    int i,j,k;
    root = new node();
    cout<<"Enter the name of book : ";
    cin>>root -> label;
    cout<<"Enter the no.of chapters : ";
    cin>>root->chcount;
    for(int i = 0; i < root -> chcount; i++){
        cout<<"Enter the name of chapter "<< i + 1 <<":";
        cin>>root -> child[i] -> label;
        cout<<"no.of section in chapter "<< i + 1 <<":";
        cin>>root -> child[i] -> chcount;
        for(int j=0; j < root -> child[i] -> chcount; j++){
            cout<<"Enter the name of section "<< i + 1 <<":";
            cin>>root -> child[i] -> child[j] -> label;
            cout<<"Enter the no. of subsection in section "<< i + 1 <<":";
            cin>>root -> child[i] -> child[j] -> chcount;
            for(int k=0; k <root -> child[i] -> child[j] -> chcount; k++){
                cout<<"Enter the name of suubsection "<< i + 1 <<":";
                cin>>root -> child[i] -> child[j] -> child[k] -> label;
            }
        }
    }
}

void Booktree :: display() {
    cout<<"Name of book is : "<<root -> label<<endl;
    for(int i = 0; i < root -> chcount; i++){
        cout<< i + 1 <<".Chapter name is "<<root -> child[i] -> label<<endl;
    
       for(int j = 0; j < root -> child[i] -> chcount; j++){
            cout<< i + 1 <<".Section name is "<<root -> child[i] -> child[j] -> label<<endl;
         
           for(int k=0; k <root -> child[i] -> child[j] -> chcount; k++){
              cout<< i + 1 <<".Subsection name is "<<root -> child[i] -> child[j] -> child[k] -> label<<endl;
              }
        }
    }

}

int main() {
    Booktree b;
    int choice;
    do {
        cout << "Please enter your choice!!" << endl;
        cout << "1.create \n2.display"<< endl;
        cin >> choice;
        switch (choice) 
        {
        case 1:
           
                b.create();
                break;
        case 2:
               b.display();
               break; 
        default:
            cout<<"invalid choice!!";
            break;
        }
    } while (choice != 0);
    return 0;
}
