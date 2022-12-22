#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAXIMO_PARTICIPANTES 500
#define MAXIMO_ATIVIDADES 200
#define MAXIMO_INSCRICAO 100

typedef struct
{
    int identificador;
    char nome;
    char associacao;
    int NIF;
    char email;
    int telefone;
} t_participante;

typedef struct
{
    int identificador;
    char designacao;
    char data;
    char hora;
    char local;
    char tipo;
    char associacao;
    float valor_inscricao;
} t_atividade;

typedef struct
{
    int identificador;
    int identificador_participante;
    int identificador_atividade;
    float valor_pago;
    char data;
    char hora;
} t_inscricao;

int registar_participantes(t_participante[],int);
void mostrar_participantes(t_participante[],int);
int registar_atividades(t_atividade[],int);
void mostrar_atividades(t_atividade[],int);
int registar_inscricoes(t_inscricao[],int);
void mostrar_inscricoes(t_inscricao[],int);
int numero_atividades_associacao(t_atividade[],int);
void percentagem_inscricoes_escola(t_inscricao[], int);
int valor_inscricoes_por_2_datas(t_inscricao[], int);
int menu_opcoes(void);
int submenu_1_opcoes(void);
int submenu_2_opcoes(void);
int submenu_3_opcoes(void);
int submenu_4_opcoes(void);
int submenu_5_opcoes(void);
char confirmar_saida(void);

int main()
{

    setlocale(LC_ALL,"Portuguese");

    t_participante participantes[MAXIMO_PARTICIPANTES];
    t_atividade atividades[MAXIMO_ATIVIDADES];
    t_inscricao inscricoes[MAXIMO_INSCRICAO];
    int opcao, opcao_participantes, opcao_atividades, opcao_inscricoes, opcao_estatisticas, opcao_ficheiros;
    char saida;

    do
    {
        system("cls");
        opcao = menu_opcoes();

        switch(opcao)
        {
        case 1:
            opcao_participantes = submenu_1_opcoes();

            switch(opcao_participantes)
            {
            case 1:

                break;
            case 2:

                break;
            }
            break;

        case 2:
            opcao_atividades = submenu_2_opcoes();

            switch(opcao_atividades)
            {
            case 1:
                break;
            case 2:
                break;
            }

            break;
        case 3:
            opcao_inscricoes = submenu_3_opcoes();

            switch(opcao_inscricoes)
            {
            case 1:
                break;
            case 2:
                break;
            }

            break;
        case 4:
            opcao_estatisticas = submenu_4_opcoes();

            switch(opcao_estatisticas)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            }

            break;
        case 5:
            break;
        case 0:
            saida = confirmar_saida();
            printf("Fim");
        }
    }
    while(opcao != 0);
}

int ler_numero_inteiro_intervalo(int valor_minimo, int valor_maximo)
{
    int numero;

    do
    {
        printf("Indique quantos dados deseja inserir (%i,%i): ",valor_minimo,valor_maximo);
        scanf("%i",&numero);
    }
    while(numero < valor_minimo || numero > valor_maximo);

    return numero;
}

int registar_participantes(t_participante participantes[],int numero_participantes)
{
    int indice;

    for(indice = 0; indice<numero_participantes; indice++)
    {
        printf("Indique o identicador do participante: ");
        scanf("%i",&participantes[numero_participantes].identificador);
        printf("Indique o nome do participante: ");
        scanf("%80[^\n]",&participantes[numero_participantes].nome);
        printf("Indique a associa��o que frequente o participante: ");
        scanf("%80[^\n]",&participantes[numero_participantes].associacao);
        printf("Indique o NIF do participante: ");
        scanf("%i",&participantes[numero_participantes].NIF);
        printf("Indique o email do participante: ");
        scanf("%80[^\n]",&participantes[numero_participantes].email);
        printf("Indique o telefone do participante: ");
        scanf("%i",&participantes[numero_participantes].telefone);

        numero_participantes = numero_participantes + 1;
    }

    return numero_participantes;

}

