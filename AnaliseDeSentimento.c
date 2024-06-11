#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define MAX_PARAGRAPHS 10
#define MAX_WORDS 9040
#define MAX_LIST_SIZE 1000
#define MAX_WORD_SIZE 100
#define MAX_LIST_SIZE 1000

void toLowerString(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}
void tokenizeAndStore(char *text, char storage[][21], int *index) {
    char *token = strtok(text, " ,.:()?;!\n");
    while (token != NULL) {
        strcpy(storage[*index], token); // Copia a palavra diretamente para o array de armazenamento
        token = strtok(NULL, " ,.:()?;!\n");
        (*index)++;
    }
}

void split_SentenceShort(char text_Analysis[10][9040], int num_Paragraphs, char happy[MAX_LIST_SIZE], char sad[MAX_LIST_SIZE], char stoHappy[100][21], char stoSad[100][21], int *happy_Count, int *sad_Count)
{
    int min_Words = 1000;
    int count_Words = 0;
    char sentence_Short[1000] = "";
    char *text_Copy2[9040];
    char *word_Min;
    for (int i = 0; i < num_Paragraphs; i++)
    {
        int count = 0;
        for (int j = 0; text_Analysis[i][j] != '\0'; j++)
        {
            if (text_Analysis[i][j] == ' ')
            {
                count_Words++;
            }
            if (text_Analysis[i][0] != ' ' && j == 0)
            {
                count_Words++;
            }
            if (text_Analysis[i][j] == '.')
            {
                if (count_Words < min_Words)
                {
                    strcpy(sentence_Short, "");
                    min_Words = count_Words;
                    while (count < j)
                    {
                        strncat(sentence_Short, &text_Analysis[i][count], 1);
                        count++;
                    }
                    sentence_Short[count] = '\0';
                }
                count = j;
                count_Words = 0;
            }
        }
    }

    *happy_Count = 0;
    *sad_Count = 0;

    // Tokenize and store happy words
    int index = 0;
    char happy_Copy[MAX_LIST_SIZE];
    strcpy(happy_Copy, happy);
    tokenizeAndStore(happy_Copy, stoHappy, &index);
    int happy_size = index;

    // Tokenize and store sad words
    index = 0;
    char sad_Copy[MAX_LIST_SIZE];
    strcpy(sad_Copy, sad);
    tokenizeAndStore(sad_Copy, stoSad, &index);
    int sad_size = index;

    word_Min = strtok(sentence_Short, " ,.:()?;!\n");
    index = 0;
    while (word_Min != NULL) {
        text_Copy2[index] = word_Min;
        word_Min = strtok(NULL, " ,.:()?;!\n");
        index++;
    }
    int text_size = index;
    index = 0;

    // Count sad words in the longest sentence
    for (int i = 0; i < text_size; i++) {
        for (int j = 0; j < sad_size; j++) {
            if (strcmp(text_Copy2[i], stoSad[j]) == 0) {
                (*sad_Count)++;
            }
        }
    }

    // Count happy words in the longest sentence
    for (int i = 0; i < text_size; i++) {
        for (int j = 0; j < happy_size; j++) {
            if (strcmp(text_Copy2[i], stoHappy[j]) == 0) {
                (*happy_Count)++;
            }
        }
    }
}

