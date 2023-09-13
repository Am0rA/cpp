/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:05:33 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:05:33 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("DebuG");
	harl.complain("WARNING");
	harl.complain("error");
	harl.complain("WARNING!");
	harl.complain("");
	harl.complain("ASDSADSAd");
	return (0);
}