void mostrar_participantes(t_participante participantes[],int numero_participantes)
{
    int indice;

    for(indice = 0; indice<numero_participantes; indice++)
    {
        printf("\nIdentificador do participante: %i",indice);
        printf("\nNome do participante: %i",participantes[indice].nome);
        printf("\nAssocia��o de estudantes do participante: %i",participantes[indice].associacao);
        printf("\nNif do participante: %i",participantes[indice].NIF);
        printf("\nEmail do participante: %i",participantes[indice].email);
        printf("\nTelefone do participante: %i",participantes[indice].telefone);
    }

}

int registar_atividades(t_atividade atividades[],int numero_atividades)
{
    int indice;

    for(indice = 0; indice<numero_atividades; indice++)
    {
        printf("Indique o identificador da atividade: ");
        scanf("%i",&atividades[numero_atividades].identificador);
        printf("Indique a designa��o da atividade: ");
        scanf("%i",&atividades[numero_atividades].designacao);
        printf("Indique a data da atividade: ");
        scanf("%80[^\n]",&atividades[numero_atividades].data);
        printf("Indique a hora da atividade: ");
        scanf("%80[^\n]",&atividades[numero_atividades].hora);
        printf("Indique o local da atividade: ");
        scanf("%80[^\n]",&atividades[numero_atividades].local);
        printf("Indique a associa��o da atividade: ");
        scanf("%80[^\n]",&atividades[numero_atividades].associacao);
        printf("Indique o tipo da atividade: ");
        scanf("%80[^\n]",&atividades[numero_atividades].tipo);
        printf("Indique o valor da inscri��o da atividade: ");
        scanf("%i",&atividades[numero_atividades].valor_inscricao);

        numero_atividades = atividades + 1;
    }

    return numero_atividades;

}

void mostrar_atividades(t_atividade atividades[],int numero_atividades)
{
    int indice;

    for(indice = 0; indice<numero_atividades; indice++)
    {
        printf("\nIdentificador da atividade: %i",atividades[numero_atividades].identificador);
        printf("\nDesigna��o da atividade: %c",atividades[numero_atividades].designacao);
        printf("\nData da atividade: %c",atividades[numero_atividades].hora);
        printf("\nHora da atividade: %c",atividades[numero_atividades].data);
        printf("\nLocal da atividade: %c",atividades[numero_atividades].local);
        printf("\nTipo da atividade: %c",atividades[numero_atividades].tipo);
        printf("\nAssociacao da atividade: %c",atividades[numero_atividades].associacao);
        printf("\nValor da inscri��o da atividade: %f",atividades[numero_atividades].valor_inscricao);
    }
}


int registar_inscricoes(t_inscricao inscricoes[],int numero_inscricoes)
{
    struct inscricao;
    int indice;

    for(indice = 0; indice<numero_inscricoes; indice++)
    {
        printf("Indique o identificador da inscri��o: ");
        scanf("%i",&inscricoes[numero_inscricoes].identificador);
        printf("Indique o identificador do participante da inscri��o: ");
        scanf("%i",&inscricoes[numero_inscricoes].identificador_participante);
        printf("Indique o identificador da atividade da inscri��o: ");
        scanf("%i",&inscricoes[numero_inscricoes].identificador_atividade);
        printf("Indique o identificador do participante da inscri��o: ");
        scanf("%i",&inscricoes[numero_inscricoes].valor_pago);
        printf("Indique a data da inscri��o: ");
        scanf("%80[^\n]",&inscricoes[numero_inscricoes].data);
        printf("Indique a hora da inscri��o: ");
        scanf("%80[^\n]",&inscricoes[numero_inscricoes].hora);

        numero_inscricoes = numero_inscricoes + 1;
    }

    return numero_inscricoes;

}

