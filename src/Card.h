#pragma once
#include <string>
#include <iostream>
#include <unordered_map>

struct Card{
  static const unsigned int primes[13];   
  static const std::string card_array[52];   
  Card(unsigned int val, unsigned int suit);
  const unsigned int val;
  const unsigned int suit;
  const unsigned int prime;
  std::string card_str;
  inline void print_card(){std::cout<<card_str;}
};
