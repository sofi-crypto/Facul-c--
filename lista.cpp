#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

const int m = 20;

struct filmes
{
    string nome;
    string genero;
    string diretor;
    int ano;
    float nota;
};

filmes lista[m];

void MostrarLista(int final) // imprime a lista de filmes inteira
{
    cout << "----------------------------------------\n";
    for (int i = 0; i <= final; i++)
    {
        cout << "Nome: " << lista[i].nome << endl;
        cout << "Gênero: " << lista[i].genero << endl;
        cout << "Diretor: " << lista[i].diretor << endl;
        cout << "Ano: " << lista[i].ano << endl;
        cout << "Nota: " << fixed << setprecision(1) << lista[i].nota << endl;
        cout << "----------------------------------------\n";
    }
}

void adicionarfinal(int &final) // 01. Inserir um filme no final da lista || &: Como o tamanho da lista é alterado, o & faz com que a alteração de tamanho chegue diretamente no main.
// Caso não utilizássemos o &, a função passaria de void para int, retornaria o novo valor de final (return final;) e o main precisaria recebê-lo (final = adicionarfinal(final);).
{

    if (final >= m - 1)
    {
        cout << "Lista cheia. Não é possível adicionar mais filmes.\n";
    }
    else
    {
        final++;
        cout << "\nDigite o nome do filme: ";
        getline(cin >> ws, lista[final].nome);
        cout << "\nDigite o gênero do filme: ";
        getline(cin >> ws, lista[final].genero);
        cout << "\nDigite o diretor do filme: ";
        getline(cin >> ws, lista[final].diretor);
        cout << "\nDigite o ano do filme: ";
        cin >> lista[final].ano;
        cin.ignore();
        cout << "\nDigite a nota do filme: ";
        cin >> lista[final].nota;
        cin.ignore();
    }
}

void adicionaraposprimeiro(int &final) // 02.Inserir um filme após o primeiro filme cadastrado
{
    if (final >= m - 1)
    {
        cout << "Lista cheia. Não é possível adicionar mais filmes.\n";
    }
    else if (final < 0)
    {
        cout << "Lista vazia. Não é possível adicionar após o primeiro filme.\n";
    }
    else
    {
        final++;
        int aux = final;
        for (; aux > 0; aux--)
        {
            lista[aux] = lista[aux - 1];
        }
        cout << "\nDigite o nome do filme: ";
        getline(cin >> ws, lista[aux + 1].nome);
        cout << "\nDigite o gênero do filme: ";
        getline(cin >> ws, lista[aux + 1].genero);
        cout << "\nDigite o diretor do filme: ";
        getline(cin >> ws, lista[aux + 1].diretor);
        cout << "\nDigite o ano do filme: ";
        cin >> lista[aux + 1].ano;
        cin.ignore();
        cout << "\nDigite a nota do filme: ";
        cin >> lista[aux + 1].nota;
        cin.ignore();
    }
}
void inseriraposgenero(int &final, string x) // 03.Inserir um filme depois do primeiro filme com gênero igual a x
{
    if (final >= m - 1)
    {
        cout << "Lista cheia. Não é possível adicionar mais filmes.\n";
    }
    else if (final < 0)
    {
        cout << "Lista vazia. Não é possível adicionar após o  do gênero.\n";
    }
    else
    {
        int pos = 0;
        while (pos <= final && lista[pos].genero != x)
        {
            pos++;
        }
        if (pos > final)
        {
            cout << "Nenhum filme encontrado com o gênero " << x << ".\n";
        }
        else if (lista[pos].genero == x)
        {
            final++;
            int aux = final;
            for (; aux != pos; aux--)
            {
                lista[aux] = lista[aux - 1];
            }
            cout << "\nDigite o nome do filme: ";
            getline(cin >> ws, lista[pos + 1].nome);
            cout << "\nDigite o gênero do filme: ";
            getline(cin >> ws, lista[pos + 1].genero);
            cout << "\nDigite o diretor do filme: ";
            getline(cin >> ws, lista[pos + 1].diretor);
            cout << "\nDigite o ano do filme: ";
            cin >> lista[pos + 1].ano;
            cin.ignore();
            cout << "\n Digite a nota do filme: ";
            cin >> lista[pos + 1].nota;
            cin.ignore();
        }
    }
}

int consultaranterior(int final, float y) // 04.Consultar o filme anterior ao primeiro filme com nota igual a y
{
    int pos = 0;
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível consultar filmes.\n";
        return -1;
    }
    else
    {
        while (pos <= final && lista[pos].nota != y)
        {
            pos++;
        }
    }
    if (pos > final)
    {
        cout << "Nenhum filme encontrado com a nota " << y << ".\n";
        return -1;
    }
    else
    {
        if (pos == 0)
        {
            cout << "Não há filme anterior à nota " << y << ".\n";
            return -1;
        }
    }
    return pos - 1;
}

