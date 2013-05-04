#include "Binary_tree.h"

CBinaryTree::CBinaryTree()
{
    _rootNode = NULL;
    _currentNode = NULL;
}

CBinaryTree::~CBinaryTree()
{
    Clear();
}

bool CBinaryTree::Init()
{
    if (_rootNode==NULL)
    {
        _rootNode = new BiTNode;
        _rootNode->father = NULL;
        _rootNode->lchild = NULL;
        _rootNode->rchild = NULL;
        _rootNode->data = "Root Node";
        _rootNode->depth = 0;
        _rootNode->pos = ROOT_NODE;
        _currentNode = _rootNode ;
        return true;
    }
    cout << "binary tree has be initialized." << endl;
    return false;
}

void CBinaryTree::ShowNode(BiTNode* node)
{
    if (node != NULL){
        cout << node->data << endl;
        ShowNode(node->lchild);
        ShowNode(node->rchild);
    }
}

void CBinaryTree::ShowAll()
{
    cout << endl << "==========show all node info=========" << endl;
    ShowNode(_rootNode);
    cout << "============================" << endl << endl;
}

void CBinaryTree::Show()
{
    cout << endl << "==========show current node info=========" << endl;
    ShowNode(_currentNode);
    cout << "============================" << endl << endl;
}

bool CBinaryTree::Add(Postion pos)
{
    if (_currentNode == NULL){
        cout << "Add():Current Node ponit to NULL." <<endl;
        return false;
    }

    string __str;
    Postion __pos;
    if (pos == LEFT_NODE){
        if (_currentNode->lchild != NULL){
            cout << _currentNode->data << "'s Left Node is existed." <<endl;
            return false;
        }

        __str = "->Left Node";
        __pos = LEFT_NODE;
    }
    else if (pos == RIGHT_NODE){
        if (_currentNode->rchild != NULL){
            cout << _currentNode->data << "'s Right Node is existed." <<endl;
            return false;
        }

        __str = "->Right Node";
        __pos = RIGHT_NODE;
    }
    else{
        cout << "can't to add node without LEFT_NODE or RIGHT_NODE." << endl;
        return false;
    }

    BiTNode* tmpTree = new BiTNode;
    tmpTree->father = _currentNode;
    tmpTree->lchild = NULL;
    tmpTree->rchild = NULL;
    tmpTree->data = _currentNode->data+__str;
    tmpTree->depth = _currentNode->depth+1;
    tmpTree->pos = __pos;

    if (pos == LEFT_NODE)
        _currentNode->lchild = tmpTree;
    else
        _currentNode->rchild = tmpTree;

    tmpTree = NULL;
    return true;
}

bool CBinaryTree::DeleteNode(BiTNode* &node, bool isFirst)
{
    if (node == NULL){
        if (isFirst){
            cout << "node is no existed." << endl;
        }
        return false;
    }
    else{
        if (!DeleteNode(node->lchild, false) &&
            !DeleteNode(node->rchild, false)){
                cout << "delete depth(" << node->depth<< "):" << node->data << "." << endl;
                switch (node->pos){
                case LEFT_NODE:
                    node->father->lchild = NULL;
                    break;
                case RIGHT_NODE:
                    node->father->rchild = NULL;
                    break;
                case ROOT_NODE:
                    _rootNode = NULL;
                    break;
                }
                delete node;
                node = NULL;
                return isFirst;
        }
    }
    return true;
}

bool CBinaryTree::Del()
{
    Postion __tmpPos;
    if (_currentNode != NULL){
        __tmpPos = _currentNode->pos;

        if (__tmpPos == ROOT_NODE){
            DeleteNode(_currentNode);
            return true;
        }
        else{
            _currentNode = _currentNode->father;
            return DeleteChild(__tmpPos);
        }
    }

    cout << "Del():Current Node ponit to NULL." <<endl;
    return false;
}

bool CBinaryTree::DeleteChild(Postion pos)
{
    if (_currentNode == NULL){
        cout << "DeleteChild():Current Node ponit to NULL." <<endl;
        return false;
    }

    if (pos == LEFT_NODE){
        DeleteNode(_currentNode->lchild);
    }
    else if (pos == RIGHT_NODE){
        DeleteNode(_currentNode->rchild);
    }
    else{
        cout << "can't to delete child node without LEFT_NODE or RIGHT_NODE." << endl;
        return false;
    }

    return true;
}

void CBinaryTree::Clear()
{
    BacktoRoot();
    DeleteNode(_currentNode);
}

bool CBinaryTree::IntoNode(BiTNode* node)
{
    if (node != NULL){
        _currentNode = node;
        cout << "go to " << _currentNode->data << "." << endl;
        return true;
    }

    cout << "node is no existed." << endl;
    return false;
}

bool CBinaryTree::GotoChild(Postion pos)
{
    if (_currentNode == NULL){
        cout << "GotoChild():Current Node ponit to NULL." <<endl;
        return false;
    }

    switch(pos){
    case LEFT_NODE:
        return IntoNode(_currentNode->lchild);
        break;
    case RIGHT_NODE:
        return IntoNode(_currentNode->rchild);
        break;
    default:
        cout << "can't to go to child node without LEFT_NODE or RIGHT_NODE." << endl;
        break;
    }

    return false;
}

bool CBinaryTree::BacktoFather()
{
    if (_currentNode == NULL){
        cout << "IntoNode():Current Node ponit to NULL." <<endl;
        return false;
    }

    return IntoNode(_currentNode->father);
}

bool CBinaryTree::BacktoRoot()
{
    return IntoNode(_rootNode);
}
