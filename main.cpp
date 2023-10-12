#include <stdio.h>
#include <string.h>

struct Candidate{
    char name[10];
    int age[10];
    char gender[10];
    char birthPlace[10];
    char experience[10];
    int votes[10];
};

void add(Candidate* person, int* candidateCount){
    if(*candidateCount<10){
        printf("Name : ");
        scanf("%[\n]", person[*candidateCount].name);
        printf("Age : ");
        scanf("%d", &person[*candidateCount].age);
        printf("Gender : ");
        scanf("%[\n]", person[*candidateCount].gender);
        printf("Birth Place : ");
        scanf("%[^\n]", person[*candidateCount].birthPlace);
        printf("One Major Experience : ");
        scanf("%[^\n]", person[*candidateCount].experience);
    }
}

void view(Candidate* person, int candidateCount){
    for(int i = 0;i<candidateCount; i++){
        printf("Name : %s\n", person[i].name);
        printf("Age : %d\n", person[i].age);
        printf("Gender : %c\n", person[i].gender);
        printf("Birth Place : %s\n", person[i].birthPlace);
        printf("Experience : %s\n", person[i].experience);
        printf("votes : %d\n", person[i].votes);
    }
}

void vote(struct Candidate* person, int candidateCount, int* counter ){
    char choice[100];
    view(person, candidateCount);
    printf("Who do you want to vote?\n");
    scanf("%s", choice);
    for(int i =0 ; i<candidateCount;i++){
        if(strcmp(choice, person[i].name)==0 ){
            person[i].votes++;
            (*counter)++;
            break;
        }
    }
}

int main(){
    struct Candidate candidates[10];
    int candidateCount;
    int input;
    int counter =0;

    while(1){
        printf("==========================LEADER ELECTION===========================\n");
        printf("Hi citizens, it is finally the time for us to pick out a new leader!\n");
        printf("Please choose one of these options.\n");
        printf("1. Add Leader Candidate\n");
        printf("2. Vote A Candidate\n");
        printf("3. View Added Candidates\n");
        printf("4. Exit\n");

        printf("Enter Choice:");
        scanf("%d",&input);
        switch(input){
            case 1 : 
                add(candidates, &candidateCount);
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
                view(candidates, candidateCount);
                break;
            case 4 : 
                return 0;
            default:
                printf("Invalid choice, plese enter a valid option.\n");
        }

    }

    return 0;
}