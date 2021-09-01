//GRUPO III  (5 Valores)
#include <iostream>

using namespace std;

class Stack { // uma stack de inteiros
    int top, d_size, *items; // topo, comprimento do vector dinamico
public:
    Stack(int size) { // construtor
        top = -1; d_size = size; 
        items = new int[size];
    }
    ~Stack() { delete []items;}  // destrutor

    bool empty() const { return top==-1; } // O(1), true se stack vazia

    int size() const { return top+1; } // O(1), devolve o tamanho

    void push(int elem) { // O(1), inclui elem no topo
        if(size()==d_size) cerr << "Stack Full!\n";
        else { top++; items[top] = elem; }
    }

    int pop() { // O(1), remove e retorna o elem do topo
        if(this->empty()) cerr << "Empty stack\n";
        else return items[top--];
        return 0;
    }

    int peek() const { // O(1), inspeciona o topo
        if(this->empty()) cerr << "Empty stack\n";
        else return items[top];
        return 0;
    }

    void print() const { // O(n), mostra a pilha no ecra
        cout << "stack with " << size() << " elements\n";
        for(int i = size()-1; i>=0; i--)
            cout << items[i] << "\n";
        cout << "---" << endl;
    }
    void introduz_nX(int n, int x);
	int elimina_menor();
}; // final da classe Stack


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
  int contaEntre(int x1, int x2);
  int zipar();
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
	void escreve_maiores(ostream &os); //Alinea 3.3
	void calcula_maiores(TNode *N, int &max1, int &max2); //alinea 3.3
}; // fim da class BTree


/*3.1) Implemente os seguintes membros-função para a classe 
Stack (pilha de inteiros) descrita nos slides/aulas da disciplina. 
a) void introduz_nX(int n, int x) que adiciona n elementos 
com valor x no topo da pilha.
c) int elimina_menor() que elimina o menor dos três elementos 
que se encontram no topo da pilha. Devem ser considerados os casos 
em que a pilha tem menos de três elementos ou está mesmo vazia. 
A função deve retornar o elemento eliminado ou 0 caso a pilha 
esteja vazia. */

void Stack::introduz_nX(int n, int x)
{
	for(int i=0; i<n; i++)
		push(x);
}

int Stack::elimina_menor() 
{
	int a1, a2, a3;
	if (size()==0) return 0;
	if (size()==1) return pop();
	a1=pop(); a2=pop();
	if (size()==2) {
		if (a1<a2) { push(a2); return a1; }	
		else { push(a1); return a2; }	
	}
	a3 = pop();
	if (a1<a2 & a1<a3){ push(a3); push(a2); return a1; }
	else if (a2<a3){ push(a3); push(a1); return a2; }
	     else { push(a2); push(a1); return a3; }
}

/* 3.2) Suponha a classe List descrita nos slides/aulas da 
disciplina.
a) Implemente o método int contaEntre(int x1, int x2); 
que conte o número de elementos de uma lista que são maiores 
que x1 e menores que x2. A função deve escrever no écran 
todos os elementos nestas condições e retornar a sua contagem. 
Exemplo: Aplicar contaEntre(2,8) a [ 1 10 5 8 2 2 3 4 5 9 ]  
resulta na escrita de 5 3 4 5 e é retornado o valor 4.
b) Construa uma função int zipar(); que elimine 
todos os elementos consecutivos iguais de uma lista ordenada 
retornando o número de elementos eliminados. Por exemplo: 
aplicando zipar a [ 1 1 2 2 2 3 3 3 3 4 4 7 8 8 ]  resulta 
em [ 1 2 3 4 7 8 ] e é retornado o valor 8.
*/
int List::contaEntre(int x1, int x2)
{
	Node *fi = first;
	int c=0;
	while(fi!=0) {								//1
		if(fi->data()>x1 && fi->data()<x2){
			c++;
			cout << fi->data() << " ";
		}
		fi = fi->next();
	}	
	return c;
}

int List::zipar()
{
	Node *fi = first,*aux;
	int c=0;
	while(fi!=0 && fi->next()!=0) {								//1
		if(fi->data()==fi->next()->data()){
			c++;
			cout << fi->data() << " ";
			aux=fi->next();
			fi->setNext(aux->next());
			delete aux;
    	}			
		else fi = fi->next();
	}	
	return c;	
}

/* 3.3) Na classe BTree descrita nos slides/aulas da 
disciplina implemente o método: 
void escreve_maiores(ostream &os);
Este método percorre a árvore e determina quais os dois 
elementos maiores presentes na árvore e escreve no output 
stream considerado, o número total de elementos existente 
na árvore e os dois maiores elementos ordenados por ordem 
decrescente. Devem ser considerados os casos em que a árvore 
está vazia ou só tem um elemento. Exemplos: 
A árvore tem 8 elementos e os maiores são 25 e 18.
A árvore está vazia.
A árvore tem 1 único elemento com valor 23.
*/
void BTree::calcula_maiores(TNode *N, int &max1, int &max2)
{
	if(N!=0) { 
		if(N->data()>max1) {max2 = max1; max1= N->data();	}
		else if(N->data()>max2) max2 = N->data();	
		calcula_maiores(N->left(), max1, max2);
        calcula_maiores(N->right(), max1, max2);
    }
}

void BTree::escreve_maiores(ostream &os)
{
	int n=size(root), max1=-10000, max2=-10000;
	calcula_maiores(root, max1, max2);
	if (n==0) os << "A arvore esta vazia" << endl;
	else if (n==1) os << "A arvore tem 1 unico elemento com valor" << max1 << endl;
	     else os << "A arvore tem " << n << " elementos e os maiores sao " << max1 << " e " << max2 << endl;
}

//Main para teste das alineas 3.1 a 3.3
int main()
{
	Stack s1(10);
	cout << s1.elimina_menor() << endl;
	s1.introduz_nX(3,5); s1.print();
	s1.push(4); s1.push(6); s1.print();
	cout << "Eliminado " << s1.elimina_menor() << endl; s1.print();
	cout << "Eliminado " << s1.elimina_menor() << endl; s1.print();
	
	List l1;
	l1.insert_head(8); l1.insert_head(8); l1.insert_head(7); 
	l1.insert_head(4); l1.insert_head(4); l1.insert_head(3); 
	l1.insert_head(3); l1.insert_head(3); l1.insert_head(3);
	l1.insert_head(2); l1.insert_head(2); l1.insert_head(2);
	l1.insert_head(1); l1.insert_head(1);
	l1.print(); 
	cout << "Contagem Entre 2 e 7: " << l1.contaEntre(2,7) << endl;
	cout << "Zipando " << l1.zipar() << endl;
	l1.print(); 
	
	BTree bt;
	bt.insert_sort(1); bt.insert_sort(10); bt.insert_sort(4); 
	bt.insert_sort(2); bt.insert_sort(6); 
	bt.print();
	bt.escreve_maiores(cout);
	
	return 0;
}


