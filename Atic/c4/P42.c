//add new numbers at the head of the list
int main() {
    void printList(NodePtr);
    NodePtr makeNode(int);
    int n;
    NodePtr top, np;
    top = NULL;
    if (scanf("%d", &n) != 1) n = 0;
    while (n != 0) {
        np = makeNode(n); //create a new node containing n
        np -> next = top; //set link of new node to first node
        top = np;         //set top to point to new node
        if (scanf("%d", &n) != 1) n = 0;
    }
    printList(top);
} //end main
