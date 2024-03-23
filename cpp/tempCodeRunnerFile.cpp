int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << exp << endl;
    cout << "Postfix Expression: " << infixToPostfix(exp) << endl;
    return 0;
}
