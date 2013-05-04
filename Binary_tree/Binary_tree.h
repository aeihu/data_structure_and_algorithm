#ifndef BINARY_TREE_H_INCLUDED
    #define BINARY_TREE_H_INCLUDED

 #include <string>
 #include <iostream>

using namespace std;

class CBinaryTree
{
 public:
    typedef enum{
         LEFT_NODE,
         RIGHT_NODE,
         ROOT_NODE
    }Postion;
 private:
     typedef struct BiTNode
     {
         unsigned int depth;
         Postion pos;
         string data;
         struct BiTNode *father, *lchild, *rchild;
     }BiTNode;

 private:
    BiTNode* _rootNode;
    BiTNode* _currentNode;

    void ShowNode(BiTNode* node);
    bool DeleteNode(BiTNode* &node, bool isFirst=true);
    bool IntoNode(BiTNode* node);
 public:

     CBinaryTree();
     ~CBinaryTree();

     bool Init();
     void ShowAll();
     void Show();
     bool Add(Postion pos);
     bool Del();
     bool DeleteChild(Postion pos);
     void Clear();

     bool GotoChild(Postion pos);
     bool BacktoFather();
     bool BacktoRoot();
};

#endif // BINARY_TREE_H_INCLUDED
