#include "videos.h"
#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include <string.h>


struct Video
{
    char nome[100];
    char tipo[20];
    char classificacao[20];
    int ano;
    char sinopse[200];
    int nota;
};

//-----------------------------------------------------------------------

struct Video buscarVideoArquivo(char nomeVideo[]){
    struct Video v;
    FILE *arquivo;

    arquivo = fopen("videos.csv", "r");

    // == 6 para ler os campos, quando chega na ultima linha e ve q não tem     mais 6 campos ele para
    //fscanf já preenche os valores das variaveis 
    while (fscanf(arquivo, "%[^;];%[^;];%[^;];%d;%[^;];%d\n", v.nome, v.tipo, v.classificacao, &v.ano, v.sinopse, &v.nota) == 6) {
        //strcmp retorna um numero, 0 se as strings forem iguais
        if (strcmp(v.nome, nomeVideo) == 0 ) { 
            fclose(arquivo);
            return v;
        }
    }

    fclose(arquivo);

    // caso não encontre ? retorna "vazio"
    struct Video vazio = {"", "", "", 0, "", 0};
    return vazio;
}

//----------------------------------------------------------------------------------

void mostrarVideo(struct Video v) {
    printf("Nome: %s\n", v.nome);
    printf("Tipo: %s\n", v.tipo);
    printf("Classificação: %s\n", v.classificacao);
    printf("Ano: %d\n", v.ano);
    printf("Sinopse: %s\n", v.sinopse);
    printf("Nota: %d\n", v.nota);
}

//----------------------------------------------------------------------------------

void buscarVideo(char nomeVideo[]){
    struct Video v = buscarVideoArquivo(nomeVideo);

    printf("%s", v.nome);

    if(strlen(v.nome) == 0) {
        system("cls");
        printf("Filme ou Série não encontrados no sistema!\n");
        printf("Aperte enter e tente novamente...\n");
        getchar();
        system("cls");
        return;
    }

    system("cls");
    printf("Filme/Série encontrado com sucesso!\n");
    mostrarVideo(v);

    printf("\nDigite enter para voltar ao Menu Usuário...\n");
    getchar();
    system("cls");
}

//----------------------------------------------------------------------------------

void adicionarVideo(char emailUsuario[], char nomePlaylist[], char nomeVideo[]){
    struct Video v = buscarVideoArquivo(nomeVideo);

    if(strlen(v.nome) == 0){
        system("cls");
        printf("Vídeo não encontrado\n");
        printf("Digite enter para voltar ao menu...\n");
        getchar();
        system("cls");
        return;
    }

    salvarVideoPlaylist(emailUsuario, nomePlaylist, nomeVideo);

    system("cls");
    printf("Vídeo adicionado à playlist com sucesso!\n");
    printf("Digite enter para voltar ao menu...\n");
    getchar();
    system("cls");
}

//----------------------------------------------------------------------------------

void curtirVideo(char email[], char nomeVideo[]){
    struct Video v = buscarVideoArquivo(nomeVideo);

    if(strlen(v.nome) == 0){
        system("cls");
        printf("Vídeo não encontrado\n");
        printf("Digite enter para voltar ao menu...\n");
        getchar();
        system("cls");
        return;
    }

    salvarVideoPlaylist(email, "Curtidos", v.nome);

    system("cls");
    printf("Vídeo curtido com sucesso!\n");
    printf("Digite enter para voltar ao menu...\n");
    getchar();
    system("cls");
}

//----------------------------------------------------------------------------------

void removerCurtida(char email[], char nomeVideo[]) {
    FILE *arquivo = fopen("playlist.csv", "r");
    //arquivo temporario
    FILE *temp = fopen("temp.csv", "w");

    char linha[300];
    int encontrou = 0;

    char linhaRemover[300];
    //formata para ficar igual as linhas no csv
    sprintf(linhaRemover, "%s;Curtidos;%s\n", email, nomeVideo);

    //roda enquanto isso for true
    while (fgets(linha, 300, arquivo)) {

        if (strcmp(linha, linhaRemover) == 0) {
            encontrou = 1;
            continue; 
        }
        fprintf(temp, "%s", linha);
    }
    fclose(arquivo);
    fclose(temp);

    remove("playlist.csv");
    rename("temp.csv", "playlist.csv");

    if (encontrou) {
        system("cls");
        printf("Vídeo descurtido com sucesso!\n");
        printf("Digite enter para voltar ao Menu Usuário...\n");
        getchar();
        system("cls");
    } else {
        system("cls");
        printf("Vídeo não estava nos curtidos.\n");
        printf("Digite enter para voltar ao Menu Usuário...\n");
        getchar();
        system("cls");
    }
}

//----------------------------------------------------------------------------------

void removerVideo(char emailUsuario[], char nomePlaylist[], char nomeVideo[]){
    FILE *arquivo = fopen("playlist.csv", "r");
    //arquivo temporario
    FILE *temp = fopen("temp.csv", "w");

    char linha[300];
    int encontrou = 0;

    char linhaRemover[300];
    //formata para ficar igual as linhas no csv
    sprintf(linhaRemover, "%s;%s;%s\n", emailUsuario, nomePlaylist, nomeVideo);

    //roda enquanto isso for true
    while (fgets(linha, 300, arquivo)) {

        if (strcmp(linha, linhaRemover) == 0) {
            encontrou = 1;
            continue; 
        }
        fprintf(temp, "%s", linha);
    }
    fclose(arquivo);
    fclose(temp);

    remove("playlist.csv");
    rename("temp.csv", "playlist.csv");

    if (encontrou) {
        system("cls");
        printf("Vídeo removido com sucesso!\n");
        printf("Digite enter para voltar ao Menu Playlist...\n");
        getchar();
        system("cls");
    } else {
        system("cls");
        printf("Vídeo ou Playlist foram encontrados.\n");
        printf("Digite enter para voltar ao Menu Playlist...\n");
        getchar();
        system("cls");
    }
}

//----------------------------------------------------------------------------------

void salvarVideoPlaylist(char emailUsuario[], char nomePlaylist[], char nomeVideo[]){
    FILE *arquivo = fopen("playlist.csv", "a");

    fprintf(arquivo, "%s;%s;%s\n", emailUsuario, nomePlaylist, nomeVideo);

    fclose(arquivo);
}
