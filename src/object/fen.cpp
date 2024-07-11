#include "fen.h"
#include "move.h"

/**
 * Check that a Fen have the correct format
 *
 * @param fen The FEN to check
 * @throws invalid_argument If the fen is not in correct FEN format
 * @TODO
 */
void check_fen(const Fen &fen);

/**
 * Build a Fen from its FEN string
 *
 * @param fen The FEN of the board
 * @throws invalid_argument If the fen is not in correct FEN format
 * */
FenEntity::FenEntity(const Fen& fen) {
  FenEntity::check_fen(fen);
  this->_fen = fen;
    all_fens.insert({fen, this});
}


/**
 * Generate the Fen of the board  obtained when playing the indicated move
 * from the current board state
 *
 * @param move The move to play
 * @return A pointer on the Fen after the move is played
 * @throws invalid_argument If the move does not respect the format
 * @throws impossible_move If the move is not possible considering the
 * current board state
 * @TODO
 * */
FenEntity *FenEntity::play_move(const MoveEntity &move) const;
