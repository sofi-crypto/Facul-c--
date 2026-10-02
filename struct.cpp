#include <iostream>

using namespace std;

struct Funcionario
{
    char nome[50];
    int id;
    float salario;
    int departamento;
};

void salarios(Funcionario cliente[5])
{
    int s = 0;
    int dep;
    cout << "\nEscolha um departamento:";
    cin >> dep;
    for (int i = 0; i < 5; i++)
    {
        if (cliente[i].departamento == dep)
        {
            s += cliente[i].salario;
        }
    }
    cout << "O total de salarios no departamento" << dep << "foi de " << s << endl;
}

int main()
{

    Funcionario cliente[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Digite as informacoes (nome, id, salario e departamento): ";
        cin >> cliente[i].nome >> cliente[i].id >> cliente[i].salario >> cliente[i].departamento;
    }
    cout << "------- Lista de funcionarios --------\n\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "\t" << cliente[i].nome << endl;
    }

    salarios(cliente);
}