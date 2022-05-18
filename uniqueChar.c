#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LETTERS     26

typedef struct alphabetTable{
    char letter;
} alphabetTable;

alphabetTable * hash_table[MAX_LETTERS];

/**
 * Hash function
 * @param str string to hash
 * @return the hash value
 */
unsigned int hash(const char str) {
    int hash = 0;
    
    hash = str - 'a'; /* hash - a */

    return hash;
}

/**
 * @brief Initialize the hash table
 */
bool init_hash_table() {
    for (int i = 0; i < MAX_LETTERS; i++) {
        hash_table[i] = NULL;
    }
    return true;
}

/**
    * @param letter
    * @return true if the letter was added to the hash table
    */
bool insert_hash_table(alphabetTable * letter) {
    if(letter == NULL) {
        return false;
    }
    int index = hash(letter->letter);
    hash_table[index] = letter;
    return true;
}

bool find_hash_table(alphabetTable * letter) {
    if(letter == NULL) {
        return false;
    }
    int index = hash(letter->letter);
    if(hash_table[index] != NULL)
        return true;
    return false;
}

int main(void) {
    alphabetTable * letter = malloc(sizeof(alphabetTable));
    letter->letter = 'l';
    alphabetTable letter2 = {'b'};
    printf("%d \n", hash(letter->letter));
    printf("%d \n", hash(letter2.letter));
    insert_hash_table(letter);
    if(find_hash_table(letter)) {
        printf("Found letter\n");
    }
    else {
        printf("Did not find letter\n");
    }
    return 0;
}