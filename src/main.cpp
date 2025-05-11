#include "../includes/blackjack.hpp"

std::string getUserChoice()
{
	std::string choice;
	std::cout << "Hit[h] or Stand[s]?" << '\n' << '\n';
	std::cin >> choice;
	std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	return choice;
}

void playerTurn(std::vector<int> &playerHand)
{
	int total;
	std::string choice;
	while (true)
	{
		clearScreen();
		total = calculateTotal(playerHand);
		std::cout << "\nYour cards: ";
		print(playerHand, false);
		std::cout << "Total: " << total << "\n";

		if (total > 21)
		{
			std::cout << "It's a bust! You Lose." << '\n';
			exit(0);
		}
		choice = getUserChoice();
		if (choice == "stand" || choice == "s") break;
		else if (choice == "hit" || choice == "h")
		{
			playerHand.push_back(drawCard());
			std::cout << "You drew: " << playerHand.back() << '\n';
		}
		else
			std::cout << "Invalid Input. Type 'hit[h]' or 'stand[s]'." << '\n';
	}
}

void dealersTurn(std::vector<int> &dealersHand)
{
	std::cout << "\nDealer cards: ";
	print(dealersHand, false);

	while (calculateTotal(dealersHand) < 17)
	{
		int card = drawCard();
		dealersHand.push_back(card);
		std::cout << "Dealer draws: " << ctos(card)
		          << " (Total: " << calculateTotal(dealersHand) << ")\n";
	}
	std::cout << "Dealer's final hand: ";
	print(dealersHand, false);
	std::cout << "Total: " << calculateTotal(dealersHand) << '\n';
}

void determine(const std::vector<int> &player, const std::vector<int> &dealer)
{
	int playerTotal = calculateTotal(player);
	int dealerTotal = calculateTotal(dealer);
	
	std::cout << "\nFinals Results:\n";
	std::cout << "You: " << playerTotal << " | Dealer: " << dealerTotal << '\n';
	if (dealerTotal > 21 || playerTotal > dealerTotal)
		std::cout << "You Win!" << '\n';
	else if (dealerTotal > playerTotal)
		std::cout << "Dealer Wins." << '\n';
	else
		std::cout << "It's a tie!" << '\n';
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> playerHand = { drawCard(), drawCard() };
    std::vector<int> dealersHand = { drawCard(), drawCard() };

    std::cout << "Welcome to Blackjack!" << '\n';
    std::cout << "Dealer shows: ";
    print(dealersHand, true);

    playerTurn(playerHand);
    dealersTurn(dealersHand);
    determine(playerHand, dealersHand);

    return 0;
}