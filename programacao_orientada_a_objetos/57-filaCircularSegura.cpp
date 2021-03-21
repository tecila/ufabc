// g++ 57-filaCircularSegura.cpp -o filaCircularSegura.exe

#include <iostream>

using namespace std;

class FilaCheiaException : public runtime_error
{
public:
  FilaCheiaException() : runtime_error("Runtime Error: Fila Cheia")
  {
  }
};

class FilaVaziaException : public runtime_error
{
public:
  FilaVaziaException() : runtime_error("Runtime Error: Fila Vazia")
  {
  }
};

class FilaCircular
{
private:
  int *itens;
  int tamanho;
  int inicio;
  int fim;

public:
  FilaCircular(int);
  ~FilaCircular();

  void setItens(int, int);
  void setTamanho(int);
  void setInicio(int);
  void setFim(int);

  int getItens(int);
  int getTamanho();
  int getInicio();
  int getFim();

  bool vazia();
  bool cheia();

  void enfileirar(int);
  int desenfileirar();
};

FilaCircular::FilaCircular(int tam)
{
  this->setTamanho(tam);
  this->itens = new int[tam];
  this->setFim(0);
  this->setInicio(0);
}

FilaCircular::~FilaCircular()
{
  delete[] this->itens;
}

void FilaCircular::setItens(int i, int valor)
{
  this->itens[i] = valor;
}

void FilaCircular::setTamanho(int tam)
{
  this->tamanho = tam;
}

void FilaCircular::setInicio(int t)
{
  this->inicio = t;
}

void FilaCircular::setFim(int t)
{
  this->fim = t;
}

int FilaCircular::getItens(int indice)
{
  return this->itens[indice];
}

int FilaCircular::getTamanho()
{
  return this->tamanho;
}

int FilaCircular::getInicio()
{
  return this->inicio;
}

int FilaCircular::getFim()
{
  return this->fim;
}

bool FilaCircular::vazia()
{
  return this->getInicio() == this->getFim();
}

bool FilaCircular::cheia()
{
  return ((this->getFim() + 1) % this->getTamanho()) == this->getInicio();
}

void FilaCircular::enfileirar(int x)
{
  if (this->cheia())
    throw FilaCheiaException();

  this->setItens(this->getFim(), x);

  int fim = (this->getFim() + 1) % this->getTamanho();
  this->setFim(fim);

  if (this->getInicio() == -1)
    this->setInicio(0);
}

int FilaCircular::desenfileirar()
{
  if (this->vazia())
    throw FilaVaziaException();

  int item = this->getItens(this->getInicio());
  int inicio = (this->getInicio() + 1) % this->getTamanho();

  this->setInicio(inicio);

  cout << item << endl;

  return item;
}

int main()
{
  int n, x;

  cin >> n;

  FilaCircular fila(n);
  char op;
  while (cin >> op)
  {
    switch (op)
    {
    case 'E':
      cin >> x;

      try
      {
        fila.enfileirar(x);
      }
      catch (FilaCheiaException e)
      {
        cout << e.what() << endl;
      }
      break;

    case 'D':
      try
      {
        fila.desenfileirar();
      }
      catch (FilaVaziaException e)
      {
        cout << e.what() << endl;
      }
      break;
    }
  }
  return 0;
}
