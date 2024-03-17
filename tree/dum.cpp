Code :
# include <conio.h>
# include <process.h>
# include <iostream>
using namespace std;

struct node
{
	int ele;
	node *left;
	node *right;
};

typedef struct node *nodeptr;
class stack
{
	private:
		struct snode
		{
			nodeptr ele;
			snode *next;
		};
		snode *top;
	public:
		stack()
		{
			top=NULL;
		}
		void push(nodeptr p)
		{
			snode *temp;
			temp = new snode;
			temp->ele = p;
			temp->next = top;
			top=temp;
		}

		void pop()
		{
			if (top != NULL)
			{
			nodeptr t;
			snode *temp;
			temp = top;
			top=temp->next;
			delete temp;
			}
		}

		nodeptr topele()
		{
			if (top !=NULL)
				return top->ele;
			else
				return NULL;
		}



		int isempty()
		{
		return ((top == NULL) ? 1 : 0);
		}

};


class bstree
{
	public:
		void insert(int,nodeptr &);
		void del(int,nodeptr &);
		int deletemin(nodeptr &);
		void find(int,nodeptr &);
		nodeptr findmin(nodeptr);
		nodeptr findmax(nodeptr);
		void copy(nodeptr &,nodeptr &);
		void makeempty(nodeptr &);
		nodeptr nodecopy(nodeptr &);
		void preorder(nodeptr);
		void inorder(nodeptr);
		void postorder(nodeptr);
		void preordernr(nodeptr);
		void inordernr(nodeptr);
		void postordernr(nodeptr);
		void leftchild(int,nodeptr &);
		void rightchild(int,nodeptr &);


};

void bstree::insert(int x,nodeptr &p)
{
	if (p==NULL)
	{
		p = new node;
		p->ele=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if (x < p->ele)
			insert(x,p->left);
		else if (x>p->ele)
			insert(x,p->right);
		else
			cout<<"Element already Exits !";
	}
}

void bstree:: del(int x,nodeptr &p)
{
	nodeptr d;
	if (p==NULL)
		cout<<"Element not found ";
	else if (x < p->ele)
		del(x,p->left);
	else if (x > p->ele)
		del(x,p->right);
	else if ((p->left == NULL) && (p->right ==NULL))
	{
		d=p;
		free(d);
		p=NULL;
	}
	 else if (p->left == NULL)
	{
		d=p;
		free(d);
		p=p->right;
	}
	else if (p->right ==NULL)
	{
		d=p;
		p=p->left;
		free(d);
	}
	else
	p->ele=deletemin(p->right);
}

int bstree::deletemin(nodeptr &p)
{
	int c;
	if (p->left == NULL)
	{
		c=p->ele;
		p=p->right;
		return c;
	}
	else
		c=deletemin(p->left);
		return c;
}

void bstree::copy(nodeptr &p,nodeptr &p1)
{
	makeempty(p1);
	p1=nodecopy(p);
}

void bstree::makeempty(nodeptr &p)
{
	nodeptr d;
	if (p!=NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d=p;
		free(d);
		p=NULL;
	}
}

nodeptr bstree::nodecopy(nodeptr &p)
{
	nodeptr temp;
	if (p == NULL)
		return p;
	else
	{
		temp = new node;
		temp->ele=p->ele;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}


nodeptr bstree::findmin(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"Tree is empty !";
		return p;
	}
	else
	{
		while (p->left !=NULL)
			p=p->left;
		return p;
	}
}



nodeptr bstree::findmax(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"Tree is empty !";
		return p;
	}
	else
	{
		while (p->right !=NULL)
			p=p->right;
		return p;
	}
}

void bstree::find(int x,nodeptr &p)
{
	if (p==NULL)
		cout<<"Element not found  !";
	else
	{
		if (x <p->ele)
			find(x,p->left);
		else if ( x> p->ele)
			find(x,p->right);
		else
			cout<<"Element Found !";
	}
}

void bstree::preorder(nodeptr p)
{
	if (p!=NULL)
	{
		cout<<p->ele<<"-->";
		preorder(p->left);
		preorder(p->right);
	}
}
void bstree::inorder(nodeptr p)
{
	if (p!=NULL)
	{
		inorder(p->left);
		cout<<p->ele<<"-->";
		inorder(p->right);
	}
}

void bstree::postorder(nodeptr p)
{
	if (p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->ele<<"-->";
	}
}



void bstree::preordernr(nodeptr p)
{
	stack s;
	while (1)
	{
	if  (p != NULL)
	{
		cout<<p->ele<<"-->";
		s.push(p);
		p=p->left;
	}
	else
	if (s.isempty())
	{
		cout<<"Stack is empty";
		return;
	}
	else
	{
		nodeptr t;
		t=s.topele();
		p=t->right;
		s.pop();
	}
	}
}


void bstree::inordernr(nodeptr p)
{
	stack s;
	while (1)
	{
	if  (p != NULL)
	{
		s.push(p);
		p=p->left;
	}
	else
	{
	if (s.isempty())
	{
		cout<<"Stack is empty";
		return;
	}
	else
	{
		p=s.topele();
		cout<<p->ele<<"-->";
	}
	s.pop();
	p=p->right;
	}
	}
}


