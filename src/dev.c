
#include <string.h>
#include <stdio.h>

int sort(char* k1,char* k2){
    int x=0;
    while(k1[x]==k2[x] && x<strlen(k1) && x<strlen(k2)){
        x++;
    }
    //printf("\nk1==%c", k1[x]);
   // printf("\nk2==%c", k2[x]);
    
    if (x==strlen(k1)) return 0;
    if (x==strlen(k2)) return 1;
    if (k1[x]>k2[x]) return 1;
    return 0;


}

char computing(char *array, int count_words){
    int i=0,j=0,k=0;
    char array_char[count_words][16]; // [words][simbol]
    while (i<count_words){
        memset(array_char[i],0,16);
        i++; //clean memory
    }
    for(i=0;i<count_words;i++){
        j=0;
        while(i+j<count_words && array[i+j]!=' '){ // separated
            array_char[k][j]=array[i+j];
            j++;
            printf("\narray_char= %s",array_char[k]); // print words
        }
        k++;
        i+=j;
    } // get array_char with words

    j=0; char tmp[16];
    while(j<count_words){
        i=0;
        while (i<count_words){
            printf("\nnod=%s",array_char[0]);
            if(sort(array_char[i],array_char[i+1])){
                strcpy(tmp,array_char[i]); printf("\ntmp-->%s",tmp);
                strcpy(array_char[i],array_char[i+1]);
                strcpy(array_char[i+1],tmp);
                printf("\nYE%s",array_char[0]);
            }
        i++;
        }
        // print array
    }
}

/*    array_char = array[i];
    printf("%c", array_char);
    array_char[i] = 'a';
    strcat(array_char[i], *(array+i));
    //array_char[i] += '\0';
*/  //  printf("\n%c", array_char[0]);



char string(int count_words){
    int i;
    char *str;
    char array[count_words]; // Create char array 
    str = array;
    //printf("Please press Enter\n");
    printf("Please enter u text ==>");
    scanf("\n%d", &i);
    while((*str ++= getchar ()) != '\n'){
        *str = '\0'; // Add last mark string
    }
    //printf("%s\n", array);
    computing(array, count_words);
    return 0;
}



int main(){
    int i=0,j=0;
    int count_words = 0;
    char array[count_words];
    printf("Please enter maximum number of words in the text ==> ");
    scanf("%d", &count_words);
//  printf("count_words --> %d\n",count_words);
    string(count_words); // void function

/*  char array[count_words]; // Create char array 
    char *str; // Init temporary mark
    str = array;
    printf("Please enter u text ==> \n");
    while((*str ++= getchar ()) != '\n'){
        *str = '\0'; // Add last mark string
    }
*/    
    
}