string removerultimo(int &final) // 05.Remover o último filme da lista
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível remover filmes.\n";
        return "";
    }
    else
    {
        string removido = lista[final].nome;
        final--;
        return removido;
    }
}
string removerposterior(int &final, string x) // 06.Remover o filme posterior ao primeiro filme com nome igual a x
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível remover filmes.\n";
        return "";
    }
    else
    {
        int pos = 0;
        while (pos <= final && lista[pos].nome != x)
        {
            pos++;
        }
        if (pos > final)
        {
            cout << "Nenhum filme encontrado com o nome " << x << ".\n";
            return "";
        }
        else if (pos == final)
        {
            cout << "Não há filme posterior ao filme " << x << ".\n";
            return "";
        }
        else
        {
            string removido = lista[pos + 1].nome;
            for (int i = pos + 1; i < final; i++)
            {
                lista[i] = lista[i + 1];
            }
            final--;
            return removido;
        }
    }
}

string consultarprimeiro(int final) // 07.consultar o primeiro filme da lista
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível consultar filmes.\n";
        return "";
    }
    else
    {
        return lista[0].nome;
    }
}

string alterargenero(int final, string x) // 08.Alterar o gênero do filme com diretor igual a y (y alterado para x por já ser string)
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível alterar filmes.\n";
        return "";
    }
    else
    {
        int pos = 0;
        while (pos <= final && lista[pos].diretor != x)
        {
            pos++;
        }
        if (pos > final)
        {
            cout << "Nenhum filme encontrado com o diretor " << x << ".\n";
            return "";
        }
        else
        {
            cout << "Digite o novo gênero do filme: ";
            getline(cin >> ws, lista[pos].genero);
            return lista[pos].nome;
        }
    }
}

void impressaoimpares(int final) // 09.Imprimir os filmes armazenados nas posições ímpares
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível imprimir filmes.\n";
    }
    else
    {
        cout << "Filmes nas posições ímpares...\n";
        for (int i = 1; i <= final; i++)
        {
            if (i % 2 != 0)
            {
                cout << "Nome: " << lista[i].nome << endl;
                cout << "Gênero: " << lista[i].genero << endl;
                cout << "Diretor: " << lista[i].diretor << endl;
                cout << "Ano: " << lista[i].ano << endl;
                cout << "Nota: " << fixed << setprecision(1) << lista[i].nota << endl;
                cout << "----------------------------------------\n";
            }
        }
    }
}

void impressaonotamaior(int final, float y) // 10.Imprimir os filmes  com nota maior ou igual a x (x alterado para y por já ser float)
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível imprimir filmes.\n";
    }
    else
    {
        cout << "Filmes com nota maior ou igual a " << y << "...\n";
        for (int i = 0; i <= final; i++)
        {
            if (lista[i].nota >= y)
            {
                cout << "Nome: " << lista[i].nome << endl;
                cout << "Gênero: " << lista[i].genero << endl;
                cout << "Diretor: " << lista[i].diretor << endl;
                cout << "Ano: " << lista[i].ano << endl;
                cout << "Nota: " << fixed << setprecision(1) << lista[i].nota << endl;
                cout << "----------------------------------------\n";
            }
        }
    }
}

void classificarano(int final) // 11.Classificar a lista em ordem crescente de ano
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível classificar filmes.\n";
    }
    else
    {
        for (int i = 0; i <= final; i++)
        {
            for (int j = 0; j < final - i; j++)
            {
                if (lista[j].ano > lista[j + 1].ano)
                {
                    filmes aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                }
            }
        }
        cout << "Lista de filmes classificada por ano em ordem crescente...\n";
        MostrarLista(final); // impressão utilizando o procedimento
    }
}

void classificarnome(int final) // 12.Classificar e imprimir os filmes em ordem decrescente de nome
{
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível classificar filmes.\n";
    }
    else
    {
        for (int i = 0; i <= final; i++)
        {
            for (int j = 0; j < final - i; j++)
            {
                if (lista[j].nome < lista[j + 1].nome)
                {
                    filmes aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                }
            }
        }
        cout << "Lista de filmes classificada por nome em ordem decrescente de Z a A...\n";
        MostrarLista(final); // impressão utilizando o procedimento
    }
}

