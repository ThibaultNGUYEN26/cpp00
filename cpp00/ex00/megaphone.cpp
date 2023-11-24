/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 03:38:10 by thibault          #+#    #+#             */
/*   Updated: 2023/10/29 16:59:10 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1)
		while (argv[++i])
			for (size_t j = 0; j < strlen(argv[i]); j++)
				std::cout << (char)std::toupper(argv[i][j]);
	std::cout << std::endl;
	return 0;
}