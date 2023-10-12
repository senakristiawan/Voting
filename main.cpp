#include <stdio.h>
#include <string.h>

// void addCandidate();
// void view();

struct Candidate{
    char name[50];
    int age;
    char gender[50];
    char birthPlace[50];
    char experience[50];
    int votes = 0;
};
void addCandidate(struct Candidate person[], int* candidateCount);
void view(struct Candidate person[], int candidateCount);
void vote(struct Candidate person[], int candidateCount, int* counter);

int main(){
    struct Candidate candidates[10];
    int candidateCount=0;
    int input;
    int counter =0;

    while(1){
        printf(" ______________________________________________________________________\n");
        printf("|                     L E A D E R_E L E C T I O N                     \t|\n");
        printf("|_____________________________________________________________________\t|\n");
        printf("|Hi citizens, it is finally the time for us to pick out a new leader!\t|\n");
        printf("|Please choose one of these options.\t\t\t\t\t|\n");
        printf("|_____________________________________________________________________\t|\n");
        printf(" ______________________________\n");
        printf("|No.| Options\t\t\t|\n");
        printf("|1. | Add Leader Candidate\t|\n");
        printf("|2. | Vote A Candidate\t\t|\n");
        printf("|3. | View Added Candidates\t|\n");
        printf("|4. | Exit\t\t\t|\n");
        printf("|______________________________\t|\n");

        printf("Enter Number:");
        scanf("%d",&input);
        getchar();
        switch(input){
            case 1 : 
                addCandidate(candidates, &candidateCount);
                candidateCount++;
                break;
            case 2 : 
                if(counter == 1){
                    printf("Sorry, you can only vote once.\n");
                    break;
                }else{
                    vote(candidates, candidateCount, &counter);
                }
                break;
            case 3 : 
                puts("");
                view(candidates, candidateCount);
                break;
            case 4 : 
                puts("Thank you for using this program!");
                return 0;
            default:
                printf("Invalid choice, plese enter a valid option.\n");
        }
    }

    return 0;
}

void addCandidate(struct Candidate person[], int* candidateCount){
    if(*candidateCount<10){
        printf("|Name : ");
        scanf("%s", &person[*candidateCount].name);
        puts("");
        getchar();
        printf("|Age : ");
        scanf("%d", &person[*candidateCount].age);
        puts("");
        getchar();
        printf("|Gender : ");
        scanf("%s", &person[*candidateCount].gender);
        puts("");
        getchar();
        printf("|Birth Place : ");
        scanf("%s", &person[*candidateCount].birthPlace);
        puts("");
        getchar();
        printf("|One Major Experience : ");
        scanf(" %s", &person[*candidateCount].experience);
        puts("");
        getchar();
    }
}


void view(struct Candidate person[], int candidateCount){
    if (candidateCount>0){
        puts("Candidate Data List");
        printf("________________________________________________________________________________________________\n");
        printf("|\tName\t|\tAge\t|\tGender\t|\tBirth\t|\tExp\t|\tVotes\t|\n");
        printf("________________________________________________________________________________________________\n");
        for(int i = 0;i<candidateCount; i++){
            printf("|\t%s\t|\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%d\t|\n", person[i].name, person[i].age, person[i].gender, person[i].birthPlace, person[i].experience, person[i].votes);
            printf("________________________________________________________________________________________________\n");
        }
        puts("\n");
    }else{
        printf("There is no Candidate!\n\n");
    }
}

void vote(struct Candidate person[], int candidateCount, int* counter ){
    char choice[100];
    view(person, candidateCount);
    printf("Who do you want to vote?\n");
    scanf("%s", choice);
    for(int i = 0 ; i<candidateCount;i++){
        if(strcmp(choice, person[i].name)==0 ){
            person[i].votes++;
            (*counter)++;
            break;
        }
    }
}