void imprimirpordiretor(int final, string x) // 13. Imprimir todos os filmes de um diretor
{
    int pos = 0;
    if (final < 0)
    {
        cout << "Lista vazia. Não é possível imprimir filmes.\n";
    }
    else
    {
        while (pos <= final && lista[pos].diretor != x)
        {
            pos++;
        }
        if (pos > final)
        {
            cout << "Nenhum filme encontrado do diretor " << x << ".\n";
        }
        else
        {
            cout << "Filmes do diretor " << x << ":\n";
            for (int i = 0; i <= final; i++)
            {
                if (lista[i].diretor == x)
                {
                    cout << "Nome: " << lista[i].nome << endl;
                    cout << "Gênero: " << lista[i].genero << endl;
                    cout << "Ano: " << lista[i].ano << endl;
                    cout << "Nota: " << fixed << setprecision(1) << lista[i].nota << endl;
                    cout << "----------------------------------------\n";
                }
            }
        }
    }
}

int main()
{
    system("chcp 65001 > nul"); // Para a acentuação ficar correta
    char resp;
    int qtd;
    int final = -1;
    string x;
    float y;

    srand(time(0)); // usa a hora do computador para gerar uma lista aleatoria a cara "rodada"

    do
    {
        final = -1; // zera a lista a cada vez que inicia o programa

        cout << "\n Deseja digitar a lista de filmes (S - sim) (N - não): "; // leitura nao automática da lista
        cin >> resp;

        switch (resp)
        {
        case 'S':
        case 's':
        {
            cout << "\nDigite a lista de filmes: (Máximo " << m << ")\n";
            cout << "----------------------------------------\n";
            while (final < m - 1)
            {
                final++;
                cout << "Digite o nome do filme: ";
                getline(cin >> ws, lista[final].nome);
                cout << "Digite o gênero do filme: ";
                getline(cin >> ws, lista[final].genero);
                cout << "Digite o diretor do filme: ";
                getline(cin >> ws, lista[final].diretor);
                cout << "Digite o ano do filme: ";
                cin >> lista[final].ano;
                cin.ignore();
                cout << "Digite a nota do filme: ";
                cin >> lista[final].nota;
                cin.ignore();
                cout << "----------------------------------------\n";
                if (final < m - 1)
                {
                    cout << "Deseja continuar digitando a lista de filmes? (S - sim) (N - não): ";
                    cin >> resp;
                    if (resp == 'N' || resp == 'n')
                    {
                        break;
                    }
                }
                else
                {
                    cout << "Lista cheia.\n";
                    break;
                }
            }
            cout << "----------------------------------------\n";
            cout << "Lista de filmes digitada:\n";
            MostrarLista(final);
            break;
        }
        case 'N': // leitura automática da lista
        case 'n':
        {
            const int tot = 20;
            filmes catalogo[tot] = {
                {"Um Sonho de Liberdade", "Drama", "Frank Darabont", 1994, 9.3},
                {"O Poderoso Chefão", "Crime", "Francis Ford Coppola", 1972, 9.2},
                {"Batman: O Cavaleiro das Trevas", "Ação", "Christopher Nolan", 2008, 9.0},
                {"A Lista de Schindler", "Drama", "Steven Spielberg", 1993, 9.0},
                {"O Senhor dos Anéis: A Sociedade do Anel", "Fantasia", "Peter Jackson", 2001, 8.9},
                {"Pulp Fiction", "Crime", "Quentin Tarantino", 1994, 8.9},
                {"Forrest Gump", "Drama", "Robert Zemeckis", 1994, 8.8},
                {"A Origem", "Ficção científica", "Christopher Nolan", 2010, 8.8},
                {"Clube da Luta", "Drama", "David Fincher", 1999, 8.8},
                {"Matrix", "Ficção científica", "Lana e Lilly Wachowski", 1999, 8.7},
                {"Interestelar", "Ficção científica", "Christopher Nolan", 2014, 8.7},
                {"Cidade de Deus", "Crime", "Fernando Meirelles", 2002, 8.6},
                {"Gladiador", "Ação", "Ridley Scott", 2000, 8.5},
                {"Parasita", "Suspense", "Bong Joon-ho", 2019, 8.5},
                {"O Rei Leão", "Animação", "Roger Allers e Rob Minkoff", 1994, 8.5},
                {"De Volta para o Futuro", "Ficção científica", "Robert Zemeckis", 1985, 8.5},
                {"Coringa", "Drama", "Todd Phillips", 2019, 8.4},
                {"Toy Story", "Animação", "John Lasseter", 1995, 8.3},
                {"Titanic", "Romance", "James Cameron", 1997, 7.9},
                {"Avatar", "Ficção científica", "James Cameron", 2009, 7.9}};

            cout << "\n Quantos filmes deseja adicionar à lista? (Máximo " << m << "): ";
            cin >> qtd;
            if (qtd > m || qtd <= 0)
            {
                cout << "Quantidade inválida.\n";
            }
            else
            {
                for (int i = 0; i < qtd; i++) // sorteia do catálogo, a quantidade de filmes escolhida
                {
                    int cat = rand() % tot;   // sorteia uma posição de 0 a 19 do catálogo
                    lista[i] = catalogo[cat]; // copia o filme sorteado para a lista
                }
                final = qtd - 1;
                cout << "\nLista sendo preenchida automaticamente com filmes aleatórios...\n";
                MostrarLista(final);
            }
            break;
        }
        default:
            cout << "\n Opcao invalida!";
            break;
        }
        cout << "\nDeseja adicionar um filme no final? (S- sim) (N - não): "; // 01
        cin >> resp;

        switch (resp)
        {
        case 'S':
        case 's':
            adicionarfinal(final);
            MostrarLista(final);
            break;
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nDeseja adicionar um filme após o primeiro? (S- sim) (N - não): "; // 02
        cin >> resp;

        switch (resp)
        {
        case 'S':
        case 's':
            adicionaraposprimeiro(final);
            MostrarLista(final);
            break;
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nDeseja adicionar um filme após o primeiro do gênero que escolherá? (S- sim) (N - não): "; // 03
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            cout << "\nDigite X sendo ele um gênero: ";
            getline(cin >> ws, x);
            inseriraposgenero(final, x);
            MostrarLista(final);
            break;
        }
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nDeseja consultar o filme anterior a nota que escolherá? (S- sim) (N - não): "; // 04
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            cout << "\ndigite y sendo ele uma nota: ";
            cin >> y;
            int anterior = consultaranterior(final, y);
            if (anterior != -1)
            {
                cout << "\nFilme anterior à nota " << y << ":\n\n";
                cout << "Nome: " << lista[anterior].nome << endl;
                cout << "Gênero: " << lista[anterior].genero << endl;
                cout << "Diretor: " << lista[anterior].diretor << endl;
                cout << "Ano: " << lista[anterior].ano << endl;
                cout << "Nota: " << fixed << setprecision(1) << lista[anterior].nota << endl;
            }
        }
        break;
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nDeseja remover o último filme da lista? (S- sim) (N - não): "; // 05
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            string removido = removerultimo(final);
            if (removido != "")
            {
                cout << "Filme removido: " << removido << endl;
            }
            MostrarLista(final);
            break;
        }
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nDeseja remover o filme  posterior ao com nome que escolherá? (S- sim) (N - não): "; // 06
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            cout << "\nDigite x sendo ele o nome do filme: ";
            getline(cin >> ws, x);
            string removido = removerposterior(final, x);
            if (removido != "")
            {
                cout << "\nFilme removido: " << removido << endl;
            }
            MostrarLista(final);
        }
        break;
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nDeseja consultar o primeiro filme da lista? (S- sim) (N - não): "; // 07
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            string primeiro = consultarprimeiro(final);
            if (primeiro != "")
            {
                cout << "\nPrimeiro filme da lista: " << primeiro << endl;
            }
            break;
        }
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nDeseja alterar o gênero do filme com o diretor que escolherá? (S- sim) (N - não): "; // 08
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            cout << "\nDigite x sendo ele um diretor: ";
            getline(cin >> ws, x);
            string alteracao = alterargenero(final, x);
            if (alteracao != "")
            {
                cout << "Gênero do filme " << alteracao << " alterado.\n";
            }
            MostrarLista(final);
            break;
        }
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\nIniciar impressão da lista de filmes nas posições impares? (S- sim) (N - não): "; // 09
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
            impressaoimpares(final);
            break;
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\n Iniciar impressão da lista de filmes com nota maior ou igual a que escolherá? (S- sim) (N - não): "; // 10
        cin >> resp;
        switch (resp)
        {

        case 'S':
        case 's':
        {
            cout << "\n Digite y sendo ele uma nota: ";
            cin >> y;
            impressaonotamaior(final, y);
            break;
        }
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        classificarano(final); // 11

        classificarnome(final); // 12

        cout << "\n Deseja imprimir todos os filmes de um diretor da lista de filmes? (S- sim) (N - não): "; // 13
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            cout << "\nDigite x sendo ele um diretor: ";
            getline(cin >> ws, x);
            imprimirpordiretor(final, x);
            break;
        }
        case 'N':
        case 'n':
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        cout << "\n Deseja sair do programa? (S- sim) (N - não): "; // 14. Sair do programa
        cin >> resp;
        switch (resp)
        {
        case 'S':
        case 's':
        {
            cout << "Saindo do programa.\n";
            break;
        }
        case 'N':
        case 'n':
            cout << "\nContinuando no programa.\n";
            break;

        default:
            cout << "Opcao invalida!\n";
            break;
        }
    } while (resp != 'S' && resp != 's');
}
