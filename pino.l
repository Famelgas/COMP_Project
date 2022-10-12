%{

int col = 1, line=1; 
bool strflag = true; 
bool printLex = true; //para o lex
int saveLine = 1, saveCol = 1; //para comentarios
char * str;

%}

%X COMMENTLINE COMMENT STRLIT

ID          ([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*

INTLIT		0|[1-9]+("_"*[0-9]|[0-9]*)*

REALLIT     (((("_"*)?[0-9]+)+"."?(("_"*)?[0-9]+)*)|((("_"*)?[0-9]+)*"."?(("_"*)?[0-9]+)+))[eE][+-]?(("_"*)?[0-9]+)+|(("_"*)?[0-9]+)*"."(("_"*)?[0-9]+)+|(("_"*)?[0-9]+)+"."(("_"*)?[0-9]+)*

CHAR        [^\r\n\"\\]
ESCAPE      \\t|\\n|\\f|\\r|\\\"|\\\\
ESPACE      \t|" "
NEWLINE     \r\n|\n|\r

RESERVED   "--"|"++"|"Integer"|"System"|"null"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"
            
%%

\"                             {str=yytext; saveLine =  line; saveCol = col; col += yyleng; strflag = true;  BEGIN STRLIT;}
<STRLIT>{NEWLINE}              {col=1; printf("Line %d, col %d: unterminated string literal\n",  line, saveCol); line++; col = 1;  BEGIN 0;}
<STRLIT>({CHAR}|{ESCAPE})*     {col += yyleng;}
<STRLIT>\\{NEWLINE}            {printf("Line %d, col %d: invalid escape sequence (\\)\nLine %d, col %d: unterminated string literal\n", line, col, line, saveCol); col = 1; line++; strflag = false; BEGIN 0;}
<STRLIT>\\                     {printf("Line %d, col %d: invalid escape sequence (\\)\n", line, col); col += yyleng; strflag = false; }

<STRLIT>\\.                    {printf("Line %d, col %d: invalid escape sequence (%s)\n",  line, col, yytext); col += yyleng; strflag = false; }
<STRLIT>\"                     {col += yyleng; if (strflag && printLex) {printf("STRLIT(%s)\n", str); strflag = true; } BEGIN 0;}
<STRLIT><<EOF>>                {printf("Line %d, col %d: unterminated string literal\n",  line, saveCol); exit(0);}


"//"                    {BEGIN COMMENTLINE;}
<COMMENTLINE>{NEWLINE}  {line++; col = 1; BEGIN 0; }
<COMMENTLINE>.          {col += yyleng;}


"/*"               {saveLine =  line; saveCol = col; col += yyleng; BEGIN COMMENT;}
<COMMENT><<EOF>>   {printf("Line %d, col %d: unterminated comment\n", saveLine, saveCol); exit(0);}
<COMMENT>"*/"      {col += yyleng; saveLine = 1; saveCol = 1; BEGIN 0;}
<COMMENT>{NEWLINE} {line++; col = 1;}
<COMMENT>.         {col += yyleng;}

"false"                 {if (printLex) printf("BOOLLIT(false)\n"); col += yyleng; }
"true"                  {if (printLex) printf("BOOLLIT(true)\n"); col += yyleng; }
"&&"       	            {if (printLex) printf("AND\n"); col += yyleng; }
"="         	        {if (printLex) printf("ASSIGN\n"); col += yyleng; }
"*"         	        {if (printLex) printf("STAR\n"); col += yyleng; }
","         	        {if (printLex) printf("COMMA\n"); col += yyleng; }
"/"         	        {if (printLex) printf("DIV\n"); col += yyleng; }
"=="        	        {if (printLex) printf("EQ\n"); col += yyleng; }
">="      	            {if (printLex) printf("GE\n"); col += yyleng; }
">"         	        {if (printLex) printf("GT\n"); col += yyleng; }
"{"         	        {if (printLex) printf("LBRACE\n"); col += yyleng; }
"<="        	        {if (printLex) printf("LE\n"); col += yyleng; }
"("        	            {if (printLex) printf("LPAR\n"); col += yyleng; }
"["         	        {if (printLex) printf("LSQ\n"); col += yyleng; }
"<"         	        {if (printLex) printf("LT\n"); col += yyleng; }
"-"         	        {if (printLex) printf("MINUS\n"); col += yyleng; }
"%"         	        {if (printLex) printf("MOD\n"); col += yyleng; }
"!="        	        {if (printLex) printf("NE\n"); col += yyleng; }
"!"         	        {if (printLex) printf("NOT\n"); col += yyleng; }
"||"       	            {if (printLex) printf("OR\n"); col += yyleng; }
"+"         	        {if (printLex) printf("PLUS\n"); col += yyleng; }
"}"         	        {if (printLex) printf("RBRACE\n"); col += yyleng; }
")"         	        {if (printLex) printf("RPAR\n"); col += yyleng; }
"]"         	        {if (printLex) printf("RSQ\n"); col += yyleng; }
";"         	        {if (printLex) printf("SEMICOLON\n"); col += yyleng; }
"->"                    {if (printLex) printf("ARROW\n"); col += yyleng; }
"<<"                    {if (printLex) printf("LSHIFT\n"); col += yyleng; }
">>"                    {if (printLex) printf("RSHIFT\n"); col += yyleng; }
"^"                     {if (printLex) printf("XOR\n"); col += yyleng; }
"boolean"               {if (printLex) printf("BOOL\n"); col += yyleng; }
"class"                 {if (printLex) printf("CLASS\n"); col += yyleng; }
".length"               {if (printLex) printf("DOTLENGTH\n"); col += yyleng; }
"double"                {if (printLex) printf("DOUBLE\n"); col += yyleng; }
"else"                  {if (printLex) printf("ELSE\n"); col += yyleng; }
"if"                    {if (printLex) printf("IF\n"); col += yyleng; }
"int"                   {if (printLex) printf("INT\n"); col += yyleng; }
"System.out.print"      {if (printLex) printf("PRINT\n"); col += yyleng; }
"Integer.parseInt"      {if (printLex) printf("PARSEINT\n"); col += yyleng; }
"public"                {if (printLex) printf("PUBLIC\n"); col += yyleng; }
"return"                {if (printLex) printf("RETURN\n"); col += yyleng; }
"static"                {if (printLex) printf("STATIC\n"); col += yyleng; }
"String"                {if (printLex) printf("STRING\n"); col += yyleng; }
"void"                  {if (printLex) printf("VOID\n"); col += yyleng; }
"while"                 {if (printLex) printf("WHILE\n"); col += yyleng; }


{RESERVED}		    {if (printLex) printf("RESERVED(%s)\n", yytext); col += yyleng; }
{ESPACE}            {col += yyleng;}
"\f"                {col += yyleng;}
{NEWLINE}           {line++; col = 1;}

{ID}		        {if (printLex) printf("ID(%s)\n", yytext); col += yyleng; }

{INTLIT}	        {if (printLex) printf("INTLIT(%s)\n", yytext); col += yyleng; }
{REALLIT}	        {if (printLex) printf("REALLIT(%s)\n", yytext); col += yyleng; }

.                   {printf("Line %d, col %d: illegal character (%s)\n", line, col, yytext); col += yyleng; }
<<EOF>>             {col = 1; exit(0);}


%%

int main(int argc, char **argv){

    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-l") == 0){
            printLex = true;
        }
        if (strcmp(argv[i], "-e1") == 0){
            printLex = false;
        }
    }
    yylex();
    return 0;
}

int yywrap(){

    return 1; 
}