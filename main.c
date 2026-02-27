#include <stdio.h>
#include <stdbool.h>


typedef struct {
    char memoryKey[200];
    int assocationCount;
    char associations[2000];
    } InputForm;

void create(const char *path) {
    FILE *fp = fopen(path, "a");
    if (fp != NULL)
        fclose(fp);
}

void openNexFile(FILE *fp, InputForm *form) {



    printf("Memory Key: \n");
    scanf("%199s", form->memoryKey);
    fprintf(fp, "%s\n", form->memoryKey);
    printf("Assocation Count: \n");
    scanf("%d", &form->assocationCount);
    for (int i = 0; i < form->assocationCount; i++ )
    {
        printf("Assocation: \n");
        scanf("%1999s", form->associations);
        fprintf(fp, "%s\n", form->associations);
    }


}

void append(const char *path) {

    FILE *fp = fopen(path, "a");
    printf("Appending to: %s\n", path);
    if (fp == NULL)
        return;
    InputForm form = {0};
    openNexFile(fp, &form);
    fclose(fp);


}

void runner(const char *path) {
    create(path);
    append(path);

}

int main() {

    bool inputBool = false;
    char entry[30];

    runner("Testing2.nex");


    return 0;
}
