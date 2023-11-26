/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:20:21 by thibault          #+#    #+#             */
/*   Updated: 2023/11/24 16:25:49 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "../includes/PhonebookMain.hpp"

class Contact {


public:

    Contact();
    Contact(const std::string& first, const std::string& name, const std::string& nickname, const std::string& number, const std::string& secret);
    ~Contact();

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_secret() const;
    
    void set_first_name(const std::string& first);
    void set_last_name(const std::string& name);
    void set_nickname(const std::string& nickname);
    void set_phone_number(const std::string& number);
    void set_secret(const std::string& secret);


private:

    std::string _first;
    std::string _name;
    std::string _nickname;
    std::string _number;
    std::string _secret;

};

#endif