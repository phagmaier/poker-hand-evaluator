#include "Card.h"

const unsigned int Card::primes[13] = {
  2,3,5,7,11,
  13,17,19,23,
  29,31,37,41
};

const std::string Card::card_array[52] = {
    "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD", "AD",
    "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH", "AH",
    "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS", "AS",
    "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC", "AC"
};

Card::Card(unsigned int val, unsigned int suit) : 
  val(val), suit(1<<suit), prime(primes[val]),
  card_str(card_array[(suit*13) + val])
{}