void split_SentenceMax(char texto[10][9040], int num_Paragraphs, char happy[MAX_LIST_SIZE], char sad[MAX_LIST_SIZE], char stoHappy[100][21], char stoSad[100][21], int *happy_Count, int *sad_Count) {
    int len_Max = 0;
    int len = 0;
    int index = 0;
    char sentence_Long[9040] = "";
    char text_Copy[9040];
    char *text_Copy2[9040];
    char *word_Max;

    *happy_Count = 0;
    *sad_Count = 0;

    // Tokenize and store happy words
    index = 0;
    char happy_Copy[MAX_LIST_SIZE];
    strcpy(happy_Copy, happy);
    tokenizeAndStore(happy_Copy, stoHappy, &index);
    int happy_size = index;

    index = 0;
    char sad_Copy[MAX_LIST_SIZE];
    strcpy(sad_Copy, sad);
    tokenizeAndStore(sad_Copy, stoSad, &index);
    int sad_size = index;

    for (int i = 0; i < num_Paragraphs; i++) {
        strcpy(text_Copy, texto[i]);
        char *sentenca = strtok(text_Copy, ".");
        while (sentenca != NULL) {
            len = strlen(sentenca);
            if (len > len_Max) {
                len_Max = len;
                strcpy(sentence_Long, sentenca);
            }
            sentenca = strtok(NULL, ".");
        }
    }

    word_Max = strtok(sentence_Long, " ,.:()?;!\n");
    index = 0;
    while (word_Max != NULL) {
        text_Copy2[index] = word_Max;
        word_Max = strtok(NULL, " ,.:()?;!\n");
        index++;
    }
    int text_size = index;

    for (int i = 0; i < text_size; i++) {
        for (int j = 0; j < sad_size; j++) {
            if (strcmp(text_Copy2[i], stoSad[j]) == 0) {
                (*sad_Count)++;
            }
        }
    }
    for (int i = 0; i < text_size; i++) {
        for (int j = 0; j < happy_size; j++) {
            if (strcmp(text_Copy2[i], stoHappy[j]) == 0) {
                (*happy_Count)++;
            }
        }
    }

}
int main() {
    int num_Paragraphs = 0;
    int question_Type = 0;
    int happy_Count = 0;
    int sad_Count = 0;
    int paragraph_Polarity = 0;
    int var_Temp = 0;
    int num_Questions = 0;
    int happy_size = 0;
    int sad_size = 0;

    char text_Analysis[MAX_PARAGRAPHS][MAX_WORDS];
    char list_Happy[MAX_LIST_SIZE];
    char list_Sad[MAX_LIST_SIZE];

    char storage_Analysis[MAX_WORDS][21];
    char storage_Happy[100][21];
    char storage_Sad[100][21];

    scanf("%d", &num_Paragraphs);
    getchar();

    for (int i = 0; i < num_Paragraphs; i++) {
        fgets(text_Analysis[i], MAX_WORDS, stdin);
    }

    fgets(list_Happy, MAX_LIST_SIZE, stdin);
    fgets(list_Sad, MAX_LIST_SIZE, stdin);

    scanf("%d", &num_Questions);
    getchar();

    for (int z = 0; z < num_Questions; z++) {
        happy_Count = 0;
        sad_Count = 0;

        scanf("%d", &question_Type);
        if (question_Type == 1) {
            int index = 0;             
            for (int i = 0; i < num_Paragraphs; i++) {
                char temp[MAX_WORDS];
                strcpy(temp, text_Analysis[i]);
                tokenizeAndStore(temp, storage_Analysis, &index);
            }
            int text_size = index;

            index = 0;
            char happy_Copy[MAX_LIST_SIZE];
            strcpy(happy_Copy, list_Happy);
            tokenizeAndStore(happy_Copy, storage_Happy, &index);
            int happy_size = index;

            index = 0;
            char sad_Copy[MAX_LIST_SIZE];
            strcpy(sad_Copy, list_Sad);
            tokenizeAndStore(sad_Copy, storage_Sad, &index);
            int sad_size = index;

            for (int i = 0; i < text_size; i++) {
                toLowerString(storage_Analysis[i]);
                for (int j = 0; j < happy_size; j++) {
                    if (strcmp(storage_Analysis[i], storage_Happy[j]) == 0) {
                        happy_Count++;
                        break;
                    }
                }
            }

            for (int i = 0; i < text_size; i++) {
                for (int j = 0; j < sad_size; j++) {
                    if (strcmp(storage_Analysis[i], storage_Sad[j]) == 0) {
                        sad_Count++;
                        break;
                    }
                }
            }
        }


        if (question_Type == 2) {
            scanf("%d", &paragraph_Polarity);
            getchar(); 
            int index = 0;             
            char text_Copy[MAX_WORDS];
            strcpy(text_Copy, text_Analysis[paragraph_Polarity]);
            tokenizeAndStore(text_Copy, storage_Analysis, &index);
            int text_size = index;

            index = 0;
            char happy_Copy[MAX_LIST_SIZE];
            strcpy(happy_Copy, list_Happy);
            tokenizeAndStore(happy_Copy, storage_Happy, &index);
            int happy_size = index;

            index = 0;
            char sad_Copy[MAX_LIST_SIZE];
            strcpy(sad_Copy, list_Sad);
            tokenizeAndStore(sad_Copy, storage_Sad, &index);
            int sad_size = index;

            for (int i = 0; i < text_size; i++) {
                toLowerString(storage_Analysis[i]);
                for (int j = 0; j < happy_size; j++) {
                    if (strcmp(storage_Analysis[i], storage_Happy[j]) == 0) {
                        happy_Count++;
                        break;
                    }
                }
            }

            for (int i = 0; i < text_size; i++) {
                for (int j = 0; j < sad_size; j++) {
                    if (strcmp(storage_Analysis[i], storage_Sad[j]) == 0) {
                        sad_Count++;
                        break;
                    }
                }
            }
        }


        if (question_Type == 3) {
            split_SentenceMax(text_Analysis, num_Paragraphs, list_Happy, list_Sad, storage_Happy, storage_Sad, &happy_Count, &sad_Count);

        }   

        if (question_Type == 4) {
            split_SentenceShort(text_Analysis, num_Paragraphs, list_Happy, list_Sad, storage_Happy, storage_Sad, &happy_Count, &sad_Count);
        }
        if ((happy_Count - sad_Count) > 3) {
            printf("%d Palavras positivas, %d Palavras negativas: Polaridade positiva\n", happy_Count, sad_Count);
        } else if (happy_Count > 0 && sad_Count == 0) {
            printf("%d Palavras positivas, %d Palavras negativas: Polaridade positiva\n", happy_Count, sad_Count);
        } else if ((sad_Count - happy_Count) > 3) {
            printf("%d Palavras positivas, %d Palavras negativas: Polaridade negativa\n", happy_Count, sad_Count);
        } else if (happy_Count == 0 && sad_Count > 0) {
            printf("%d Palavras positivas, %d Palavras negativas: Polaridade negativa\n", happy_Count, sad_Count);
        } else if (happy_Count > 0 && sad_Count > 0 && (abs(happy_Count - sad_Count) <= 3)) {
            printf("%d Palavras positivas, %d Palavras negativas: Polaridade neutra\n", happy_Count, sad_Count);
        }else if(happy_Count == 0 && sad_Count == 0){
            printf("0 Palavras positivas, 0 Palavras negativas: Polaridade neutra\n");
        }

    }

    return 0;
}