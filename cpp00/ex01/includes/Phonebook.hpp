/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:50 by thibault          #+#    #+#             */
/*   Updated: 2023/11/23 20:33:15 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "../includes/PhonebookMain.hpp"

const int MAX_CONTACTS = 8;

class Phonebook {


public:

	Phonebook();
	~Phonebook();
	
	void add_contact(const std::string& first, const std::string& name, const std::string& nickname, const std::string& number, const std::string& secret);
	const Contact& get_last_contact() const;
	void display_contact() const;

private:

	Contact contacts[MAX_CONTACTS];
	int _nb_contacts;
	int _temp;

};

#endif