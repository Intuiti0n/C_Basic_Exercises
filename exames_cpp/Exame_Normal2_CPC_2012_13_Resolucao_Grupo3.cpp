#include <iostream>

using namespace std;

class Node // nodo de uma lista ligada de int
{ private: 
    int d_data;   // pode ser string ou até um outro objecto
    Node *d_next; // aponta para o próximo nodo
public:
    Node(int data, Node *next){ d_data=data; d_next=next; }
    void setData(int data) { d_data=data; }
    void setNext(Node *next) { d_next=next; }
// acessores
    int data() const { return d_data;}
    Node *next() const { return d_next;}
    void print() const { cout << d_data << " ";}
};



class List { // lista ligada de int
private: 
	 Node *first; // aponta para o primeiro nodo
public:
    List(){ // construtor de lista ligada vazia 
        first=0;
    }
    ~List() { // destrutor
        Node *aux=first; Node *cur;
        while(aux!=0) { 
             cur = aux; aux = aux->next(); delete cur;
        }
    }
    bool empty() const { return (first==0);}   // O(1)

    void print() const {   // O(n)
        Node *aux=first;
        while(aux!=0) { aux->print(); aux=aux->next();}
        cout << "\n";
    }
Node *find(int elem) { // O(n)
      Node *aux = first;
      while(aux!=0 && aux->data()!=elem) aux=aux->next();
      if(aux!=0) return aux;
      else { cerr << "Elem is not in list\n"; return 0;}
  }

  void insert_head(int elem){ // O(1), insere no inicio da lista
      Node *res = new Node(elem, first);
      first = res;
  }

  void insert_end(int elem){ // O(n), insere no fim
      Node *node, *aux;
      node = new Node(elem,0); 
      aux = first;
      if(aux==0) first=node;
      else { 
          while(aux->next()!=0) aux = aux->next();
          aux->setNext(node);
      }
  }
void insert_sort(int elem) { // O(n), insere de modo ordenado
    Node *prev, *node, *aux;
    node = new Node(elem,0); prev = 0; aux = first;
    while(aux!=0 && aux->data()<elem) { prev = aux; aux = aux->next();}
    node->setNext(aux);
    if(prev==NULL) first=node; else prev->setNext(node);
  }

  Node *remove(int elem) { // remove elem da lista
    Node *prev, *aux;
    prev= 0; aux = first;
    while(aux!=0 && aux->data()!=elem){ prev = aux; aux = aux->next();}
    if(aux==0) cerr << "Item not found\n";
    else {
        if(prev!=0) prev->setNext(aux->next());
        else first=aux->next();
        delete aux;
    }
    
  }
  void intercalar(const List &lst);
}; // fim de list.h

class TNode // nodo de uma arvore binaria
{
private: 
	int d_data; // pode ser string ou ate uma classe
	TNode *d_left; TNode *d_right;
public:
	TNode(int data, TNode *left, TNode *right) {
		 d_data=data; d_left=left; d_right=right;
   }
	void setData(int data) { d_data=data;}
	void setLeft(TNode *left) { d_left=left;}
	void setRight(TNode *right) { d_right=right;}
	int data() const { return d_data;}
	TNode *left() const { return d_left;}
	TNode *right() const { return d_right;}
	void print() const { cout << d_data << " ";}
};

class BTree   // arvore de int, continuação do tree.cpp
{
private: 
	TNode *root; // nodo raiz
public:
    BTree(){ root=0;} // lista ligada vazia
    ~BTree() // destrutor
        { destroy(root);}
    void destroy(TNode *N) { // O(N)
	    if(N!=0) { 
         destroy(N->left()); destroy(N->right()); delete N;} 
    }
    bool empty() const { return (root==0);} // O(1)
    int size() const { return size(root);} // O(N), trav. preorder
    int size(TNode *N) const { // travesia preorder
        if(N!=0) { return 1+size(N->left())+size(N->right());}
        else return 0;
    }
	void print() const { print(root); cout << "\n";} // O(N), travesia preorder
	void print(TNode *N) const // travesia preorder
    { 
        if(N!=0) { N->print(); cout << "[";
        print(N->left()); cout << "][";
        print(N->right()); cout << "]";}
    }
	TNode *find(int elem) const { find(root,elem); } // O(log2n), se bal.
	TNode *find(TNode *N,int elem) const { // preorder
  	  if(N==0 || N->data()==elem) return N;
  	  else if(N->data()>elem) return find(N->left(),elem);
  	  else return find(N->right(),elem);
	}
	TNode *insert_sort(int elem) { 
  	  	root=insert_sort(root,elem);} // O(log2n), se bal.
	TNode *insert_sort(TNode *N,int elem) {
    	TNode *res=0;
    	if(N==0){res=new TNode(elem,0,0);}
    	else if(N->data()>elem) { N->setLeft(insert_sort(N->left(),elem));res=N;}
    		 else { N->setRight(insert_sort(N->right(),elem));res=N;}
    	return res;
	}
	int minData(TNode *N) const { // valor minimo a partir de um TNode
    	if(N->left()==0) return N->data(); // min=a folha mais à esquerda de N
    	else return minData(N->left());
	}
	int escreverN(const int n);
	int escreverN(int n, TNode *N);
}; // fim da class BTree



void List::intercalar(const List &lst)
{
	Node *fi = first, *se = lst.first, *aux;   //1
	while(se!=0) {								//1
		aux = fi;
		Node *node = new Node(se->data(),aux->next());  //1
		se = se->next();     //2
		fi = fi->next();
		aux->setNext(node);
	}
}

int BTree::escreverN(const int n) { 
   int soma = escreverN(n, root);
   cout << "soma: " << soma <<endl;
   return soma; 
}  //1

int BTree::escreverN(int n, TNode *N)
{
    if(N!=0 && n>0) {   //1
    	n--;  //1
        int s1 = escreverN(n, N->left());  //2
		cout << N->data() << " ";
        int s2 = escreverN(n, N->right());
        return s1+s2+N->data();   //1
    }
    return 0;
}






int main()
{
	List l1, l2;
	l1.insert_end(1); l1.insert_end(2); l1.insert_end(3); l1.insert_end(4);
	l1.insert_end(5); l1.insert_end(6); l1.insert_end(7);
	l2.insert_end(11); l2.insert_end(12); l2.insert_end(13); l2.insert_end(14); l2.insert_end(15);
	l1.print(); l2.print(); 
	l1.intercalar(l2);
	l1.print(); l2.print(); 
	
	BTree bt;
	bt.insert_sort(1); bt.insert_sort(5); bt.insert_sort(4); bt.insert_sort(2); bt.insert_sort(3); 
	int soma=bt.escreverN(3); cout << " = " << soma << endl;
	bt.print();
	return 0;
}


