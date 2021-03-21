// g++ 35-fila.cpp -o fila.exe

#include <iostream>

using namespace std;

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
  this->setInicio(-1);
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
  return this->getInicio() > this->getFim();
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
  int n, x;

  cin >> n;

  Fila fila(n);
  char op;

  while (cin >> op)
  {
    switch (op)
    {
    case 'E':
      cin >> x;

      if (x > 0)
      {
        fila.enfileirar(x);
      }
      break;

    case 'D':
      fila.desenfileirar();
      break;
    }
  }
  return 0;
}
