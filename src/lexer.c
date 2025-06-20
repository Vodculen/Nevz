#include "include/lexer.h"

/**
 * @param source (char pointer) the token which is going to be lexed and identified as a token type
 * 
 * @returns The lexer with the given token parameters defined
 */
LEXER* new_lexer(char* source)
{
	LEXER* lexer = malloc(sizeof(LEXER));

	// Finding size and what the file is
	lexer -> src = source;
	lexer -> src_size = strlen(source);

	// Positioning logic in the the file
	lexer -> index = 0;
	lexer -> current = source[lexer -> index];

	// This tracks the line which the lexer's on
	lexer -> line = 1;

	return lexer;
}

/**
 * @param lexer The lexer with the file's contents
 */
void consume(LEXER* lexer)
{
	// Checks if we will go over the EOF so we don't have a memory leak
	if (lexer -> index < lexer -> src_size && !eof(lexer -> current))
	{
		// Incrementing the index by one and then setting the current character to that new position
		lexer -> index += 1;
		lexer -> current = lexer -> src[lexer -> index];
	}
}

void whitespace(LEXER* lexer)
{
	// Just seeing if the current character is a tab, space, or newline so its ignored as the langauge doesnt care for whitespaces
	while (check_symbol(lexer -> current, '\t') || check_symbol(lexer -> current, '\n') || check_symbol(lexer -> current, ' '))
	{
		// If it is a newline we want the language to know that the next tokens are on a newline
		if (check_symbol(lexer -> current, '\n'))
		{
			lexer -> line += 1;
		}

		consume(lexer);
	}
	
}


/**
 * @param lexer The file you want to peek ahead in
 * @param amount How far ahead you want to peek
 * 
 * @return The character either at how far the program peeked or the last character that it can peek
 */
char peek(LEXER* lexer, int amount) 
{
	return lexer -> src[min(lexer -> current + amount, lexer -> src_size)];
}

/**
 * @param lexer The file that the specific token type is being read from
 * @param type The type of the inputted token (It's an enum so we index it by int)
 * 
 * @returns The token so that it can be used for other stuff
 */
TOKEN* consume_type(LEXER* lexer, int type)
{
	// Allocate enough memory for the token's value and a null terminator and set value[0] to the current character
	char* value = calloc(2, sizeof(char));
	value[0] = lexer -> current;
	value[1] = '\0';

	// We give the token the value as well as the type based of the enum the consume it
	TOKEN* token = new(value, type);
	consume(lexer);

	return token;
}

TOKEN* identifer(LEXER* lexer)
{
	char* value = calloc(1, sizeof(char));

	while (isalnum(lexer -> current))
	{
		value = realloc(value, (strlen(value + 2) * sizeof(char)));
		strcat(value, (char[]) { lexer -> current, 0 });

		consume(lexer);
	}

	if (strcmp(value, "return") == 0) {
		return new(value, TOKEN_RETURN);
	}

	return new(value, TOKEN_IDENTIFIER);
}

TOKEN* numbers(LEXER* lexer)
{
	char* value = calloc(1, sizeof(char));

	while (isdigit(lexer -> current))
	{
		value = realloc(value, (strlen(value + 2) * sizeof(char)));
		strcat(value, (char[]) { lexer -> current, 0 });

		consume(lexer);
	}

	return new(value, TOKEN_INTEGER_LITERAL);
}


TOKEN* lex(LEXER* lexer)
{
	while (!eof(lexer -> current))
	{
		whitespace(lexer);

		if (isdigit(lexer -> current))
		{
			return numbers(lexer);
		}
		if (isalpha(lexer -> current))
		{
			return identifer(lexer);
		}

		switch (lexer -> current)
		{
			case ';': return consume_type(lexer, TOKEN_SEMICOLON);
			case '\0': break;
			
			default: {
				printf("[Lexer]: Found an unexpected character \"%c\"\n", lexer -> current);
				exit(1);
				break;
			}
				
		}
	}

	return new(0, TOKEN_EOF);
}

/**
 * @param character The character that is being checked if it is at the end
 * 
 * @returns 1 if it isnt at the end, 0 if it is at the end
 */
int eof(char character)
{	
	// This just checks if the lexer is at the end of the file
	if (character == '\0')
	{
		return 0;
	}

	return 1;
}

/**
 * @param character The character that is being checked if it is simmilar to the symbol
 * @param symbol The symbol that is what the character should be simmilar tolower
 * 
 * @returns 1 if the two don't match, o if the do match
 */
int check_symbol(char character, char symbol)
{
	if (character == symbol)
	{
		return 0;
	}

	return 1;
}