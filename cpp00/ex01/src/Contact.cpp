/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:54 by thibault          #+#    #+#             */
/*   Updated: 2023/11/26 19:56:09 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhonebookMain.hpp"

// Default constructor for Contact class
Contact::Contact() : _first(""), _name(""), _nickname(""), _number(""), _secret("") {}

// Parameterized constructor for Contact class
Contact::Contact(const std::string& first, const std::string& name, const std::string& nickname, const std::string& number, const std::string& secret)
	: _first(first), _name(name), _nickname(nickname), _number(number), _secret(secret) {}

// Destructor for Contact class
Contact::~Contact() {}

// Getter function for retrieving the first name of the contact
std::string Contact::get_first_name() const {
	return _first;
}

// Getter function for retrieving the last name of the contact
std::string Contact::get_last_name() const {
	return _name;
}

// Getter function for retrieving the nickname of the contact
std::string Contact::get_nickname() const {
	return _nickname;
}

// Getter function for retrieving the phone number of the contact
std::string Contact::get_phone_number() const {
	return _number;
}

// Getter function for retrieving the secret information of the contact
std::string Contact::get_secret() const {
	return _secret;
}

// Setter function for setting the first name of the contact
void Contact::set_first_name(const std::string& first) {
	this->_first = first;
}

// Setter function for setting the last name of the contact
void Contact::set_last_name(const std::string& name) {
	this->_name = name;
}

// Setter function for setting the nickname of the contact
void Contact::set_nickname(const std::string& nickname) {
	this->_nickname = nickname;
}

// Setter function for setting the phone number of the contact
void Contact::set_phone_number(const std::string& number) {
	this->_number = number;
}

// Setter function for setting the secret information of the contact
void Contact::set_secret(const std::string& secret) {
	this->_secret = secret;
}