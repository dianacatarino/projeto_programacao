#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_PARTICIPANTES 500
#define MAXIMO_ATIVIDADES 200
#define MAXIMO_INSCRICOES 100

typedef struct
{
    int dia, mes, ano;
}t_data;

typedef struct
{
    int hora, minutos, segundos;
}t_hora;

typedef struct
{
    int identificador;
    char nome [80];
    char escola [6];
    int NIF;
    char email [80];
    int telefone;
} t_participante;

typedef struct
{
    int identificador;
    char designacao [30];
    t_data data_atividade;
    t_hora hora_atividade;
    char local [30];
    char tipo [30];
    char associacao[10];
    float valor_inscricao;
} t_atividade;

typedef struct
{
    int identificador;
    t_participante identificador_participante;
    t_atividade identificador_atividade;
    float valor_pago;
    t_data data_inscricao;
    t_hora hora_inscricao;
} t_inscricao;

int registar_participantes(t_participante[],int);
void mostrar_participantes(t_participante[],int);
int registar_atividades(t_atividade[],int);
void mostrar_atividades(t_atividade[],int);
int registar_inscricoes(t_inscricao[],int);
void mostrar_inscricoes(t_inscricao[],int);
int numero_atividades_associacao(t_atividade[],int);
void percentagem_inscricoes_escola(t_atividade[], t_inscricao[], int, int);
int valor_inscricoes_por_2_datas(t_atividade[], t_inscricao[], int, int);
int procurar_inscricoes(t_inscricao[],int);
void gravar_dados_ficheiro(t_participante[],t_atividade[],t_inscricao[],int,int,int);
int ler_dados_ficheiro(t_participante[],t_atividade[],t_inscricao[]);
int menu_opcoes(void);
int submenu_1_opcoes(void);
int submenu_2_opcoes(void);
int submenu_3_opcoes(void);
int submenu_4_opcoes(void);
int submenu_5_opcoes(void);
char confirmar_saida(void);

int main()
{

    t_participante participantes[MAXIMO_PARTICIPANTES];
    t_atividade atividades[MAXIMO_ATIVIDADES];
    t_inscricao inscricoes[MAXIMO_INSCRICOES];
    int numero_estudantes = 0, numero_atividades = 0, numero_inscricoes = 0, opcao, opcao_participantes, opcao_atividades, opcao_inscricoes, opcao_estatisticas, opcao_ficheiros;
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
                numero_estudantes = registar_participantes(participantes,numero_estudantes);
                fflush(stdin);
                getchar();
                break;
            case 2:
                mostrar_participantes(participantes,numero_estudantes);
                fflush(stdin);
                getchar();
                break;
            }
            break;
        case 2:
            opcao_atividades = submenu_2_opcoes();

            switch(opcao_atividades)
            {
            case 1:
                numero_atividades = registar_atividades(atividades,numero_atividades);
                fflush(stdin);
                getchar();
                break;
            case 2:
                mostrar_atividades(atividades,numero_atividades);
                fflush(stdin);
                getchar();
                break;
            }
            break;
        case 3:
            opcao_inscricoes = submenu_3_opcoes();

            switch(opcao_inscricoes)
            {
            case 1:
                numero_inscricoes = registar_inscricoes(inscricoes,numero_inscricoes);
                fflush(stdin);
                getchar();
                break;
            case 2:
                mostrar_inscricoes(inscricoes,numero_inscricoes);
                fflush(stdin);
                getchar();
                break;
            }
            break;
        case 4:
            opcao_estatisticas = submenu_4_opcoes();

            switch(opcao_estatisticas)
            {
            /*case 1:
                numero_atividades = numero_atividades_associacao(atividades,numero_atividades);
                break;
            case 2:
                percentagem_inscricoes_escola(atividades,inscricoes,numero_inscricoes,numero_atividades);
                break;*/
            case 3:
                numero_inscricoes = valor_inscricoes_por_2_datas(atividades,inscricoes,numero_atividades,numero_inscricoes);
                break;
            }
            break;
        case 5:
            opcao_ficheiros = submenu_5_opcoes();

            switch(opcao_ficheiros)
            {
            case 1:
                gravar_dados_ficheiro(participantes,atividades,inscricoes,numero_estudantes,numero_atividades,numero_inscricoes);
                break;
            case 2:
                numero_estudantes = ler_dados_ficheiro(participantes,atividades,inscricoes);
                numero_atividades = ler_dados_ficheiro(participantes,atividades,inscricoes);
                numero_inscricoes = ler_dados_ficheiro(participantes,atividades,inscricoes);
                break;
            }
            break;
        case 0:
            saida = confirmar_saida();
            printf("Fim");
            break;
        default:
            printf("Operacao Inválida");
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

    printf("Indique o nome do participante: ");
    scanf("%s",participantes[numero_participantes].nome);
    printf("\nIndique a escola que frequente o participante: ");
    scanf("%s",participantes[numero_participantes].escola);
    printf("\nIndique o NIF do participante: ");
    scanf("%i",&participantes[numero_participantes].NIF);
    printf("\nIndique o email do participante: ");
    scanf("%s",participantes[numero_participantes].email);
    printf("\nIndique o telefone do participante: ");
    scanf("%i",&participantes[numero_participantes].telefone);

    numero_participantes = numero_participantes + 1;

    return numero_participantes;

}

