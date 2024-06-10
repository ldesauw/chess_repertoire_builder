#ifndef BOARDSTATE_H_
#define BOARDSTATE_H_

#include "fen.h"
#include <set>
#include <string>

#define Move std::string

class BoardState {
private:
  // The state of the board in FEN format
  const FenElement *fen;

  // The list of next move and a pointer to the associated BoardState
  std::set<std::string, BoardState *> next_move;

  // The evaluation of the current board state in advantage for the white player
  float evaluation;

public:
  /**
   * Initialize a BoardState with the state of the board (FEN format)
   *
   * @param fen Le state of the board in FEN format
   * @throws invalid_argument If the fen does not respect the FEN format
   */
  BoardState(const FenElement *fen);

  /**
   *  Add a move to the set of next move
   *
   *  @param move Move to add on the current Board State.
   *  @return 0 if the move has been added correctly, -1 otherwise
   *  @throws invalid_argument If the move does not respect the format
   *  @throws impossible_move If the move is not possible considering the
   * current board state
   * */
  int add_move(const Move &move);

  /**
   *  Delete a move to the set of next move.
   *  If there is no move to delete, the fuction return a success
   *
   *  @param move Move to delete on the current Board State.
   *  @return 0 if the move has been deleted correctly, -1 otherwise
   *  @throws invalid_argument If the move does not respect the format
   * */
  int del_move(const Move &move);
};

#endif // BOARDSTATE_H_
