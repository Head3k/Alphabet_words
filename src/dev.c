#include <string.h>
#include <stdio.h>

int sort(char* k1,char* k2){  // function for decisions move for two words
    int x=0; // init var for enumeration symbol in the words
    while(tolower(k1[x])==tolower(k2[x]) && x<strlen(k2)){  // cicle for check symbols and choice next
        x++; // var for next symbol int the word
    } //
    if (x==strlen(k1)) return 0;  // condition for move two words
    if (x==strlen(k2)) return 1;  // condition for move two words
    if (tolower(k1[x])>tolower(k2[x])) return 1;  // condition for move two words
    return 0; // return NULL
}

char computing(char *array, int count_words, int count_symbols){  // function for symbols -> words and move words in array
    int i=0,j=0,k=0;  // init var for cicle
    char array_char[count_words][16];   // init general array  
    while (i<count_words){             // cicle general array with data
        memset(array_char[i],0,16);   // clear memory array
        i++;                         // clean memory array
    }                               //
    for(i=0;i<count_symbols;i++){  // cicle for enumeration symbols
        while(i+j<count_symbols && array[i+j]!=' ' && array[i+j]!=','){  // cicle for symbols -> words
            array_char[k][j]=array[i+j]; // symbols -> words
            j++; // var for next symbol in words
        }
        i+=j; // save number last symbol
        k++; // var for next words in array
        j=0; // clear number last symbol
    }  // 
    j=0;
    char tmp[16];  // init var for buble sort array
    while(j<(count_words)){  // cicle for retry 'cicle for enumeration words'
        i=0;  // var for enumeration two words
        while (i<(count_words) && (array_char[i][16] != '\0')){  // cicle for enumeration words 
            if(sort(array_char[i],array_char[i+1])){  // condition sort two words
                strcpy(tmp,array_char[i]);  // first words -> tmp  
                strcpy(array_char[i],array_char[i+1]);  // second words -> first words
                strcpy(array_char[i+1],tmp);  // tmp -> second words
            } //
        i++; // var for next two words
        }
    j++;  // var for retry 'cicle for enumeration words'
    }
    i=0; // clean var for cicle for print general array
    while (i<count_words){  // cicle for print general array
        printf("\n%s", array_char[i]);  // print [i] word from the array
        i++;  // var for next [i] word
    }  //
} //

char string(int count_words){                     // function for enter data and check quantity symbols
    int i=0;                                       // init var for clear clipboard
    char *str;                                      // init string for data
    int count_symbols=0;                             // init var for count symbols in the text
    char array[count_words*16];                          // create char array
    str = array;                                       // array --> str
    printf("Please don't use a space after punctuation marks");  //
    printf("\nEnter u text ==> ");                  //
    scanf("\n%d", &i);                                  // scan for clean clipboard
    while((*str ++= getchar ()) != '\n'){              // enter data
        count_symbols++;                              // quantity symbols ++;
        *str = '\0';                                 // add last mark string
    }                                               //
    computing(array, count_words, count_symbols);  // void function
    return 0;                                     //
}                                                //

int main(){                   // main
    int count_words = 0;       // init var for count words in the text
    printf("Enter maximum number of words in the init var for text ==> ");
    scanf("%d", &count_words);  // enter count words in the text
    count_words++;             // for E0F string
    string(count_words);      // void function
    
}