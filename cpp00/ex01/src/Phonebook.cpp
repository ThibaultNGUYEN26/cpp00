/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:40 by thibault          #+#    #+#             */
/*   Updated: 2023/11/23 20:22:13 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhonebookMain.hpp"

Phonebook::Phonebook() : _nb_contacts(0), _temp(0) {}

Phonebook::~Phonebook() {}

void Phonebook::add_contact(const std::string& first, const std::string& name, const std::string& nickname, const std::string& number, const std::string& secret) {
	if (_nb_contacts < MAX_CONTACTS) {
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
}

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

void display_contact_info(const std::string& info, int width) {
	int spaces = (width - info.length()) / 2;
	std::string spaces_string(spaces, ' ');
	std::cout << spaces_string << info << spaces_string;
	if (info.length() % 2 != 0) {
		std::cout << ' ';
	}
}

void Phonebook::display_contact() const {
	std::stringstream ss;
	int num_contacts = (_nb_contacts < 8) ? _nb_contacts : 8;
	
	for (int i = 0; i < num_contacts; ++i) {
		ss << i + 1;
		std::cout << "                ││";
		display_contact_info(ss.str(), 10);
		std::cout << " │ ";
		display_contact_info(contacts[i].get_first_name(), 10);
		std::cout << " │ ";
		display_contact_info(contacts[i].get_last_name(), 10);
		std::cout << " │ ";
		display_contact_info(contacts[i].get_nickname(), 10);
		std::cout << "││ " << std::endl;

		ss.str("");
	}
}
