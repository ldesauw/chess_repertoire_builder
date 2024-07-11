#ifndef FENENTITY_H_
#define FENENTITY_H_
#include <map>
#include <move.h>
#include <string>

#define Fen std::string

class FenEntity {
private:
  // String encoding of the FEN
  const Fen _fen;

  /**
   * Check that a Fen have the correct format
   *
   * @param fen The FEN to check
   * @throws invalid_argument If the fen is not in correct FEN format
   */
  void check_fen(const Fen &fen);

public:
  // A cache of all Fen created
  static std::map<Fen, FenEntity *> all_fens;


  /**
   * Build a Fen from its FEN string
   *
   * @param fen The FEN of the board
   * @throws invalid_argument If the fen is not in correct FEN format
   * */
  FenEntity(const Fen &fen);

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
  FenEntity *play_move(const MoveEntity &move) const;
};

#endif // FENENTITY_H_
