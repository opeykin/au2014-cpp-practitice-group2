#include "scanner.h"
#include <iostream>

char Scanner::GetChar() {
  return Code[Pos++];
}

char Scanner::LookAhead(size_t shift)
{
  return Code[Pos + shift];
}

bool Scanner::Match(const string& pattern)
{
  for (size_t i = 0; i < pattern.length(); ++i) 
  {
    if (LookAhead(i) != pattern[i])
      return false;
  }

  Pos += pattern.length();
  return true;
}

bool Scanner::Match(char c, const string& pattern)
{
  return c == pattern[0] && Match(pattern.substr(1));
}

string Scanner::ReadIdent(char symbol)
{
  string ident; 
  ident += symbol;

  while(isalnum(LookAhead(0)))
  {
    ident += GetChar();
  }

  return ident;
}

TokenType Scanner::GetTokenType(const string& value)
{
  std::cout << '\"'<< value << '\"' << " ";
  if (value == "var")
    return tDECL;

  if (value == "begin")
    return tBEGIN;

  if (value == "end")
    return tEND;

  if (value == "print")
    return tPRINT;

  if (value == "if")
    return tIF;

  return tIDENT;
}

Token Scanner::GetAlphanumToken(const string& value, size_t pos)
{
  TokenType type = GetTokenType(value);
  return Token(type, value, pos);
}

void Scanner::AddToken(TokenType type, const string& value, size_t pos)
{
  Tokens.push_back(Token(type, value, pos));
}
void Scanner::Scan(const string & code) {
  Code = code;
  Pos = 0;


  while (true)
  {
    char symbol = GetChar();

    if (symbol == '\0')
      break;

    if (isspace(symbol))
      continue;

    if (isalpha(symbol))
    {
      string ident = ReadIdent(symbol);
      Token token = GetAlphanumToken(ident, Pos - ident.length());
      Tokens.push_back(token);
      std::cout << token.Type << "\n";
    }

    if (symbol == '=')
      AddToken(tEQ, "=", Pos - 1);

    if (symbol == '<')
      AddToken(tLESS, "<", Pos - 1);
  }
}