void bstree::postordernr(nodeptr p)
{
	stack s;
	while (1)
	{
	if  (p != NULL)
	{
		s.push(p);
		p=p->left;
	}
	else
	{
		if (s.isempty())
		{
			cout<<"Stack is empty";
			return;
		}
		else
		if (s.topele()->right == NULL)
		{
			p=s.topele();
			s.pop();
			cout<<p->ele<<"-->";
			if (p==s.topele()->right)
			{
				cout<<s.topele()->ele<<"-->";
				s.pop();
			}
		}
		if (!s.isempty())
			p=s.topele()->right;
		else
			p=NULL;
	}
	}
}

void bstree::leftchild(int q,nodeptr &p)
{
	if (p==NULL)
		cout<<"The node does not exists ";

	else
	if (q < p->ele )
		leftchild(q,p->left);
	else
	if (q > p->ele)
		leftchild(q,p->right);
	else
	if (q == p->ele)
	{
		if (p->left != NULL)
			cout<<"Left child of "<<q<<"is "<<p->left->ele;
		else
			cout<<"No Left child !";
	}
}

void bstree::rightchild(int q,nodeptr &p)
{
	if (p==NULL)
		cout<<"The node does not exists ";
	else
	if (q < p->ele )
		rightchild(q,p->left);
	else
	if (q > p->ele)
		rightchild(q,p->right);
	else
	if (q == p->ele)
	{
		if (p->right != NULL)
			cout<<"Right child of "<<q<<"is "<<p->right->ele;
		else
			cout<<"No Right Child !";
	}
}





int main()
{
int ch,x,leftele,rightele;
bstree bst;
char c='y';
nodeptr root,root1,min,max;
root=NULL;
root1=NULL;
do
{
//	system("clear");
	clrscr();
	cout<<"Binary Search Tree 
";
	cout<<"-------------------------
";
	cout<<"		1.Insertion
		2.Deletion
		3.NodeCopy
";
	cout<<"		4.Find
		5.Findmax
		6.Findmin
";
	cout<<"		7.Preorder
		8.Inorder
		9.Postorder
";
	cout<<"
		10.Leftchild
		11.Rightchild
		0.Exit
";
	cout<<"
Enter your choice :";
	cin>>ch;

	switch(ch)
	{
	case 1:
		cout<<"
		1.Insertion
";
		cout<<"Enter the new element to get inserted :
";
		cin>>x;

		bst.insert(x,root);
		cout<<"Inorder traversal is :
";
		bst.inorder(root);
		break;

	case 2:
		cout<<"
		2.Deletion
";
		cout<<"Enter the element to get deleted :
";
		cin>>x;
		bst.del(x,root);
		bst.inorder(root);
		break;

	case 3:
		cout<<"
		3.Nodecopy
";
		bst.copy(root,root1);
		cout<<"
The new tree is :
";
		bst.inorder(root1);
		break;

	case 4:
		cout<<"
		4.Find
";
		cout<<"Enter the element to be searched :
";
		cin>>x;
		bst.find(x,root);
		break;

	case 5:
		cout<<"
		5.Findmax
";
		if (root == NULL)
			cout<<"
Tree is empty";
		else
		{
			max=bst.findmax(root);
			cout<<"Largest element is :	"<<max->ele<<endl;
		}
		break;

	case 6:
		cout<<"
		6.Findmin
";
		if (root == NULL)
			cout<<"
Tree is empty";
		else
		{
			min=bst.findmin(root);
			cout<<"Smallest element is :	"<<min->ele<<endl;
		}
		break;

	case 7:
		cout<<"
		7.Preorder
";
		if (root==NULL)
			cout<<"
Tree is empty";
		else
		{
			cout<<"
Preorder traversal (Non-Recursive) is :
";
			bst.preordernr(root);
			cout<<"
Preorder traversal (Recursive) is :
";
			bst.preorder(root);
		}
		break;

	case 8:
		cout<<"
		8.Inorder
";
		if (root==NULL)
			cout<<"
Tree is empty";
		else
		{
			cout<<"
Inorder traversal (Non-Recursive) is :
";
			bst.inordernr(root);
			cout<<"
Inorder traversal (Recursive) is :
";
			bst.inorder(root);
		}
		break;

	case 9:
		cout<<"
		9.Postorder
";
		if (root==NULL)
			cout<<"
Tree is empty";
		else
		{
			cout<<"
Postorder traversal (Non-Recursive) is :
";
			bst.postordernr(root);
			cout<<"
Postorder traversal (Recursive) is :
";
			bst.postorder(root);
		}
		break;

	case 10:
		cout<<"
		10.Finding the left Child 
";
		if (root==NULL)
			cout<<"
Tree is empty";
		else
		{
			cout<<"Enter the node for which the left child is to be found :
";
			cin>>leftele;
			bst.leftchild(leftele,root);
		}
		break;

	case 11:
		cout<<"
		11.Finding the Right Child 
";
		if (root==NULL)
			cout<<"
Tree is empty";
		else
		{
			cout<<"Enter the node for which the Right child is to be found :
";
			cin>>rightele;
			bst.rightchild(rightele,root);
		}
		break;


	case 0:
		exit(0);
	}
	cout<<"
Continue (y/n) ?
";
	cin>>c;
	}while (c=='y' || c == 'Y');
	return 0;
}













void del(tnode *t,int k)
{if(t==NULL)
return;
if(t->data>k)
del(t->lchild,k);
else if(t->data<k)
del(t->rchild,k);
else if(t->lchild!=NULL&&t->rchild!=NULL)
{t->data=fmin(t->rchild)->data;
del(t->rchild,t->data);}
else 
{tnode *m=t;
if(t->lchild!=NULL)
t=t->l;
else t=t->rchild;
delete m;}
}

















