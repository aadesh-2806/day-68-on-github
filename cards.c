#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define VALUE_ACE 14
#define VALUE_KING 13
#define VALUE_QUEEN 12
#define VALUE_JACK 11
typedef enum 
{
	SPADES,
	HEARTS,
	DIAMONDS,
	CLUBS,
	NUM_SUITS
} suit_t;

struct card_tag 
{
	unsigned value;
	suit_t suit;
};
typedef struct card_tag card_t;
typedef enum 
{
	STRAIGHT_FLUSH,
	FOUR_OF_A_KIND,
	FULL_HOUSE,
	FLUSH,
	STRAIGHT,
	THREE_OF_A_KIND,
	TWO_PAIR,
	PAIR,
	NOTHING
} hand_ranking_t;
void assert_card_valid(card_t c)
{
	assert(c.value>=2 && c.value<=14 &&( c.suit==SPADES || c.suit==CLUBS || c.suit==HEARTS || c.suit==DIAMONDS ));
}

const char * ranking_to_string(hand_ranking_t r)
{
	switch(r)
	{
	   case 1:
	        return (const char*)'1';
	   case 2:
	        return (const char*)'2';
	   case 3:
	        return (const char*)'3';
	   case 4:
	        return (const char*)'4';
	   case 5:
	        return (const char*)'5';
	   case 6:
	        return (const char*)'6';
	   case 7:
	        return (const char*)'7';
	   case 8:
	        return (const char*)'8';
	   case 9:
	        return (const char*)'9';
	}
return (const char*)'?';
}

char value_letter(card_t c)
{
	char x;
	if(c.value>=2 && c.value<=9)
	x='0'+c.value;
	if(c.value==10)
	x='0';
	if(c.value==11)
	x='J';
	if(c.value==12)
	x='Q';
	if(c.value==13)
	x='K';
	  if(c.value==14)
	x='A';
	if(c.value<2 || c.value>14)
	x='?';
	return x;
}

char suit_letter(card_t c)
{
	char x;
	switch(c.suit)
	{
	 case 'c': return 'c';
	 case 's': return 's';
	 case 'd': return 'd';
	 case 'h': return 'h';
	 default: return '?';
	}
	x='?';
	return x;
}

void print_card(card_t c)
{
	printf("%c%c",c.value,c.suit);
}

card_t card_from_letters(int value_let, char suit_let)
{
	card_t temp;
	temp.value=value_let;
	temp.suit=suit_let;
	assert_card_valid(temp);
	temp.value=value_letter(temp);
	temp.suit=suit_letter(temp);
  return temp;
}

card_t card_from_num(unsigned c)
{
	card_t temp;
	int t;
	if(c>=0 && c<52)
	{
	t=c/13;
	if(t==0)
	  temp.suit='s';
	if(t==1)
	  temp.suit='h';
	if(t==2)
	  temp.suit='d';
	if(t==3)
	  temp.suit='c';
	t=c%13;
	if(t>=3 && t<=11)
	  temp.value=13-t;
	if(t==0)
	  temp.value=13;
	if(t==1)
	  temp.value=12;
	if(t==2)
	  temp.value=11;
	if(t==12)
	  temp.value=14;
	}
	//printf("%c",temp.suit);
	return temp;
}


int main(void)
{
	int n;
	card_t i;
	hand_ranking_t r;
	char t;
	printf("enter card no");
	scanf("%d",&n);
	i=card_from_num(n);
	i=card_from_letters(i.value,i.suit);
	t = ranking_to_string(r);
	print_card(i);
	return 0;
}
