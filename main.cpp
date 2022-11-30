#include<bits/stdc++.h>


using namespace std;

#define nn 1e3



class binaryTree{

   public: 

   int val;
   binaryTree *left,*right;

   binaryTree(int val){
       
       this->val=val;
       left=right=NULL;
   }
  
};


class Queue{

    public:

    int f;
    int end;
    vector<binaryTree*>arr;

    Queue(){
         
         f=-1;
         end=-1;
         arr=vector<binaryTree*>(nn,NULL);
    }

   bool push(binaryTree *node){
         
         if(end==1e3){
            cout<<"queue is full"<<endl;
            return false;
         }

         arr[end++]=node;

         return true;

    }

    bool pop(){

        if(f==end){
            cout<<"queue is empty"<<endl;
            return false;
        }

        for(int i=0;i<end-1;i++){
            arr[i]=arr[i+1];
        }
        end--;
    }


    binaryTree* front(){
         
         if(f==end){
            cout<<"queue is empty"<<endl;
            
         }
         f++;
         return arr[f];

    }


    bool empty(){
         
         if(f==end){
            return true;
         }
         return false;
    }

    void display(){

        for(auto i: arr){
            cout<<i->val<<" ";
        }cout<<endl;
    }





};





void inOrder(binaryTree *root){
      

      if(root==NULL)return;
      inOrder(root->left);
      cout<<root->val<<" ";
      inOrder(root->right);
}


void levelOrderTraversal(binaryTree *root){
     
     if(root==NULL)return;

     queue<binaryTree*>q;

    // Queue q;
     q.push(root);

     while(!q.empty()){

        binaryTree *temp=q.front();
        q.pop();

        cout<<temp->val<<" ";

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }

        
     }
}


void insertion(binaryTree *root,int data){
      
   //creating the node with given data
     
     binaryTree *n=new binaryTree(data);


      if(root==NULL){
        
        root=n;
        return;


      }

      queue<binaryTree*>q;
      
    //   Queue q;
      q.push(root);


      while(!q.empty()){
           
           binaryTree *temp=q.front();
           q.pop();

           if(temp->left==NULL){
              
              temp->left=n;
              return;
           }else{
               q.push(temp->left);
           }


           if(temp->right==NULL){
               temp->right=n;
               return;
           }else{
               q.push(temp->right);
           }
      }
}


bool searchData(binaryTree *root,int data){
       
       if(root==NULL){
           return false;
       }

       if(root->val==data){
           return true;
       }


       return searchData(root->left,data) or searchData(root->right,data);
}


binaryTree *findDeepest(binaryTree *root){
      
      if(root==NULL){
        return NULL;
      }

      binaryTree *res;

      queue<binaryTree*>q;

    //  Queue q;

      q.push(root);

      while(!q.empty()){
           
           binaryTree *temp=q.front();
           q.pop();

           if(temp->left){
              res=temp->left;
              q.push(temp->left);
           }
           if(temp->right){
              
              res=temp->right;
              q.push(temp->right);
           }
      }

      return res;
}



void deletion(binaryTree *root,binaryTree *d_node){
       


     
     queue<binaryTree*>q;

    // Queue q;

     binaryTree *temp;
       
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);

        }       
 
    }

}


void deletDeepest( binaryTree* root,  binaryTree* d_node)
{
    queue< binaryTree*> q;

    // Queue q;
    q.push(root);
 
    // Do level order traversal until last node
    binaryTree* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

binaryTree* deletion( binaryTree* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->val == key)
			return NULL;
		else
			return root;
	}

	queue< binaryTree*> q;

    // Queue q;
	q.push(root);

	struct binaryTree* temp;
	struct binaryTree* key_node = NULL;

	// Do level order traversal to find deepest
	// node(temp) and node to be deleted (key_node)
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->val == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->val;
		deletDeepest(root, temp);
		key_node->val = x;
	}
	return root;
}





int main(){

    binaryTree *root=new binaryTree(56);
    root->left=new binaryTree(23);
    root->right=new binaryTree(12);


    // Queue q;
    // q.push(root);
    // q.push(root->left);

    // q.display();

    

  

    inOrder(root);
    cout<<endl;
    levelOrderTraversal(root);

    insertion(root,34);
    
    for(int i=0;i<5;i++){
          insertion(root,i*5);
    }
    cout<<endl;

    //   binaryTree *n=findDeepest(root);
    // cout<<n->val<<endl;

    levelOrderTraversal(root);
    cout<<endl;

    // if(searchData(root,2)){
    //     cout<<"this is present"<<endl;
    // }else{
    //     cout<<"This is not in tree"<<endl;
    // }

    deletion(root,34);


    levelOrderTraversal(root);






    return 0;
}