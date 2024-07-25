#include "fen.h"
#include "move.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>



std::map<Fen, FenEntity *> FenEntity::all_fens;

/**
 * Check that a Fen have the correct format
 *
 * @param fen The FEN to check
 * @throws invalid_argument If the fen is not in correct FEN format
 * @TODO : check the pieces' placement 
 */
void FenEntity::check_fen(const Fen &fen){
 // Split the FEN string by spaces
    std::istringstream iss(fen);
    std::vector<std::string> parts;
    std::string part;
    while (iss >> part) {
        parts.push_back(part);
    }

    // There must be exactly 6 parts
    if (parts.size() != 6) {
        throw std::invalid_argument( "FEN does not have the correct structure" );
    }

    // Validate piece placement data
    std::regex piece_placement_regex("([rnbqkpRNBQKP1-8]+/){7}[rnbqkpRNBQKP1-8]+");
    if (!std::regex_match(parts[0], piece_placement_regex)) {
        throw std::invalid_argument( "FEN's piece placement does not match the regexp" );
    }

    // Validate row length (must sum up to 8)
    std::istringstream row_iss(parts[0]);
    std::string row;
    while (std::getline(row_iss, row, '/')) {
        int row_length = 0;
        for (char ch : row) {
            if (isdigit(ch)) {
                row_length += ch - '0';
            } else {
                row_length++;
            }
        }
        if (row_length != 8) {
            throw std::invalid_argument( "FEN's piece placementis incorrect" );

        }
    }

    // Validate active color (must be 'w' or 'b')
    if (parts[1] != "w" && parts[1] != "b") {
        throw std::invalid_argument( "FEN's active color is incorrect" );

    }

    // Validate castling availability (must be a combination of 'K', 'Q', 'k', 'q' or '-')
    std::regex castling_regex("[-KQkq]*");
    if (!std::regex_match(parts[2], castling_regex)) {
        throw std::invalid_argument( "FEN's castling is incorrect" );

    }

    // Validate en passant target square (must be a valid square or '-')
    std::regex en_passant_regex("^(-|[a-h][36])$");
    if (!std::regex_match(parts[3], en_passant_regex)) {
        throw std::invalid_argument( "FEN's en passant is incorrect" );
    }

    // Validate halfmove clock (must be a non-negative integer)
    std::regex halfmove_clock_regex("\\d+");
    if (!std::regex_match(parts[4], halfmove_clock_regex)) {
        throw std::invalid_argument( "FEN's halfmove clock is incorrect" );
    }

    // Validate fullmove number (must be a positive integer)
    std::regex fullmove_number_regex("[1-9]\\d*");
    if (!std::regex_match(parts[5], fullmove_number_regex)) {
      throw std::invalid_argument( "FEN's fullmove number is incorrect" );
    }

    return;
  }

/**
 * Build a Fen from its FEN string
 *
 * @param fen The FEN of the board
 * @throws invalid_argument If the fen is not in correct FEN format
 * */
FenEntity::FenEntity(const Fen& fen) : _fen(fen){
  FenEntity::check_fen(fen);
  FenEntity::all_fens.insert({fen, this});
}


/**
 * Generate the Fen of the board  obtained when playing the indicated move
 * from the current board state
 *
 * @param move The move to play
 * @return A pointer on the Fen after the move is played
 * @throws invalid_argument If the move does not respect the format
 * @throws impossible_move If the move is not possible considering the
 * current board state
 * @TODO
 * */
FenEntity *FenEntity::play_move(const MoveEntity &move) const{
  // TODO 
  return nullptr; 
}