void mostrar_participantes(t_participante participantes[],int numero_participantes)
{
    int indice;

    for(indice = 0; indice<numero_participantes; indice++)
    {
        participantes->identificador = indice + 1;
        printf("\nIdentificador do participante: %i",indice+1);
        printf("\nNome do participante: %s",participantes[indice].nome);
        printf("\nEscola de estudantes do participante: %s",participantes[indice].escola);
        printf("\nNIF do participante: %i",participantes[indice].NIF);
        printf("\nEmail do participante: %s",participantes[indice].email);
        printf("\nTelefone do participante: %i",participantes[indice].telefone);
    }

}

int registar_atividades(t_atividade atividades[],int numero_atividades)
{

    printf("Indique a designacao da atividade: ");
    scanf("%s",atividades[numero_atividades].designacao);
    printf("\nIndique a data da atividade: ");
    scanf("%i %i %i",&atividades[numero_atividades].data_atividade.dia,&atividades[numero_atividades].data_atividade.mes,&atividades[numero_atividades].data_atividade.ano);
    printf("\nIndique a hora da atividade: ");
    scanf("%i %i",&atividades[numero_atividades].hora_atividade.hora,&atividades[numero_atividades].hora_atividade.minutos);
    printf("\nIndique o local da atividade: ");
    scanf("%s",atividades[numero_atividades].local);
    printf("\nIndique a associacao da atividade: ");
    scanf("%s",atividades[numero_atividades].associacao);
    printf("\nIndique o tipo da atividade: ");
    scanf("%s",atividades[numero_atividades].tipo);
    printf("\nIndique o valor da inscricao da atividade: ");
    scanf("%f",&atividades[numero_atividades].valor_inscricao);

    numero_atividades = atividades + 1;

    return numero_atividades;

}

void mostrar_atividades(t_atividade atividades[],int numero_atividades)
{
    int indice;

    for(indice = 0; indice<numero_atividades; indice++)
    {
        atividades[numero_atividades].identificador = indice + 1;
        printf("\nIdentificador da atividade: %i",indice+1);
        printf("\nDesignacao da atividade: %s",atividades[numero_atividades].designacao);
        printf("\nData da atividade: %i-%i-%i",atividades[numero_atividades].data_atividade.dia,atividades[numero_atividades].data_atividade.mes,atividades[numero_atividades].data_atividade.ano);
        printf("\nHora da atividade: %i:%i",atividades[numero_atividades].hora_atividade.hora,atividades[numero_atividades].hora_atividade.minutos);
        printf("\nLocal da atividade: %s",atividades[numero_atividades].local);
        printf("\nTipo da atividade: %s",atividades[numero_atividades].tipo);
        printf("\nAssociacao da atividade: %s",atividades[numero_atividades].associacao);
        printf("\nValor da inscricao da atividade: %f",atividades[numero_atividades].valor_inscricao);
    }
}


int registar_inscricoes(t_inscricao inscricoes[],int numero_inscricoes)
{

    printf("\nIndique o valor pago da inscrição: ");
    scanf("%f",&inscricoes[numero_inscricoes].valor_pago);
    printf("\nIndique a data da inscricao: ");
    scanf("%i %i %i",&inscricoes[numero_inscricoes].data_inscricao.dia,&inscricoes[numero_inscricoes].data_inscricao.mes,&inscricoes[numero_inscricoes].data_inscricao.ano);
    printf("\nIndique a hora da inscricao: ");
    scanf("%i %i %i",&inscricoes[numero_inscricoes].hora_inscricao.hora,&inscricoes[numero_inscricoes].hora_inscricao.minutos,&inscricoes[numero_inscricoes].hora_inscricao.segundos);

    numero_inscricoes = numero_inscricoes + 1;

    return numero_inscricoes;

}

void mostrar_inscricoes(t_inscricao inscricoes[],int numero_inscricoes)
{
    int indice;

    for(indice = 0; indice<numero_inscricoes; indice++)
    {
        printf("\nIdentificador da inscricao: %i",indice+1);
        printf("\nIdentificador do participante: %i",inscricoes[numero_inscricoes].identificador_participante);
        printf("\nIdentificador da atividade: %i",inscricoes[numero_inscricoes].identificador_atividade);
        printf("\nValor pago: %f",inscricoes[numero_inscricoes].valor_pago);
        printf("\nData: %i-%i-%i",inscricoes[numero_inscricoes].data_inscricao.dia,inscricoes[numero_inscricoes].data_inscricao.mes,inscricoes[numero_inscricoes].data_inscricao.ano);
        printf("\nHora: %i:%i:%i",inscricoes[numero_inscricoes].hora_inscricao.hora,inscricoes[numero_inscricoes].hora_inscricao.minutos,inscricoes[numero_inscricoes].hora_inscricao.segundos);
    }
}

