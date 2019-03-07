#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
struct BTNode
{
  BTNode * left;
  BTNode * right;
  int data;
};
class Traversal{
    public:
        virtual void doTraversal(BTNode*) = 0;
};

class PreOrder:public Traversal{
public:
    void doTraversal(BTNode*);
};
class InOrder:public Traversal{
public:
    void doTraversal(BTNode * n);
};
class PostOrder:public Traversal{
public:
    void doTraversal(BTNode * n);
};

void getSortType(Traversal&,BTNode*);
void printTree(int[], int);
void setPosition(int ,int);

#endif // HEADER_H_INCLUDED
