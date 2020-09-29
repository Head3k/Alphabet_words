#include "computing.h"
#include <stdio.h>
#include <string.h>

int sort(char* k1, char* k2) // function for decisions move for two words
{                            //
    int x = 0;               // init var for enumeration symbol in the words
    while (tolower(k1[x]) == tolower(k2[x]) //
           && x < strlen(k2)) { // cicle for check symbols and choice next
        x++;                    // var for next symbol int the word
    }                           //
    if (x == strlen(k1))        // condition for move two words
        return 0;               // return don't move
    if (x == strlen(k2))        // condition for move two words
        return 1;               // return move
    if (tolower(k1[x]) > tolower(k2[x])) // condition for move two words
        return 1;                        // return move
    return 0;                            // return don't move
}

char computing(char array[][16],int count_words){
    int k = 0;
		/*while(k<4){
			printf(" ==>  %c",array[0][k]);
			k++;
		}
		k=0;
		while(k<3){
			printf(" -->  %c",array[2][k]);
			k++;
		}*/
    int i=0;
    int j=0;  
    char tmp[16];                            // init var for buble sort array
    while (j < (count_words)) { // cicle for retry 'cicle for enumeration words'
        i = 0;                  // var for enumeration two words
        while (i < (count_words)                 //
               && (array[i][16] != '\0')) { // cicle for enumeration words
            if (sort(array[i],              //
                     array[i + 1])) {       // condition sort two words
                strcpy(tmp, array[i]);      // first words -> tmp
                strcpy(array[i],            //
                       array[i + 1]);       // second words -> first words
                strcpy(array[i + 1], tmp);  // tmp -> second words
            }                                    //
            i++;                                 // var for next two words
        }                                        //
        j++;                      // var for retry 'cicle for enumeration words'
    }                             //
    i = 0;                        // clean var for cicle for print general array
    while (i < count_words - 1) { // cicle for print general array
        printf("%d words -> ", i + 1);
        printf("%s\n", array[i]); // print [i] word from the array
        i++;                           // var for next [i] word
    }   
}

int stringing(             //
        int count_words)   // function for enter data and check quantity symbols
{                          //
    printf("Please use a space after punctuation marks"); //
    printf("\nEnter u text ==> \n");                        //
    int i = 0;
	int n = 0;
	int t;
	char str;
	char array[count_words][16]; 
    memset(array,0,16*count_words);                        // 5 words per 16 symbols
	while (i<count_words){
		while ((str = getchar()) != ' '){
			if (str != ' '){
                		array[i][n] = str; 
                		//printf("\nn-> %d",n);  
                		//printf("\ni-> %d",i);
						if (str == '\n'){
							break;
						}
				n++;
			}	
		}
		if (str == '\n'){
			break;
		}
		i++;
		n = 0;
	}
    computing(array, count_words); // void function
    return 0;                                     
}
                           

void print() // function for print start text
{            //
    printf("\n┏━━━┳┓╋╋╋┏┓╋╋╋╋┏┓╋╋╋╋┏┓╋╋╋╋╋╋╋╋╋╋╋┏┓    "); //
    printf("\n┃┏━┓┃┃╋╋╋┃┃╋╋╋╋┃┃╋╋╋┏┛┗┓╋╋╋╋╋╋╋╋╋╋┃┃    "); //
    printf("\n┃┃╋┃┃┃┏━━┫┗━┳━━┫┗━┳━┻┓┏┫┏┓┏┳━━┳━┳━┛┣━━┓ "); //
    printf("\n┃┗━┛┃┃┃┏┓┃┏┓┃┏┓┃┏┓┃┃━┫┃┗┛┗┛┃┏┓┃┏┫┏┓┃━━┫ "); //
    printf("\n┃┏━┓┃┗┫┗┛┃┃┃┃┏┓┃┗┛┃┃━┫┗┓┏┓┏┫┗┛┃┃┃┗┛┣━━┃ "); //
    printf("\n┗┛╋┗┻━┫┏━┻┛┗┻┛┗┻━━┻━━┻━┻┛┗┛┗━━┻┛┗━━┻━━┛ "); //
    printf("\n╋╋╋╋╋╋┃┃                                "); //
    printf("\n╋╋╋╋╋╋┗┛                              \n"); //
}
