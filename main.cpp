#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxent 100
#define maxnam 50

typedef struct {
    char name[maxnam];
    int subscribed;
    int points;
} Entry;

int main() {
    Entry entries[maxent];
    int num_entries = 0;
    int i, j;
    char name[maxnam];
    char response;
    
    printf("Welcome to the giveaway management system!\n\n");
    
    do {
        printf("Enter the name of the entrant: ");
        scanf("%s", name);
        
        // Check if the entrant is already in the system
        for (i = 0; i < num_entries; i++) {
            if (strcmp(entries[i].name, name) == 0) {
                printf("%s is already in the system.\n\n", name);
                break;
            }
        }
        
        // If the entrant is not already in the system, add them
        if (i == num_entries) {
            strcpy(entries[num_entries].name, name);
            entries[num_entries].subscribed = 0;
            entries[num_entries].points = 0;
            num_entries++;
            printf("%s has been added to the system.\n\n", name);
        }
        
        // Ask if the entrant is subscribed
        printf("Is %s subscribed? (y/n) ", name);
        scanf(" %c", &response);
        
        if (response == 'y') {
            entries[i].subscribed = 1;
            entries[i].points += 10;
            printf("%s has been awarded 10 points for being subscribed.\n\n", name);
        }
        
        // Ask if there are any more entrants
        printf("Are there any more entrants? (y/n) ");
        scanf(" %c", &response);
        printf("\n");
    } while (response == 'y' && num_entries < maxent);
    
    // Find the entrant with the most points
    int max_points = 0;
    int max_index = -1;
    for (i = 0; i < num_entries; i++) {
        if (entries[i].points > max_points) {
            max_points = entries[i].points;
            max_index = i;
        }
    }
    
    if (max_index == -1) {
        printf("There are no entries.\n");
    } else {
        printf("%s has won!", entries[max_index].name, entries[max_index].points);
    }
    
    return 0;
}