#include <stdio.h>
//Field goal (FG) worth 3 points
//Touchdown (TD) worth 6 points
// Safety worth 2 points
//Touchdown (TD) + 2-point conversion worth 8 points
//Touchdown (TD) + 1-point field goal worth 7 points

void getcombinations(int score) {
    int  numTD, numTDFG, numTDTD,  numTDthree,  safety;
    for (numTD = 0; score >= (8 * numTD); numTD++) {
        for (numTDFG = 0; score >= (8 * numTD+ 7 * numTDFG); numTDFG++) {
            for (numTDTD = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD); numTDTD++) {
                for (numTDthree = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD + 3 * numTDthree); numTDthree++) {
                    for (safety = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD+ 3 * numTDthree + 2 * safety); safety++) {
                        if (score == (8 * numTD + 7 * numTDFG + 6 * numTDTD+ 3 * numTDthree + 2 * safety)) {
                            printf("%d TD +2pt, %d TD + FG,%d TD + %d 3pt FG , %d Safety\n", numTD, numTDFG, numTDTD, numTDthree, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
   int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program ended goodbye.\n");
            break;
        } else {
            printf("Possible combinations of scoring plays:\n");
            getcombinations(score);
        }
    }
     

    return 0;
}