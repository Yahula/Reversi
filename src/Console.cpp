/*
 * Console.cpp
 */

#include "../include/Console.h"

Console::Console(int r, int c) : Board(r,c){
}

Console::~Console(){

}

void Console::displayBoard() {
    char row = '1';
    char col = '1';

    for(int i=0; i<((r*2)+4); i++){
        if (i==(r*2)+2){
            break;
        }
        for(int j=0; j<(c*4)+2; j++){
            if(j==(c*4)+2){
                break;
            }
            if (i%2==0){
                if (j%4 == 0||j%4==2){
                    if(j==0 && i>0){
                        cout<< row;
                        row++;
                    }
                    else{
                        cout<<' ';
                    }
                }
                if (j%4 == 1){
                    cout<<'|';
                }
                if(j%4 == 3) {
                    if (i==0){
                        cout<<col;
                        col++;
                    }
                    else{
                        if (board[(i/2)-1][((j+1)/4)-1]==0){
                            cout<<' ';
                        }
                        if (board[(i/2)-1][((j+1)/4)-1]==1){//white
                            cout<<'O';
                        }
                        if (board[(i/2)-1][((j+1)/4)-1]==-1){//black
                            cout<<'X';
                        }
                    }
                }
            }
            else if (i%2 == 1){
                cout<<'-';
            }
        }
        cout<<endl;
    }
}
