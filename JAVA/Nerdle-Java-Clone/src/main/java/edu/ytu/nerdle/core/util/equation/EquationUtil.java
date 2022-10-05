package edu.ytu.nerdle.core.util.equation;

import java.util.Random;
import java.util.Stack;

public class EquationUtil {

    private static final String ms_operators = "+-*/";
    private static boolean isdigit(char c)  {
        return c >= '0' && c <= '9';
    }
    private static boolean isOperator(char c) {
        return (!isdigit(c));
    }
    private static int getPriority(char C) {
        if (C == '-' || C == '+')
            return 1;
        else if (C == '*' || C == '/')
            return 2;

        return 0;
    }
    private static String reverse(char[] str, int start, int end) {
        char temp;
        while (start < end)
        {
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
        return String.valueOf(str);
    }
    private static String infixToPostfix(char[] infix1) {
        System.out.println(infix1);
        String infix = '(' + String.valueOf(infix1) + ')';
        int l = infix.length();
        Stack<Character> charStack = new Stack<>();
        String output="";
        for (int i = 0; i < l; i++)
        {
            if (isdigit(infix.charAt(i)))
                output += infix.charAt(i);

            else if (infix.charAt(i) == '(')
                charStack.add('(');

            else if (infix.charAt(i) == ')') {
                while (charStack.peek() != '(') {
                    output += charStack.peek();
                    charStack.pop();
                }
                charStack.pop();
            }
            else {
                if (isOperator(charStack.peek()))
                {
                    while ((getPriority(infix.charAt(i)) < getPriority(charStack.peek()))
                            || (getPriority(infix.charAt(i)) <= getPriority(charStack.peek()) &&  infix.charAt(i) == '^')) {
                        output += charStack.peek();
                        charStack.pop();
                    }
                    charStack.add(infix.charAt(i));
                }
            }
        }
        while(!charStack.empty()){
            output += charStack.pop();
        }
        return output;
    }

    private static int getRandomNumber(Random r) {
        return r.nextInt(100);
    }
    private static int getRandomNumber() {
        return getRandomNumber(new Random());
    }

    private static char getRandomOperator(Random r) {
        return ms_operators.charAt(r.nextInt(ms_operators.length()));
    }
    private static char getRandomOperator() {
        return getRandomOperator(new Random());
    }

    public static String generateEquation(Random r, int equationLength) {
        String equation = "";
        int num1 = getRandomNumber(r);
        int num2 = getRandomNumber(r);
        char op = getRandomOperator(r);

        if (op == '-')
            if (num1 < num2) {
                int tmp = num1;
                num1 = num2;
                num2 = tmp;
            }

        equation += num1;
        equation += op;
        equation += num2;
        equation += "=";

        if (equation.length() != equationLength)
            return generateEquation(r, equationLength);

        return equation;
    }
    public static String generateEquation(int equationLength) {
        return generateEquation(new Random(), equationLength);
    }
    public static String generateEquation() {
        Random r = new Random();
        return generateEquation(r, r.nextInt(2) + 5);
    }
    public static String infixToPrefix(char[] infix) {
        int l = infix.length;
        String infix1 = reverse(infix, 0, l - 1);
        infix = infix1.toCharArray();
        String prefix = infixToPostfix(infix);
        prefix = reverse(prefix.toCharArray(), 0, l-1);
        return prefix;
    }
}
