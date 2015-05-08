#include <string>
#include <vector>
using std::string;

enum TokenType { 
  tDECL,
  tIDENT,
  tEQ,
  tLESS,
  tNUM,
  tBEGIN,
  tEND,
  tPRINT,
  tPROGEND,
  tIF 
};

struct Token
{
  Token(TokenType type, const string value, size_t pos) : Type(type), Value(value), Pos(pos) { }
  TokenType Type;
  string Value;
  size_t Pos;
};

class Scanner
{
  string Code;
  size_t Pos;
  std::vector<Token> Tokens;
  public:
  void Scan(const string& code);
  char GetChar();
  char LookAhead(size_t shift = 1);
  bool Match(const string& pattern);
  bool Match(char c, const string& pattern);

  string ReadIdent(char symbol);
  TokenType GetTokenType(const string& value);
  Token GetAlphanumToken(const string& value, size_t pos);

void AddToken(TokenType type, const string& value, size_t pos);
};
