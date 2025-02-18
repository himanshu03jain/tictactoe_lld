#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
#include "player.h"
#include "peiceO.h"
#include "peiceX.h"
#include "playingppiece.h"
#include "board.h"
#include <deque>

class tictactoegame{
public:
    std::deque<player*> dq;
    board gameboard;

    tictactoegame(): gameboard(3){}

    void initialize(){
        dq.clear();
        pieceX* px = new pieceX();
        player* p1 = new player("player1", px);

        pieceo* po = new pieceo();
        player* p2 = new player("player2", po);

        dq.push_back(p1);
        dq.push_back(p2);

        gameboard = board(3);
    }

    std::string startgame(){
        bool nowinner = true;
        while(nowinner)
        {
            player* temp = dq.front();
            dq.pop_front();
            gameboard.printBoard();

            std::vector<std::pair<int, int>> free = gameboard.getFreeCells();
            if(free.empty()){
                nowinner = false;
                continue;
            }

            std::cout<<"Player "<<temp->getname()<<" Enter row and col : ";
            int row, col;
            std::cin>>row>>col;

            bool addpiece = gameboard.addPiece(row, col, temp->playpc);
            if(!addpiece){
                std::cout<<"Incorrect position try again \n";
                dq.push_front(temp);
                continue;
            }
            dq.push_back(temp);

            bool winner = isThereWinner(row, col, temp->playpc->piecetype);
            if(winner){
                gameboard.printBoard();
                return temp->getname();
            }
        }
        gameboard.printBoard();
        return "tie";
    }

    bool isThereWinner(int row, int col, pieces peice){
        bool rowmatch = true;
        bool colmatch = true;
        bool diagnolmatch = true;
        bool antidiagonalmatch = true;

        for(int i=0;i<gameboard.size;i++){
            if(gameboard.vec[row][i] == nullptr || gameboard.vec[row][i]->piecetype != peice){
                rowmatch = false;
            }
        }

        for(int i=0;i<gameboard.size;i++){
            if(gameboard.vec[i][col] == nullptr || gameboard.vec[i][col]->piecetype != peice){
                colmatch = false;
            }
        }

        for(int i=0, j=0; i<gameboard.size;i++, j++){
            if(gameboard.vec[i][j]== nullptr || gameboard.vec[i][j]->piecetype != peice){
                diagnolmatch = false;
            }
        }

        for(int i=0, j=gameboard.size-1;i<gameboard.size;i++, j--){
            if(gameboard.vec[i][j]== nullptr || gameboard.vec[i][j]->piecetype != peice){
                antidiagonalmatch = false;
            }
        }

        return rowmatch || colmatch || diagnolmatch || antidiagonalmatch;   

    }
};

#endif