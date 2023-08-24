#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

Node* merging(Node* l, Node* r) {
    if (!l)
        return r;
    if (!r)
        return l;

    Node* ans = NULL;
    if (l->data <= r->data) {
        ans = l;
        ans->next = merging(l->next, r);
    } else {
        ans = r;
        ans->next = merging(l, r->next);
    }
    return ans;
}

void spliting(Node* source, Node** first, Node** last) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *first = source;
    *last = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** header) {
    Node* head = *header;
    if (head == NULL || head->next == NULL)
        return;

    Node* first;
    Node* last;
    spliting(head, &first, &last);

    mergeSort(&first);
    mergeSort(&last);

    *header = merging(first, last);
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "N: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter " <<n<< " values: ";
    for (int i = 0; i <n; ++i) {
        int value;
        cin >> value;

        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    mergeSort(&head);
    cout << "Sorted list: ";
    printList(head);
    return 0;
}