#include "boardState.h"
#include "fen.h"
#include <iostream>
int main() {
  Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  FenEntity* fenE = new FenEntity(fen);
  BoardState bState = BoardState(fenE);
  return 0;
}
