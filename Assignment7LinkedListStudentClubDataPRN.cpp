#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int prn, rollno;
    char name[50];
    node *next;
};

class info {
private:
    node *s = nullptr, *head1 = nullptr, *temp1 = nullptr,
         *head2 = nullptr, *temp2 = nullptr,
         *head = nullptr, *temp = nullptr;
    int b, c, i, j, ct;
    char a[20];

public:
    node *create();
    void insertp();
    void insertm();
    void delm();
    void delp();
    void dels();
    void display();
    void count();
    void concat();
};

node *info::create() {
    node *p = new node;
    cout << "\nEnter name of student: ";
    cin >> a;
    strcpy(p->name, a);
    cout << "\nEnter PRN of student: ";
    cin >> b;
    p->prn = b;
    cout << "\nEnter roll number of student: ";
    cin >> c;
    p->rollno = c;
    p->next = nullptr;
    return p;
}

void info::insertm() {
    node *p = create();
    if (head == nullptr) {
        head = p;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void info::insertp() {
    node *p = create();
    p->next = head;
    head = p;
}

void info::display() {
    if (head == nullptr) {
        cout << "\nLinked list is empty." << endl;
    } else {
        temp = head;
        cout << "\n PRN Roll No Name" << endl;
        cout << " --------------------------" << endl;
        while (temp != nullptr) {
            cout << " " << temp->prn;
            cout << " " << temp->rollno;
            int nameLength = strlen(temp->name);
            int spaces = 14 - nameLength;
            cout << string(spaces, ' ') << temp->name << endl;
            temp = temp->next;
        }
    }
}

void info::delm() {
    int m;
    cout << "\nEnter the PRN number of the student whose data you want to delete: ";
    cin >> m;
    temp = head;
    s = nullptr;
    while (temp != nullptr && temp->prn != m) {
        s = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "\nMember not found." << endl;
        return;
    }
    if (s == nullptr) {
        head = temp->next;
    } else {
        s->next = temp->next;
    }
    delete temp;
}

void info::delp() {
    if (head == nullptr) {
        cout << "\nList is empty." << endl;
        return;
    }
    temp = head;
    head = head->next;
    delete temp;
}

void info::dels() {
    if (head == nullptr) {
        cout << "\nList is empty." << endl;
        return;
    }
    temp = head;
    if (temp->next == nullptr) {
        delete temp;
        head = nullptr;
        return;
    }
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void info::count() {
    temp = head;
    ct = 0;
    while (temp != nullptr) {
        ct++;
        temp = temp->next;
    }
    cout << "\nCount of members is: " << ct << endl;
}

void info::concat() {
    int k, j;
    cout << "\nEnter number of members in list1: ";
    cin >> k;
    head1 = nullptr;
    for (i = 0; i < k; i++) {
        insertm();
        if (head1 == nullptr) {
            head1 = head;
        }
    }
    head = nullptr;
    cout << "\nEnter number of members in list2: ";
    cin >> j;
    head2 = nullptr;
    for (i = 0; i < j; i++) {
        insertm();
        if (head2 == nullptr) {
            head2 = head;
        }
    }
    if (head1 == nullptr) {
        head1 = head2;
    } else {
        temp1 = head1;
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        temp1->next = head2;
    }
    temp2 = head1;
    cout << "\nConcatenated List Members: " << endl;
    while (temp2 != nullptr) {
        cout << " " << temp2->prn << " " << temp2->rollno << " " << temp2->name << endl;
        temp2 = temp2->next;
    }
}

int main() {
    info s;
    int choice;
    char cont;
    do {
        cout << "\nWelcome to Pinnacle Club !" << endl;
        cout << "\nEnter your choice: " << endl;
        cout << "1. To insert president" << endl;
        cout << "2. To insert member" << endl;
        cout << "3. To insert secretary" << endl;
        cout << "4. To delete president" << endl;
        cout << "5. To delete member" << endl;
        cout << "6. To delete secretary" << endl;
        cout << "7. To display data" << endl;
        cout << "8. To count members" << endl;
        cout << "9. To concatenate two lists" << endl;
        cin >> choice;
        switch (choice) {
            case 1: s.insertp(); break;
            case 2: s.insertm(); break;
            case 3: s.insertm(); break;
            case 4: s.delp(); break;
            case 5: s.delm(); break;
            case 6: s.dels(); break;
            case 7: s.display(); break;
            case 8: s.count(); break;
            case 9: s.concat(); break;
            default: cout << "Unknown choice." << endl;
        }
        cout << "\nDo you want to continue? Enter Y/y: ";
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');
    return 0;
}
