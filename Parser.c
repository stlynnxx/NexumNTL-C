//
// Created by steviexx on 3/31/26.
//
#include "Nexum.h"
#include "Parser.h"
#include "Lexer.h"
#include "SourceGenerator.h"
#include "SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>




// int workIdx = breakdownIdx + 1;


// This will be for checking if a given search term is within the values matrix
const char *valuesSearch(const char *searchTerm) {
    for (int i = 0; i < 26; i++) {
        int cols = sizeof(valuesMatrix[0]) / sizeof(valuesMatrix[0][0]);
        for (int j = 0; j < cols; j++) {
            const char *v = valuesMatrix[i][j];
            if (!v || strcmp(v, "NULL") == 0)
                continue;
            if (strcmp(v, searchTerm) == 0)
                return v;
        }
    }
    return NULL;
}

// Loads a row associated with a given wC into compArray
char look(const char *compArray[], char wC) {
    for (int r  = 0; r < 26; r++) {
        if (toupper(wC) == *valuesMatrix[r][0]) {
            for (int ii = 0; ii < 14; ii++)
                compArray[ii] = valuesMatrix[r][ii];
            return *compArray[0];
        }
        return '\0';
    }
}

char increment(int breakdownIdx, char wC, Breakdown *breakdown, int direction) {
    switch (direction) {
        case 1:
            breakdownIdx++;
            wC = breakdown->memoryKey.data[breakdownIdx];
            break;
        case 2:
            breakdownIdx++;
            wC = breakdown->associations.data[breakdownIdx];
            break;
        case 3:
            breakdownIdx++;
            wC = breakdown->workingAssociators.data[breakdownIdx];
            break;
        default:
            break;
    }
    return wC;
}

int encode(char buffer[100], int foundI, int row, int scratchOneIdx, int flag) {
    Export ex;
    char *encodedMorpheme[10];
    encodedMorpheme[0] = encodedMatrix[row][foundI];
    // Should we have write target write to export at this point?
    // writeTarget[scratchOneIdx] = encodedMorpheme[0];
    switch (flag) {
        case 1:
            ex.memKey.data[scratchOneIdx] = *encodedMorpheme[0];
            break;
        case 2:
            ex.assoc.data[scratchOneIdx] = *encodedMorpheme[0];
            break;
        case 3:
            ex.associators.data[scratchOneIdx] = *encodedMorpheme[0];
        default:
            break;
    }

}

int verify(char buffer[100], int rowSiZe, int row, int scratchOneIdx, int flag) {
    int encodeVal;
    int foundI;
    for (int i = 0; i <= rowSiZe; i++) {
        if (valuesMatrix[row][i] == NULL) break;
        if (strncmp(buffer, valuesMatrix[row][i], strlen(buffer)) == 0) {
            // match is found here
            foundI = i;
            encodeVal = encode(buffer, foundI, row, scratchOneIdx, flag);
            return 1;
        }
        else {
            return 0;
        }
        if (encodeVal == 0) {
            perror("Morpheme Encoding Error");
        }
    }
}



