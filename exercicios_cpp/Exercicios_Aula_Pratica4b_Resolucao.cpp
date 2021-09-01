/*
Exercicio 4b
Um programa de gestão de um clube desportivo guarda informação sobre o seu 
pessoal, que inclui atletas, professores e sócios. Sabendo que:
  - Todo o pessoal do clube desportivo é identificado por um código único 
    e sequencial e possui um nome e uma data de admissão no clube.
  - Existem diversas turmas, cada qual identificada por uma letra. 
    Cada turma tem uma única modalidade. A turma deve especificar o seu 
    horário semanal composto por várias aulas (número de aulas 
    indefinido). Sugestão: use um vetor de aulas.
  - Cada aula tem um dia da semana, uma hora de início e uma duração.
  - Existem diversas modalidades, cada qual com um número e uma 
    designação.
  - Os atletas estão inscritos numa única modalidade e numa determinada 
    turma. 
  - Os professores lecionam uma determinada modalidade a várias turmas e 
    têm um salário. Lecionam todas as aulas da respetiva turma.
  - Os sócios pagam uma determinada quota mensal e podem ser de três 
    tipos: normal, privilegiado e vip. 
Implemente a hierarquia de classes que na sua opinião melhor descreve o 
cenário acima, especificando os dados e métodos de cada classe. Justifique 
a sua escolha. Nota: Não é necessário implementar qualquer método, 
simplesmente definir os ficheiros *.h das classes respectivas.
*/
//Nota: Topicos de resolução. Exercicio não está completo:

class CDate {
   int dia, mes, ano;    
};

class CPessoal {
   protected:
       int codigo;
       string nome;
       CDate data_adm;
   public:
       CPessoal(int, string, CDate);
};

class CModalidade {
   protected:  
       int numero;
       string designacao;
};
      
class CAula {
      int dia, hora, duracao;
};

class CTurma {
   protected:  
       char idturma;
       CModalidade mod;
       vector <CAula> aulas;
};      

class CProfessor: public CPessoal {
   protected:  
        CModalidade mod;
        double salario;      
};

class CAtletas: public CPessoal {
   protected:  
        //CModalidade mod;
        CTurma turma;      
};

class CSocios: public CPessoal {
   protected:  
        double quota;
        string tipo;      
};

