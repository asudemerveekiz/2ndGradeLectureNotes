package edu.ytu.nerdle.core.util.validators;

import edu.ytu.nerdle.core.model.equation.Equation;

public interface IValidators {
    boolean isValid(Equation equation);
    boolean isRightFormatted(Equation equation);
    boolean isResultCorrect(Equation equation);
}
