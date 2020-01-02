#include "new.cpp"


template <typename T>
class diagonalSumTreeNode{
public:
    T data;
    int diagonalLevel;
    diagonalSumTreeNode* left;
    diagonalSumTreeNode* right;
public:
    diagonalSumTreeNode(T data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

void printUnorderedMap(std::unordered_map<int,int> myMap){
    for (auto it=myMap.begin();it!=myMap.end();it++){
        std::cout<<it->second<<std::endl;
    }
}

void diagonalSumOfTree(diagonalSumTreeNode<int>* root){
    std::unordered_map<int,int> diagonalSum;
    if (root==nullptr){
        return ;
    }
    std::queue<diagonalSumTreeNode<int>*> pending;
    pending.push(root);
    root->diagonalLevel=0;
    while (!pending.empty()){
        diagonalSumTreeNode<int>* temp=pending.front();
        pending.pop();
        if (temp->left) {temp->left->diagonalLevel=temp->diagonalLevel+1; pending.push(temp->left);}
        if (temp->right) {temp->right->diagonalLevel=temp->diagonalLevel; pending.push(temp->right);}
        diagonalSum[temp->diagonalLevel]+=temp->data;
    }
    printUnorderedMap(diagonalSum);

}

template <typename T>
diagonalSumTreeNode<T>* diagonalSumNewNode(T data){
    diagonalSumTreeNode<T>* newNode=new diagonalSumTreeNode<T>(data);
    return newNode;
}

template <typename T>
diagonalSumTreeNode<T>* diagonalSumTakeInputLevelWise(){
    T data;
    std::cout<<"Enter root node : ";
    std::cin>>data;
    if (data==-1){
        return nullptr;
    }
    else if (data!=-1){
        std::queue<diagonalSumTreeNode<T>*> pending;
        diagonalSumTreeNode<T>* root=diagonalSumNewNode(data);
        pending.push(root);
        while (!pending.empty()){
            diagonalSumTreeNode<T>* temp=pending.front();
            pending.pop();

            T child;
            std::cout<<"Enter left child of "<<temp->data<<" : ";
            std::cin>>child;
            if (child!=-1){
                diagonalSumTreeNode<T>* leftChild=diagonalSumNewNode(child);
                temp->left=leftChild;
                pending.push(leftChild);
            }

            //std::cout<<std::endl;

            std::cout<<"Enter right child of "<<temp->data<<" : ";
            std::cin>>child;
            if (child!=-1){
                diagonalSumTreeNode<T>* rightChild=diagonalSumNewNode(child);
                temp->right=rightChild;
                pending.push(rightChild);
            }
        }
        return root;
    }
}

int main()
{
    diagonalSumTreeNode<int>* root=diagonalSumTakeInputLevelWise<int>();
    diagonalSumOfTree(root);
	return 0;
}










