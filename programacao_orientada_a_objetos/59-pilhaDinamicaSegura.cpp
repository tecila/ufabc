// g++ 59-pilhaDinamicaSegura.cpp -o pilhaDinamicaSegura.exe
#include <iostream>

using namespace std;

class PilhaVaziaException : public underflow_error
{
public:
  PilhaVaziaException() : underflow_error("Underflow Error: Pilha Vazia.")
  {
  }
};

class Item
{
private:
  int chave;
  Item *proximo;

public:
  Item(int);
  void setChave(int);
  int getChave();
  void setProximo(Item *);
  Item *getProximo();
};

Item::Item(int x)
{
  this->setChave(x);
  this->setProximo(NULL);
}

void Item::setChave(int x)
{
  this->chave = x;
}

int Item::getChave()
{
  return this->chave;
}

void Item::setProximo(Item *p)
{
  this->proximo = p;
}

Item *Item::getProximo()
{
  return this->proximo;
}

class Pilha
{
private:
  Item *topo;
  int quantidade;

public:
  Pilha();
  ~Pilha();
  void setTopo(Item *);
  void setQuantidade(int);

  Item *getTopo();
  int getQuantidade();
  bool vazia();
  void imprimir();
  void empilhar(int);
  int desempilhar();
};

Pilha::Pilha()
{
  this->setTopo(NULL);
  this->setQuantidade(0);
}

Pilha::~Pilha()
{
  Item *atu = this->getTopo(), *ant = NULL;
  while (atu != NULL)
  {
    ant = atu;
    atu = atu->getProximo();
    delete ant;
  }
}

void Pilha::setTopo(Item *p)
{
  this->topo = p;
}

void Pilha::setQuantidade(int q)
{
  this->quantidade = q;
}

Item *Pilha::getTopo()
{
  return this->topo;
}

int Pilha::getQuantidade()
{
  return this->quantidade;
}

bool Pilha::vazia()
{
  return this->getTopo() == NULL;
}

void Pilha::imprimir()
{
  if (this->vazia())
    throw PilhaVaziaException();

  Item *atu = this->getTopo();
  int i, n = this->getQuantidade();
  for (i = 0; i < n - 1; i++)
  {
    cout << atu->getChave() << " ";
    atu = atu->getProximo();
  }
  if (n > 0)
  {
    cout << atu->getChave() << "\n";
  }
}

void Pilha::empilhar(int x)
{
  Item *novo = new Item(x);
  novo->setProximo(this->getTopo());
  this->setTopo(novo);
  this->setQuantidade(this->getQuantidade() + 1);
}

int Pilha::desempilhar()
{
  if (this->vazia())
    throw PilhaVaziaException();

  Item *rem = this->getTopo();
  int x = rem->getChave();
  this->setTopo(rem->getProximo());
  delete rem;
  this->setQuantidade(this->getQuantidade() - 1);
  return x;
}

int main()
{
  char op;
  int x;
  Pilha *pilha = new Pilha();
  while (cin >> op)
  {
    switch (op)
    {
    case 'E':
      cin >> x;
      pilha->empilhar(x);
      break;

    case 'D':
      try
      {
        x = pilha->desempilhar();
        cout << "[" << x << "]\n";
      }
      catch (PilhaVaziaException e)
      {
        cout << e.what() << endl;
      }
      break;

    case 'M':
      try
      {
        pilha->imprimir();
      }
      catch (PilhaVaziaException e)
      {
        cout << e.what() << endl;
      }
      break;
    }
  }
  delete pilha;
  return 0;
}
