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


    printf("%i", letters);


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

    for (int i = 0 n = strlen(text); i < n; i++)
    {
        text[1]
    }

    return 0;

}


int S_in100(string text)
{


    return 0;

}


int coleman_alg(int L, int S)
{

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int x = round(index);
    return x;

}
