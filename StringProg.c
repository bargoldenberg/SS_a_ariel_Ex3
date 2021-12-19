#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#define A 65
#define Z 90
#define a 97
#define z 122
#define tilda 126

int GematriaValue(char SENTENCE[]){
    int sum=0;
    for(int i=0;i<strlen(SENTENCE);i++){
        if(SENTENCE[i]>=A&&SENTENCE[i]<=Z){
            sum+=SENTENCE[i]-A+1;
        }else if(SENTENCE[i]>=a&&SENTENCE[i]<=z){
            sum+=SENTENCE[i]-a+1;
        }
    }
    return sum;

}

char* GematriaSequences(char WORDARR[],char SENTENCE[],char* SEQUENCE){
    int Value = GematriaValue(WORDARR);
    int currINDEX=0;
    int sqINDEX=0;
    char CURRSQ[TXT]={0};
    for(int i =0;i<strlen(SENTENCE);i++){
        char strcheck[] ={SENTENCE[i],'\0'};
        if(GematriaValue(strcheck)==0){
            continue;
        }
        CURRSQ[currINDEX++]=SENTENCE[i];
        for(int j=i+1;j<strlen(SENTENCE);j++){
            char str[] ={SENTENCE[j],'\0'};
            if(GematriaValue(CURRSQ)+GematriaValue(str)<Value){
                CURRSQ[currINDEX++]=SENTENCE[j];
            }else if(GematriaValue(CURRSQ)+GematriaValue(str)==Value||GematriaValue(CURRSQ)==Value){
                char CheckSize [TXT] ={0};
                strcpy(CheckSize,CURRSQ);
                CheckSize[currINDEX]='\0';
                if(!(GematriaValue(CURRSQ)==Value)){ 
                    CURRSQ[currINDEX++]=SENTENCE[j];
                }
                CURRSQ[currINDEX++]=tilda;
                for(int k=0;k<currINDEX;k++){
                    *(SEQUENCE+sqINDEX++)=CURRSQ[k];
                    CURRSQ[k]=0;
                }
                currINDEX=0;
                j=strlen(SENTENCE);
            }else{
                for(int i =0;i<currINDEX;i++){
                    CURRSQ[i]=0;
                }
                j=strlen(SENTENCE);
                currINDEX=0;
            }

        }
    }
    SEQUENCE[sqINDEX-1]='\0';
    return SEQUENCE;
}

char* AtbashString(char *ATBASH){
    for(int i =0;i<sizeof(ATBASH);i++){
        if(ATBASH[i]>=A&&ATBASH[i]<=Z){
            char str[]={ATBASH[i],'\0'};
            ATBASH[i]=Z-GematriaValue(str)+1;
        }
        if(ATBASH[i]>=a&&ATBASH[i]<=z){
            char str[]={ATBASH[i],'\0'};
            ATBASH[i]=z-GematriaValue(str)+1;
        }
    }
    return ATBASH;
}

char* stringrev(char *str){
    int len = strlen(str);
    str[len]='0';
    int k=len-1;
    if(len%2==0){
        for(int i=0;i<len/2;i++){
            char tmp = str[k];
            str[k--]=str[i];
            str[i]=tmp;
        }
    }else{
        for(int i=0;i<(len-1)/2+1;i++){
            char tmp = str[k];
            str[k--]=str[i];
            str[i]=tmp;
        }
    }
    str[len]='\0';
    return str;
}

