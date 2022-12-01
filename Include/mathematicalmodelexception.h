#ifndef MATHEMATICALMODELEXCEPTION_H
#define MATHEMATICALMODELEXCEPTION_H

#include "MathematicalModel_global.h"

#include <exception>
#include <QMap>
#include <QString>
#include <QVariant>

enum MATHEMATICALMODEL_EXPORT MathematicalModelExceptionType {
    VARIABLE_ALREADY_EXISTS,
    SEARCHED_VARIABLE_DOES_NOT_EXIST,
    FUNCTION_ALREADY_EXISTS,
    FUNCTION_DOES_NOT_EXISTS
};

class MATHEMATICALMODEL_EXPORT MathematicalModelException : public std::exception
{
private:
    MathematicalModelExceptionType _type;
    QMap<QString, QVariant> _vars;

public:
    ///
    /// \brief MathematicalModelException is the exception for MathematicalModel
    /// \param t is the type of the exception. See enum MathematicalModelExceptionType
    /// \param vars is the arguments for exception. See the detailed description of this constructor
    ///
    /// type VARIABLE_ALREADY_EXISTS : This exception is thrown when a variable with that name already exists in the dictionary.
    ///     var_name : the name of an existing variable
    ///     where_dictionary : the name of the type dictionary
    ///
    /// type SEARCHED_VARIABLE_DOES_NOT_EXIST : This exception is thrown when a variable with that name does not exist in the dictionary.
    ///     var_name : the name of an needing variable
    ///     where_dictionary : the name of the type dictionary
    ///
    /// type FUNCTION_ALREADY_EXISTS : This exception is thrown when a searched function with that name already exists.
    ///     func_name : the name of the function.
    ///
    /// type FUNCTION_DOES_NOT_EXISTS : This exception is thrown when a searched function with that name does not exist.
    ///     func_name : the name of the function.
    ///
    MathematicalModelException(MathematicalModelExceptionType t, QMap<QString, QVariant> vars);

    const char* what() const noexcept override;
};

#endif // MATHEMATICALMODELEXCEPTION_H
