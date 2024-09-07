#include <stdio.h>
#include <string.h>

#define CANDIDATE_COUNT 3

// Structure for storing candidate information
struct Candidate {
    char name[50];
    int votes;
};

int main() {
    struct Candidate candidates[CANDIDATE_COUNT];
    int totalVoters, vote, i;

    // Initialize candidate names and votes
    strcpy(candidates[0].name, "Candidate 1");
    candidates[0].votes = 0;

    strcpy(candidates[1].name, "Candidate 2");
    candidates[1].votes = 0;

    strcpy(candidates[2].name, "Candidate 3");
    candidates[2].votes = 0;

    // Ask for the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &totalVoters);

    // Voting process
    for (i = 1; i <= totalVoters; i++) {
        printf("Voter %d, choose your candidate (1, 2, or 3): ", i);
        scanf("%d", &vote);

        if (vote >= 1 && vote <= 3) {
            candidates[vote - 1].votes++;
        } else {
            printf("Invalid vote! Please vote again.\n");
            i--; // Reduce counter to allow re-voting
        }
    }

    // Display voting results
    printf("\nVoting Results:\n");
    for (i = 0; i < CANDIDATE_COUNT; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}

