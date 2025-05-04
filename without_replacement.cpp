#include <iostream>
#include <string.h>
#define max 10
using namespace std;

struct node {
    char name[15];
    long int mobno;
    int chain;

    node() {
        strcpy(name, "-");
        mobno = 0;
        chain = -1;
    }
};

class hasht {
    node ht[max];
public:
    int hashfun(long int);
    void insert();
    void display();
    void search();
    void del();
};

int hasht::hashfun(long int num) {
    return (num % max);
}

void hasht::insert() {
    node S;
    cout << "Enter name and mobile number of a person:\n";
    cin >> S.name >> S.mobno;

    int ind = hashfun(S.mobno);
    if (ht[ind].mobno == 0) {
        ht[ind] = S;
    } else {
        int prev = ind;
        while (ht[ind].mobno != 0) {
            ind = (ind + 1) % max;
        }
        ht[ind] = S;

        // Maintain chain from prev to current
        while (ht[prev].chain != -1) {
            prev = ht[prev].chain;
        }
        ht[prev].chain = ind;
    }
}

void hasht::display() {
    cout << "\nIndex\tName\t\tMobile Number\tChain\n";
    for (int i = 0; i < max; i++) {
        cout << i << "\t" << ht[i].name << "\t\t" << ht[i].mobno << "\t\t" << ht[i].chain << endl;
    }
}

void hasht::search() {
    long int num;
    cout << "Enter the mobile number to search: ";
    cin >> num;

    int ind = hashfun(num);
    while (ind != -1) {
        if (ht[ind].mobno == num) {
            cout << "Mobile number found at index: " << ind << endl;
            cout << "Name: " << ht[ind].name << ", Mobile: " << ht[ind].mobno << endl;
            return;
        }
        ind = ht[ind].chain;
    }
    cout << "Mobile number not found.\n";
}

void hasht::del() {
    long int num;
    cout << "Enter the mobile number to delete: ";
    cin >> num;

    int ind = hashfun(num), prev = -1;

    while (ind != -1) {
        if (ht[ind].mobno == num) {
            // Case: End of chain
            if (ht[ind].chain == -1) {
                strcpy(ht[ind].name, "-");
                ht[ind].mobno = 0;
                if (prev != -1)
                    ht[prev].chain = -1;
                cout << "Record deleted.\n";
                return;
            }
            // Case: Has chain - move next into current
            int next = ht[ind].chain;
            ht[ind] = ht[next];
            strcpy(ht[next].name, "-");
            ht[next].mobno = 0;
            ht[next].chain = -1;
            cout << "Record deleted.\n";
            return;
        }

        prev = ind;
        ind = ht[ind].chain;
    }
    cout << "Record not found.\n";
}

int main() {
    int cho;
    hasht h;
    char a;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Search\n4. Delete\n5. Exit\nEnter your choice: ";
        cin >> cho;

        switch (cho) {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.search();
                break;
            case 4:
                h.del();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> a;

    } while (a == 'y' || a == 'Y');

    return 0;
}