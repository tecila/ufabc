// g++ 37-lde.cpp -o lde.exe
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

class Lista
{
private:
  Item *primeiro;
  int quantidade;

public:
  Lista();
  ~Lista();
  void setPrimeiro(Item *);
  void setQuantidade(int);
  Item *getPrimeiro();
  int getQuantidade();
  bool vazia();
  void imprimir();
  void inserir(int);
  Item *buscar(int);
  Item *remover(int);
};

Lista::Lista()
{
  this->setPrimeiro(NULL);
  this->setQuantidade(0);
}

Lista::~Lista()
{
  Item *atu = this->getPrimeiro(), *ant = NULL;
  while (atu != NULL)
  {
    ant = atu;
    atu = atu->getProximo();
    delete ant;
  }
}

void Lista::setPrimeiro(Item *p)
{
  this->primeiro = p;
}

void Lista::setQuantidade(int q)
{
  this->quantidade = q;
}

Item *Lista::getPrimeiro()
{
  return this->primeiro;
}

int Lista::getQuantidade()
{
  return this->quantidade;
}

bool Lista::vazia()
{
  return this->getQuantidade() == 0;
}

void Lista::imprimir()
{
  Item *atu = this->getPrimeiro();
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

void Lista::inserir(int x)
{
  Item *novo = new Item(x);

  if (this->vazia())
  {
    this->setPrimeiro(novo);
    this->setQuantidade(1);
  }
  else
  {
    Item *atu = this->getPrimeiro(), *ant = NULL;
    while (atu != NULL && x > atu->getChave())
    {
      ant = atu;
      atu = atu->getProximo();
    }

    if (atu == NULL)
    {
      ant->setProximo(novo);
      this->setQuantidade(this->getQuantidade() + 1);
    }
    else if (atu->getChave() != x)
    {
      if (ant == NULL)
      {
        novo->setProximo(this->getPrimeiro());
        this->setPrimeiro(novo);
      }
      else
      {
        ant->setProximo(novo);
        novo->setProximo(atu);
      }
      this->setQuantidade(this->getQuantidade() + 1);
    }
    else
    {
      delete novo;
    }
  }
}

Item *Lista::buscar(int x)
{
  Item *atu = this->getPrimeiro();
  while (atu != NULL && atu->getChave() != x)
  {
    atu = atu->getProximo();
  }
  return atu;
}

Item *Lista::remover(int x)
{
  Item *atu = this->getPrimeiro(), *ant = NULL;

  while (atu != NULL && atu->getChave() < x)
  {
    ant = atu;
    atu = atu->getProximo();
  }

  if (atu != NULL && atu->getChave() == x)
  {
    if (ant == NULL)
      this->setPrimeiro(atu->getProximo());
    else
      ant->setProximo(atu->getProximo());
    this->setQuantidade(this->getQuantidade() - 1);
    return atu;
  }
  return NULL;
}

int main()
{
  char op;
  int x;
  Lista *lista = new Lista();
  while (cin >> op)
  {
    Item *rem = NULL;
    switch (op)
    {
    case 'I':
      cin >> x;
      lista->inserir(x);
      break;
    case 'R':
      cin >> x;
      rem = lista->remover(x);
      if (rem != NULL)
        delete rem;
      break;
    case 'B':
      cin >> x;
      if (lista->buscar(x))
        cout << "SIM\n";
      else
        cout << "NAO\n";
      break;
    case 'L':
      lista->imprimir();
      break;
    }
  }
  delete lista;
  return 0;
}
