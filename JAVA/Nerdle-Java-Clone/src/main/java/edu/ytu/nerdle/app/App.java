package edu.ytu.nerdle.app;

import edu.ytu.nerdle.core.util.equation.EquationUtil;

public class App {
    public static void main(String[] args) {
        System.out.println(EquationUtil.infixToPrefix("A*B+C/D".toCharArray()));
        System.out.println(EquationUtil.generateEquation());


    }
}
