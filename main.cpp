#include<iostream>
#include<windows.h>
#include<time.h>
#include "header.h"
using namespace std;
HANDLE hConsole;
COORD CursorPosition;
bool running;
int main(){
    int menu_item = 0,x = 13;
    int counter = 0;
    int treeTab[11];
    running = true;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute( hConsole, 12 );
    srand (time(NULL));
        while(counter<=11){
            treeTab[counter] = rand() % 40 + 1;
            counter++;
        }
     //tworzymy liœcie drzewa
    BTNode G = {NULL,NULL,treeTab[6]};
    BTNode H = {NULL,NULL,treeTab[7]};
    BTNode I = {NULL,NULL,treeTab[8]};
    BTNode J = {NULL,NULL,treeTab[9]};
    BTNode K = {NULL,NULL,treeTab[10]};

    // Tworzymy kolejnych ojców

    BTNode D = { &H,  &I,treeTab[3]};
    BTNode E = { &J,NULL,treeTab[4]};
    BTNode F = { &K,NULL,treeTab[5]};
    BTNode B = { &D,  &E,treeTab[1]};
    BTNode C = { &F,  &G,treeTab[2]};

    // Tworzymy korzeñ drzewa

    BTNode A = { &B,  &C,treeTab[0]};
    cout<<"=======================================\n";
    cout<<"=========== DFS BINARY TREE ===========\n";
    cout<<"=======================================\n";

    printTree(treeTab,11);
    cout<<endl<<endl;

    SetConsoleTextAttribute( hConsole, 7 );
    cout<<"   PLEASE SELECT THE TREE DFS TYPE:\n";
    cout<<"=======================================";
    setPosition(0,13); cout << "->";


    while(running)
	{
        setPosition(3,13);  cout << "PRE-ORDER";
		setPosition(3,14);  cout << "IN-ORDER";
		setPosition(3,15);  cout << "POST-ORDER";
		setPosition(3,16);  cout << "QUIT";
		cout<<endl;
		cout<<endl;
	

		if(GetAsyncKeyState(VK_DOWN) && x != 16) //down button pressed
			{
				setPosition(0,x); cout << "  ";
				x++;
				setPosition(0,x); cout << "->";
				menu_item++;
				continue;

			}

		if(GetAsyncKeyState(VK_UP) && x != 13) //up button pressed
			{
				setPosition(0,x); cout << "  ";
				x--;
				setPosition(0,x); cout << "->";
				menu_item--;
				continue;
			}

			if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed

			switch(menu_item){

				case 0: {
                    cout<<"PRE-ORDER SEARCHING   ";
                    cout<<endl;
                    PreOrder preorder;
                    getSortType(preorder,&A);
                    cout<<endl;
					break;
				}
                case 1: {
                    cout<<"IN-ORDER SEARCHING    ";
                    cout<<endl;
                    InOrder inorder;
					getSortType(inorder,&A);
					cout<<endl;
					break;
				}
				case 2: {
                    cout<<"POST-ORDER SEARCHING  ";
					PostOrder postorder;
					cout<<endl;
					getSortType(postorder,&A);
					cout<<endl;
					break;
				}
				case 3: {
                    cout<<endl;
					cout << "The program has now terminated.";
					running = false;
				}

			}

		}
	}
    return 0;
}
void setPosition(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole,CursorPosition);
}
void printTree(int treeTab[], int nodesCount){
    SetConsoleTextAttribute( hConsole, 10 );
    setPosition(18,3);
    cout<<treeTab[0];

    setPosition(9,5);
    cout<<treeTab[1];
    setPosition(27,5);
    cout<<treeTab[2];

    setPosition(4,7);
    cout<<treeTab[3];
    setPosition(14,7);
    cout<<treeTab[4];
     setPosition(21,7);
    cout<<treeTab[5];
    setPosition(33,7);
    cout<<treeTab[6];


    setPosition(0,9);
    cout<<treeTab[7];
    setPosition(7,9);
    cout<<treeTab[8];
     setPosition(11,9);
    cout<<treeTab[9];
    setPosition(25,9);
    cout<<treeTab[10];


}
void getSortType(Traversal& TraversalType, BTNode* n){
        TraversalType.doTraversal(n);
}
