#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressRLE(unsigned char *data, int tailleData, unsigned char *DataCompressed, int *taille) {
    int compte = 1;
    int val = 0;
    for (int i = 1; i < tailleData; i++) {
        if (data[i] == data[i - 1] && compte < 255) {
            compte++;
        } else {
            DataCompressed[val++] = compte;
            DataCompressed[val++] = data[i - 1];
            compte = 1;
        }
    }
    DataCompressed[val++] = compte;
    DataCompressed[val++] = data[tailleData - 1];
    *taille = val;
}

int main() {
    char inputPath[256], outputPath[256];

    // Demander le chemin du fichier source
    printf("Chemin du fichier a compresser : ");
    scanf("%255s", inputPath);

    // Ouvrir le fichier source en mode binaire
    FILE *inputFile = fopen(inputPath, "rb");
    if (!inputFile) {
        perror("Erreur : Impossible d'ouvrir le fichier source");
        return 1;
    }

    // Determiner la taille du fichier
    fseek(inputFile, 0, SEEK_END);
    int size = ftell(inputFile);
    rewind(inputFile);

    // Allouer de la memoire pour lire le fichier
    unsigned char *data = malloc(size);
    if (!data) {
        perror("Erreur : Allocation de memoire echouee");
        fclose(inputFile);
        return 1;
    }

    // Lire les donnees
    if (fread(data, 1, size, inputFile) != size) {
        perror("Erreur : Lecture du fichier source echouee");
        free(data);
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);

    // Allouer de la memoire pour les donnees compressees
    unsigned char *DataCompressed = malloc(size * 2);
    if (!DataCompressed) {
        perror("Erreur : Allocation de memoire pour la compression echouee");
        free(data);
        return 1;
    }

    // Compression des donnees
    int tailleCompressed;
    compressRLE(data, size, DataCompressed, &tailleCompressed);

    // Demander le chemin du fichier compresse
    printf("Chemin du fichier compresse : ");
    scanf("%255s", outputPath);

    // Ecrire les donnees compressees dans le fichier de sortie
    FILE *outputFile = fopen(outputPath, "wb");
    if (!outputFile) {
        perror("Erreur : Impossible de creer le fichier compresse");
        free(data);
        free(DataCompressed);
        return 1;
    }

    if (fwrite(DataCompressed, 1, tailleCompressed, outputFile) != tailleCompressed) {
        perror("Erreur : Ecriture dans le fichier compresse echouee");
        free(data);
        free(DataCompressed);
        fclose(outputFile);
        return 1;
    }

    // Liberer la memoire et fermer les fichiers
    free(data);
    free(DataCompressed);
    fclose(outputFile);

    printf("Compression terminee avec succes.\n");
    return 0;
}
