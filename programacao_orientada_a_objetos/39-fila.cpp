// g++ 39-fila.cpp -o fila.exe

#include <iostream>
using namespace std;

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

class Fila
{
private:
  Item *primeiro, *ultimo;

public:
  Fila();
  ~Fila();
  void setPrimeiro(Item *);
  void setUltimo(Item *);
  Item *getPrimeiro();
  Item *getUltimo();
  bool vazia();
  void imprimir();
  void enfileirar(int);
  Item *desenfileirar();
};

Fila::Fila()
{
  this->setPrimeiro(NULL);
  this->setUltimo(NULL);
}

Fila::~Fila()
{
  Item *atu = this->getPrimeiro(), *ant = NULL;
  while (atu != NULL)
  {
    ant = atu;
    atu = atu->getProximo();
    delete ant;
  }
}

void Fila::setPrimeiro(Item *p)
{
  this->primeiro = p;
}

void Fila::setUltimo(Item *p)
{
  this->ultimo = p;
}

Item *Fila::getPrimeiro()
{
  return this->primeiro;
}

Item *Fila::getUltimo()
{
  return this->ultimo;
}

bool Fila::vazia()
{
  return this->getPrimeiro() == NULL && this->getUltimo() == NULL;
}

void Fila::imprimir()
{
  Item *aux = this->getPrimeiro();

  while (aux != NULL)
  {
    cout << aux->getChave() << endl;
    aux = aux->getProximo();
  }
}

void Fila::enfileirar(int x)
{
  Item *novo = new Item(x);
  int dado = novo->getChave();

  if (this->vazia())
  {
    this->setPrimeiro(novo);
    this->setUltimo(novo);
  }

  this->getUltimo()->setProximo(novo);
  this->setUltimo(novo);
  novo->setProximo(NULL);
}

Item *Fila::desenfileirar()
{
  Item *inicio = this->getPrimeiro();
  int x = inicio->getChave();

  this->setPrimeiro(primeiro->getProximo());

  delete (inicio);

  if (this->getPrimeiro() == NULL)
    this->setUltimo(NULL);

  cout << "<" << x << ">" << endl;

  return 0;
}

int main()
{
  char op;
  int x;
  Fila *fila = new Fila();
  while (cin >> op)
  {
    switch (op)
    {
    case 'E':
      cin >> x;
      fila->enfileirar(x);
      break;

    case 'D':
      if (!fila->vazia())
        fila->desenfileirar();

      break;

    case 'M':
      fila->imprimir();
      break;
    }
  }
  delete fila;
  return 0;
}
