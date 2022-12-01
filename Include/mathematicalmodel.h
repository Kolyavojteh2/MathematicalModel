#ifndef MATHEMATICALMODEL_H
#define MATHEMATICALMODEL_H

#include "MathematicalModel_global.h"

#include <QVariant>
#include <QString>
#include <exception>

///
/// \brief MathematicalVars is a common type for keeping values in the class
///
/// This type is a map which has a QString type as a key and QVariant as a value.
///
typedef QMap<QString, QVariant> MathematicalVars;

///
/// \brief MathematicalFunction is the function which recieve vars, calculate and return vars.
/// \param arguments are the variables which needed by the calculation.
/// \return vars which defined by user.
///
typedef MathematicalVars(*MathematicalFunction)(MathematicalVars arguments);

class MATHEMATICALMODEL_EXPORT MathematicalModel
{
protected:
    ///
    /// \brief The storage for input values
    ///
    MathematicalVars _input_data;

    ///
    /// \brief The storage for temporary or common values
    ///
    MathematicalVars _variables;

    ///
    /// \brief The storage for functions or operations, which are defined by user
    ///
    QMap<QString, MathematicalFunction> _functions;

public:
    MathematicalModel();

    ///
    /// \brief addInputValue addes the input value to the dictionary of input or throws the exception if the var with the same name is exists.
    /// \param name is the name of the variable.
    /// \param value is the value of variable.
    ///
    void addInputValue(const QString& name, const QVariant& value);

    ///
    /// \brief getInputValue returns the value of input variable or throw exception if this var does not exist.
    /// \param name is the name of the variable.
    /// \return the value of variable that named as "name".
    ///
    QVariant getInputValue(const QString& name) const;

    ///
    /// \brief addVariable addes a variable to the dictionary or throws the exception if the var with the same name is exists.
    /// \param name is the name of the variable.
    /// \param value is the value of variable.
    ///
    void addVariable(const QString& name, const QVariant& value);

    ///
    /// \brief getVariable returns the value of variable or throw exception if this var does not exist.
    /// \param name is the name of the variable.
    /// \return the value of variable that named as "name".
    ///
    QVariant getVariable(const QString& name) const;

    ///
    /// \brief eraseVariable erases the variable by name from the dictionary or throws the exception if the var does not exist.
    /// \param name is the name of the variable.
    ///
    void eraseVariable(const QString& name);

    ///
    /// \brief updateVariable updates the variable by name to newValue or throws the exception if the var does not exist.
    /// \param name is the name of the variable.
    /// \param newValue is the new value of variable.
    ///
    void updateVariable(const QString& name, const QVariant& newValue);

    ///
    /// \brief addFunction addes a function to the function dictionary or throws the exception if the function exists.
    /// \param name is the name of the function.
    /// \param func is the pointer to the function.
    ///
    void addFunction(const QString& name, MathematicalFunction func);

    ///
    /// \brief runFunction run the found function by name with arguments or throws the exception if the function does not exist.
    /// \param name is the name of the function.
    /// \param arguments is arguments to the function
    /// \return calculated vars by the function.
    ///
    MathematicalVars runFunction(const QString& name, const MathematicalVars& arguments) const;

    ///
    /// \brief eraseFunction erases the function by name or throws the exception if the function does not exist.
    /// \param name is the name of the function.
    ///
    void eraseFunction(const QString& name);

    ///
    /// \brief simulateTheModel runs the imitation of the mathematical model. See detailed description.
    /// \return calculated vars after simulation.
    ///
    /// This function is used for simulation the mathematical model in inheritanced classes.
    ///
    virtual MathematicalVars simulateTheModel();
};

#endif // MATHEMATICALMODEL_H
