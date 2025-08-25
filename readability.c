#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int L_in100(string text);
int S_in100(string text);
int coleman_alg(int L, int S);


int main(void)
{

    string text = get_string("Text: ");


    int letters = L_in100(text);
    int sentences = S_in100(text);


    int result = coleman_alg(letters, sentences);

    if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }

}


int L_in100(string text)
{

    int letter = 0;
    int sum_word = 1;



    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isalpha(text[i]))
        {
            letter++;
        }
        else if (isspace(text[i]))
        {
            sum_word++;
        }

    }

    int L = (letter * 100) / sum_word;

    return L;

}


int S_in100(string text)
{

    int end_count = 0;
    int sum_word = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if ('.' == text[i])
        {
            end_count++;
        }
        else if ('!' == text[i])
        {
            end_count++;
        }
        else if ('?' == text[i])
        {
            end_count++;
        }
        else if (isspace(text[i]))
        {
            sum_word++;
        }

    }

    int S = end_count * 100 /sum_word;


    return S;

}


int coleman_alg(int L, int S)
{

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int x = round(index);
    return x;

}
