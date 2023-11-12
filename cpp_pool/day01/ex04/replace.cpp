/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:05:20 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:05:21 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int replaceClone(std::ifstream &file, const char **argv)
{
	std::string filename = argv[1];
	filename += ".replace";

	std::ofstream res_file(filename.c_str());
	if (!res_file)
	{
		std::cerr << "Unable to create the file\n";
		return (1);
	}

	std::string line;
	while (std::getline(file, line))
	{
		size_t pos = line.find(argv[2]);
		while (pos != std::string::npos)
		{
			res_file << line.substr(0, pos);
			line.erase(0, pos);
			res_file << argv[3];
			line.erase(0, std::string(argv[2]).length());
			pos = line.find(argv[2]);
		}
		res_file << line << '\n';
	}
	return 0;
}