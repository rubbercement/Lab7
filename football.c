#include <stdio.h>
#include <string.h>

int main()
{
    int acceptInput = 1;
    int totalPoints = 0;
    int checkVal = 0;
    int TD = 6;
    int FG = 3;
    int SFTY = 2;
    int TD2PC = 8;
    int TD1FG = 7;

    while (acceptInput > 0) 
    {
        printf("ENTER 0 OR 1 TO STOP\n");
        printf("Enter the NFL score: ");
        checkVal = scanf("%d", &totalPoints);
        if (checkVal == 0)
        {
            printf("Invalid Entry");
            printf("%d", totalPoints);
        }
        else if (totalPoints < 2)
        {
            acceptInput = 0;
        }
        else
        {
            printf("Possible combinations of scoring plays if a team’s score is %d: \n", totalPoints);
            for (int td2pcs = 0; td2pcs <= totalPoints; td2pcs++) {
                for (int td1fgs = 0; td1fgs <= totalPoints; td1fgs++) {
                    for (int tds = 0; tds <= totalPoints; tds++) {
                        for (int fgs = 0; fgs <= totalPoints; fgs++) {
                            for (int sftys = 0; sftys <= totalPoints; sftys++) {
                                if (((sftys * SFTY) + (fgs * FG) + (tds * TD) + (td1fgs * TD1FG) + (td2pcs * TD2PC)) == totalPoints) {
                                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pcs, td1fgs, tds, fgs, sftys);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}