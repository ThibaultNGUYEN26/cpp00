/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookMain.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:19:09 by thibault          #+#    #+#             */
/*   Updated: 2023/11/16 18:56:18 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhonebookMain.hpp"

std::string ft_toupper(std::string str) {
	std::string temp(str.length(), ' ');

	for (size_t i = 0; i < str.length(); i++)
		temp[i] = toupper(str[i]);
	return temp;
}

std::string ft_capitalize(std::string str) {
	std::string temp(str.length(), ' ');

	for (size_t i = 0; i < str.length(); i++)
		temp[i] = tolower(str[i]);
	temp[0] = toupper(str[0]);
	return temp;
}

int main()
{
	Phonebook phone_book;
	std::string input;
	
	std::cout << std::endl << WHITE "                           ╭─────────────────────────────╮" << std::endl;
	std::cout << "                ╭──────────│ " CYAN "Welcome to your Phonebook !" WHITE " │──────────╮" << std::endl;
	std::cout << "                │          ╰─────────────────────────────╯          │" << std::endl;
	std::cout << "                │       " BLUE "ADD" WHITE "       |     " BLUE "SEARCH" WHITE "     |      " BLUE "EXIT" WHITE "      │" << std::endl;
	std::cout << "                │                                                   │" EOC << std::endl;

	int it = 0;
	while (true) {
		std::cout << MAGENTA "[INPUT] : " WHITE;
		std::getline(std::cin, input);
		
		if (ft_toupper(input) == "ADD") {
			std::string first, name, nickname, number, secret;
			std::cout << MAGENTA "[INPUT] " YELLOW "First name   : " WHITE;
			std::cin >> first;
			std::cout << MAGENTA "[INPUT] " YELLOW "Last name    : " WHITE;
			std::cin >> name;
			std::cout << MAGENTA "[INPUT] " YELLOW "Nickname     : " WHITE;
			std::cin >> nickname;
			std::cout << MAGENTA "[INPUT] " YELLOW "Phone number : " WHITE;
			std::cin >> number;
			std::getline(std::cin, secret);
			std::cout << MAGENTA "[INPUT] " YELLOW "Secret       : " WHITE;
			std::getline(std::cin >> std::ws, secret);
			
			phone_book.add_contact(first, name, nickname, number, secret);

			const Contact& last_contact = phone_book.get_last_contact();
			std::string first_name = last_contact.get_first_name();
			std::string last_name = last_contact.get_last_name();

			if (it < 8) {
				for (int i = 0; i < 7; i++) {
					std::cout << "\033[1A\033[K";
				}
			} else {
					for (int i = 0; i < 6; i++) {
					std::cout << "\033[1A\033[K";
				}
			}
			it++;
			
			int spaces = (51 - (first_name.length() + last_name.length() + 1)) / 2;
			std::string spaces_string;
			for (int i = 0; i < spaces; i++) {
				spaces_string += " ";
			}
			
			std::cout << "                │" << spaces_string << ft_capitalize(first_name) << " " << ft_capitalize(last_name) << spaces_string;
			if ((first_name.length() + last_name.length() + 1) % 2 == 0) {
				std::cout << " │"<<std::endl;
			} else {
				std::cout << "│"<<std::endl;
			}
			std::cout << "                │            " GREEN "Contact added successfully!" WHITE "            │" << std::endl;
		} else if (ft_toupper(input) == "SEARCH") {
			std::cout << "\033[1A\033[K";
			std::cout << "                │                                                   │" EOC << std::endl;
			std::cout << "                │╭─────────────────────────────────────────────────╮│" EOC << std::endl;
			std::cout << "                ││   " YELLOW "INDEX   " WHITE "│ " YELLOW "FIRSTNAME  " WHITE "│ " YELLOW "LAST NAME  " WHITE "│ " YELLOW "NICKNAME  " WHITE "││" << std::endl;
			phone_book.display_contact();
			std::cout << "                │╰─────────────────────────────────────────────────╯│" EOC << std::endl;
			std::cout << "                │                                                   │" EOC << std::endl;
			std::cout << "                │       " BLUE "ADD" WHITE "       |     " BLUE "SEARCH" WHITE "     |      " BLUE "EXIT" WHITE "      │" << std::endl;
			std::cout << "                │                                                   │" EOC << std::endl;
		} else if (ft_toupper(input) == "EXIT") {
			std::cout << "\033[1A\033[K";
			std::cout << WHITE "                │              " RED "You left the phonebook." WHITE "              │" << std::endl;
			std::cout << WHITE "                ╰───────────────────────────────────────────────────╯" EOC << std::endl;
			break;
		} else {
			std::cout << "\033[1A\033[K";
			continue;
		}
	}
	return 0;
}


