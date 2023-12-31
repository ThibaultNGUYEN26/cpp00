/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:40 by thibault          #+#    #+#             */
/*   Updated: 2023/11/27 17:47:44 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhonebookMain.hpp"

// Default constructor for Phonebook class, initializing member variables
Phonebook::Phonebook() : _nb_contacts(0), _temp(0) {}

// Destructor for Phonebook class
Phonebook::~Phonebook() {}

// Function to check if an input is a single word or not
static bool ft_is_single_word(const std::string& input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if (isspace(input[i])) {
			return false;
		}
	}
	return true;
}

// Function to check if an input is only numeric or not
static bool ft_is_numeric(const std::string& input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]) && input[i] != '-' && input[i] != '.') {
			return false;
		}
	}
	return true;
}

// Function to add a new contact to the Phonebook
int Phonebook::add_contact(const std::string& first, const std::string& name, const std::string& nickname, const std::string& number, const std::string& secret) {
	if (!ft_is_numeric(number) || !ft_is_single_word(number)) {
		for (int i = 0; i < 6; i++) {
			std::cout << "\033[1A\033[K";
		}
		std::cout << "                │                  " RED "Invalid number." WHITE "                  │" << std::endl;
		std::cout << "                │               " RED "Fail to add Contact..." WHITE "              │" << std::endl;
		std::cout << "                │                                                   │" EOC << std::endl;
		return 0;
	} else if (first.length() > 51 || name.length() > 51 || nickname.length() > 51 || number.length() > 51 || secret.length() > 51) {
		for (int i = 0; i < 6; i++) {
			std::cout << "\033[1A\033[K";
		}
		std::cout << "                │               " RED "Input length too long." WHITE "              │" << std::endl;
		std::cout << "                │               " RED "Fail to add Contact..." WHITE "              │" << std::endl;
		std::cout << "                │                                                   │" EOC << std::endl;
		return 0;
	} if (_nb_contacts < MAX_CONTACTS) {
		contacts[_nb_contacts] = Contact(first, name, nickname, number, secret);
		contacts[_nb_contacts].set_first_name(first);
		contacts[_nb_contacts].set_last_name(name);
		contacts[_nb_contacts].set_nickname(nickname);
		contacts[_nb_contacts].set_phone_number(number);
		contacts[_nb_contacts].set_secret(secret);
		_temp = _nb_contacts;
		_nb_contacts++;
	} else {
		_temp++;
		contacts[_temp % MAX_CONTACTS] = Contact(first, name, nickname, number, secret);
	}
	return 1;
}

// Function to retrieve the last contact added to the Phonebook
const Contact& Phonebook::get_last_contact() const {
	if (_nb_contacts > 0) {
		if (_nb_contacts < MAX_CONTACTS) {
			return contacts[_nb_contacts - 1];
		} else {
			return contacts[_temp % MAX_CONTACTS];
		}
	} else {
		static Contact default_contact;
		return default_contact;
	}
}

// Function to display contact information in a formatted way
void display_contact_info(const std::string& info, int width) {
	int spaces = (width - info.length()) / 2;
	std::string spaces_string(spaces, ' ');
	std::cout << spaces_string << info << spaces_string;
	if (info.length() % 2 != 0) {
		std::cout << ' ';
	}
}

// Function to display contacts with limited information in a tabular format
int Phonebook::display_contact() const {
	std::stringstream ss;
	int num_contacts = (_nb_contacts < 8) ? _nb_contacts : 8;
	
	for (int i = 0; i < num_contacts; ++i) {
		ss << i + 1;
		std::cout << "                │   │";
		display_contact_info(ss.str(), 10);
		std::cout << "│";
		if (contacts[i].get_first_name().length() >= 10) {
			display_contact_info(contacts[i].get_first_name().substr(0, 9) + ".", 10);
		} else {
			display_contact_info(contacts[i].get_first_name(), 10);
		}
		std::cout << "│";
		if (contacts[i].get_last_name().length() >= 10) {
			display_contact_info(contacts[i].get_last_name().substr(0, 9) + ".", 10);
		} else {
			display_contact_info(contacts[i].get_last_name(), 10);
		}
		std::cout << "│";
		if (contacts[i].get_nickname().length() >= 10) {
			display_contact_info(contacts[i].get_nickname().substr(0, 9) + ".", 10);
		} else {
			display_contact_info(contacts[i].get_nickname(), 10);
		}
		std::cout << "│   │ " << std::endl;

		ss.str("");
	}
	return num_contacts;
}

// Function to get detailed information of a specific contact using an index
void Phonebook::get_info_contact(std::string index) const {
	if (!ft_is_single_word(index)) {
		std::cout << "                │              " RED "[Error] Invalid number." WHITE "              │" << std::endl;
		std::cout << "                │                                                   │" EOC << std::endl;
	} else {
		int converted_nb = std::atoi(index.c_str());
		if (converted_nb != 0 || (index == "0" && index.length() == 1)) {
			int index_int = converted_nb - 1;
			if (index_int == -1) {
				return;
			} else if (index_int >= 0 && index_int < _nb_contacts) {
				std::cout << "                │ ";
				display_contact_info(contacts[index_int].get_first_name(), 50);
				std::cout << "│" << std::endl;
				std::cout << "                │ ";
				display_contact_info(contacts[index_int].get_last_name(), 50);
				std::cout << "│" << std::endl;
				std::cout << "                │ ";
				display_contact_info(contacts[index_int].get_nickname(), 50);
				std::cout << "│" << std::endl;
				std::cout << "                │ ";
				display_contact_info(contacts[index_int].get_phone_number(), 50);
				std::cout << "│" << std::endl;
				std::cout << "                │ ";
				display_contact_info(contacts[index_int].get_secret(), 50);
				std::cout << "│" << std::endl;
				std::cout << "                │                                                   │" EOC << std::endl;
			} else {
				std::cout << "                │            " RED "[Error] Contact not found." WHITE "             │" << std::endl;
				std::cout << "                │                                                   │" EOC << std::endl;
			}
		} else {
			std::cout << "                │             " RED "[Error] Invalid number." WHITE "               │" << std::endl;
			std::cout << "                │                                                   │" EOC << std::endl;
		}
	}
}