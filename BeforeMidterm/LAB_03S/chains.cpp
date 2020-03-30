#include <stdio.h>
#include <iostream>

using namespace std;

#define gc getchar_unlocked

void scan_integer(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = gc())
        ;
    if (c == '-')
    {
        neg = 1;
        c = gc();
    }
    for (; c > 47 && c < 58; c = gc())
    {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg)
        x = -x;
}

struct Node
{
    int data;
    int head;
    int tail;
    Node *prev = NULL;
    Node *next = NULL;
    Node(int data)
        : data(data) {}
};
void print_list(Node *header)
{
    Node *p = header;
    while (p != NULL)
    {
        if (p->prev != NULL)
            cout << " <- ";
        cout << p->data;
        if (p->next != NULL)
            cout << " -> ";

        p = p->next;
    }
}
Node *node[100002];
void reverse_line(Node *header)
{
    Node *tmp;
    Node *p = header;
    while (p != NULL)
    {
        tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = p->next;
    }
}
void reverse_node(Node *header)
{
    Node *p = header;
    Node *tmp = p->next;
    p->next = p->prev;
    p->prev = tmp;
}
void updateLast(Node *&curr, int &lastHead, int &lastTail)
{
    if (curr->head != 0)
    {
        if (curr->head != lastHead)
        {
            lastHead = curr->head;
        }
    }
    if (curr->tail != 0)
    {
        if (curr->tail != lastTail)
        {
            lastTail = curr->tail;
        }
    }
}
int main()
{
    for (int i = 1; i <= 100000; i++)
        node[i] = new Node(i);
    for (int i = 1; i <= 100000; i++)
    {
        node[i]->head = 0;
        node[i]->tail = 0;
        if (i > 1)
            node[i]->prev = node[i - 1];
        if (i < 100000)
            node[i]->next = node[i + 1];
    }

    int l, n, lastI = 0, tmp;
    scan_integer(l);
    scan_integer(n);
    for (int ll = 0; ll < l; ll++)
    {
        scan_integer(tmp);

        node[lastI + 1]->prev = NULL;
        node[lastI + 1]->head = 0;
        node[lastI + 1]->tail = lastI + tmp;

        node[lastI + tmp]->next = NULL;
        node[lastI + tmp]->head = 0;
        node[lastI + tmp]->tail = lastI + tmp;

        lastI += tmp;
    }

    Node *curr = node[1];
    curr->head = 1;
    Node *tmpp;
    int lastHead = curr->head;
    int lastTail = curr->tail;
    char cmd;
    for (int nn = 0; nn < n; nn++)
    {
        scanf(" %c", &cmd);
        updateLast(curr, lastHead, lastTail);
        if (curr->head == 0)
            curr->head = lastHead;
        switch (cmd)
        {
        case 'F':
            if (curr->next != NULL)
            {
                if (curr->next != NULL && curr->next->next == curr)
                    reverse_node(curr->next);
                curr = curr->next;
            }
            break;
        case 'B':
            if (curr->prev != NULL)
            {
                curr = curr->prev;
            }
            break;
        case 'C':
            int at;
            scan_integer(at);
            if (curr->next != NULL)
            {
                if (curr->next->next == curr)
                    reverse_node(curr->next);

                tmpp = curr->next;
                node[lastTail]->head = tmpp->data;

                tmpp->prev = NULL;
                tmpp->head = tmpp->data;
                tmpp->tail = lastTail;

                lastTail = curr->data;
                node[lastHead]->tail = lastTail;
                curr->tail = lastTail;

                updateLast(curr, lastHead, lastTail);
            }

            if (node[at]->next != NULL || node[at]->prev == NULL)
            {
            }
            else
            {
                reverse_node(node[at]);
            }

            if (curr->next != NULL)
            {
                curr->next->prev = NULL;
            }

            node[at]->head = lastHead;
            node[node[at]->tail]->head = lastHead;
            node[lastHead]->tail = node[at]->tail;
            node[at]->prev = curr;

            curr->next = node[at];
            curr = curr->next;
            updateLast(curr, lastHead, lastTail);
            break;
        }

        printf("%d\n", curr->data);
    }
    return 0;
}