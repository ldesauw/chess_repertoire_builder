#include "move.h"
#include <iostream>
#include <regex>
#include <string>

  /**
   * Instantiate a MoveEntity from a move in PGN format
   *
   * @param move The description of the move in PGN format
   * @throws invalid_argument If the move is not in correct PGN format
   */
  MoveEntity::MoveEntity(const Move &move) :_move(move), _piece(""), _source_file(""), _source_rank(""), _destination_file(""),
                                             _destination_rank(""), _promotion_piece(""), _isEating(false), _isCheck(false), 
                                             _isMate(false), _isCastle(false), _isLongCastle(false), _isPromoting(false){
      
    std::regex castle_regex("^(O-O-O|O-O)$");
    std::regex move_regex("^(N|B|R|Q|K)?([a-h]?[1-8]?)x?([a-h][1-8])(=N|=B|=R|=Q)?[+#]?$");

    std::smatch match;

    if (std::regex_match(move, match, castle_regex)) {
        if (move == "O-O") {
            _isCastle = true;
        } else if (move == "O-O-O") {
            _isLongCastle = true;
        }
    } else if (std::regex_match(move, match, move_regex)) {
        /* Sub match are as following : 
        1 - (N|B|R|Q|K)? : piece 
        2 - ([a-h]?[1-8]?) : source 
        3 - x? : eating 
        4 - ([a-h][1-8]) : destination 
        5 - (=N|=B|=R|=Q) : promotion 
        6 - [+#]? : Check or Mate flag
        */ 
        
        _piece = match[1].str();
        std::string source = match[2].str();
        std::string destination = match[3].str();
        std::string promotion = match[4].str();

        if (!source.empty()) {
            if (source.length() == 2) {
                _source_file = source[0];
                _source_rank = source[1];
            } else if (isdigit(source[0])) {
                _source_rank = source[0];
            } else {
                _source_file = source[0];
            }
        }

        _destination_file = destination[0];
        _destination_rank = destination[1];

        if (!promotion.empty()) {
            _promotion_piece = promotion[1];
            _isPromoting = true;
        }

        _isEating = move.find('x') != std::string::npos;
        _isCheck = move.find('+') != std::string::npos;
        _isMate = move.find('#') != std::string::npos;
    } else {
        throw std::invalid_argument("Invalid move notation");
    }
    }

  /**
   * Compare less operator
   * The order is the lexical order on the text of the move
   *
   * @param a A MoveEntity to compare to
   * @return True  if this < a, False otherwise
   */
  bool MoveEntity::operator<(const MoveEntity &a) const {
    return this->_move < a._move;
  }