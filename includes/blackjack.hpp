#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

/*		Utils		*/

int			drawCard();
int			calculateTotal(const std::vector<int> &hand);
void 		print(const std::vector<int> &hand, bool hideFirst);
void 		clearScreen();
std::string ctos(int card);

std::string getUserChoice();
void 		playerTurn(std::vector<int> &playerHand);
void 		dealersTurn(std::vector<int> &dealersHand);
void 		determine(const std::vector<int> &player, const std::vector<int> &dealer);

#endif