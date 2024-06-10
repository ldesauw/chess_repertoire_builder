#ifndef BOARDSTATE_H_
#define BOARDSTATE_H_

#include "fen.h"
#include <map>
#include <string>

#define Move std::string

class BoardState {
private:
  // The state of the board in FEN format
  const FenElement *fen;

  // The list of next move and a pointer to the associated BoardState
  std::map<std::string, BoardState *> next_move;

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
   * Initialize a BoardState with the state of the board (FEN format)
   *
   * @param fen The state of the board in FEN format
   * @param evaluation The evaluation of advantage for the white player
   * @throws invalid_argument If the fen does not respect the FEN format or if
   * evaluation does not respect the range [0,100]
   */
  BoardState(const FenElement *fen, const float &evaluation);

  /**
   * Initialize a BoardState with the state of the board (FEN format)
   *
   * @param fen Le state of the board in FEN format
   * @throws invalid_argument If the fen does not respect the FEN format
   */
  BoardState(const Fen *fen);

  /**
   * Initialize a BoardState with the state of the board (FEN format)
   *
   * @param fen The state of the board in FEN format
   * @param evaluation The evaluation of advantage for the white player
   * @throws invalid_argument If the fen does not respect the FEN format or if
   * evaluation does not respect the range [0,100]
   */
  BoardState(const Fen *fen, const float &evaluation);

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

  /**
   * Set the evaluation of advantage of the white player
   * @param evaluation The evaluation of advantage for the white player
   * @throws invalid_argument If evaluation does not respect the range [0,100]
   */
  void set_evaluation(const float &evaluation);
};

#endif // BOARDSTATE_H_
