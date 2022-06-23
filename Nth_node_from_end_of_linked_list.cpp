// In this we have to find the n node from the end of  the linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    { // Zero argument constructor
    }
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    Node *append(Node *head, int element)
    {
        Node *temp, *rear;
        if (head == NULL)
        {
            temp = new Node(element);
            head = temp;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            rear = new Node(element);
            temp->next = rear;
        }
        return head;
    }
    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "   ";
            temp = temp->next;
        }
    }
    int NthNodefromLast(Node *head, int n)
    {
        // n is the number of node to search from last
        // we will first count the number of nodes in the Linked list
        int number_of_nodes = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            number_of_nodes++;
            temp = temp->next;
        }
        int position_from_start = number_of_nodes - n;
        if (n > number_of_nodes)
        {
            return -1;
        }
        int count = 0; // To take track of  number of nodes from start
        temp = head;
        while (temp != NULL)
        {
            if (position_from_start == count)
            {
                return temp->data;
            }
            count++; // Counting the nodes each time
            temp = temp->next;
        }
        return -1;
    }
    // Its time complexity is O(N) and space complexity is constant
};
int main()
{
    Node *LinkedList = NULL; // Initializing the  nodes from the NULL
    int n, node_from_last;   // n is the number of nodes we want in Linked list
    cout << "Enter the number of nodes you want in Linked list " << endl;//To take input from the user how many nodes want in linked list 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        LinkedList = LinkedList->append(LinkedList, val);
    }
    LinkedList->printList(LinkedList);
    cout << "\nEnter the node number you want to search from last " << endl;
    cin >> node_from_last;
    cout << LinkedList->NthNodefromLast(LinkedList, node_from_last) << endl;
    return 0;
}
