// g++ 36-filaCircular.cpp -o filaCircular.exe

#include <iostream>

using namespace std;

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
  if (!this->cheia())
  {
    this->setItens(this->getFim(), x);

    int fim = (this->getFim() + 1) % this->getTamanho();
    this->setFim(fim);

    if (this->getInicio() == -1)
      this->setInicio(0);
  }
}

int FilaCircular::desenfileirar()
{
  if (!this->vazia())
  {
    int item = this->getItens(this->getInicio());
    int inicio = (this->getInicio() + 1) % this->getTamanho();

    this->setInicio(inicio);

    cout << item << endl;

    return item;
  }
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

      if (x > 0)
        fila.enfileirar(x);
      break;

    case 'D':
      fila.desenfileirar();
      break;
    }
  }
  return 0;
}
