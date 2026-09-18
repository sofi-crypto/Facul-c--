
// Sofia Leite Pereira da Costa

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int T = 5;

int verificacao_k(int K, int &QTD, int j, int i, int matriz[T][T], int VLinha[], int VColuna[])
{
    QTD = 0;

    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            if (matriz[i][j] == K)
            {
                VLinha[QTD] = i;
                VColuna[QTD] = j;
                QTD++;
            }
        }
    }
}

int main()
{
    int matriz[T][T];
    int K, i, j, QTD;
    int VLinha[T * T];
    int VColuna[T * T];
    char resp;

    srand(time(0));

    cout << "\nDeseja digitar a matriz (S - sim) (N - nao): ";
    cin >> resp;

    switch (resp)
    {
    case 'S':
    case 's':
        cout << "Digite a Matrix (5x5):";
        for (i = 0; i < T; i++)
        {
            for (j = 0; j < T; j++)
            {
                cin >> matriz[i][j];
            }
        }

        cout << setw(4) << " ";
        for (j = 0; j < T; j++)
        {
            cout << setw(8) << j;
        }
        cout << "\n\n";
        for (i = 0; i < T; i++)
        {
            cout << setw(4) << i ;
            for (j = 0; j < T; j++)
            {
                cout << setw(8) << matriz[i][j];
            }
            cout << "\n\n";
        }

        break;

    case 'N':
    case 'n':
        cout << "\nGerando a matriz (5x5).\n\n";
        for (i = 0; i < T; i++)
        {
            for (j = 0; j < T; j++)
            {
                matriz[i][j] = rand() % 15;
            }
        }

      cout << setw(4) << " ";
        for (j = 0; j < T; j++)
        {
            cout << setw(8) << j;
        }
        cout << "\n\n";

        for (i = 0; i < T; i++)
        {
            cout << setw(4) << i ;
            for (j = 0; j < T; j++)
            {
                 cout << setw(8) << matriz[i][j] << "|";
            }
            cout << "\n\n";
        }

        break;

    default:
        cout << "\nOpção invalida";

        break;
    }

    cout << "\nDigite o valor de verificacao (K):";
    cin >> K;

    verificacao_k(K, QTD, j, i, matriz, VLinha, VColuna);
    cout << "\nO numero " << K << " apareceu " << QTD << " vezes.\n";

    if (QTD > 0)
    {
        cout << "\nNas posicoes:\n";
        for (i = 0; i < QTD; i++)
        {
            cout << "Linha " << VLinha[i] << "  |  " << "Coluna " << VColuna[i] << ".\n";
        }
    }
}
