#ifndef _EVALUATE_H
#define _EVALUATE_H

#include "types.h"

// PROTOTYPES
int evaluate_board(Board * board);

void evaluatePawns(int* mid, int* end, Board* board);
void evaluateKnights(int* mid, int*end, Board* board);
void evaluateBishops(int* mid, int* end, Board* board);
void evaluateRooks(int* mid, int* end, Board* board);
void evaluateKings(int* mid, int* end, Board* board);

// PIECE VALUES
#define PawnValue   (  100)
#define KnightValue (  310)
#define BishopValue (  310)
#define RookValue   (  500)
#define QueenValue  ( 1000)
#define KingValue   (  100)

// KING EVALUATION TERMS
#define KING_HAS_CASTLED    (10)
#define KING_CAN_CASTLE     ( 5)

// ROOK EVALUATION TERMS
#define ROOK_OPEN_FILE_MID   (12)
#define ROOK_OPEN_FILE_END   ( 8)
#define ROOK_SEMI_FILE_MID   ( 6)
#define ROOK_SEMI_FILE_END   ( 6)
#define ROOK_ON_7TH_MID      ( 6)
#define ROOK_ON_7TH_END      ( 2)

// BISHOP EVALUATION TERMS
#define BISHOP_PAIR_MID      ( 36)
#define BISHOP_PAIR_END      ( 46)
#define BISHOP_HAS_WINGS_MID (  9)
#define BISHOP_HAS_WINGS_END ( 36)

static int BishopOutpost[2][64] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 1, 2, 4, 4, 2, 1, 0, 
      0, 2, 4, 8, 8, 4, 2, 0, 
      0, 1, 6, 9, 9, 6, 1, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, },
      
    { 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 1, 6, 9, 9, 6, 1, 0, 
      0, 2, 4, 8, 8, 4, 2, 0, 
      0, 1, 2, 4, 4, 2, 1, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, }
};

// KNIGHT EVALUATION TERMS
static int KnightOutpost[2][64] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 2, 4, 6, 6, 4, 2, 0, 
      0, 3, 6, 8, 8, 6, 3, 0, 
      0, 4, 8,10,10, 8, 4, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, },
      
    { 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 4, 8,10,10, 8, 4, 0, 
      0, 3, 6, 8, 8, 6, 3, 0, 
      0, 2, 4, 6, 6, 4, 2, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, }
};

// PAWN EVALUATION TERMS
static int PawnStackedMid[8]  = { 3,  5,  7,  8,  8,  7,  5,  3};
static int PawnStackedEnd[8]  = {10, 10, 14, 16, 16, 14, 10, 10};

static int PawnIsolatedMid[8] = { 7, 10, 13, 13, 13, 13, 10,  7};
static int PawnIsolatedEnd[8] = { 5,  7,  9,  9,  9,  9,  7,  5};

static int PawnPassedMid[8]   = { 0, 10, 10, 25, 50,  85, 130, 0};
static int PawnPassedEnd[8]   = { 0, 15, 15, 35, 70, 130, 190, 0};

// OTHER TERMS
#define PSQT_MULTIPLIER (1)
static int PieceValues[8] = {PawnValue, KnightValue, BishopValue, RookValue, QueenValue, KingValue, 0, 0};

#endif