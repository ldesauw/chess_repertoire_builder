#include "boardState.h"
#include "fen.h"
#include <stdexcept>

/**
 * Initialize a BoardState with the state of the board (FEN format)
 *
 * @param fen Le state of the board in FEN format
 * @throws invalid_argument If the fen does not respect the FEN format
 */
BoardState::BoardState(const FenElement *fen) {
  if (fen == nullptr)
    throw new std::invalid_argument("Received wrongful pointer to FenElement");

  this->fen = fen;
}

/**
 * Initialize a BoardState with the state of the board (FEN format)
 *
 * @param fen Le state of the board in FEN format
 * @param evaluation The evaluation of advantage for the white player
 * @throws invalid_argument If the fen does not respect the FEN format or if
 * evaluation does not respect the range [0,100]
 */
BoardState::BoardState(const FenElement *fen, const float &evaluation) {
  if (fen == nullptr)
    throw std::invalid_argument("Received wrongful pointer to FenElement");

  if (evaluation < 0 || evaluation > 100) {
    throw std::invalid_argument(
        "Received wrongful evaluation : must be contained in [0,100]");
  }

  this->fen = fen;
  this->evaluation = evaluation;
}

/**
 * Initialize a BoardState with the state of the board (FEN format)
 *
 * @param fen Le state of the board in FEN format
 * @throws invalid_argument If the fen does not respect the FEN format
 */
BoardState::BoardState(const Fen *fen) { this->fen = FenElementBuilder(fen); }

/**
 * Initialize a BoardState with the state of the board (FEN format)
 *
 * @param fen The state of the board in FEN format
 * @param evaluation The evaluation of advantage for the white player
 * @throws invalid_argument If the fen does not respect the FEN format or if
 * evaluation does not respect the range [0,100]
 */
BoardState::BoardState(const Fen *fen, const float &evaluation) {

  if (evaluation < 0 || evaluation > 100) {
    throw std::invalid_argument(
        "Received wrongful evaluation : must be contained in [0,100]");
  }

  this->fen = FenElementBuilder(fen);
  this->evaluation = evaluation;
}
/**
 *  Add a move to the set of next move
 *
 *  @param move Move to add on the current Board State.
 *  @return 0 if the move has been added correctly, -1 otherwise
 *  @throws invalid_argument If the move does not respect the format
 *  @throws impossible_move If the move is not possible considering the
 * current board state
 * */
int BoardState::add_move(const Move &move) {
  // TODO check Move format
  const FenElement *fenE = this->fen->play_move(move);
  this->next_move.insert({move, new BoardState(fenE)});
  return 0;
}

/**
 *  Delete a move to the set of next move.
 *  If there is no move to delete, the fuction return a success
 *
 *  @param move Move to delete on the current Board State.
 *  @return 0 if the move has been deleted correctly, -1 otherwise
 *  @throws invalid_argument If the move does not respect the format
 * */
int BoardState::del_move(const Move &move) {
  // TODO Check Move format
  this->next_move.erase(move);
  return 0;
}

/**
 * Set the evaluation of advantage of the white player
 * @param evaluation The evaluation of advantage for the white player
 * @throws invalid_argument If evaluation does not respect the range [0,100]
 */
void BoardState::set_evaluation(const float &evaluation) {
  this->evaluation = evaluation;
}
