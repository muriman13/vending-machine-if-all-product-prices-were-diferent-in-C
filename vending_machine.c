#include <stdio.h>
#include <stdlib.h>
#define products 3
    struct prod {      // struc e globalen poneje go polzvam v funcite za sortirane
        //vid 1- napitka vid 2-ne-napitka
        char name [36];
        int type;
        int weight ;
        int price;
        int count;
    };
    void sortbytype(int row,int col,int product, struct prod array[row][col][product]);
    void sortbyweightother(int row,int col,int product, struct prod array[row][col][product]);

int main()
{
    int col=2,row=2;
     time_t t;
    struct prod array[row][col][products];

//zadava random teglo do 500 na vseki product
srand((unsigned) time(&t));
for(int r=0;r<row;r++){
    for(int c=0;c<col;c++){
        for(int i=0;i<products;i++){
            scanf("%d", &array[r][c][i].type);
            array[r][c][i].weight=rand() %499;
        }
    }
}

//dvete sort funkcii
sortbytype(row,col,products,array);
sortbyweightother(row,col,products,array);


//printira sortiranata mashina
for(int r=0;r<row;r++){

    for(int c=0;c<col;c++){

        for(int i=0;i<products;i++){
            printf("%d   %d\n", array[r][c][i].type,array[r][c][i].weight);
        }
    }
}

}

void sortbytype(int row,int col,int product, struct prod array[row][col][product]){

struct prod temp;
for(int r=0;r<row;r++){
    for(int c=0;c<col;c++){
        for(int i=0;i<product;i++){
           for(int rr=0;rr<row;rr++){
                for(int cc=0;cc<col;cc++){
                    for(int ii=0;ii<product;ii++){
                      if (array[r][c][i].type < array[rr][cc][ii].type){
                                temp = array[r][c][i];
                                array[r][c][i] = array[rr][cc][ii];
                                array[rr][cc][ii] = temp;
                                }
                    }
                }

            }
        }
    }

}
}


void sortbyweightother(int row,int col,int product, struct prod array[row][col][product]){
     struct prod temp2;
for(int r=0;r<row;r++){
    for(int c=0;c<col;c++){
        for(int i=0;i<products;i++){
           for(int rr=0;rr<row;rr++){
                for(int cc=0;cc<col;cc++){
                    for(int ii=0;ii<products;ii++){
                      if (array[rr][cc][ii].weight < array[r][c][i].weight && array[r][c][i].type==2 && array[rr][cc][ii].type ==2) {
                                temp2 = array[r][c][i];
                                array[r][c][i] = array[rr][cc][ii];
                                array[rr][cc][ii] = temp2;
                                }
                    }
                }

            }
        }
    }
}

}












