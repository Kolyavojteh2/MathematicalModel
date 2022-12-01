#include "Include/mathematicalmodelexception.h"
#include <QString>
#include <string.h>

MathematicalModelException::MathematicalModelException(MathematicalModelExceptionType t, QMap<QString, QVariant> vars) : _type(t), _vars(vars) {}

const char* MathematicalModelException::what() const noexcept {
    QString str = "Error!\n";

    switch (_type) {
    case MathematicalModelExceptionType::VARIABLE_ALREADY_EXISTS:
        str = QString("The var \"%1\" is already exists in the %2\n")
                .arg(_vars["var_name"].toString())
                .arg(_vars["where_dictionary"].toString());
        break;

    case MathematicalModelExceptionType::SEARCHED_VARIABLE_DOES_NOT_EXIST: {
        str = QString("The var \"%1\" does not exist in the %2\n")
                .arg(_vars["var_name"].toString())
                .arg(_vars["where_dictionary"].toString());
        break;
    }

    case MathematicalModelExceptionType::FUNCTION_ALREADY_EXISTS:
        str = QString("The function \"%1\" already exists in the dictionary\n")
                .arg(_vars["func_name"].toString());
        break;

    case MathematicalModelExceptionType::FUNCTION_DOES_NOT_EXISTS:
        str = QString("The function \"%1\" does not exist in the dictionary\n")
                .arg(_vars["func_name"].toString());
        break;
    }

    char* c_str = new char[str.size()];
    strcpy(c_str, str.toStdString().c_str());

    return c_str;
}
