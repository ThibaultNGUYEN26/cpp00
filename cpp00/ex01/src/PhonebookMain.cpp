/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookMain.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:19:09 by thibault          #+#    #+#             */
/*   Updated: 2023/11/27 17:37:08 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhonebookMain.hpp"

// Function to convert string to uppercase
std::string ft_toupper(std::string str) {
	std::string temp(str.length(), ' ');

	for (size_t i = 0; i < str.length(); i++)
		temp[i] = toupper(str[i]);
	return temp;
}

// Function to capitalize the first character of the string
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

	while (true) {
		std::cout << MAGENTA "[INPUT] : " WHITE;
		std::getline(std::cin, input);
		
		if (ft_toupper(input) == "ADD") {
			std::string first, name, nickname, number, secret;
			std::cout << MAGENTA "[INPUT] " YELLOW "First name   : " WHITE;
			std::getline(std::cin >> std::ws, first);
			std::cout << MAGENTA "[INPUT] " YELLOW "Last name    : " WHITE;
			std::getline(std::cin >> std::ws, name);
			std::cout << MAGENTA "[INPUT] " YELLOW "Nickname     : " WHITE;
			std::getline(std::cin >> std::ws, nickname);
			std::cout << MAGENTA "[INPUT] " YELLOW "Phone number : " WHITE;
			std::getline(std::cin >> std::ws, number);
			std::cout << MAGENTA "[INPUT] " YELLOW "Secret       : " WHITE;
			std::getline(std::cin >> std::ws, secret);
			
			int contact_status = phone_book.add_contact(first, name, nickname, number, secret);
			
			if (contact_status) {
				const Contact& last_contact = phone_book.get_last_contact();
				std::string first_name;
				std::string last_name;
				if (last_contact.get_first_name().length() >= 10) {
					first_name = last_contact.get_first_name().substr(0, 9) + ".";
				} else {
					first_name = last_contact.get_first_name();
				}
				if (last_contact.get_last_name().length() >= 10) {
					last_name = last_contact.get_last_name().substr(0, 9) + ".";
				} else {
					last_name = last_contact.get_last_name();
				}

				for (int i = 0; i < 6; i++) {
					std::cout << "\033[1A\033[K";
				}
				
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
			}
		} else if (ft_toupper(input) == "SEARCH") {
			std::cout << "\033[1A\033[K";
			std::cout << "                │                                                   │" EOC << std::endl;
			std::cout << "                │   ╭───────────────────────────────────────────╮   │" EOC << std::endl;
			std::cout << "                │   │  " YELLOW "INDEX   " WHITE "│" YELLOW "FIRSTNAME " WHITE "│" YELLOW "LAST NAME" WHITE " │ " YELLOW "NICKNAME " WHITE "│   │" << std::endl;
			int num_contacts = phone_book.display_contact();
			std::cout << "                │   ╰───────────────────────────────────────────╯   │" EOC << std::endl;
			std::cout << "                │                                                   │" EOC << std::endl;
			if (num_contacts) {
				std::cout << MAGENTA "[INPUT] " YELLOW "Enter index to get info (0 to skip): " WHITE;
				std::getline(std::cin, input);
				std::cout << "\033[1A\033[K";
				phone_book.get_info_contact(input);
			}
			std::cout << "                │       " BLUE "ADD" WHITE "       |     " BLUE "SEARCH" WHITE "     |      " BLUE "EXIT" WHITE "      │" << std::endl;
			std::cout << "                │                                                   │" EOC << std::endl;
		} else if (ft_toupper(input) == "EXIT") {
			std::cout << "\033[1A\033[K";
			std::cout << WHITE "                │              " RED "You left the phonebook." WHITE "              │" << std::endl;
			std::cout << WHITE "                ╰───────────────────────────────────────────────────╯" EOC << std::endl;
			break;
		} else {
			std::cout << "\033[1A\033[K";
		}
	}
	return 0;
}