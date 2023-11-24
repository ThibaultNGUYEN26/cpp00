/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:54 by thibault          #+#    #+#             */
/*   Updated: 2023/11/16 00:25:50 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhonebookMain.hpp"

Contact::Contact() : first(""), name(""), nickname(""), number(""), secret("") {}

Contact::Contact(const std::string& first, const std::string& name, const std::string& nickname, const std::string& number, const std::string& secret) : first(first), name(name), nickname(nickname), number(number), secret(secret) {};

Contact::~Contact() {}

std::string Contact::get_first_name() const {
	return first;
}

std::string Contact::get_last_name() const {
	return name;
}

std::string Contact::get_nickname() const {
	return nickname;
}

std::string Contact::get_phone_number() const {
	return number;
}

std::string Contact::get_secret() const {
	return secret;
}

void Contact::set_first_name(const std::string& first) {
	if (first.length() > 10) {
		std::cout << "LOL" << std::endl;
		this->first = first.substr(0, 9) + ".";
	} else {
		std::cout << "JE SUIS LA" << std::endl;
		this->first = first;
	}
}

void Contact::set_last_name(const std::string& name) {
	if (name.length() > 10) {
		this->name = name.substr(0, 9) + ".";
	} else {
		this->name = name;
	}
}

void Contact::set_nickname(const std::string& nickname) {
	if (nickname.length() > 10) {
		this->nickname = nickname.substr(0, 9) + ".";
	} else {
		this->nickname = nickname;
	}
}

void Contact::set_phone_number(const std::string& number) {
	if (number.length() > 10) {
		this->number = number.substr(0, 9) + ".";
	} else {
		this->number = number;
	}
}

void Contact::set_secret(const std::string& secret) {
	if (secret.length() > 10) {
		this->secret = secret.substr(0, 9) + ".";
	} else {
		this->secret = secret;
	}
}