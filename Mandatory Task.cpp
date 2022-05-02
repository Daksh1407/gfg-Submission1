//Check whether linked list is Palindrome or not

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

//declare the structure of linked list
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution{
  public:
  //Function for reverse the linked list
    Node* reverse(Node* head){
        Node* curr=head->next;
        Node* prev=NULL;
    while(head!=NULL){
        curr=head->next;
        head->next=prev;
        prev=head;
        head=curr;
    }
    head=prev;    
    return head;
}
bool isPalindrome(Node* head) {
    bool flag=false;
    Node *slow=head;
    Node *fast=head;
    // Getting the mid of linked list 
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //Reverse half of the linked list
    Node* temp=reverse(slow);
    //compare both half linked list
    while(head!=slow){
        if(head->data==temp->data){
            head=head->next;
            temp=temp->next;
        }
        else{
            flag=true;
            break;
        }
    }
    if(flag)
        return false;
    else
        return true;
    }
};

struct Node* head = NULL;
//Funtion to insert the nodes
void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}

//Driver code (main function)
int main(){
    
    int n;
    cout<<"Enter the size of linked list:- ";
    cin>>n;
    int data;
    cout<<"Enter the values :-\n";
    while(n!=0){
        cin>>data;
        insert(data);
        n--;
    }
    //creating the object of class to excess its funtions
    Solution obj;
    
    if(obj.isPalindrome(head))
        cout<<"Given linked list is Palindrome..";
    else
        cout<<"Given linked list is not Palindrome";
    return 0;
}
