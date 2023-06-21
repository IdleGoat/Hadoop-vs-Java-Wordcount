#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

void generateFile(const char* filename, long long filesize) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saat membuka file untuk penulisan.\n");
        return;
    }

    const char* story = "Once upon a time, in a land far, far away, there was a brave knight named Sir Miles. He embarked on a grand adventure to rescue the princess and defeat the evil dragon. With his sword in hand and his wits sharp, Sir Miles overcame numerous challenges and solved perplexing riddles. After many trials and tribulations, he finally emerged victorious, saving the princess and bringing peace to the kingdom. The end.";

    long long bytesWritten = 0;
    while (bytesWritten < filesize) {
        int bufferSize = (filesize - bytesWritten < MAX_BUFFER_SIZE) ? (int)(filesize - bytesWritten) : MAX_BUFFER_SIZE;
        fwrite(story, sizeof(char), bufferSize, file);
        bytesWritten += bufferSize;
    }

    fclose(file);
    printf("File berhasil dibuat.\n");
}

int main() {
    long long fileSize;
    printf("Masukkan ukuran file dalam megabyte (MB): ");
    scanf("%lld", &fileSize);

    if (fileSize <= 0) {
        printf("Ukuran file tidak valid. Harap masukkan nilai positif.\n");
        return 1;
    }

    // Konversi fileSize ke byte
    fileSize *= 1024 * 1024;

    // Periksa ruang disk yang tersedia
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Terjadi kesalahan saat membuat file sementara. Ruang disk tidak mencukupi atau akses ditolak.\n");
        return 1;
    }
    fclose(tempFile);
    remove("temp.txt");

    srand(time(NULL)); // Inisialisasi pembangkit bilangan acak

    char filename[100];
    sprintf(filename, "wordfile_%lldMB.txt", fileSize / (1024 * 1024));

    generateFile(filename, fileSize);

    return 0;
}

