#include <stdio.h>
#include <string.h>

enum
{
  ZERO = 0,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  ELEVEN,
  TWELVE,
  THIRTEEN,
  FOURTEEN,
  FIFTEEN,
  SIXTEEN,
  SEVENTEEN,
  EIGHTEEN,
  NINETEEN
} Number;

enum
{
  TWENTY = 2,
  THIRTY,
  FORTY,
  FIFTY,
  SIXTY,
  SEVENTY,
  EIGHTY,
  NINETY
} Prefix;

char* dictionary[20];
char* prefix[10];

void buildDictionary()
{
  dictionary[ZERO] = "zero";
  dictionary[ONE] = "one";
  dictionary[TWO] = "two";
  dictionary[THREE] = "three";
  dictionary[FOUR] = "four";
  dictionary[FIVE] = "five";
  dictionary[SIX] = "six";
  dictionary[SEVEN] = "seven";
  dictionary[EIGHT] = "eight";
  dictionary[NINE] = "nine";
  dictionary[TEN] = "ten";
  dictionary[ELEVEN] = "eleven";
  dictionary[TWELVE] = "twelve";
  dictionary[THIRTEEN] = "thirteen";
  dictionary[FOURTEEN] = "fourteen";
  dictionary[FIFTEEN] = "fifteen";
  dictionary[SIXTEEN] = "sixteen";
  dictionary[SEVENTEEN] = "seventeen";
  dictionary[EIGHTEEN] = "eighteen";
  dictionary[NINETEEN] = "nineteen";
}

void buildPrefix()
{
  prefix[TWENTY] = "twenty";
  prefix[THIRTY] = "thirty";
  prefix[FORTY] = "forty";
  prefix[FIFTY] = "fifty";
  prefix[SIXTY] = "sixty";
  prefix[SEVENTY] = "seventy";
  prefix[EIGHTY] = "eighty";
  prefix[NINETY] = "ninety";
}

#define CACHE_SIZE 512

char cache[CACHE_SIZE];

int translate(int value)
{
  memset(cache, '\0', CACHE_SIZE);

  int offset = 0;
  int thousandDigit = value / 1000;
  int leftNumber = value - thousandDigit * 1000;

  int hundredDigit =  leftNumber / 100;
  leftNumber -= hundredDigit * 100;

  int tenDigit = leftNumber / 10;
  leftNumber -= tenDigit * 10;

  int unitDigit = leftNumber;
  //  printf("thousand %d, hundred %d, ten %d, unit %d.\n", thousandDigit, hundredDigit, tenDigit, unitDigit);
  if(thousandDigit > 0)
  {
    offset += sprintf(cache, "%s thousand", dictionary[thousandDigit]);
  }

  if(hundredDigit > 0)
  {
    offset += sprintf(cache + offset, "%s%s hundred", thousandDigit > 0 ? " " : "", dictionary[hundredDigit]);
  }

  if((thousandDigit > 0 || hundredDigit > 0) && (tenDigit > 0 || unitDigit > 0))
  {
    offset += sprintf(cache + offset, "%s", " and ");
  }

  if(tenDigit > 0 || unitDigit > 0)
  {
    int lowerValue = tenDigit * 10 + unitDigit;
    if(lowerValue <= 19)
    {
      offset += sprintf(cache + offset, "%s", dictionary[lowerValue]);
    }
    else
    {
      if(tenDigit > 0)
      {
	offset += sprintf(cache + offset, "%s%s", prefix[tenDigit], unitDigit > 0 ? " " : "");
      }

      if(unitDigit > 0)
      {
	offset += sprintf(cache + offset, "%s", dictionary[unitDigit]);
      }
    }
  }

  return offset;
}

int countLettersInWord(char* c)
{
  int count;
  while(*c != '\0')
  {
    if(*c != ' ')
    {
      count++;
    }
    c++;
  }

  return count;
}

int main(int argc, char** args)
{
  buildDictionary();
  buildPrefix();
  
  int value = atoi(args[1]);
  translate(value);
  printf("%d translted into %s, length %d.\n", value, cache, countLettersInWord(cache));
  
  value = atoi(args[2]);
  translate(value);
  printf("%d translted into %s, length %d.\n", value, cache, countLettersInWord(cache));

  int count = 0;
  int i=1;
  for(; i <= 1000; i++)
  {
    translate(i);
    count +=  countLettersInWord(cache);    
  }

  printf("Number of letters %d.\n", count);
  return 0;
}
