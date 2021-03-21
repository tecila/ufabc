// g++ 34-pilha.cpp -o pilha.exe

#include <iostream>

using namespace std;

class Pilha
{
private:
  int *itens;
  int tamanho;
  int topo;

public:
  Pilha(int);
  ~Pilha();
  /* criar metodos "set" e "get" */
  void setItens(int, int);
  void setTamanho(int);
  void setTopo(int);

  int getItens(int);
  int getTamanho();
  int getTopo();

  bool vazia();
  bool cheia();
  void printBottomUp();
  void printTopDown();
  void empilhar(int);
  int desempilhar();
};

Pilha::Pilha(int tam)
{
  this->setTamanho(tam);
  this->itens = new int[tam];
  this->setTopo(-1);
}

Pilha::~Pilha()
{
  delete[] this->itens;
}

void Pilha::setItens(int i, int valor)
{
  this->itens[i] = valor;
}

void Pilha::setTamanho(int tam)
{
  this->tamanho = tam;
}

void Pilha::setTopo(int t)
{
  this->topo = t;
}

int Pilha::getItens(int indice)
{
  return this->itens[indice];
}

int Pilha::getTamanho()
{
  return this->tamanho;
}

int Pilha::getTopo()
{
  return this->topo;
}

bool Pilha::vazia()
{
  return this->getTopo() == -1;
}

bool Pilha::cheia()
{
  return this->getTopo() == this->getTamanho();
}

void Pilha::printBottomUp()
{
  int n = this->getTopo() + 1;

  for (int i = 0; i < n; i++)
  {
    cout << this->getItens(i) << "\n";
  }
}

void Pilha::printTopDown()
{
  int i, n = this->getTopo();

  for (i = n; i >= 0; i--)
  {
    cout << this->getItens(i) << "\n";
  }
}

void Pilha::empilhar(int x)
{
  if (this->getTopo() == -1)
  {
    this->setItens(0, x);
    this->setTopo(this->getTopo() + 1);
  }
  else if (!this->cheia())
  {
    int n = this->getTopo() + 1;
    this->setItens(n, x);
    this->setTopo(this->getTopo() + 1);
  }
}

int Pilha::desempilhar()
{
  if (this->getTopo() != -1)
  {
    int n = this->getTopo();
    int valor = this->getItens(n);
    this->setTopo(this->getTopo() - 1);
    return valor;
  }
  return 0;
}

int main()
{
  int n, x;
  cin >> n;
  Pilha pilha(n);
  char op;
  while (cin >> op)
  {
    switch (op)
    {
    case 'E':
      cin >> x;

      if (!pilha.cheia())
        pilha.empilhar(x);
      break;

    case 'D':
      if (!pilha.vazia())
        x = pilha.desempilhar();
      break;

    case 'T':
      pilha.printTopDown();
      break;

    case 'B':
      pilha.printBottomUp();

      break;
    }
  }
  return 0;
}
