#include<iostream>
#include<string.h>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
};
class Stack{
    node* s[20];
    int top=-1;
    public:
    void push(node* t){
        s[++top]=t;
    };
    node* pop(){
        return s[top--];
    };
    int isempty(){
        if(top==-1){
            return 1;
        }
        return 0;
    }
};
class ExpTree{
    char prefix[20];
    node* top=nullptr;  
    public:
    void expression(char prefix[]);
    void inorder(node* t){
        if(t==NULL){return;}
        inorder(t->left);
        cout<<t->data;
        inorder(t->right);
    }
    void postorder(node *tm){
        if(tm==NULL){return;}
        Stack s1,s2;
        s1.push(tm);
        while(!s1.isempty()){
            node* temp=s1.pop();
            s2.push(temp);
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
            while(!s2.isempty()){
                node* t=s2.pop();
                cout<<t->data;
            }
        }
    }

    void display(){
        cout<<"Display Postorder Sequence:";
        postorder(top);
        cout<<endl;
        cout<<"Display inorder Sequence:";
        inorder(top);
        cout<<endl;
        cout<<"Deleting Nodes From Tree"<<endl;
        DelTree(top);
        cout<<"Tree Deleted Sucessfully";
    }

    void DelTree(node* t){
        if(t==NULL){
            return;
        }
        DelTree(t->left);
        DelTree(t->right);
        cout<<t->data<<"  is deleted"<<endl;
        delete t;
    }
};

void ExpTree::expression(char prefix[]){
    Stack s1;
    node *d1,*d2;
    int len=strlen(prefix);
    for(int i=len;i>=0;i--){
        if(isalpha(prefix[i])){
            node *top=new node;
            top->left=NULL;
            top->right=NULL;
            top->data=prefix[i];
            s1.push(top);
        }else if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/'){
            d1=s1.pop();
            d2=s1.pop();
            node *top=new node;
            top->data=prefix[i];
            top->left=d1;
            top->right=d2;
            s1.push(top);
        }
    }
    top=s1.pop();
}


int main(){
    ExpTree t;
    char ch[20];
    cout<<"enter the expression"<<endl;
    cin>>ch;
    t.expression(ch);
    t.display();
}