Character::Character(Character const & other) : _name(other._name) {
    for (size_t i = 0; i < _inventory.size(); ++i) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        } else {
            _inventory[i] = nullptr;
        }
    }
}

Character & Character::operator=(Character const & other) {
    if (this != &other) {
        _name = other._name;
        for (size_t i = 0; i < _inventory.size(); ++i) {
            delete _inventory[i];
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            } else {
                _inventory[i] = nullptr;
            }
        }
    }
    return *this;
}

Character::~Character() {
    for (size_t i = 0; i < _inventory.size(); ++i) {
        delete _inventory[i];
    }
}

void Character::equip(AMateria* m) {
    for (size_t i = 0; i < _inventory.size(); ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        _inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        _inventory[idx]->use(target);
    }
}