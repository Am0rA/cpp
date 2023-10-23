/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:33:56 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/23 17:33:56 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data*	data = new Data();
	data->value = "Tester";

	uintptr_t raw = Serializer::serialize(data);
	Data*	newData = Serializer::deserialize(raw);

	std::cout << "Addess of data: " << data << std::endl;
	std::cout << "Unsigned int raw: " << raw << std::endl;
	std::cout << "Address of newData: " << newData << std::endl;

	if (data == newData)
		std::cout << C_GREEN "Succeeded" C_RESET << std::endl;
	else
		std::cout << C_GREEN "Failed" C_RESET << std::endl;
	
	std::cout << "Original value: " << data->value << std::endl;
	std::cout << "Deserialized value: " << newData->value << std::endl;
	delete data;

	return 0;
}
