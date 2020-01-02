#include "new.cpp"



template <typename T>
class verticalSumTreeNode{
public:
    T data;
    int horizontalLevel;
    verticalSumTreeNode* left;
    verticalSumTreeNode* right;
public:
    verticalSumTreeNode(T data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};



template <typename T>
verticalSumTreeNode<T>* verticalSumNewNode(T data){
    verticalSumTreeNode<T>* newNode=new verticalSumTreeNode<T>(data);
    return newNode;
}



template <typename T>
verticalSumTreeNode<T>* verticalSumTakeInputLevelWise(){
    T data;
    std::cout<<"Enter root node : ";
    std::cin>>data;
    if (data==-1){
        return nullptr;
    }
    else if (data!=-1){

        std::queue<verticalSumTreeNode<T>*> pending;
        verticalSumTreeNode<T>* root=verticalSumNewNode(data);
        pending.push(root);
        root->horizontalLevel=0;
        while (!pending.empty()){
            verticalSumTreeNode<T>* temp=pending.front();
            pending.pop();

            T child;
            std::cout<<"Enter left child of "<<temp->data<<" : ";
            std::cin>>child;
            if (child!=-1){
                verticalSumTreeNode<T>* leftChild=verticalSumNewNode(child);
                temp->left=leftChild;
                temp->left->horizontalLevel=temp->horizontalLevel-1;
                pending.push(leftChild);
            }

            //std::cout<<std::endl;

            std::cout<<"Enter right child of "<<temp->data<<" : ";
            std::cin>>child;
            if (child!=-1){
                verticalSumTreeNode<T>* rightChild=verticalSumNewNode(child);
                temp->right=rightChild;
                temp->right->horizontalLevel=temp->horizontalLevel+1;
                pending.push(rightChild);
            }
        }
        return root;
    }
}


void printOrderedMap(std::map<int,int> myMap){
    for (auto it=myMap.begin();it!=myMap.end();it++){
        std::cout<<it->second<<std::endl;
    }
}


void verticalSumOfTree(verticalSumTreeNode<int>* root){
    std::map<int,int> verticalSum;
    if (root==nullptr){
        return ;
    }
    std::queue<verticalSumTreeNode<int>*> pending;
    pending.push(root);
    while (!pending.empty()){
        verticalSumTreeNode<int>* temp=pending.front();
        pending.pop();
        verticalSum[temp->horizontalLevel]+=temp->data;
        if (temp->left) pending.push(temp->left);
        if (temp->right) pending.push(temp->right);
    }

    printOrderedMap(verticalSum);
}



int main()
{
    verticalSumTreeNode<int>* root=verticalSumTakeInputLevelWise<int>();
    verticalSumOfTree(root);
	return 0;
}