void match(char buffer[100], char compBuffer[100], int scratchOneIdx, int flag) {
    char select = buffer[0];
    char compSelect =  compBuffer[0];
    char workSelect = toupper(select);
    size_t rowSize;
    int verifyReturn;
    bool verifyBool;
    if (isalnum(select)) {
        switch (workSelect)
        {
            case 'A':
                rowSize = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[A][0]);
                verifyReturn = verify(buffer, rowSize, A, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;

                }
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[B][0]);
                verify(buffer, rowSize, B, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                verify(buffer, rowSize, C, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                verify(buffer, rowSize, D, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                verify(buffer, rowSize, E, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                verify(buffer, rowSize, F, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                verify(buffer, rowSize, G, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                verify(buffer, rowSize, H, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                 break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                verify(buffer, rowSize, I, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                verify(buffer, rowSize, J, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                verify(buffer, rowSize, K, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                verify(buffer, rowSize, L,scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                verify(buffer, rowSize, M, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                verify(buffer, rowSize, N, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                verify(buffer, rowSize, O, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                verify(buffer, rowSize, P, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                verify(buffer, rowSize, Q, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                verify(buffer, rowSize, R, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                verify(buffer, rowSize, S, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                verify(buffer, rowSize, T, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                verify(buffer, rowSize, U, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                verify(buffer, rowSize, V, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                verify(buffer, rowSize, W, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix)[X][0];
                verify(buffer, rowSize, X, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                verify(buffer, rowSize, Y, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                verify(buffer, rowSize, Z, scratchOneIdx, flag);
                if (verifyReturn == 0) {
                    verifyBool = false;
                }
                else if (verifyReturn == 1) {
                    verifyBool = true;
                }
                break;
            default:
                break;
            }
        }
    }


int newCheck(int breakdownIdx, int scratchOneIdx, int writeFlag, builder *builderr, Breakdown *breakdown, char wC) {
    int encodedScratch;
    int peekIdx = breakdownIdx + 1;
    char wCPeek = breakdown->associations.data[peekIdx];
    char compArray[800]; // This is a placeholder size that needs changed, this is for loading portions of the matrix
    char compBuffer[100];
    char buffer[100];
    char comp; // Comp is sort of the opposite of wC, it is what wC is being compared against from the matrix
    size_t compSize;
    size_t sizeX;
    size_t sizeY;
    bool isAssociator = false;
    bool delimCheck = false;
    compArray[0] = look(compArray, wC); // At this point we should have all of the row associated with the given wC loaded into compArray
    compSize = sizeof(compArray) / sizeof(compArray[0]); // This gives us the number of entries within compArray

    if (isupper(wC)) {
        builderr->assocScratch.data[scratchOneIdx] = wC;
        scratchOneIdx++;
        for (int i = 0; i < compSize; i++) {
            if (wC == compArray[i]) {
                if (wC || compArray[i] == COMMA) {
                    // the comma is the delimiter, so this should denote the end of a word/entry
                    delimCheck = true;

                }
                buffer[i] = compArray[i];
                // We need to figure out how to determine direction for this call
                wC = increment(breakdownIdx, wC, &*breakdown,2);
            }

            if (wC != compArray[i]) {
                perror("Parser->newCheck failure");
                exit(EXIT_FAILURE);
            }

            if (delimCheck == true) {
                sizeX = sizeof(buffer) / sizeof(buffer[0]);
                for (int i = 0; i < sizeX; i++) {
                    compArray[i] = compBuffer[i];
                }
                sizeY = sizeof(compBuffer) / sizeof(compBuffer[0]);
                if (sizeX != sizeY) {
                    perror("Size x y error");
                    exit(EXIT_FAILURE);
                }
                if (sizeX == sizeY) {
                    // Morpheme match
                    match(buffer, compBuffer, scratchOneIdx, writeFlag);

                }



            }
            // If we go through letter by letter manually until a 'soft match', can we not then confirm it by comparing it to the entry size?
            // if i == wC, append to buffer until soft token match, then hard confirm via buffer size vs comp size?
        }
    }
}

void sendToSource() {
    nexcodeFlag = true;
    sgRun("Testing2.nexcode");

}


void parse(Breakdown *breakdown, Export *export_, builder *builderr) {
    int writeFlag = 1;
    size_t assocSize; // size of the assoc array in the working struct
    size_t memKeySize; // size of mem key array in breakdown
    size_t associatorsSize;
    bool firstNameTokenCheck = false;
    bool secondNameTokenCheck = false;
    bool closeBraceCheck = false;
    int assocCharCount = 0; // a working count of the current association being parsed
    int counts[2000]; // An array that stores the values that represent the amount of chars in each associaton
    int countsIdx = 0; // The index for appending to the above array
    int commaPoint;
    int breakdownIdx = 0;
    int scratchOneIdx = 0;
    int workIdx = breakdownIdx + 1;
    assocSize = sizeof(breakdown->associations) / sizeof(breakdown->associations.data[0]);
    memKeySize = sizeof(breakdown->memoryKey)/ sizeof(breakdown->memoryKey.data[0]);
    associatorsSize = sizeof(breakdown->workingAssociators)/ sizeof(breakdown->workingAssociators.data[0]);
    char wC; // Similar to wC in Lexer, is the current working character
    bool run = true;
    // wC = breakdown->associations[breakdownIdx]; // This sets the current working character
    char *writeTarget; // the array being written to within checker

    for (int j = 0; j < memKeySize; j++) { // This loops through the memKeys
        wC = breakdown->memoryKey.data[breakdownIdx]; // Setting wC for this logic block
        wC = increment(breakdownIdx, wC, breakdown, 1);
        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->memKeyScratch.data[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
                if (secondNameTokenCheck == true) {
                    firstNameTokenCheck = false;
                    secondNameTokenCheck = false;
                }
            }
        }
        else {
            perror("Parser nametoken error");
        }
        wC = increment(breakdownIdx, wC, breakdown, 1);
        writeTarget = builderr->memKeyScratch.data; // Assigns write target
        // The next line is what will be replaced with newCheck
        /// breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(breakdownIdx, scratchOneIdx, 1, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        
        export_->memKey.data[breakdownIdx] = writeTarget[breakdownIdx]; // We need to replace breakdownIdx

        wC = increment(breakdownIdx, wC, breakdown, 1);
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            closeBraceCheck = true;
            j = memKeySize + 1;
        }
    } // End memkey loop
    breakdownIdx = 0;
    for (int i = 0; i < assocSize; i++) { // this loops through associations
        writeFlag++;
        wC = breakdown->associations.data[breakdownIdx]; // Setting wC for this logic block

        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->assocScratch.data[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
                secondNameTokenCheck = true;
                if (secondNameTokenCheck == true) {
                    firstNameTokenCheck = false;
                    secondNameTokenCheck = false;
                }
            }
        }
        else {
            perror("Parser nametoken error");
        }
        wC = increment(breakdownIdx, wC, breakdown, 2);
        writeTarget = builderr->assocScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(breakdownIdx, scratchOneIdx, 2, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->assoc.data[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace BreakdownIDX

        /* This was originally updating wC from memoryKey before increment; i've implemented increment with 2 for association because
         I think that the memoryKey was a mistake */
        wC = increment(breakdownIdx, wC, breakdown, 2);
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            closeBraceCheck = true;
            i = assocSize + 1;
        }
    } // End associations loop
    breakdownIdx = 0;
    for (int k = 0; k < associatorsSize; k++) { // this loops through associators
        writeFlag++;
        wC = breakdown->workingAssociators.data[breakdownIdx]; // Setting wC for this logic block

        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->associatorScratch.data[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
                secondNameTokenCheck = true;
                if (secondNameTokenCheck == true) {
                    firstNameTokenCheck = false;
                    secondNameTokenCheck = false;
                }
            }
        }
        else {
            perror("Parser nametoken error");
        }
        wC = increment(breakdownIdx, wC, breakdown, 3);
        writeTarget = builderr->associatorScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(breakdownIdx, scratchOneIdx, 3, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->associators.data[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace breakdownIdx
        wC = increment(breakdownIdx, wC, breakdown, 3);
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            closeBraceCheck = true;
            k = associatorsSize + 1;
        }
    } // End associators loop
}




    // I don't remember why I wrote this so it's commented out hoping it'll become obvious that I do or don't need it

    /*
    for (int b = 0; b < assocSize; b++) {
        // These if statements get the char counts for the associations
        if (isalpha(working->assoc[b])) {
            assocCharCount++;
        }
        if (isalnum(working->assoc[b])) {
            assocCharCount++;
        }
        if (breakdown->associations[b] == COMMA) {
            commaPoint = breakdown->associations[b];
            counts[countsIdx] = assocCharCount;
            countsIdx++;
            assocCharCount = 0;
        }
        // The k for loop is isolating assocations
        for (int k = 0; k <= commaPoint - 1; k++) {
            breakdown->associations[k] = breakdown->associations[b];

        } // End of k for
        */

    // Here we will need to reference the symbol table for encodings and translate to .nexcode

    // For checking for macro'd morphemes (mm's) we should have a list of all of the first letters of
    // the mm's and if there's a match advance one letter at a time checking for mm matches



    // This is checking to see if the current char being examined is a capital letter,
    // and append it to the scratch if so




    //}

    void flag()
    {
        nexcodeFlag = true;
    }
    void exp_init(Export *export_) {
        export_->assoc.length = 0;
        export_->assoc.capacity = 0;
        export_->memKey.length = 0;
        export_->memKey.capacity = 0;
        export_->memKey.data = malloc(32);
        export_->assoc.data = malloc(64);
        export_->associators.data = malloc(32);
        if (!export_->memKey.data || !export_->assoc.data || !export_->associators.data) {
            perror("exp_init malloc failed");
            exit(EXIT_FAILURE);
        }
    }
    void exp_add(Export *export_, int value) {


    }
    void build_init(builder *builderr)
    {
        builderr->associatorScratch.length = 0;
        builderr->associatorScratch.capacity = 0;
        builderr->memKeyScratch.length = 0;
        builderr->memKeyScratch.capacity = 0;
        builderr->memKeyScratch.data = malloc(32);
        builderr->assocScratch.data = malloc(64);
        builderr->associatorScratch.data = malloc(32);
        if (!builderr->memKeyScratch.data || !builderr->assocScratch.data || !builderr->associatorScratch.data)
        {
            perror("build_init malloc failed");
            exit(EXIT_FAILURE);
        }
    }

    int prun()
    {
        // This establishes the struct instances and
        // passes them into parseAssocs
        Breakdown breakdown;
        breakdown_init(&breakdown);
        Export export_;
        exp_init(&export_);
        builder builderr;
        build_init(&builderr);
        parse(&breakdown, &export_, &builderr);
        return 0;
    }


