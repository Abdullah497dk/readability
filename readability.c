#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>




int coleman_alg(int L, int W, int S);


int main(void)
{

    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if ('.' == text[i] || '!' == text[i] || '?' == text[i])
        {
            sentences++;
        }
    }


    int result = coleman_alg(letters, words, sentences);

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



int coleman_alg(int L, int W, int S)
{

    float L_in100 = (float) (L * 100) / W;
    float S_in100 = (float) (S * 100) / W;

    float index = 0.0588 * L_in100 - 0.296 * S_in100 - 15.8;

    int x = round(index);
    return x;

}
