#include<iostream>
using namespace std;

struct node{
    char label[50];
    int chcount;
    node *child[15];

};

class BookTree{
    node *root;
    public:
    void display();
    void create();
    BookTree(){
        root=NULL;
    }
};

void BookTree::create(){
    int i,j,k;
    root = new node;
    cout<<"enter the name of book:";
    cin>>root->label;

    cout<<"\nHow many chapters:";
    cin>>root->chcount;
    for(i=0;i<root->chcount;i++){
        root->child[i]=new node;
        cout<<"enter the name of chapter "<<i+1<<":";
        cin>>root->child[i]->label;

        cout<<"How many sections: ";
        cin>>root->child[i]->chcount;

        for(j=0;j<root->child[i]->chcount;j++){
            root->child[i]->child[j]=new node;
            cout<<"Enter the name of section "<<j+1<<":";
            cin>>root->child[i]->child[j]->label;

            cout<<"\nHow many subsections:";
            cin>>root->child[i]->child[j]->chcount;

            for(k=0;k<root->child[i]->child[j]->chcount;k++){
                root->child[i]->child[j]->child[k]=new node;
                cout<<"Enter the name of subsection "<<k+1<<":";
                cin>>root->child[i]->child[j]->child[k]->label;
            }

        }
    }
}

void BookTree::display(){
    int i,j,k;
    cout<<"Name of book:"<<root->label<<endl;
    for(i=0;i<root->chcount;i++){
        cout<<"   Chapter "<<i+1<<": "<<root->child[i]->label<<endl;
        for(j=0;j<root->child[i]->chcount;j++){
            cout<<"      Section "<<j+1<<": "<<root->child[i]->child[j]->label<<endl;

            for(k=0;k<root->child[i]->child[j]->chcount;k++){
                cout<<"         Subsection "<<k+1<<": "<<root->child[i]->child[j]->child[k]->label<<endl;
            }
        }
    }
}
int main(){
    BookTree b;
    b.create();
    b.display();
    return 0;
}