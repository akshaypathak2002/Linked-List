/*
Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

*/

#include <iostream>
#include <set>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node()
  {
    // Zero argument constructor
  }
  Node(int val)
  {
    // One arguement constructor
    this->data = val;
    this->next = NULL;
  }
  // for appending the element in the linked list
  Node *append(Node *head, int element)
  {
    Node *temp, *rear;
    if (head == NULL)
    { // if head node is null
      temp = new Node(element);
      head = temp;
    }
    else
    {
      // Else do this
      temp = head;
      while (temp->next != NULL)
        temp = temp->next;
      rear = new Node(element);
      temp->next = rear;
    }
    return head;
  }
  // for the Intersection of two linked list
  Node *intersectionofLinkedList(Node *head1, Node *head2)
  {
    // In this we are going to use hashing
    set<int> s1;
    Node *intersect = NULL;
    Node *temp2 = head2;
    while (temp2 != NULL)
    {
      s1.insert(temp2->data);
      temp2 = temp2->next;
    }
    Node *temp1 = head1;
    while (temp1 != NULL)
    {
      if (s1.find(temp1->data) != s1.end())
        intersect = append(intersect, temp1->data);
      // We are not erasing the element because we are given that every element is distinct
      temp1 = temp1->next;
    }
    return intersect;
    // Its time complexity is O(M+N) that is the size of the two linked list
    // And space complexity is also O(M+N ) as we are using sets 
  }
  // For printing the Linked list
  void printLinkedList(Node *head)
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << "  " << endl;
      temp = temp->next;
    }
  }
};
int main()
{
  /* code */
  int n1, n2; // For the size of two linkes lists
  cin >> n1 >> n2;
  Node *intersect = NULL;
  Node *LinkedList1 = NULL;
  Node *LinkedList2 = NULL;
  cout << "Enter the elemenst for first Linked List " << endl;
  for (int i = 0; i < n1; i++) // fro the first Linked list
  {
    int val;
    cin >> val;
    LinkedList1 = LinkedList1->append(LinkedList1, val);
  }
  cout << "Enter the element for second Linked list " << endl;
  for (int i = 0; i < n2; i++)
  {
    int val;
    cin >> val;
    LinkedList2 = LinkedList2->append(LinkedList2, val);
  }
  cout << "\nLinked List 1 " << endl;
  LinkedList1->printLinkedList(LinkedList1);
  cout << "\nLinked List 2 " << endl;
  LinkedList2->printLinkedList(LinkedList2);
  intersect = intersect->intersectionofLinkedList(LinkedList1, LinkedList2);
  cout << "\nIntersection of Linked List " << endl;
  intersect->printLinkedList(intersect);

  return 0;
}