char *AtbashSquence(char SENTENCE[],char ATBASH[],char *ATBASHSEQ){
    char ATBASHREV[strlen(ATBASH)];
    strcpy(ATBASHREV,ATBASH);
    ATBASH=stringrev(ATBASH);
    int Value = GematriaValue(ATBASH);
    int currINDEX=0;
    int sqINDEX=0;
    char CURRSQ[TXT]={0};
    for(int i =0;i<strlen(SENTENCE)-1;i++){
        char strcheck[] ={SENTENCE[i],'\0'};
        if(GematriaValue(strcheck)==0){
            continue;
        }
        CURRSQ[currINDEX++]= strcheck[0];

        for(int j=i+1;j<strlen(SENTENCE);j++){
            int strvalue;
            int CURRSQValue = GematriaValue(CURRSQ);
            char currchar[]={SENTENCE[j],'\0'};
            strvalue=GematriaValue(currchar);
            if(CURRSQValue+strvalue<Value){
                CURRSQ[currINDEX++]=SENTENCE[j];
            }else if(CURRSQValue+strvalue==Value){
                CURRSQ[currINDEX++]=SENTENCE[j];
                CURRSQ[currINDEX]='\0';
                int FLAG =0;
                int x=0;
                for(int k=0;k<strlen(CURRSQ);k++){
                    char strtmp[] ={CURRSQ[k],'\0'};
                    char strtmp1[] ={ATBASH[x],'\0'};
                    if(GematriaValue(strtmp)==0){
                        continue;
                    }else if(strcmp(strtmp,strtmp1)==0){
                        FLAG+=1;
                        x++;
                    }
                }
                if(FLAG!=strlen(ATBASH)){
                    FLAG =0;
                    int x=0;
                    for(int k=0;k<strlen(CURRSQ);k++){
                        char strtmp[] ={CURRSQ[k],'\0'};
                        char strtmp1[] ={ATBASHREV[x],'\0'};

                        if(GematriaValue(strtmp)==0){
                            continue;
                        }else if(strcmp(strtmp,strtmp1)==0){
                            FLAG+=1;
                            x++;
                        }
                    }
                }
                if(FLAG!=strlen(ATBASH)){
                    for(int i =0;i<currINDEX;i++){
                        CURRSQ[i]=0;
                    }
                    j=strlen(SENTENCE);
                    currINDEX=0;
                }else {

                    CURRSQ[currINDEX++] = tilda;
                    for (int k = 0; k < currINDEX; k++) {
                        *(ATBASHSEQ + sqINDEX++) = CURRSQ[k];
                        CURRSQ[k] = 0;
                    }
                    currINDEX = 0;
                    j = strlen(SENTENCE);
                }
            }else{
                for(int i =0;i<currINDEX;i++){
                    CURRSQ[i]=0;
                }
                j=strlen(SENTENCE);
                currINDEX=0;
            }

        }
    }
    ATBASHSEQ[sqINDEX-1]='\0';
    return ATBASHSEQ;
}
void swap(char *x, char *y){
    char tmp = *x;
    *x=*y;
    *y=tmp;
}
void sort(char *str){
    for(int i =0;i<strlen(str)-1;i++){
        for(int j=i+1;j<strlen(str);j++){
            if(str[i]>str[j]){
                swap(&str[i],&str[j]);
            }
        }
    }
}
char* permutations(char WORDARR[],char SENTENCE[],char* SEQUENCE){
    char SORTEDWORD[strlen(WORDARR)];
    strcpy(SORTEDWORD,WORDARR);
    int Value = GematriaValue(WORDARR);
    sort(SORTEDWORD);
    int currINDEX=0;
    int sqINDEX=0;
    char CURRSQ[TXT]={0};
    for(int i =0;i<strlen(SENTENCE)-1;i++){
        char strcheck[] ={SENTENCE[i],'\0'};
        if(GematriaValue(strcheck)==0){
            continue;
        }
        CURRSQ[currINDEX++]=SENTENCE[i];
        for(int j=i+1;j<strlen(SENTENCE);j++){
            char str[] ={SENTENCE[j],'\0'};
            if(GematriaValue(CURRSQ)+GematriaValue(str)<Value){
                CURRSQ[currINDEX++]=SENTENCE[j];
            }else if(GematriaValue(CURRSQ)+GematriaValue(str)==Value){
                CURRSQ[currINDEX++]=SENTENCE[j];
                CURRSQ[currINDEX]='\0';
                char CURRSQcheck[strlen(CURRSQ)];
                strcpy(CURRSQcheck,CURRSQ);
                sort(CURRSQcheck);
                char CURRSQNOSYM[strlen(WORDARR)];
                int indx=0;
                for(int i =0;i<strlen(CURRSQ);i++){
                    if(CURRSQcheck[i]!=' '){
                        CURRSQNOSYM[indx++]=CURRSQcheck[i];
                    }
                }
                CURRSQNOSYM[indx]='\0';
                if(strcmp(CURRSQNOSYM,SORTEDWORD)==0){
                    CURRSQ[currINDEX++]=tilda;
                    for(int k=0;k<currINDEX;k++){
                        *(SEQUENCE+sqINDEX++)=CURRSQ[k];
                        CURRSQ[k]=0;
                    }
                    currINDEX=0;
                    j=strlen(SENTENCE);
                }
            }else{
                for(int i =0;i<currINDEX;i++){
                    CURRSQ[i]=0;
                }
                j=strlen(SENTENCE);
                currINDEX=0;
            }

        }
    }
    SEQUENCE[sqINDEX-1]='\0';
    return SEQUENCE;
    
}


