#include<iostream>
#include <vector>  
using namespace std;

class node {
        public:
        int data;
        node* lchild;
        node* rchild;
        	node()
    	{
    		data = 0;
    	    lchild = NULL;
			rchild = NULL;
		} 
    	   node(int data,node *ptr1=0,node *ptr2=0)
    	{
    		this->data = data;
    	    lchild = ptr1;
            rchild = ptr2;
}};

class queue{
	public:
    	int size;
    	int cs;
    	int rear;
    	int front;
        node ** array;
    queue()
    	{
    	    rear = -1;
			front = -1;
            size = 50;
            array = new node*[size]{NULL};
            cs=0;
    	}
    
	void Enqueue(node* data){
            if(rear == size - 1) {
            cout << "Queue Overflow!" << endl;
            }
            else
            {
                array[++rear] = data; 
                cs++;
            }
}
        
	node* Dequeue(void){
    node * X = NULL;
	if (IsEmpty()) 
    {  
        cout << "Queue Underflow!" << endl;  
    }      
    else
    {
        X = array[++front];
        cs--;
    }
    return X;
}
	int sizeq(){
		return cs;
	}

	bool IsEmpty(void){
            return (front == rear);
    }

	node* Peek(void){
	return array[front];
}
};

 
    
class BST {
    node* root;
  
    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
        }
        else if(x < t->data)
            t->lchild = insert(x, t->lchild);
        else if(x > t->data)
            t->rchild = insert(x, t->rchild);
        return t;
    }
    
void LevelOrder(node *p)
{
    if (p == NULL) return;
    queue q;
    q.Enqueue(p);
    while (q.IsEmpty() == false)
    {
        int leveln = q.sizeq();
 		vector <int> arr;
        while (leveln > 0)
        {
            node *p = q.Dequeue();
            arr.push_back(p->data);
            if (p->lchild != NULL)
                q.Enqueue(p->lchild);
            if (p->rchild != NULL)
                q.Enqueue(p->rchild);
            leveln--;
        }
        if(!arr.empty()){
        int min = arr[0];
        int max = arr[0];
        
        for(int i =0 ;i<arr.size();i++){
            if(arr[i]>max)
            max= arr[i];
            if(arr[i]<min)
            min = arr[i];
        }
        
        cout<< min<<" "<<max;
        arr.clear();
    	}
    	
        cout << endl;
    }
}


public:
        BST() {
            root = NULL;
        }
    
        void insert(int x) {
            root = insert(x, root);
        }
        void levelorder(){
            LevelOrder(root);
        }

};
int main(){
    BST b1;
    int count;
    cin>>count;
    int element;
    for (int i = 0; i < count; i++)
    {
        cin>>element;
        b1.insert(element);
    }
    b1.levelorder();
}
