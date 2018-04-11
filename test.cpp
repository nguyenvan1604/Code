#include <stdio.h>
#include <string.h>
enum {MAX_WORD_LEN = 20};
enum {MAX_LINE_LEN = 50};

int IsWhitespace(int ch)
{
    return (ch == ' ') || (ch == '\n') || (ch == '\t');
}

int ReadWord(char *word)
{
    int ch, pos = 0;
    ch = getchar();
    while (IsWhitespace(ch))
        ch = getchar();
    while (!IsWhitespace(ch) && (ch != EOF))
        {
            if (pos < MAX_WORD_LEN)
            {
                word[pos] = (char)ch;
                pos++;
            }
            ch = getchar();
        }
    word[pos] = '\0';
    return pos;
}

void ClearLine(char *line, int *lineLen, int *numWords)
{
    line[0] = '\0';
    *lineLen = 0;
    *numWords = 0;
}
void AddWord(const char *word, char *line, int *lineLen)
{
    if (*lineLen > 0)
    {
        line[*lineLen] = ' ';
        line[*lineLen + 1] = '\0';
        (*lineLen)++;
    }
    strcat(line, word);
    (*lineLen) += strlen(word);
}

void WriteLine(const char *line, int lineLen, int numWords)
{
    int extraSpaces, spacesToInsert, i, j;
    extraSpaces = MAX_LINE_LEN - lineLen;
    for (;;)
    {
        if (line[i] != ' ')
            putchar(line[i]);
        else
        {
            spacesToInsert = extraSpaces / (numWords - 1);
            for (j = 1; j <= spacesToInsert + 1; j++)
                putchar(' ');
            extraSpaces -= spacesToInsert;
            numWords--;
        }
    }
    putchar('\n');
}

int main(void)
{
    char word[MAX_WORD_LEN + 1];
    int wordLen;
    char line[MAX_LINE_LEN + 1];
    int lineLen = 0;
    int numWords = 0;
    ClearLine(line, &lineLen, &numWords);
    for (;;)
    {
        wordLen = ReadWord(word);
        if ((wordLen == 0) && (lineLen > 0))
        {
            puts(line);
            break;
        }
        if ((wordLen + 1 + lineLen) > MAX_LINE_LEN)
        {
            WriteLine(line, lineLen, numWords);
        ClearLine(line, &lineLen, &numWords);
        }
        AddWord(word, line, &lineLen);
        numWords++;
    }
    return 0;
}
