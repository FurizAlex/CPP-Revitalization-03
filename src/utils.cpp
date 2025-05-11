#include "../includes/blackjack.hpp"

int drawCard()
{
	int card = rand() % 13 + 1;
	if (card >= 11) return 10;
	if (card == 1) return 11;
	return card;
}

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

std::string ctos(int card)
{
	if (card == 11) return "Ace";
	if (card == 10)
	{
		static const std::string faces[] = {"jack", "queen", "king"};
		return faces[rand() % 4];
	}
	return std::to_string(card);
}

int	calculateTotal(const std::vector<int> &hand)
{
	int total = 0;
	int aceCount = 0;

	for (int card : hand)
	{
		total += card;
		if (card == 11)
			aceCount++;
	}
	while (total > 21 && aceCount--) total -= 10;

	return total;
}

void print(const std::vector<int> &hand, bool hideFirst)
{
	for (size_t i = 0; i < hand.size(); ++i)
	{
		if (i == 0 && hideFirst)
			std::cout << "[Hidden] ";
		else
			std::cout << ctos(hand[i]) << " ";
	}
	std::cout << '\n';
}