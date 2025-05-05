#include <iostream>
#include <cstring>
#define max 10
using namespace std;

struct dict {
    char name[20];
    long int mn;
    int chain;

    dict() {
        strcpy(name, "-");
        mn = 0;
        chain = -1;
    }
};

class Hash {
    dict arr[max];

public:
    int hashFun(long int a) {
        return (a % 10);
    }

    void Insert() {
        dict S;
        cout << "Enter name and mobile no" << endl;
        cin >> S.name >> S.mn;
        int index;
        index = hashFun(S.mn);
        int start = index;

        if (arr[index].mn == 0) {
            arr[index] = S;
        } 
    else 
        {
            int prev = index;
            while (arr[index].mn != 0) {
                index = (index + 1) % max;
                if (index == start) {
                    cout << "Hash table full";
                    break;
                          }
                if (arr[prev].chain != -1) {
                    prev = arr[prev].chain;
                }
            }
            arr[index] = S;
            arr[prev].chain = index;
        }
    }

    void Display() {
        for (int i = 0; i < max; i++) {
            cout << i << "  " << arr[i].name << "   " << arr[i].mn << "   " << arr[i].chain << endl;
        }
    }
};

int main() {
    Hash h;
    int choice;
    do {
        cout << "Please enter your choice!!" << endl;
        cout << "1.insert 2.display" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            int n;
            cout << "Enter how many values you want to insert" << endl;
            cin >> n;
            for (int i = 0; i < n; i++) {
                h.Insert();
            }
            break;
        case 2:
            h.Display();
            break;
        default:
            cout<<"invalid choice!!";
            break;
        }
    } while (choice != 0);

    return 0;
}
