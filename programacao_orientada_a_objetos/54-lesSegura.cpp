// g++ 54-lesSegura.cpp -o lesSegura.exe

#include <iostream>

using namespace std;

class ChaveExistenteException : public logic_error
{
public:
  ChaveExistenteException() : logic_error("LogicError: Chave existente na lista.")
  {
  }
};

class ChaveInexistenteException : public logic_error
{
public:
  ChaveInexistenteException() : logic_error("LogicError: Chave inexistente na lista.")
  {
  }
};

class PosicaoInvalidaException : public runtime_error
{
public:
  PosicaoInvalidaException() : runtime_error("RuntimeError: Posicao da lista inexistente.")
  {
  }
};

class ListaCheiaException : public runtime_error
{
public:
  ListaCheiaException() : runtime_error("RuntimeError: Lista cheia.")
  {
  }
};

class ListaVaziaException : public runtime_error
{
public:
  ListaVaziaException() : runtime_error("RuntimeError: Lista Vazia.")
  {
  }
};

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
  int buscaPosicao(int);
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
  if (this->vazia())
    throw ListaVaziaException();

  int i, n = this->getQuantidade();

  for (i = 0; i < n; i++)
  {
    cout << this->getItens(i) << "\n";
  }
}

int Lista::busca(int x)
{
  if (this->vazia())
    throw ListaVaziaException();

  int i;

  for (i = 0; i < this->getQuantidade(); i++)
  {
    if (this->getItens(i) == x)
      return i;
  }
  return -1;
}

int Lista::buscaPosicao(int i)
{
  if (this->vazia())
    throw ListaVaziaException();

  if (this->getTamanho() < i || i < 0)
    throw PosicaoInvalidaException();

  return this->getItens(i);
}

void Lista::inserir(int x)
{
  if (!this->vazia())
    if (this->busca(x) != -1)
      throw ChaveExistenteException();

  if (this->cheia())
    throw ListaCheiaException();

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
  if (this->busca(x) == -1)
    throw ChaveInexistenteException();

  if (this->vazia())
    throw ListaVaziaException();

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
  char op;
  int x, q;

  cin >> q;

  Lista lista(q);

  while (cin >> op)
  {
    switch (op)
    {
    case 'I':
      try
      {
        cin >> x;
        lista.inserir(x);
      }
      catch (ListaCheiaException e)
      {
        cout << e.what() << endl;
      }
      catch (ChaveExistenteException e)
      {
        cout << e.what() << endl;
      }
      break;

    case 'E':
      try
      {
        cin >> x;
        lista.remover(x);
      }
      catch (ListaVaziaException e)
      {
        cout << e.what() << endl;
      }
      catch (ChaveInexistenteException e)
      {
        cout << e.what() << endl;
      }
      break;

    case 'B':
      try
      {
        cin >> x;
        lista.busca(x);
      }
      catch (ListaVaziaException e)
      {
        cout << e.what() << endl;
      }
      break;

    case 'M':
      try
      {
        lista.mostra();
      }
      catch (ListaVaziaException e)
      {
        cout << e.what() << endl;
      }
      break;

    case 'C':
      try
      {
        cin >> x;
        cout << "<" << lista.buscaPosicao(x) << ">" << endl;
      }
      catch (ListaVaziaException e)
      {
        cout << e.what() << endl;
      }
      catch (PosicaoInvalidaException e)
      {
        cout << e.what() << endl;
      }
      break;
    }
  }
  return 0;
}
