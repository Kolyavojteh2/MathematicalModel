#include "Include/mathematicalmodel.h"
#include "Include/mathematicalmodelexception.h"

MathematicalModel::MathematicalModel() {}

void MathematicalModel::addInputValue(const QString& name, const QVariant& value) {
    if (_input_data.find(name) != _input_data.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("var_name", name);
        exceptionArguments.insert("where_dictionary", "_input_data");
        throw MathematicalModelException(MathematicalModelExceptionType::VARIABLE_ALREADY_EXISTS, exceptionArguments);
    }

    _input_data.insert(name, value);
}

QVariant MathematicalModel::getInputValue(const QString& name) const {
    if (_input_data.find(name) == _input_data.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("var_name", name);
        exceptionArguments.insert("where_dictionary", "_input_data");
        throw MathematicalModelException(MathematicalModelExceptionType::SEARCHED_VARIABLE_DOES_NOT_EXIST, exceptionArguments);
    }

    return *_input_data.find(name);
}

void MathematicalModel::addVariable(const QString& name, const QVariant& value) {
    if (_variables.find(name) != _variables.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("var_name", name);
        exceptionArguments.insert("where_dictionary", "_variables");
        throw MathematicalModelException(MathematicalModelExceptionType::VARIABLE_ALREADY_EXISTS, exceptionArguments);
    }

    _variables.insert(name, value);
}

QVariant MathematicalModel::getVariable(const QString& name) const {
    if (_variables.find(name) == _variables.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("var_name", name);
        exceptionArguments.insert("where_dictionary", "_variables");
        throw MathematicalModelException(MathematicalModelExceptionType::SEARCHED_VARIABLE_DOES_NOT_EXIST, exceptionArguments);
    }

    return *_variables.find(name);
}

void MathematicalModel::eraseVariable(const QString& name) {
    if (_variables.find(name) == _variables.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("var_name", name);
        exceptionArguments.insert("where_dictionary", "_variables");
        throw MathematicalModelException(MathematicalModelExceptionType::SEARCHED_VARIABLE_DOES_NOT_EXIST, exceptionArguments);
    }

    _variables.erase(_variables.find(name));
}

void MathematicalModel::updateVariable(const QString& name, const QVariant& newValue) {
    if (_variables.find(name) == _variables.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("var_name", name);
        exceptionArguments.insert("where_dictionary", "_variables");
        throw MathematicalModelException(MathematicalModelExceptionType::SEARCHED_VARIABLE_DOES_NOT_EXIST, exceptionArguments);
    }

    _variables[name] = newValue;
}

void MathematicalModel::addFunction(const QString& name, MathematicalFunction func) {
    if (_functions.find(name) != _functions.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("func_name", name);
        throw MathematicalModelException(MathematicalModelExceptionType::FUNCTION_ALREADY_EXISTS, exceptionArguments);
    }

    _functions.insert(name, func);
}

MathematicalVars MathematicalModel::runFunction(const QString& name, const MathematicalVars& arguments) const {
    if (_functions.find(name) == _functions.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("func_name", name);
        throw MathematicalModelException(MathematicalModelExceptionType::FUNCTION_DOES_NOT_EXISTS, exceptionArguments);
    }

    return (*_functions.find(name))(arguments);
}

void MathematicalModel::eraseFunction(const QString& name) {
    if (_functions.find(name) == _functions.end()) {
        MathematicalVars exceptionArguments;
        exceptionArguments.insert("func_name", name);
        throw MathematicalModelException(MathematicalModelExceptionType::FUNCTION_DOES_NOT_EXISTS, exceptionArguments);
    }

    _functions.erase(_functions.find(name));
}

MathematicalVars MathematicalModel::simulateTheModel() {
    return MathematicalVars();
}

