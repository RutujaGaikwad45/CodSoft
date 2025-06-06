#include<iostream>
#include<string.h>
using namespace std;

struct node {
    char word[20], mean[50];
    node *left, *right;
    int ht;
};

class dict {
public:
    node* create(node *root);
    node* insert(node *root, char word[], char mean[]);
    void display(node*root);
    int height(node *);
    int BF(node *);
    node* deletion(node *, char *);
    node* RR(node *);
    node* LL(node *);
    node* RL(node *);
    node* LR(node *);
};

node* dict::create(node *root) {
    int n, i;
    char w[20], m[50];
    cout << "\n Enter total number of words:";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "\n Enter word " << i + 1 << " : ";
        cin >> w;
        cout << "\n Enter meaning : ";
        cin >> m;
        root = insert(root, w, m);
    }
    return root;
}

node* dict::insert(node *root, char w[], char m[]) {
    if (root == NULL) {
        root = new node;
        strcpy(root->word, w);
        strcpy(root->mean, m);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (strcmp(w, root->word) > 0) {
        root->right = insert(root->right, w, m);
        if (BF(root) == -2) {
            root = (strcmp(w, root->word) > 0) ? RR(root) : RL(root);
        }
    } else {
        root->left = insert(root->left, w, m);
        if (BF(root) == 2) {
            root = (strcmp(w, root->word) < 0) ? LL(root) : LR(root);
        }
    }
    root->ht = height(root);
    return root;
}

void dict::display(node*root) {
    if (root != NULL) {
        display(root->left);
        cout << "\n Node is:" << root->word << "-" << root->mean;
        display(root->right);
    }
}

int dict::height(node *root) {
    if (root == NULL) return 0;
    int lh = (root->left) ? 1 + root->left->ht : 0;
    int rh = (root->right) ? 1 + root->right->ht : 0;
    return (lh > rh) ? lh : rh;
}

int dict::BF(node *root) {
    if (root == NULL) return 0;
    int lh = (root->left) ? 1 + root->left->ht : 0;
    int rh = (root->right) ? 1 + root->right->ht : 0;
    return lh - rh;
}

node* dict::LL(node *T) {
    node *y = T->left;
    T->left = y->right;
    y->right = T;
    T->ht = height(T);
    y->ht = height(y);
    return y;
}

node* dict::RR(node *T) {
    node *y = T->right;
    T->right = y->left;
    y->left = T;
    T->ht = height(T);
    y->ht = height(y);
    return y;
}
  

node* dict::LR(node *T) {
    T->left = RR(T->left);
    return LL(T);
}

node* dict::RL(node *T) {
    T->right = LL(T->right);
    return RR(T);
}

node* dict::deletion(node *T, char *w) {
    if (T == NULL) {
        cout << "\n Word not found!";
        return T;
    }
    if (strcmp(w, T->word) > 0) {
        T->right = deletion(T->right, w);
        if (BF(T) == 2) {
            T = (BF(T->left) >= 0) ? LL(T) : LR(T);
        }
    } else if (strcmp(w, T->word) < 0) {
        T->left = deletion(T->left, w);
        if (BF(T) == 2) {
            T = (BF(T->right) <= 0) ? RR(T) : RL(T);
        }
    } else {
        if (T->right != NULL) {
            node *p = T->right;
            while (p->left != NULL) p = p->left;
            strcpy(T->word, p->word);
            strcpy(T->mean, p->mean);
            T->right = deletion(T->right, p->word);
            if (BF(T) == 2) {
                T = (BF(T->left) >= 0) ? LL(T) : LR(T);
            }
        } else return T->left;
    }
    T->ht = height(T);
    return T;
}

int main() {
    int ch;
    dict d;
    node *root = NULL;
    char w[20], m[50];
    cout << "\n Dictionary using avl tree";

    do {
        cout << "\n\n MENU:";
        cout << "\n1.Create \n2.Insert \n3.Delete\n4.Display \n5.Exit";
        cout << "\n Enter your choice:";
        cin >> ch;

        switch (ch) {
            case 1: root = d.create(root); break;
            case 2: cout << "\n Enter word:"; cin >> w;
                    cout << "\n Enter meaning: "; cin >> m;
                    root = d.insert(root, w, m);
                    break;
            case 3: cout << "\nEnter word to delete: "; cin >> w;
                    root = d.deletion(root, w);
                    break;
            case 4: d.display(root); break;
            case 5: break;
            default: cout << "\n Invalid choice!";
        }
    } while (ch != 5);

    return 0;
}
        