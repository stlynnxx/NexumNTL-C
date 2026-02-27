#include <stdio.h>
#include <stdbool.h>

void create(const char *path) {
    FILE *fp = fopen(path, "a");
    if (fp != NULL)
        fclose(fp);
}
void openNexFile(FILE *fp) {
    char memoryKey[200];
    int assocationCount;
    char associations[2000];

    printf("Memory Key: \n");
    scanf("%199s", memoryKey);
    printf("Assocation Count: \n");
    scanf("%d", &assocationCount);
    for (int i = 0; i < assocationCount; i++ )
    {
        printf("Assocation: \n");
        scanf("%1999s", associations);
    }
}
void append(const char *path,int input) {
    FILE *fp = fopen(path, "a");
    if (fp == NULL)
        return;
    openNexFile(fp);
    fclose(fp);
}



void runner(const char *path, int input) {
    create(path);
    append(path, input);

}

int main() {

    bool inputBool = false;
    char entry[30];
    int input;
    printf("Type an int: \n");
    scanf("%d", &input);
    runner("Testing.nex", input);


    return 0;
}
