#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void forca(char *w)
{
    
    int len = strlen(w),x, vidas ,acerto, erro,i, vitoria;
    char *cpp[256];
    char tentativa;
    vidas = 6;
    printf("Acerte a palavra: \n");
    for (int x = 0;x <= len;x++)
    {
        cpp[x] = '_';
        printf("%c",cpp[x]);
    }

    while(vitoria < 1){
        printf("\nAcerte a palavra: \n");
        printf("\n");
        scanf("%1s", &tentativa);
        
        for(i = 0;i<len;i++)
        {
            if (w[i] == tentativa)
            {
                cpp[i] = tentativa;
                acerto++;
                printf("Acertou!\n");
                if(acerto==1){
                    i = len;
                }
            }else{
                erro++;
            }
        }
        if(erro >= len){
            printf("Errou!\n");
            vidas--;
            erro = 0;
        }

        for (int x = 0;x <= len;x++)
        {
            printf("%c",cpp[x]);
        }
        printf("\nVocê tem %d Vidas.\n", vidas);
        if(vidas <= 0){
            vitoria = 2;
        }
        if (acerto >= len)
        {
            vitoria = 1;
        }
        
    }
    if (vitoria == 1)
    {
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("\nVocê acertou!\t A palavra era **%s**", w);
    }else{
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("\nVocê perdeu! A palavra era **%s**", w);
    }
    
    
}

void main()
{
    FILE *arquivo;
    int linhas,i;
    char c;
    arquivo = fopen("palavras.txt","r");
    char frase[100];

    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        getchar();
        exit(0);
    }
    for (c = getc(arquivo); c != EOF; c = getc(arquivo))
        if (c == '\n') // Increment count if this character is newline
            linhas = linhas + 1;

    fseek(arquivo, 0, SEEK_SET);
    

    char *possiveis[linhas][256];
    //printf("%d Linhas\n",linhas);
    i = 0;

    while (fgets(possiveis[i], 100, arquivo) != NULL)
    {
        //printf("%s\n", possiveis[i]);
        i++;
    }
    srand(time(NULL));
    int num = rand()%linhas;
    int strLength = strlen(possiveis[num]);
    char rc[256];
    strcpy(rc,possiveis[num]);
    forca(rc);
}