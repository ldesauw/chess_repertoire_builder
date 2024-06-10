#ifndef FENELEMENT_H_
#define FENELEMENT_H_
#include <set>
#include <string>

#define Fen std::string
#define Move std::string

class FenElement {
private:
  // String encoding of the FEN
  const Fen fen;

public:
  // A cache of all Fen created
  static std::set<Fen, FenElement> all_fens;

  /**
   * Build a Fen from its FEN string
   *
   * @param fen The FEN of the board
   * @throws invalid_argument If the fen is not in correct FEN format
   * */
  FenElement(const Fen &fen);

  /**
   * Generate the Fen of the board  obtained when playing the indicated move
   * from the current board state
   *
   * @param move The move to play
   * @return A pointer on the Fen after the move is played
   * @throws invalid_argument If the move does not respect the format
   * @throws impossible_move If the move is not possible considering the
   * current board state
   * */
  FenElement *play_move(const Move &move);
};

#endif // FENELEMENT_H_
