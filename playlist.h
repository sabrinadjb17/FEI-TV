#include "playlist.h"
#include "outrasFuncoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criarPlaylist(char loginUsuario[], char nomePlaylist[])
{
	FILE *arquivo;
	arquivo = fopen("playlist.csv", "a");
	fprintf(arquivo, "%s;%s;\n", loginUsuario, nomePlaylist);
	fclose(arquivo);

	printf("Playlist criada com sucesso!\n");
	printf("Digite enter para voltar ao menu Playlist...\n");
	getchar();
	system("cls");
}

void renomearPlaylist(char emailUsuario[], char antigoNomePlaylist[], char novoNomePlaylist[])
{
	FILE *arquivo = fopen("playlist.csv", "r");
	// arquivo temporario
	FILE *temp = fopen("temp.csv", "w");

	char linha[300];
	int encontrou = 0;
	char linhaRenomear[300];

	// roda enquanto isso for true
	while (fgets(linha, 300, arquivo))
	{
		removerEnter(linha);
		char video[100];
		// ignora email e playlist e pega so o vídeo
		sscanf(linha, "%*[^;];%*[^;];%[^\n]", video);
		sprintf(linhaRenomear, "%s;%s;%s", emailUsuario, antigoNomePlaylist, video);

		if (strcmp(linha, linhaRenomear) == 0)
		{
			encontrou = 1;
			fprintf(temp, "%s;%s;%s\n", emailUsuario, novoNomePlaylist, video);
		}
		else
		{
			fprintf(temp, "%s\n", linha);
		}
	}
	fclose(arquivo);
	fclose(temp);

	remove("playlist.csv");
	rename("temp.csv", "playlist.csv");

	if (encontrou)
	{
		system("cls");
		printf("Playlist renomeada com sucesso!\n");
		printf("Digite enter para voltar ao Menu Playlist...\n");
		getchar();
		system("cls");
	}
	else
	{
		system("cls");
		printf("Playlist não encontrada.\n");
		printf("\nDigite enter para voltar ao Menu Playlist...\n");
		getchar();
		system("cls");
	}
}

void excluirPlaylist(char emailUsuario[], char nomePlaylist[])
{
	FILE *arquivo = fopen("playlist.csv", "r");
	// arquivo temporario
	FILE *temp = fopen("temp.csv", "w");

	char linha[300];
	int encontrou = 0;

	// roda enquanto isso for true
	while (fgets(linha, 300, arquivo))
	{
		removerEnter(linha);

		char email[50];
		char playlist[50];
		char video[100];

		sscanf(linha, "%[^;];%[^;];%[^\n]", email, playlist, video);

		if (strcmp(email, emailUsuario) == 0 &&
			strcmp(playlist, nomePlaylist) == 0)
		{
			encontrou = 1;
			continue; 
		}
		fprintf(temp, "%s\n", linha);
	}
	fclose(arquivo);
	fclose(temp);

	remove("playlist.csv");
	rename("temp.csv", "playlist.csv");

	if (encontrou)
	{
		system("cls");
		printf("Playlist exclída com sucesso!\n");
		printf("Digite enter para voltar ao Menu Playlist...\n");
		getchar();
		system("cls");
	}
	else
	{
		system("cls");
		printf("Playlist não encontrada.\n");
		printf("Digite enter para voltar ao Menu Playlist...\n");
		getchar();
		system("cls");
	}
}
