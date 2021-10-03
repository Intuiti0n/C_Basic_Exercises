// Programa Exemplo de Contagem de Operações e de Tempo

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

long int op;  //Global Counter for operations
long int searchNumber;
ofstream fich("vetorOperacoes.txt");
// Time (in seconds) between clock1 and clock2
double diffclock(clock_t clock1,clock_t clock2)
{
	return (double)(clock1-clock2)/CLOCKS_PER_SEC;
}

// Creates a random vector with n elements between 0 and 1000000
void cria_vetor(long int v[], int n)
{
    for(long int i=0; i<n; i++)
        v[i] = rand() % 1000000;    
        searchNumber = v[500];
}

// Writes the vector on the screen
void escreve_vetor(long int v[], int n)
{
    for(long int i=0; i<n; i++)
        cout << v[i] << " ";
    cout << endl;    
}

// Writes the vector on the file
void escreve_vetor_file(long int v[], int n)
{
    for(long int i=0; i<n; i++)
    fich << v[i] << " ";
    fich << endl;    
}

// sequencial search
template <class T> int ProcuraSeq(T v[], int n, long int x)
{
   for (int i = 0; i < n; i++)
   { op++;
      if (v[i] == x) return i; // encontrou
  }
   return -1;
   	; // não encontrou
}


// binary search
template <class T> int ProcuraBinaria(T v[], long int n, long int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        op++;
		int middle = (left + right) / 2; 
        if (x == v[middle]) return middle; // encontrou
        else if (x > v[middle]) left = middle + 1;
        else right = middle - 1;
        
    }
    return -1; // não encontrou
}

//Simple ordering algorithm inspired in BubbleSort
template <class T> void BubbleSort(T v[], long int n)
{
    T aux;
    long int i, j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
           if(v[j]<v[i]) { op++; aux=v[i]; v[i]=v[j]; v[j]=aux;}   
}

//QuickSort algorithm   
template <class T> void QuickSort(T vec[], long int a, long int b)
{  
   if (a >= b) return;
   T x = vec[(a+b)/2]; 
   long int i = a, j = b;
      do {
      	while (vec[i] < x) i++;
      	while (vec[j] > x) j--;
      	if (i > j) break;
      	op++;
      	T tmp=vec[i]; vec[i]=vec[j]; vec[j]=tmp;
	i++; j--; 
   } while (i <= j);  
   QuickSort(vec, a, j);
   QuickSort(vec, i, b);
 
}

//InsertionSort algorithm
template <class T> void InsertionSort(T vec[], long int n)
{
   long int i,j;
   for (i = 1; i < n; i++) {
      T x = vec[i];
      for (j = i; j > 0 && x < vec[j-1]; j--) {
         vec[j] = vec[j-1];
         op++;
      }
      vec[j] = x; 
   }
}

//SelectionSort algorithm
template <class T> void SelectionSort(T vec[], long int n)
{
 long int i, j, min, aux;
 for (i=0; i<n-1; i++) {
   min = i;
   for (j=i+1; j<n; j++) {
     if (vec[j] < vec[min]) min = j;
     op++;
   } 
   aux = vec[i];
   vec[i] = vec[min];
   vec[min] = aux;
 }
}

#define MAX 10000

