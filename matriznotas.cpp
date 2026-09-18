
// Sofia Leite Pereira da Costa

#include <iostream>

using namespace std;

const int T = 3;
const int A = 5;
const int N = 3;

void leitura_notas(float Matriz[T][A][N], int i, int j, int k)
{
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < A; j++)
        {
            for (k = 0; k < N; k++)
            {
                cout << "Digite a nota " << k + 1 << " da turma " << i + 1 << " do aluno " << j + 1 << ":\n";
                cin >> Matriz[i][j][k];
            }
        }
    }
}

float media_aluno(float Matriz[T][A][N], int i, int j, int k, float s, int turma, int aluno, float vm)
{
    s = 0;
    cout << "Escolha uma turma e um aluno:";
    cin >> turma >> aluno;
    turma--; 
    aluno--;
    if (turma >= 0 && turma < T && aluno >= 0 && aluno < A)
    {
        for ( i = 0; i < N; i++)
        {
            s = s + Matriz[turma][aluno][i];
        }
        return s / N;
    }

    return 0;
}

void media_turmas(float Matriz[T][A][N], int i, int j, int k, float s, int turma, int aluno, float vm, float ma, int qtd, int maior_m, float s_turma, float s_aluno)
{
     qtd = 0;
    for ( i = 0; i < T; i++)
    {
        s_turma = 0;
        ma = 0;
        maior_m = 0;

        for ( j = 0; j < A; j++)
        {
            s_aluno = 0;

            for ( k = 0; k < N; k++)
            {
                s_aluno = s_aluno + Matriz[i][j][k];
                s_turma = s_turma + Matriz[i][j][k];
            }

             vm = s_aluno / N;

            if (vm > ma)
            {
                ma = vm;
                maior_m = j;
            }

            if (vm > 7.0)
            {
                qtd++;
            }
        }

        cout << "\nA media da Turma " << i + 1 << " foi: " << s_turma / (A * N) << "\n";
        cout << "O aluno com maior media da Turma " << i + 1 << " foi o Aluno " << maior_m + 1 << " (Media: " << ma << ")\n";
    }

    cout << "\nQuantidade total de alunos aprovados (> 7.0): " << qtd << "\n";
}

float media_geral(float Matriz[T][A][N], int i, int j, int k, float s, int turma, int aluno, float vm, float ma)
{
     ma = 0;

    for ( i = 0; i < T; i++)
    {
        for ( j = 0; j < A; j++)
        {
             s = 0;
            for (int k = 0; k < N; k++)
            {
                s = s + Matriz[i][j][k];
            }
             vm = s / N;

            if (vm > ma)
            {
                ma = vm;
            }
        }
    }

    return ma;
}

int main()
{

    float Matriz[T][A][N], ma, s_turma, s_aluno, vm;
    int i, j, k, s, turma, aluno, qtd, maior_m;

    leitura_notas(Matriz, i, j, k);
    
    cout << "A média do aluno escolhido foi de " << media_aluno(Matriz, i, j, k, vm, s, ma, turma) << ".";

     media_turmas(Matriz, i, j, k, vm, s, ma, turma, aluno, qtd, maior_m, s_turma, s_aluno);

    media_geral(Matriz, i, j, k, s, turma, aluno, vm, ma);
    cout << "A maior média geral foi de " << media_geral(Matriz, i, j, k, s, turma, aluno, vm, ma) << ".";
}