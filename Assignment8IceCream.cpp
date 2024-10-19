#include<iostream>
using namespace std;

struct SLLNode* createSLL(int cnt, struct SLLNode *head);
void displaySLL(struct SLLNode *head);
void A_U_B();
void A_int_B();
void A_Min_B();
void B_Min_A();
void U_Min_A_U_B();

struct SLLNode {
    char data;
    struct SLLNode *next;
} *headU, *headA, *headB;

int main() {
    int i, no;
    cout << "\n\n\tHow many Linked Lists: ";
    cin >> no;
    headU = headA = headB = NULL;

    for(i = 1; i <= no; i++) {
        if(i == 1) {
            cout << "\n\n\tEnter 10 Students of SE Comp: ";
            headU = createSLL(10, headU);
            cout << "\n";
            displaySLL(headU);
        }    
        if(i == 2) {
            cout << "\n\n\tEnter 5 Students who like Vanilla Icecreme: ";            
            headA = createSLL(5, headA);
            cout << "\n";
            displaySLL(headA);
        }
        if(i == 3) {
            cout << "\n\n\tEnter 5 Students who like Butterscotch Icecreme: ";                  
            headB = createSLL(5, headB); 
            cout << "\n";
            displaySLL(headB);             
        }
    }

    cout << "\n\nInput Sets:------------------------";
    cout << "\n\nSet 'U': ";
    displaySLL(headU);
    cout << "\n\nSet 'A': ";
    displaySLL(headA);    
    cout << "\n\nSet 'B': ";
    displaySLL(headB);    

    cout << "\n\nOutput Sets:------------------------";    
    A_U_B();
    A_int_B();
    A_Min_B();
    B_Min_A();
    U_Min_A_U_B();

    cout << "\n\n";   
    return 0;
}

struct SLLNode* createSLL(int cnt, struct SLLNode *head) {
    int i;
    struct SLLNode *p, *newNode;
    
    for(i = 0; i < cnt; i++) {
        newNode = new(struct SLLNode);
        cout << "\n\tEnter Student Initial: ";    
        cin >> newNode->data;
        newNode->next = NULL;

        if(head == NULL) {             
            head = newNode;
            p = head;
        } else {
            p->next = newNode;
            p = p->next;
        }
    } 
    return head;
}

void displaySLL(struct SLLNode *head) {
    struct SLLNode *p = head;
    
    while(p != NULL) {
        cout << "  " << p->data;
        p = p->next;
    }
}

void A_U_B() {
    int i = 0, j;
    char a[10];   
    struct SLLNode *p = headA;
    struct SLLNode *q = headB;

    while(p != NULL && q != NULL) {
        if(p->data == q->data) {
            a[i++] = p->data;
            p = p->next;
            q = q->next; 
        } else {
            a[i++] = p->data;
            p = p->next;            
        }
    }

    if(p == NULL) {
        while(q != NULL) {
            a[i++] = q->data;
            q = q->next;            
        }
    }

    if(q == NULL) {
        while(p != NULL) {
            a[i++] = p->data;
            p = p->next;            
        }
    }

    cout << "\n\n\tSet A U B: ";
    for(j = 0; j < i; j++) {
        cout << " " << a[j];    
    }
}

void A_int_B() {
    int i = 0, j;
    char a[10];   
    struct SLLNode *p = headA;

    while(p != NULL) {
        struct SLLNode *q = headB;
        while(q != NULL) {
            if(p->data == q->data) {
                a[i++] = p->data;                       
            }
            q = q->next;
        }
        p = p->next;      
    }

    cout << "\n\n\tSet A ^ B: ";
    for(j = 0; j < i; j++) {
        cout << " " << a[j];        
    }
}

void A_Min_B() {
    int i = 0, j, flag;
    char a[10];   
    struct SLLNode *p = headA;

    while(p != NULL) {
        flag = 0;
        struct SLLNode *q = headB;

        while(q != NULL) {
            if(p->data == q->data) {
                flag = 1;                     
            }
            q = q->next;
        }

        if(flag == 0) {
            a[i++] = p->data;  
        }

        p = p->next;      
    }

    cout << "\n\n\tSet A - B: ";
    for(j = 0; j < i; j++) {
        cout << " " << a[j];
    }
}

void B_Min_A() {
    int i = 0, j, flag;
    char a[10];   
    struct SLLNode *q = headB;

    while(q != NULL) {
        flag = 0;
        struct SLLNode *p = headA;

        while(p != NULL) {
            if(q->data == p->data) {
                flag = 1;                     
            }
            p = p->next;
        }

        if(flag == 0) {
            a[i++] = q->data;  
        }

        q = q->next;      
    }

    cout << "\n\n\tSet B - A: ";
    for(j = 0; j < i; j++) {
        cout << " " << a[j];
    }
}

void U_Min_A_U_B() {
    int i = 0, j, flag;
    char a[10];   
    struct SLLNode *p = headU;

    while(p != NULL) {
        flag = 0;
        struct SLLNode *q = headA;
        struct SLLNode *r = headB;

        while(q != NULL) {
            if(p->data == q->data) {
                flag = 1;                     
            }
            q = q->next;
        }

        while(r != NULL) {
            if(p->data == r->data) {
                flag = 1;                     
            }
            r = r->next;
        }

        if(flag == 0) {
            a[i++] = p->data;  
        }

        p = p->next;      
    }

    cout << "\n\n\tSet U - (A U B): ";
    for(j = 0; j < i; j++) {
        cout << " " << a[j];
    }
}