//Test Times and operations for different sorting algorithms
void testa_vetores(ostream &co)
{
    long int v[MAX];
    long int i,j;
	clock_t begin, end;
	
	for(long int N=0; N<MAX; N+=5000)
    {	  
      co << N << " ; ";	   
	  cria_vetor(v,N);
	  
      op=0; begin=clock(); 
      cout << "Vetor Inicial: " << endl;
      fich << "Vetor Inicial: " << endl;
      escreve_vetor(v,N);   
      escreve_vetor_file(v,N);   
      end=clock();
      cout << "Escrita: " << diffclock(end,begin) << " ; "<< endl;
      fich <<  "Escrita: " << diffclock(end,begin) << " ; "<< endl;
      fich << endl;
	  co << endl;     
       
      op=0; begin=clock(); 
      cout << "Procura Numero: " << searchNumber << " Encontrou: "<<  ProcuraSeq(v,N, searchNumber)  << endl;
      end=clock();
      cout << "Procura sequencial: " << diffclock(end,begin) << " ; "<< endl;
      co << "Total de Operacoes: " << op << " ; "<< endl;
      co << endl;
     
      fich << "Procura sequencial: " << diffclock(end,begin) << " ; "<< endl;
      fich << "Total de Operacoes: " << op << " ; "<< endl;
      fich << endl;
     
//      op=0; begin=clock();
//	  BubbleSort(v, N);
//	  end=clock();
//	  co << op << " ; " << diffclock(end,begin) << " ; " << endl;
//	  
	  cria_vetor(v,N);
	  op=0; begin=clock();
	  InsertionSort(v, N);
	  end=clock();
	  co << "Insertion Sort ; " << diffclock(end,begin) << " ; "<< endl;
	  co << "Total de Operacoes: " << op << " ; "<< endl;
	  co << endl;
	  
	  fich << "Vetor Ordenado: " << endl;
	  escreve_vetor_file(v,N);  
	  fich << endl;
	  fich << "Insertion Sort ; " << diffclock(end,begin) << " ; "<< endl;
	  fich << "Total de Operacoes: " << op << " ; "<< endl;
	  fich << endl;
	  
	  op=0; begin=clock(); 
      cout << "Procura Numero: " << searchNumber << " Encontrou: "<<  ProcuraBinaria(v,N, searchNumber)  << endl;
      end=clock();
      cout << "Procura Binaria: " << diffclock(end,begin) << " ; "<< endl;
      co << "Total de Operacoes: " << op << " ; "<< endl;
      co << endl;
      
      fich << "Procura Binaria: " << diffclock(end,begin) << " ; "<< endl;
      fich << "Total de Operacoes: " << op << " ; "<< endl;
      fich << endl;
      
      cria_vetor(v,N);
	  op=0; begin=clock();
	  SelectionSort(v, N);
	  end=clock();
	  co << "Selection Sort: " << diffclock(end,begin) << " ; "<< endl;
	  co << "Total de Operacoes: " << op << " ; "<< endl;
	  co << endl;
	  
	  fich << "Selection Sort: " << diffclock(end,begin) << " ; "<< endl;
	  fich << "Total de Operacoes: " << op << " ; "<< endl;
	  fich << endl;
	  
      cria_vetor(v,N);
	  op=0; begin=clock();
      QuickSort(v, 0, N-1);
	  end=clock();
	  co << "Quick Sort: " << diffclock(end,begin) << " ; "<< endl;
	  co << "Total de Operacoes: " << op << " ; "<< endl;
	  fich << "Quick Sort: " << diffclock(end,begin) << " ; "<< endl;
	  fich << "Total de Operacoes: " << op << " ; "<< endl << endl;

   }	     
}

//Simple example counts time to answer with name
void exemplo_timer() {
	string name;
    cout << "Qual e' o teu Nome? ";
	clock_t begin, end;
	begin=clock();
	getline(cin, name);
	end=clock();
	cout << "Tempo Gasto: " << diffclock(end,begin) << " segundos"<< endl;
}

//Simple example counts time an operation for double cicle operation O(N^2)
void exemplo_timer2()
{
    clock_t begin, end;
	ofstream of ("res_ex.txt");
    for(long int lim=0; lim<=10000; lim+=500)
	{
      begin=clock();  
	  op = 0; 
	  for(long int i=0; i<lim; i++) {
          for(long int j=0; j<lim; j++) {
              float x= j/3.0;  //gastar tempo
              op++;
          }
      }         
	  end=clock();
	  of << lim << " ; " << op << " ; " << diffclock(end,begin) << endl;
    }
}

//Main - Calls different tests
int main()
{
    //exemplo_timer();
    //exemplo_timer2();
	testa_vetores(cout);
	ofstream of ("res.txt");
	//testa_vetores(of);
	
    system("PAUSE");
	return 0;
}
