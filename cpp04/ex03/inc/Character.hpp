/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 23:15:04 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/29 23:15:04 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
class Character : public ICharacter
{
	private:
    	std::string _name;
    	std::array<AMateria*, 4> _inventory;

	public:
    	Character(std::string const & name) : _name(name), _inventory{nullptr, nullptr, nullptr, nullptr} {}
    	Character(Character const & other);
    	Character & operator=(Character const & other);
    	virtual ~Character();
    	std::string const & getName() const { return _name; }
    	void equip(AMateria* m);
    	void unequip(int idx);
    	void use(int idx, ICharacter& target);
};

#endif