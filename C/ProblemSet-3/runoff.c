// #include <cs50.h>
// #include <stdio.h>
// #include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Placeholder value for candidate rank index
    int rankVal = -1;
    // For loop to verify if candidate is valid
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            //Set rank index value to variable
            rankVal = j;
            break;
        }
    }

    if (rankVal == -1)
    {
        return false;
    }
    // Set rank index if valid
    preferences[voter][rank] = rankVal;
    return true;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Nested For Loops to iterate through preferences table array
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // Variable for each column in row to be checked
            int validVote = preferences[i][j];
            //If statement verifying status of each column
            if (!candidates[validVote].eliminated)
            {
                //Tally result for first valid vote in row and break
                candidates[validVote].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //Variable to set half of votes
    int half = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        // If statetement comparing candidate vote amount to half of voter amount
        if (candidates[i].votes > half)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Exaggerated high amount as placeholder variable
    int minV = 1000000;
    for (int i = 0; i < candidate_count; i++)
    {
        // If statement to set lowest vote count as variable value
        if (!candidates[i].eliminated && candidates[i].votes < minV)
        {
            minV = candidates[i].votes;
        }
    }
    // If no change in variable, return 0, else return new value
    return minV == 1000000 ? 0 : minV;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    //tally remaining candidates
    int remaining = 0;
    //tally random vote
    int vote = 0;
    //tally matches between candidate votes
    int match = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            // Track random vote and increase # of remaining candidates
            vote = candidates[i].votes;
            remaining++;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        // Compare random vote with each candidate's vote and increase count of matches per instance
        if (!candidates[i].eliminated && candidates[i].votes == vote)
        {
            match++;
        }
    }
    // Compare matches with # of remaining candidates and return boolean
    return match == remaining;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate vote count is equal to minimum number of votes, set eliminated value as true
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
