#include <stdio.h>
#include <stdbool.h>
#define MAX_ASSOC 50
#define MAX_ASSOC_LEN 200


typedef struct {
    char memoryKey[200];
    int assocationCount;
    char associations[MAX_ASSOC][MAX_ASSOC_LEN];
    } InputForm;

void create(const char *path) {
    FILE *fp = fopen(path, "a");
    if (fp != NULL)
        fclose(fp);
}

void format(FILE *fp, InputForm *form) {
     fprintf(fp,"%s", "{");
     fprintf(fp, "%s", "'");
     fprintf(fp,"%s", form->memoryKey);
     fprintf(fp, "%s", "'");
     fprintf(fp,"%s", ":");
     fprintf(fp,"%s", "{ ");
    for (int i = 0; i < form->assocationCount; i++) {
        fprintf(fp, "%s", "'");
        fprintf(fp, "%s", form->associations[i]);
        fprintf(fp, "%s", "'");
        fprintf(fp, "%s", " ");

    }
     // fprintf(fp, "%s", "'");
     fprintf(fp, "%s", "}");
}

void openNexFile(FILE *fp, InputForm *form) {
    printf("Memory Key: \n");
    scanf("%199s", form->memoryKey);
    // fprintf will eventually be replaced with a format function


    printf("Assocation Count: \n");
    scanf("%d", &form->assocationCount);
    for (int i = 0; i < form->assocationCount && i < MAX_ASSOC; i++ )
    {
        printf("Assocation: \n");
        scanf("%1999s", form->associations[i]);
        // fprintf(fp, "%s\n", form->associations);
    }
    format(fp, form);
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
