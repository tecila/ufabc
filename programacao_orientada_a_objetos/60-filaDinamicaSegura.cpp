// g++ 60-filaDinamicaSegura.cpp -o filaDinamicaSegura.exe

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

class Fila
{
private:
  int *itens;
  int tamanho;
  int inicio;
  int fim;

public:
  Fila(int);
  ~Fila();

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
  void limpa();

  void enfileirar(int);
  int desenfileirar();
};

Fila::Fila(int tam)
{
  this->setTamanho(tam);
  this->itens = new int[tam];
  this->setFim(-1);
  this->setInicio(0);
}

Fila::~Fila()
{
  delete[] this->itens;
}

void Fila::setItens(int i, int valor)
{
  this->itens[i] = valor;
}

void Fila::setTamanho(int tam)
{
  this->tamanho = tam;
}

void Fila::setInicio(int t)
{
  this->inicio = t;
}

void Fila::setFim(int t)
{
  this->fim = t;
}

int Fila::getItens(int indice)
{
  return this->itens[indice];
}

int Fila::getTamanho()
{
  return this->tamanho;
}

int Fila::getInicio()
{
  return this->inicio;
}

int Fila::getFim()
{
  return this->fim;
}

bool Fila::vazia()
{
  return this->getFim() < this->getInicio();
}

bool Fila::cheia()
{
  return this->getFim() == this->getTamanho() - 1;
}

void Fila::limpa()
{
  this->setInicio(-1);
  this->setFim(-1);
}

void Fila::enfileirar(int x)
{
  if (this->vazia())
  {
    this->limpa();
  }

  if (this->cheia())
    throw FilaCheiaException();

  if (!this->cheia())
  {
    this->setFim(this->getFim() + 1);
    this->setItens(this->getFim(), x);

    if (this->getInicio() == -1)
      this->setInicio(0);
  }
}

int Fila::desenfileirar()
{
  if (this->vazia())
    throw FilaVaziaException();

  if (!this->vazia())
  {
    int item = this->getItens(this->getInicio());
    this->setInicio(this->getInicio() + 1);

    cout << item << endl;

    return item;
  }
}

int main()
{
  int x;
  char op;

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
      try
      {
        fila->desenfileirar();
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
