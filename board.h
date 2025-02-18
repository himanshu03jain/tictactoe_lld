#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <stdio.h>
#include "playingppiece.h"
#include <bits/stdc++.h>
#include <vector>

class board{
public:
    int size;
    std::vector<std::vector<playingpiece*>> vec;

    board(int size){
        this->size = size;
        vec.resize(size, std::vector<playingpiece*>(size, nullptr));
    }

    bool addPiece(int row, int col, playingpiece* piece){
        if(vec[row][col] != nullptr){
            return false;
        }
        vec[row][col] = piece;
        return true;
    }

    std::vector<std::pair<int, int>> getFreeCells(){
        std::vector<std::pair<int, int>> freevec;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(vec[i][j] == nullptr){
                    std::pair<int, int> p = {i, j};
                    freevec.push_back(p);
                }
            }
        }
        return freevec;
    }

    void printBoard(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(vec[i][j] != nullptr){
                    std::cout<<vec[i][j]->piecetype<<"   ";
                }
                else{
                    std::cout<<"    ";
                }
                std::cout<<" | ";
            }
            std::cout<<"\n";
        }
    }
};

#endif