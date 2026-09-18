
// Sofia Leite Pereira da Costa

#include <iostream>

using namespace std;

void leitura(int matriz[2][3][4])
{
    cout << "Digite os elementos da matriz (2x3x4):\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> matriz[i][j][k];
            }
        }
    }
}

void impressao(int matriz[2][3][4])
{
    cout << "Matriz (2x3x4)";
    for (int i = 0; i < 2; i++)
    {
        cout << "1ª dimensão " << i << ":";
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << matriz[i][j][k] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int soma(int matriz[2][3][4])
{
    int s = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                s += matriz[i][j][k];
            }
        }
    }
    return s;
}

int maior(int matriz[2][3][4])
{
    int maior = matriz[0][0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (matriz[i][j][k] > maior)
                {
                    maior = matriz[i][j][k];
                }
            }
        }
    }
    return maior;
}

int menor(int matriz[2][3][4])
{
    int menor = matriz[0][0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (matriz[i][j][k] < menor)
                {
                    menor = matriz[i][j][k];
                }
            }
        }
    }
    return menor;
}

int pares(int matriz[2][3][4])
{
    int par = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (matriz[i][j][k] % 2 == 0)
                {
                    par++;
                }
            }
        }
    }
    return par;
}

int impares(int matriz[2][3][4])
{
    int impar = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (matriz[i][j][k] % 2 != 0)
                {
                    impar++;
                }
            }
        }
    }
    return impar;
}

int main()
{

    int matriz[2][3][4];

    leitura(matriz);
    impressao(matriz);

    cout << "--- Resultados ---\n\n";
    cout << "Soma de todos os elementos: " << soma(matriz) << endl;
    cout << "Maior elemento: " << maior(matriz) << endl;
    cout << "Menor elemento: " << menor(matriz) << endl;
    cout << "Quantidade de pares: " << pares(matriz) << endl;
    cout << "Quantidade de impares: " << impares(matriz) << endl;
}