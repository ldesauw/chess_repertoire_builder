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
  const MovePart _piece;
  const MovePart _source_file;
  const MovePart _source_rank;
  const MovePart _destination_file;
  const MovePart _destination_rank;
  const MovePart _promotion_piece;
  const MoveSpec _isEating;
  const MoveSpec _isCheck;
  const MoveSpec _isMate;
  const MoveSpec _isCastle;
  const MoveSpec _isLongCastle;
  const MoveSpec _isPromoting;

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
  bool operator<(const MoveEntity &a);
};

#endif // MOVE_H_
