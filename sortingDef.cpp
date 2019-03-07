#include<iostream>
#include "header.h"
using namespace std;
void PreOrder::doTraversal(BTNode * n){
 if(n)
      {
        cout << n->data << " ";
        doTraversal(n->left);
        doTraversal(n->right);
      }
    }
void InOrder::doTraversal(BTNode * n){
 if(n)
      {
        doTraversal(n->left);
        cout << n->data << " ";
        doTraversal(n->right);
      }
    }

void PostOrder::doTraversal(BTNode * n){
 if(n)
      {
        doTraversal(n->left);
        doTraversal(n->right);
        cout << n->data << " ";

      }
    }
