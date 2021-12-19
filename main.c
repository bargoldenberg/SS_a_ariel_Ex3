#define TXT 1024
#define WORD 30
#define tilda 126
#include<stdio.h>
#include<string.h>
#include"StringProg.h"
int main()
{
    char SENTENCE [TXT]={0};
    char WORDARR [WORD] = {0};
    char SEQUENCE[TXT]={0};
    char ATBASH[WORD] = {0};
    scanf("%s",WORDARR);
    strcpy(ATBASH,WORDARR);
    AtbashString(ATBASH);
    int index = 0;
    char x;
    while(index<1024){
        scanf("%c",&x);
        if(x==tilda){
            break;
        }else{
            SENTENCE[index]=x;
            index++;
        }
    }
    char ATBASHSENTENCE[TXT]={0};
    char ANAGRAMSENTENCE[TXT]={0};
    char ATBASHSEQUENCE[TXT]={0};
    char ANAGRAMSEQUENCE[TXT]={0};
    strcpy(ATBASHSENTENCE,SENTENCE);
    strcpy(ANAGRAMSENTENCE,SENTENCE);
    printf("Gematria Sequences: %s\n",GematriaSequences(WORDARR,SENTENCE,SEQUENCE));
    printf("Atbash Sequences: %s\n",AtbashSquence(ATBASHSENTENCE,ATBASH,ATBASHSEQUENCE));
    printf("Anagram Sequences: %s",permutations(WORDARR,ANAGRAMSENTENCE,ANAGRAMSEQUENCE));
    return 0;
}