#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct Person{
    char name[32];
    int age;
    struct Person *next;
} Person;

/**
 * Hash function
 * @param str string to hash
 * @return the hash value
 */
unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash % TABLE_SIZE);
}

Person * hash_table[TABLE_SIZE];

/**
 * @brief Initialize the hash table
 */
bool init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    return true;
}

/**
 * @brief print_hash_table
 * 
 * @param name the name of the person
 * @param age the age of the person
 */
void print_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            Person *p = hash_table[i];
            printf("%d: ", i);
            while (p != NULL) {
                printf("%s: %d | ", p->name, p->age);
                p = p->next;
            }
            printf("\n");
        }
        else {
            printf("%d: NULL\n", i);
        }
    }
    printf("###################\n");
}

/**
    * @param person
    * @return true if the person was added to the hash table
    */
bool insert_hash_table(Person * person) {
    if(person == NULL) {
        return false;
    }
    unsigned int index = hash(person->name);
    person->next = hash_table[index];
    hash_table[index] = person;
    return true;
}

/**
 * @param name: name of the person
    * @return: person if found, NULL otherwise
    * @note: return the first person with the same name
    * @brief
        * This function will search for a person in the hash table.
        * If the person is found, it will return the person.
        * If the person is not found, it will return NULL.
 */
Person * find_hash_table(const char * name) {
    if(name == NULL) {
        return NULL;
    }
    unsigned int index = hash(name);
    if (hash_table[index] == NULL) {
        return NULL;
    }
    else {
        if(strcmp(hash_table[index]->name, name) == 0) {
            printf("Found %s: %d\n", hash_table[index]->name, hash_table[index]->age);
            return hash_table[index];
        }
        else {
            Person * person = hash_table[index];
            while(person != NULL) {
                if(strcmp(person->name, name) == 0) {
                    printf("Found %s: %d\n", person->name, person->age);
                    return person;
                }
                person = person->next;
            }
            printf("Not found\n");
            return NULL;
        }
    }
}


/**
 * @param name: name of the person
    * @return: true if the person was removed from the hash table
    * @note: return the first person with the same name
    * @brief
        * This function will search for a person in the hash table.
        * If the person is found, it will remove the person from the hash table.
        * If the person is not found, it will return false.
 */
Person * delete_hash_table(const char * name) {
    if(name == NULL) {
        return NULL;
    }
    unsigned int index = hash(name);
    if (hash_table[index] == NULL) {
        return NULL;
    }
    else {
        if(strcmp(hash_table[index]->name, name) == 0) {
            Person * person = hash_table[index];
            hash_table[index] = person->next;
            return person;
        }
        else {
            Person * person = hash_table[index];
            Person * prev = NULL;
            while(person != NULL) {
                if(strcmp(person->name, name) != 0) {
                    prev = person;
                    person = person->next;
                    break;
                }
            }
            if(person == NULL) {
                /* Not found */
                return NULL;
            }
            if(prev == NULL) {
                /* Deleting the head */
                hash_table[index] = person->next;
            }
            else {
                /* Deleting a node in the middle */
                prev->next = person->next;
            }
            return person;
        }
    }
}

int main(void) {
    init_hash_table();

    printf("%d\n", hash("Mary"));
    printf("%d\n", hash("John"));
    printf("%d\n", hash("Jane"));
    printf("%d\n", hash("Jimmy"));

    print_hash_table();

    Person mary = {"Mary", 25};
    Person john = {"John", 30};
    Person jane = {"Jane", 20};
    Person jimmy = {"Jimmy", 18};

    insert_hash_table(&mary);
    insert_hash_table(&john);
    insert_hash_table(&jane);
    insert_hash_table(&jimmy);

    print_hash_table();

    delete_hash_table("Jimmy");

    print_hash_table();

    find_hash_table("Mary");

    find_hash_table("Jimmy");

    return 0;
}