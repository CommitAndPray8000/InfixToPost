#include "/home/muhammadyahya/Documents/DSA/Stack/DynamicStack.cpp"
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class PostFixConverter 
{
  DynamicStack operator_pile;
  int size;
  char *expression_arr;
  string PostFixed;

  public:
  PostFixConverter(string expression) 
  {
    size = expression.size();
    expression_arr = new char[size + 1];
    strcpy(expression_arr, expression.c_str());
  }
  //||||||||||| New Code |||||||||||||||||||

  int precedence(char op) 
  {
    unordered_map<char, int> precedence_map;
    int PrecedenceValue;
    precedence_map['^'] = 11;
    precedence_map['*'] = 10;
    precedence_map['/'] = 10;
    precedence_map['%'] = 10;
    precedence_map['+'] = 9;
    precedence_map['-'] = 9;
    precedence_map['<'] = 8;
    precedence_map['>'] = 8;
    precedence_map['&'] = 7;
    precedence_map['|'] = 6;

    PrecedenceValue = precedence_map[op];

    return PrecedenceValue;
  }

  string Converter() {
    string result;

    for (int i = 0; i < size; i++) 
    {
      if (expression_arr[i] == '*' || expression_arr[i] == '/' ||
          expression_arr[i] == '%' || expression_arr[i] == '+' ||
          expression_arr[i] == '-' || expression_arr[i] == '<' ||
          expression_arr[i] == '>' || expression_arr[i] == '&' ||
          expression_arr[i] == '|'|| expression_arr[i] == '^') 
      {

        if (operator_pile.top == nullptr) 
        {
          operator_pile.PushStack(expression_arr[i]);
        }

        else if ((precedence(expression_arr[i]) -
                      precedence(operator_pile.top->element) > 0)) 
        {
          operator_pile.PushStack(expression_arr[i]);
        }

        else 
        {

          while ((operator_pile.top != nullptr)  && (precedence(expression_arr[i]) -
                  precedence(operator_pile.top->element) <= 0))
          {
            result += operator_pile.PopStack();
          }

          operator_pile.PushStack(expression_arr[i]);
        }

      }

      else if (expression_arr[i] == '(') 
      {
        operator_pile.PushStack(expression_arr[i]);
      }

      else if (expression_arr[i] == ')') 
      {

        while (operator_pile.top->element != '(')
        {
          result += operator_pile.PopStack();
        }
        operator_pile.PopStack();
      }

      else 
      {
        result += expression_arr[i];
      }
    }
    
    while (operator_pile.top != nullptr) 
    {
      result += operator_pile.PopStack();
    }

    return result;
  }

  // ||||||||||| Old Ineffient Code |||||||||||||
  // public:
  //   string Converter() {
  //     for (int i = 0; i < size; i++) {
  //       if (expression_arr[i] == '*' || expression_arr[i] == '/' ||
  //           expression_arr[i] == '%' || expression_arr[i] == '+' ||
  //           expression_arr[i] == '-' || expression_arr[i] == '<' ||
  //           expression_arr[i] == '>' || expression_arr[i] == '&' ||
  //           expression_arr[i] == '|') {
  //
  //         if (precedence(expression_arr[i]) || operator_pile.top ==
  //         nullptr) {
  //           operator_pile.PushStack(expression_arr[i]);
  //         } else {
  //           while ((!(precedence(expression_arr[i]))) &&
  //                  (operator_pile.top != nullptr))
  //             PostFixed += operator_pile.PopStack();
  //
  //           operator_pile.PushStack(expression_arr[i]);
  //         }
  //       } else if (expression_arr[i] == '(') {
  //         operator_pile.PushStack(expression_arr[i]);
  //
  //       } else if (expression_arr[i] == ')') {
  //         while (operator_pile.top->element != '(') {
  //           PostFixed += operator_pile.PopStack();
  //         }
  //         operator_pile.PopStack();
  //       } else {
  //         PostFixed += expression_arr[i];
  //       }
  //     }
  //     while (operator_pile.top != nullptr) {
  //       PostFixed += operator_pile.PopStack();
  //     }
  //     return PostFixed;
  //   }
  //
  // public:
  //   bool precedence(char op) {
  //     if (operator_pile.top == nullptr) {
  //       return true;
  //     }
  //     if (operator_pile.top->element == '(') {
  //       return true;
  //     }
  //
  //     if (op == '*' || op == '/' || op == '%') {
  //       switch (operator_pile.top->element) {
  //       case '*':
  //         return false;
  //         break;
  //
  //       case '/':
  //         return false;
  //         break;
  //
  //       case '%':
  //         return false;
  //         break;
  //       }
  //
  //       return true;
  //     }
  //
  //     else if (op == '+' || op == '-') {
  //       switch (operator_pile.top->element) {
  //       case '&':
  //         return true;
  //         break;
  //
  //       case '|':
  //         return true;
  //         break;
  //
  //       case '<':
  //         return true;
  //         break;
  //
  //       case '>':
  //         return true;
  //         break;
  //
  //       default:
  //         return false;
  //         break;
  //       }
  //     }
  //
  //     else if (op == '<' || op == '>') {
  //       if (operator_pile.top->element == '|')
  //         return true;
  //
  //       else if (operator_pile.top->element == '&')
  //         return true;
  //
  //       return false;
  //     }
  //
  //     else if (op == '&') {
  //       if (operator_pile.top->element == '|')
  //         return true;
  //
  //       return false;
  //     } else if (op == '|') {
  //       return false;
  //     }
  //
  //     return false;
  //   }
};
