#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocacao de espaco em memoria
#include <locale.h> //Biblioteca de alocacao de texo por regiao
#include <string.h> //Biblioteca para cuidar das string


    int registro() // funcao responsavel por cadastrar os usuarios no sistema
    {
        //inicio criacao de variaveis

        char arquivo[40];
        char cpf [40];
        char nome [40];
        char sobrenome [40];
        char cargo [40];
        //final criacao de variaveis

        printf("Digite seu cpf"); //coletando informacao de usuario
        scanf ("%s", cpf ); // referese a string

        strcpy (arquivo, cpf);// Responsavel por copiar os valores das string

        FILE *file; // Cria o arquivo
        file = fopen(arquivo, "w");// Cria o arquivo e o "w" signifca escrever
            fprintf(file,cpf); //Salva o valor da varaivel
        fclose(file); // Fecha o arquivo

        file = fopen (arquivo, "a");
        fprintf (file, ",");
        fclose (file);

        printf ("digite o nome a ser cadastrado");
            scanf ("%s", nome);

        file = fopen (arquivo, "a");
        fprintf (file,nome );
        fclose (file);

         file = fopen (arquivo, "a");
        fprintf (file, ",");
        fclose (file);

        printf ("Digite o sobrenome a ser cadastrado");
        scanf ("%s", sobrenome);

        file = fopen (arquivo, "a");
        fprintf (file,sobrenome);
        fclose(file);

           file = fopen (arquivo, "a");
        fprintf (file, ",");
        fclose (file);

        printf ("Digite o cargo a ser cadastrado");
        scanf ("%s", cargo);

        file = fopen (arquivo, "a");
        fprintf (file, cargo);
        fclose (file);

        getchar();

        }

int consulta ()
    {

     char cpf [40];
     char conteudo [200];
     printf ("Digite o cpf a ser consultado:");
     scanf ("%s",cpf );
     FILE *file;
     file = fopen(cpf, "r");

     if (file == NULL)
     {
         printf ("Nao foi possivel abrir o arquivo, nao localizada!. \n");
     }

            while(fgets(conteudo, 200, file) != NULL)
      {
          printf("\n Essas sao as informacoes do usuario:");
          printf("%s", conteudo );
          printf("\n\n");

          getchar();

      }

    }
int deletar ()
{
         char cpf [40];
         printf ("Digite o CPF a ser deletado");
         scanf ("%s", cpf);

         remove (cpf);
         FILE *file;
         file = fopen (cpf, "r");

         if (file == NULL)
         {
             printf ("O usuario nao se encontra no sistema.");
             getchar();
         }
}





    int main()
{
    int opcao=0;
    int laco=1;

    for(laco=1;laco=1;)
    {

        system ("clear");

        setlocale(LC_ALL, "Portuguese");

        printf("\t\t Seja bem vindo ao Cartorio da Ebac\n\n"); // inicio do menu
        printf("Escolha a opcao desejada no menu: \n\n");
        printf("\t1- Registrar Nomes\n\n");
        printf("\t2- Consultar Nomes\n\n");
        printf("\t3- Deletar Nomes\n\n");
        printf("opcao: "); // fim do menu

        scanf ("%d", &opcao); //Armazenamento e escolha do usuario
        system ("clear");

        switch (opcao)
         {
        case 1:
              registro ();//Chamada das funcoes
        break;

        case 2:
            consulta ();
        break;

        case 3:
            deletar ();
        break;


        default:
               printf("Essa opcao nao esta disponivel!\n\n");
        getchar();
        break;


       } // fim da selecao
    }
}

