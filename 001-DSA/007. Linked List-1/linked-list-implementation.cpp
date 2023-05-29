/* Single Linked List implementation :
 *
 * 1. insert and delete from head, tail and middle by index : 6 functions
 * 2. reverse iterative and recursive : 2 function
 * 3. access element by index and print/traverse the linked list : 2 function
 *
 * */
#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int data;
    struct node *next;
};

int len = 0;

void insertAtHead(node* &head, int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL; 

    if(head) {
        newNode->next = head;
    }

    head = newNode;
    ++len;
    return;
}

void deleteFromHead(node* &head) {
    if(!head) {
        printf("List is empty\n");
        return;
    }  
    if(!head->next) {
        head = nullptr;
        --len;
        return;
    }

    if(!head->next) {
        head->next = nullptr;
        --len;
        return;
    }
    node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    --len;
    return;
}

void insertAtEnd(node* &head, int const &data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;

    if(!head) {
        head = newNode;
        len++;
        return;
    } else {
        node *temp = head;
        while(temp->next) {
            temp = temp->next;
        }

        temp->next= newNode;
        len++;
        return;
    }
}

void deleteFromEnd(node* &head) {
    if(!head) {
        printf("List is empty\n");
        return;
    } 
    if(!head->next) {
        head = nullptr;
        --len;
        return;
    }
    node *temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    temp2->next = nullptr;
    delete temp2;
    --len;
    return;
}

// assumption : 0 based indexing
void insertAtMiddle(node* &head, int const &data, int const &idx) {
    if(idx < 0 || idx > len) {
        cout << len << endl;
        printf("Invalid Index!!\n");
        return;
    }

    if(!idx) {
        insertAtHead(head, data);
        return;
    }

    if(idx == len) {
        insertAtEnd(head, data);
        return;
    }

    node *temp = head;
    for(int i=0; i<idx-1; i++) {
        temp = temp->next;
    }
    
    node *newNode = new node;
    newNode->next = nullptr;
    newNode->data = data;

    newNode->next= temp->next;
    temp->next= newNode;
    ++len;
    return;
}

void deleteFromMiddle(node* &head, int const &idx) {
    if(!head) {
        printf("List is empty!!\n");
        return;
    }
    if(idx < 0 || idx >= len) {
        printf("Invalid Index!!\n");
        return;
    }

    if(!idx) {
        deleteFromHead(head);
        return;
    }

    if(idx == len-1) {
        deleteFromEnd(head);
        return;
    }

    node *temp = head;
    for(int i=0; i<idx-1; i++) {
        temp = temp->next;
    }

    node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = nullptr;
    delete temp2;
    --len;
}

void reverseItr(node* &head) {

    if(!head || !head->next)    return;   

    node *prev = nullptr, *next = nullptr, *curr = head;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return;
}

node* reverseRec(node* head, node* ptr) {
    if(!ptr->next)  return ptr;

    head = reverseRec(head, ptr->next);
    ptr->next->next = ptr;
    ptr->next = nullptr;
    return head;
}

node* getNode(node* const &head, int const &idx) {
    if(!head) {
        printf("Empty List!!\n");
        return nullptr;
    }
    if(idx < 0 || idx >= len) {
        printf("Invalid Index!!\n");
        return nullptr;
    }

    node *temp = head;
    for(int i=0; i<idx; i++) {
        temp = temp->next;
    }

    return temp;
}

void printList(node* const &head) {
    node *temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int main(void) {
    node *head = NULL;
    int response;
        int n;
        printf("Enter the number of element: ");
        scanf("%d", &n);

        int data;
        printf("Inserting at head\n");
        for(int i=0; i<n; i++) {
            printf("Enter element-%d: ", i+1);
            scanf("%d", &data);
            insertAtHead(head, data);
            printList(head);
        }

        printf("\nSize: %d\nLinked List: ", len);
        printList(head);

    do {

        // printf("\nDelete from head\n");
        // for(int i=0; i<=n; i++) {
        //     deleteFromHead(head);
        //     printList(head);
        // }

        // printf("\nSize : %d\nLinked List: ", len);
        // printList(head);

        // printf("Enter the number of element: ");
        // scanf("%d", &n);

        // printf("Inserting at tail\n");
        // for(int i=0; i<n; i++) {
        //     printf("Enter element-%d: ", i+1);
        //     scanf("%d", &data);
        //     insertAtEnd(head, data);
        //     printList(head);
        // }

        // printf("\nSize : %d\nLinked List: ", len);
        // printList(head);

        // printf("\nDelete from tail\n");
        // for(int i=0; i<=n; i++) {
        //     deleteFromEnd(head);
        //     printList(head);
        // }

        // printf("\nSize : %d\nLinked List: ", len);
        // printList(head);

        // reverse list
        reverseItr(head);
        printList(head);
        head = reverseRec(head, head);
        printList(head);

        //insert at middle, by index, indexing starts from zero
        int idx, data;
        printf("Insert in middle, Enter the index and data : "); 
        scanf("%d %d", &idx, &data);

        insertAtMiddle(head, data, idx);
        printList(head);

        // delete from middle
        printf("Delete From middle, index : ");
        scanf("%d", &idx);
        deleteFromMiddle(head, idx);
        printList(head);


        printf("Response? ");
        scanf("%d", &response);
    } while(response);

    return 0;
}