/*int numero_atividades_associacao(t_atividade atividades[],int numero_atividades)
{
    int contador, indice;

    for (indice = 0; indice < MAXIMO_ATIVIDADES; indice++)
    {
        contador = atividades[indice].associacao[] + atividades[indice].associacao[];
        contador = (numero_atividades / atividades[indice].associacao[]);
        printf("Número de atividades por associação: %i",contador);
    }
    return contador;
}

void percentagem_inscricoes_escola(t_atividade atividades[],t_inscricao inscricoes[], int numero_inscricoes, int numero_atividades)
{
    int percentagem, indice;

    for (indice = 0; indice < MAXIMO_INSCRICOES; indice++)
    {
        percentagem = (numero_inscricoes / atividades[indice].associacao[]) * 100;
    }
    printf("A percentagem de inscricoes por associação: %i", percentagem);

}*/

int valor_inscricoes_por_2_datas(t_atividade atividades[],t_inscricao inscricoes[],int numero_atividades, int numero_inscricoes)
{
    int indice, soma;

    for (indice = 0; indice < MAXIMO_INSCRICOES; indice++)
    {
        soma = soma + inscricoes[indice].valor_pago;
        printf("O valor de inscricoes por 2 datas: %i", soma);
    }
}


void gravar_dados_ficheiro(t_participante participantes[],t_atividade atividades[],t_inscricao inscricoes[],int numero_participantes,int numero_atividades,int numero_inscricoes)
{
    FILE *ficheiro;
    ficheiro = fopen("ficheiro_projeto.dat","wb");

    if(ficheiro == NULL)
    {
        printf("Ficheiro nao existe");
    }
    else
    {
        fwrite(&numero_participantes, sizeof(int), 1,ficheiro);
        fwrite(participantes, sizeof(t_participante),MAXIMO_PARTICIPANTES,ficheiro);
        fwrite(&numero_atividades, sizeof(int), 1,ficheiro);
        fwrite(atividades, sizeof(t_atividade),MAXIMO_ATIVIDADES,ficheiro);
        fwrite(&numero_inscricoes, sizeof(int), 1,ficheiro);
        fwrite(inscricoes, sizeof(t_inscricao),MAXIMO_INSCRICOES,ficheiro);

        printf("\nOs dados foram guardados no ficheiro com sucesso");
        fclose(ficheiro);
    }
}

int ler_dados_ficheiro(t_participante participantes[],t_atividade atividades[],t_inscricao inscricoes[])
{
    FILE *ficheiro;
    int numero_participantes, numero_atividades, numero_inscricoes, numero_participantes_lidos, numero_atividades_lidos, numero_inscricoes_lidos;

    ficheiro = fopen("ficheiro_projeto.dat", "rb");
    if(ficheiro == NULL)
        printf("\nFicheiro nao existe");
    else
    {
        fread(&numero_participantes, sizeof(int), 1,ficheiro);
        numero_participantes_lidos=fread(participantes, sizeof(t_participante),numero_participantes,ficheiro);
        fread(&numero_atividades, sizeof(int), 1,ficheiro);
        numero_atividades_lidos=fread(atividades, sizeof(t_atividade),numero_atividades,ficheiro);
        fread(&numero_inscricoes, sizeof(int), 1,ficheiro);
        numero_inscricoes_lidos=fread(inscricoes, sizeof(t_inscricao),numero_inscricoes,ficheiro);
        if(numero_participantes_lidos==numero_participantes && numero_atividades_lidos==numero_atividades && numero_inscricoes_lidos==numero_inscricoes)
            printf("\nOs dados foram lidos no ficheiro com sucesso");
        else
            printf("\nOcorreu um erro");
        fclose(ficheiro);
    }

    return numero_participantes;

}

int menu_opcoes(void)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tMenu de Opcoes");
        printf("\n\t\t\t\t1 - Participantes");
        printf("\n\t\t\t\t2 - Atividades");
        printf("\n\t\t\t\t3 - Inscricoes");
        printf("\n\t\t\t\t4 - Estatisticas");
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
        printf("\n\t\t\t\tMenu Inscricoes");
        printf("\n\t\t\t\t1 - Registar os dados das inscricoes");
        printf("\n\t\t\t\t2 - Consultar os dados das inscricoes");
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
        printf("\n\t\t\t\tMenu Estatisticas");
        printf("\n\t\t\t\t1 - Numero de atividades realizadas por cada associacao");
        printf("\n\t\t\t\t2 - Percentagem de inscrições por escola");
        printf("\n\t\t\t\t3 - Valor total das inscricoes entre duas datas por tipo de atividade");
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

