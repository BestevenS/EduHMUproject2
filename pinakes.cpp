#include <stdio.h>
#include <stdlib.h>


// Oti einai grammeno prin tin main einai Global
// Diladi isxuei kai uparxei gia ola ta functions

// stathera D_max gia tis diastaseis tou pinaka A
// prepei na einai idies gia na einai tetragwnikos
// gia auto exoume mia stathera
#define D_max 60

// statheres tis diastaseis tou pinaka B
#define Br 11    // rows
#define Bc 3   // columns


// tetragwnikos pinakas A D_max * D_max
int A[D_max][D_max];

// Pinakas akeraiwn 3 * 11
int B[Br][Bc];

// Diastaseis neou pinaka
int M, N;


// Kanei print ton pinaka A
void printArrayA();

// mas apothikeuei 10 tuxaious arithmous
// se 10 tuxaies theseis tou neou pinaka
// ara kai tou pinaka A 
void randomGenerator();

// kataskeui pinaka B
void createB();

void printArrayB();

void calcs();

int main(){

    // Gemizoume me 0ika ton pinaka A
    for(int i = 0; i < D_max; i++){
        for(int j = 0; j < D_max; j++){
            A[i][j] = 0;
        }
    }

    // rwtame ti megethos thelei na exei o neos pinakas
    while(1){

        // Diastasi prwti(grammi)(rows)
        printf("Dwse to plithos twn grammwn tou neou pinaka(>50): ");
        scanf("%d", &M);

        // Diastasi deuteri(stili)(columns)
        printf("Dwse to plithos twn sthlwn tou neou pinaka(>50): ");
        scanf("%d", &N);

        // elegxoume an oi diastaseis einai megalyteres apo 50
        if(M > 50 && N > 50){
            // an einai teleiwnei h epanalhpsh
            break;
        }
        else{
            // alliws emfanizoume minima lathous
            // kai epanaekteleitai h epanalhpsh
            printf("Lathos eisodos. Dwse ksana.\n");
        }

    }

    // just using the A[D_max][D_max] array as
    // A[M][N] array

    randomGenerator();

    printArrayA();

    createB();

    printArrayB();

    calcs();

    printArrayB();

    printArrayA();

}


void randomGenerator(){

    // r: row(grammi)
    // c: column(sthlh)
    // counter: posoi tuxaioi arithmoi theloume na vazei
    // i: metrhths gia tis 10 tuxaies theseis
    int r, c, counter = 10, i = 0;

    // to megalutero noumero pou mporei na parei o tuxaios arithmos
    int upper = 400;    // i megaluteri timi tis theseis tou pinaka 
    int upperR = M - 1; // i megaluteri tuxaia grammi (row)
    int upperC = N - 1; // i megaluteri tuxaia sthlh (column)

    // to mikrotero noumero pou mporei na parei o tuxaios arithmos
    int lower = 100;    // i mikroteri timi tis theseis tou pinaka
    int lowerR = 0;     // i mikroteri tuxaia grammi (row)
    int lowerC = 0;     // i mikroteri tuxaia sthlh (column)

    // bazoume 10 tuxaious arithmous se 10 tuxaies theseis
    while(i < counter){

        // tuxaia grammi
        r = (rand() % (upperR - lowerR + 1)) + lowerR;

        // tuxaia sthlh
        c = (rand() % (upperC - lowerC + 1)) + lowerC;

        // An i tuxaia thesi [r][c] einai 0, simainei pws den exei
        // akoma peiraxtei
        // To elegxw gia na min peiraxei 2 fores tin idia thesi, 
        // giati tha exoume ligoterous tuxaious arithmous
        if(A[r][c] == 0){
            // auxanoume ton metrhth kata 1 gia na stamatisei 
            // h epanalhpsh stis 10
            i++;
            // vazoume enan tuxaio arithmo stin thesi [r][c]
            A[r][c] = (rand() % (upper - lower + 1)) + lower;
        }

    }

}

void printArrayA(){
    
    printf("\n");

    for(int i = 0; i < N; i++){
        if(i == 0){
            printf("%6d", i);
        }

        else
            printf("%3d", i);
    }
    
    printf("\n");
    
    for(int i = 0; i < M; i++){
        printf("%3d", i);
        for(int j = 0; j < N; j++){
            // emfanizoume tin timi tou kathe stoixeiou tou pinaka
            // to \t prostheti ena tab(keno) meta apo kathe stoixeio
            printf("%3d", A[i][j]);
        }
        // meta apo kathe grammi(row) kanoume allagi grammis gia na
        // einai pio euanagnwsto to apotelesma
        printf("\n");
    }
}

void createB(){

    // arxikopoioume tin prwti grammi B[0] me ton arithmo twn rows
    // tou pinaka A kai tin prwti sthlh B[0][0] me ton arithmo twn
    // columns tou pinaka A kai to 0 apla mpainei sto telos
    B[0][0] = M;
    B[0][1] = N;
    B[0][2] = 0;

    // ftiaxnoume 2 metrites gia row kai column tou neou pinaka B
    // to row den xekinaei apo to 0, giati exei arxikopoihthei parapanw
    // to by xekinaei kanonika po to 0
    int bx = 1, by = 0;

    printf("\n\n");
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            printf("%3d", A[i][j]);
            if(A[i][j] != 0){

                // vazoume ti grammi pou brisketai to stixeio
                B[bx][by] = i;
                
                // auksanoume kata 1 ton metrhth sthlhs
                by++;

                // vazoume tin sthlh pou brisketai to stixeio
                B[bx][by] = j;
                
                // auksanoume kata 1 ton metrhth sthlhs
                by++;

                // vazoume to tuxaio arithmo pou brisketai stin thesi
                B[bx][by] = A[i][j];
                
                // auksanoume kata 1 ton metrhth grammis gia na 
                // apothikeusoume to epomeno stixeio stin epomeni grammi
                bx++;

                // afou teleiwsame me auti tin grammi, xeroume oti sthn epomeni
                // tha prepei na xekinisoume pali apo tin 0 sthlh
                // opote metavaloume tin timi tou by se 0
                by = 0;

                // by = 0; line destroying the program, fuck me 
            }
        }
        // meta apo kathe grammi(row) kanoume allagi grammis gia na
        // einai pio euanagnwsto to apotelesma
        printf("\n");
    }

}

void printArrayB(){
    printf("\n\nmy array B\n\n");
    for(int i = 0; i < Br; i++){
        for(int j = 0; j < Bc; j++){
            // emfanizoume tin timi tou kathe stoixeiou tou pinaka
            // to \t prosthetei ena tab(keno) meta apo kathe stoixeio
            printf("%5d", B[i][j]);
        }
        // meta apo kathe grammi(row) kanoume allagi grammis gia na
        // einai pio euanagnwsto to apotelesma
        printf("\n");
    }
}

void calcs(){
    int sum = 0;
    
    for(int i = 1; i < Br; i++){
        sum = B[i][0] + B[i][1];

        if(sum % 2 == 0)
            // Metafora twn newn timwn ston A
            A[B[i][0]][B[i][1]] = B[i][2] = 2 * B[i][2];

        else 
            // Metafora twn newn timwn ston A
            A[B[i][0]][B[i][1]] = B[i][2] = 3 * B[i][2];
    }
    
}
