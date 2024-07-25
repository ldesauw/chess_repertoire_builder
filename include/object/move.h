#ifndef MOVE_H_
#define MOVE_H_
#include <string>

#define Move std::string
#define MovePart std::string
#define MoveSpec bool

class MoveEntity {
private:
  // The move in PGN format
  const Move _move;

  // Move descriptor interpreted from the description
  MovePart _piece;
  MovePart _source_file;
  MovePart _source_rank;
  MovePart _destination_file;
  MovePart _destination_rank;
  MovePart _promotion_piece;
  MoveSpec _isEating;
  MoveSpec _isCheck;
  MoveSpec _isMate;
  MoveSpec _isCastle;
  MoveSpec _isLongCastle;
  MoveSpec _isPromoting;

public:
  /**
   * Instantiate a MoveEntity from a move in PGN format
   *
   * @param move The description of the move in PGN format
   * @throws invalid_argument If the move is not in correct PGN format
   */
  MoveEntity(const Move &move);

  /**
   * Compare less operator
   *
   * @param a A MoveEntity to compare to
   * @return True  if this < a, False otherwise
   */
  bool operator<(const MoveEntity &a) const;
};

#endif // MOVE_H_
