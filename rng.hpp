#pragma once

#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
#include "hashing.hpp"

using std::stringstream;
using std::string;

unsigned int seed = (std::chrono::system_clock::now().time_since_epoch().count());
std::mt19937 mt(seed);

int getRandomInteger(int min, int max) {
  std::uniform_int_distribution<int> uid(min, max);

  return uid(mt);
}

void generateTextFile(string newFileName);

void generateStrings();