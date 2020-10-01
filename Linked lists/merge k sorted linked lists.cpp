#include <bits/stdc++.h>
using namespace std; 

/* C++ code to merge K sorted linked lists in O(NKlog(K)) similar to merge sort algorithm,where N is the maximum
 number of nodes in a list */

//Definition for singly-linked list.
struct node 
{
	int val;
	node *next;	
	node()//default constructor
	{
		val=0;next=nullptr;
	}
	node(int x)
	{
		val=x;next=nullptr;
	}
	node(int x, node *next_node)
	{
		val=x;
		next=next_node;
	}
};

//This function is similar to the merge step of merge sort algorithm on arrays
node *Merge2Lists(node *l1,node *l2) 
{
    if(l1==nullptr)return l2;
    if(l2==nullptr)return l1;
    node *start,*next,*last;
    start=new node;    
    last=start;
    //we create a dummy node called "start" to simplify the code, and return dummy->next (start->next); 
    while(l1!=nullptr and l2!=nullptr)
    {
        if(l1->val<=l2->val)
        {
            last->next=l1;
            l1=l1->next;
        }
        else
        {
            last->next=l2;
            l2=l2->next;
        }
        last=last->next;
    }
    if(l1!=nullptr)
    {
        last->next=l1;
    }
    else if(l2!=nullptr)last->next=l2;
    else last->next=nullptr;
    return start->next;
}
node *Divide(vector<node*> &lists,int lft,int rt) 
{
	
	//we repeatedly divide the vector(array) of lists until we are left with just one list element(1 head)
	//similar to merge sort where we are left with one element
    if(lft<rt)
    {
        int mid=lft+(rt-lft)/2;
        node *firstPart=Divide(lists,lft,mid);
        node *secondPart=Divide(lists,mid+1,rt);
        return Merge2Lists(firstPart,secondPart);
    }
    else if(lft==rt)
    {
        return lists[lft];
    }
    else return nullptr;
}

//helper function to merge k sorted lists,need to be called from driver or main function
node* mergeKLists(vector <node*> &lists) 
{
    int i,j;
    int n=lists.size();
    if(n==0)return nullptr;
    return Divide(lists,0,n-1);
}

