#ifndef MOVE_H_
#define MOVE_H_

#define Move std::string
#define MovePart std::string
#define MoveSpec bool

class MoveEntity {
private:
    const Move      _move;
    const MovePart  _piece;
    const MovePart  _source_file;
    const MovePart  _source_rank;
    const MovePart  _destination_file;
    const MovePart  _destination_rank;
    const MovePart  _promotion_piece;
    const MoveSpec  _isEating;
    const MoveSpec  _isCheck;
    const MoveSpec  _isMate;
    const MoveSpec  _isCastle;
    const MoveSpec  _isLongCastle;
    const MoveSpec  _isPromoting;

public:
    MoveEntity(const Move &move);
}

#endif // MOVE_H_