void mostrar_inscricoes(t_inscricao inscricoes[],int numero_inscricoes)
{
    int indice;

    for(indice = 0; indice<numero_inscricoes; indice++)
    {
        printf("\nIdentificador da inscricao: %i",inscricoes[numero_inscricoes].identificador);
        printf("\nIdentificador do participante: %i",inscricoes[numero_inscricoes].identificador_participante);
        printf("\nIdentificador da atividade: %i",inscricoes[numero_inscricoes].identificador_atividade);
        printf("\nValor pago: %f",inscricoes[numero_inscricoes].valor_pago);
        printf("\nData: %c",inscricoes[numero_inscricoes].data);
        printf("\nHora: %c",inscricoes[numero_inscricoes].hora);
    }
}



void percentagem_inscricoes_escola(t_inscricao inscricoes[], int numero_inscricoes)
{
    int percentagem, indice;

    for (indice = 0; indice < MAXIMO_INSCRICAO; indice++)
    {
        percentagem = (numero_inscricoes / associacao) * 100;
    }
    printf("A percentagem de inscricoes por escola: %i", percentagem);

}

int menu_opcoes(void)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tMenu de Op��es");
        printf("\n\t\t\t\t1 - Participantes");
        printf("\n\t\t\t\t2 - Atividades");
        printf("\n\t\t\t\t3 - Inscri��es");
        printf("\n\t\t\t\t4 - Estat�sticas");
        printf("\n\t\t\t\t5 - Ficheiros");
        printf("\n\t\t\t\t0 - Sair");

        printf("\n\t\t\t\tOPCAO -> ");
        scanf("%i",&opcao);

        return opcao;

    }
    while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 0);
}

int submenu_1_opcoes(void)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tMenu Participantes");
        printf("\n\t\t\t\t1 - Registar os dados dos participantes");
        printf("\n\t\t\t\t2 - Consultar os dados dos participantes");
        printf("\n\t\t\t\t0 - Voltar");

        printf("\n\t\t\t\tOPCAO -> ");
        scanf("%i",&opcao);

        return opcao;

    }
    while(opcao != 1 && opcao != 2 && opcao != 0);
}

int submenu_2_opcoes(void)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tMenu Atividades");
        printf("\n\t\t\t\t1 - Registar os dados das atividades");
        printf("\n\t\t\t\t2 - Consultar os dados das atividades");
        printf("\n\t\t\t\t0 - Voltar");

        printf("\n\t\t\t\tOPCAO -> ");
        scanf("%i",&opcao);

        return opcao;

    }
    while(opcao != 1 && opcao != 2 && opcao != 0);
}

int submenu_3_opcoes(void)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tMenu Inscri��es");
        printf("\n\t\t\t\t1 - Registar os dados das inscri��es");
        printf("\n\t\t\t\t2 - Consultar os dados das inscri��es");
        printf("\n\t\t\t\t0 - Voltar");

        printf("\n\t\t\t\tOPCAO -> ");
        scanf("%i",&opcao);

        return opcao;

    }
    while(opcao != 1 && opcao != 2 && opcao != 0);
}

int submenu_4_opcoes(void)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tMenu Estat�sticas");
        printf("\n\t\t\t\t1 - N�mero de atividades realizadas por cada associa��o");
        printf("\n\t\t\t\t2 - Percentagem de inscri��es por escola");
        printf("\n\t\t\t\t3 - Valor total das inscri��es entre duas datas por tipo de atividade");
        printf("\n\t\t\t\t0 - Voltar");

        printf("\n\t\t\t\tOPCAO -> ");
        scanf("%i",&opcao);

        return opcao;

    }
    while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0);
}

int submenu_5_opcoes(void)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tMenu Ficheiros");
        printf("\n\t\t\t\t1 - Guardar dados em ficheiros");
        printf("\n\t\t\t\t2 - Ler dados de ficheiros");
        printf("\n\t\t\t\t0 - Voltar");

        printf("\n\t\t\t\tOPCAO -> ");
        scanf("%i",&opcao);

        return opcao;

    }
    while(opcao != 1 && opcao != 2 && opcao != 0);
}

char confirmar_saida(void)
{
    char saida;

    do
    {
        printf("\nDeseja sair da aplicacao? (S/N): ");
        scanf(" %c",&saida);

    }
    while(saida != 's' && saida != 'n');

    return saida;
}
