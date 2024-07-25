#include "move.h"

  /**
   * Instantiate a MoveEntity from a move in PGN format
   *
   * @param move The description of the move in PGN format
   * @throws invalid_argument If the move is not in correct PGN format
   */
  MoveEntity::MoveEntity(const Move &move) :_move(move), _piece(""), _source_file(""), _source_rank(""), _destination_file(""),
                                             _destination_rank(""), _promotion_piece(""), _isEating(false), _isCheck(false), 
                                             _isMate(false), _isCastle(false), _isLongCastle(false), _isPromoting(false){
    // TODO 
    }

  /**
   * Compare less operator
   *
   * @param a A MoveEntity to compare to
   * @return True  if this < a, False otherwise
   */
  bool MoveEntity::operator<(const MoveEntity &a) const {
    // TODO
    return false; 
  }