// g++ 33-les.cpp -o les.exe

#include <iostream>

using namespace std;

class Lista
{
private:
  int *itens;
  int tamanho;
  int quantidade;

public:
  Lista(int);
  ~Lista();

  void setTamanho(int);
  void setQuantidade(int);
  void setItens(int, int);

  int getTamanho();
  int getQuantidade();
  int getItens(int);

  bool cheia();
  bool vazia();

  void mostra();
  int busca(int);
  void inserir(int);
  void remover(int);
};

Lista::Lista(int tam)
{
  this->setTamanho(tam);
  this->itens = new int[tam];
  this->setQuantidade(0);
}

Lista::~Lista()
{
  delete[] this->itens;
}

void Lista::setTamanho(int tam)
{
  this->tamanho = tam;
}

void Lista::setQuantidade(int q)
{
  this->quantidade = q;
}

void Lista::setItens(int indice, int valor)
{
  this->itens[indice] = valor;
}

int Lista::getTamanho()
{
  return this->tamanho;
}

int Lista::getQuantidade()
{
  return this->quantidade;
}

int Lista::getItens(int indice)
{
  return this->itens[indice];
}

bool Lista::cheia()
{
  return this->getQuantidade() == this->getTamanho();
}

bool Lista::vazia()
{
  return this->getQuantidade() == 0;
}

void Lista::mostra()
{
  int i, n = this->getQuantidade();

  for (i = 0; i < n; i++)
  {
    cout << this->getItens(i) << "\n";
  }
}

int Lista::busca(int x)
{
  int i;

  for (i = 0; i < this->getQuantidade(); i++)
  {
    if (this->getItens(i) == x)
      return i;
  }
  return -1;
}

void Lista::inserir(int x)
{
  if (this->vazia())
  {
    this->setQuantidade(1);
    this->setItens(0, x);
  }
  else
  {
    int i = 0;

    while (i < this->getQuantidade() && x > this->getItens(i))
    {
      i++;
    }
    if (i == this->getQuantidade())
    {
      this->setQuantidade(this->getQuantidade() + 1);
      this->setItens(i, x);
    }
    else if (x != this->getItens(i))
    {
      int j;
      for (j = this->getQuantidade() - 1; j >= i; j--)
      {
        this->setItens(j + 1, this->getItens(j));
      }
      this->setQuantidade(this->getQuantidade() + 1);
      this->setItens(i, x);
    }
  }
}

void Lista::remover(int x)
{
  int i = this->busca(x);

  if (i >= 0)
  {
    int j;
    for (j = i; j <= this->getQuantidade() - 2; j++)
    {
      this->setItens(j, this->getItens(j + 1));
    }

    this->setQuantidade(this->getQuantidade() - 1);
  }
}

int main()
{
  int q, i, x;
  char op;

  cin >> q;

  Lista lista(q);

  for (i = 0; i < q; i++)
  {
    cin >> op >> x;

    switch (op)
    {
    case 'I':
      if (x > 0)
      {
        lista.inserir(x);
        break;
      }
    case 'E':
      lista.remover(x);
      break;
    }
  }
  lista.mostra();
  return 0;
}
