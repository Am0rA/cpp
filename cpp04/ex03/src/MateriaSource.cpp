MateriaSource::~MateriaSource() {
    for (size_t i = 0; i < _materias.size(); ++i) {
        delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (size_t i = 0; i < _materias.size(); ++i) {
        if (!_materias[i]) {
            _materias[i] = m->clone();
            return;
        }
    }
    delete m; // If there's no space to learn new materia, delete it.
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (size_t i = 0; i < _materias.size(); ++i) {
        if (_materias[i] && _materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
    return nullptr;
}