/*# C-Project-Card-Games-
It is a code written in C language .It consists of three card games (Poker ,Teen Patti ,Blackjack)
🃏CRAZY THREE🃏

PROBLEM STATEMENT:
Write a program for a card game. There will be 3 
games (Poker, Teen Patti, BlackJack),an option 
function will decide which game will be played by 
the user. The program will consist of functions for 
all the possible variations and outcomes, the main 
function will just call the option function and will 
show which input is to be taken and their 
respective results.
1. For Poker the user will give input of 5 
Cards(number and colour of card) for two players 
and the program will check which player wins.
2. For Teen Patti user will give input of 3 
Cards(number and colour of cards) for two players 
and the program will check which player wins.
3. For BlackJack to run the game each player will 
alternate get cards. At each turn, the user will 
have to prompted “Hit” (draw a card) “Stand” (stop 
drawing the card) The player has to total the card 
and the highest score should be 21 or below that if 
it exceeds the player “burts” and the player with 
highest score (at or below 21) will win the hand.*/

#include<time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define CARDS 52
int options();
void take_input_P();
int is_onepair_P(int player);
int check_three_P(int x, int y, int z);
int is_twopair_P(int player);
int is_tok_P(int player);
int is_straight_P(int player);
int is_flush_P(int player);
int is_fullhouse_P(int player);
int is_fourofkind_P(int player);
int is_straight_flush_P(int player);
int check_player_P(int player);
int check_winner_P();
int max_P();
void input_TP();
int isTrial_TP(int player);
int pureSequence_TP(int player);
int isSequeunce_TP(int player);
int isColor(int player);
int isPair_TP(int player);
int max_TP();
int checkStatus_TP(int player);
int checkWinner_TP();
int balance;
int pot;
int deck[52];
int sdeck[52];
void play();
void turn();
int hit(int *val);
char *cface(int v);
char *csuit(int v);
int cval(int v);
void bet();
void dealer();
void result();
void initdeck();
void shuffle();
void checkAce(int v1, int v2, int *a1);
void quit();
clrscr();
// H for Hearts, C for Clover, D for Diamond, 
S for Spades
//Jack is 11, Queen is 12, King is 13
struct card
{
char color;
int value;
};
struct card game_card[10];
int options(){
 int opt;
 system("cls");
 printf("\t\t\tWELCOME TO CRAZY 
THREE!!\nWHICH GAME DO YOU WANT TO 
PLAY BUDDY!!\n1. POKER \n2. TEEN PATTI 
\n3. BLACKJACK\nENTER YOUR GAME 
NUMBER:\t");
 scanf("%d",&opt);
 return opt;
}
int main(){
 int whichopt,again;
 cont:
 whichopt=options();
 if(whichopt==1){
 take_input_P();
 if (check_winner_P() == 1){
 printf("Player 1 wins!\n");
 }
 else if(check_winner_P()==2)
 {
 printf("Player 2 wins!\n");
 }
 else{printf("It's a draw!");
 }
 }
 else if(whichopt==2){
 input_TP();
 if(checkWinner_TP()==1){
 printf("YAY!! Player 1 won!!");
 }
 else if(checkWinner_TP()==2){
 printf("YAY!! Player 2 won!!");
 }
 else{
 printf("OK It's a draw!");
 }
 }
 else if(whichopt==3){
 system("cls");
 printf("\t\t\tWelcome to my BlackJack 
Simulator!!\n Below are the basic rules:\nBeat the dealer's hand without going over 
21.\n- Face cards are worth 10, Aces are 
worth 1 or 11, whichever makes a better 
hand.\n- Each player starts with two cards, 
and one of the dealer's cards is hidden until 
the end.\n- Type 'hit' to ask for another card. 
Type 'stand' to hold your total and end your 
turn.\n- If you go over 21 you bust, and the 
dealer wins regardless of his hand.\n- If you 
are dealt 21 from the start (Ace & 10), you got 
a blackjack. If you get a blackjack, you win 
1.5 times the amount of your bet 
automatically, unless the dealer also gets a 
blackjack, in which case it is a push.\nRemember: Type 'hit' to get another card, and 
'stand' to hold. At the beginning of the round, 
type 'bet' followed by the quantity you want to 
bet (i.e. 'bet 50').\n");
 getch();
 system("cls");
 printf("Type 'play' to begin. At any time, 
you may type 'help' to get a list of valid 
commands.\n");
 char input[6];
 scanf("%5s", input);
 while(strcmp(input, "quit") != 0){
 while(strcmp(input, "play") != 0){
 if(strcmp(input, "help") == 0)
 printf("Type 'play' to begin the 
game.\n");
 else if(strcmp(input, "quit")==0){
 quit();
 printf("Enter 'play' to start the 
game.\n");
 }else
 printf("Invalid command, type 
'play' to begin.\n");
 scanf("%s", input);
 }
 play();
 scanf("%5s", input);
 }
 }
 getch();
 system("cls");
 printf("If you want to play again press 1 
else 0:");
 scanf("%d",&again);
 if(again==1){
 goto cont;
 }
 else{
 printf("THANK YOU FOR PLAYING THIS 
GAME\n");
 return 0;
 }
}

/************************/
void take_input_P(){
 system("cls");
 printf("\t\tWELCOME TO POKER\n");
 printf("Every card has a value and a color 
(Spades, Hearts, Clubs, Diamonds).\nThe 
values are ordered as follows from the weaker 
to the stronger: from 2 to 10, then Jack, 
Queen, King, Ace (which is also 1).\nFive 
cards of the hand of a player form a 
combination.\nHere are the various 
combinations, classified in increasing order 
by value:\n");
 printf("1. High card: None of the following 
combinations\n");
 printf("2. One pair: two cards of the same 
value.\n");
 printf("3. Two pairs: two times two cards of 
same value.\n");
 printf("4. Three of a kind: Three cards of 
the same value.\n");
 printf("5. Straight: five cards with values in 
sequence\n");
 printf("6. Flush(color): Five cards of same 
color.\n");
 printf("7. Full house: three of a kind and 
one pair.\n");
 printf("8. Four of a kind: four cards of the 
same value.\n");
 printf("9. Straight Flush: Straight in which 
the cards have the same color.\n");
 printf("If a player has a better combination 
than the other player, he wins.\n");
 getch();
 system("cls");
 printf("Please enter details of cards of 
player 1 for poker:\n");
int i;
for(i=0;i<5;i++){
 scanf("%d %c", &game_card[i].value, 
&game_card[i].color);
}
printf("Please enter details of cards of player 
2 for poker:\n");
for(i=5;i<10;i++){
scanf("%d %c", &game_card[i].value, 
&game_card[i].color);
}
 for(i=0;i<10;i++){
 if(game_card[i].value==1)
 game_card[i].value==14;
 }
}
int is_onepair_P(int player){
if (player == 1){
 int a,b,c,d,e;
 a = game_card[0].value;
 b = game_card[1].value;
 c = game_card[2].value;
 d = game_card[3].value;
 e = game_card[4].value;
 if ( a==b || a==c || a==d || a==e || b==c 
|| b==d || b==e || c==d || c==e || d==e){
 return 1;
 }
 else{
 return 0;
 }
}
else{
 int a,b,c,d,e;
 a = game_card[5].value;
 b = game_card[6].value;
 c = game_card[7].value;
 d = game_card[8].value;
 e = game_card[9].value;
 if ( a==b || a==c || a==d || a==e || b==c 
|| b==d || b==e || c==d || c==e || d==e){
 return 1;
 }
 else{
 return 0;
 }
}
}
int check_three_P(int x, int y, int z){
if (x == y || x == z || y==z){
 return 1;
}
else{
 return 0;
}
}
int is_twopair_P(int player){
if (player == 1){
 int a,b,c,d,e;
 a = game_card[0].value;
 b = game_card[1].value;
 c = game_card[2].value;
 d = game_card[3].value;
 e = game_card[4].value;
 if ( (a==b) && (check_three_P(c,d,e) ==1 ) ){
 return 1;
 }
 else if( (a==c) && (check_three_P(b,d,e) ==1 ) 
){
 return 1;
 }
 else if( (a==d) && (check_three_P(c,b,e) ==1 ) 
){
 return 1;
 }
 else if( (a==e) && (check_three_P(b,c,d) ==1 ) 
){
 return 1;
 }
 else if( (b==c) && (check_three_P(a,d,e) ==1 )
){
 return 1;
 }
 else if( (b==d) && (check_three_P(a,c,e) ==1 ) 
){
 return 1;
 }
 else if( (b==e) && (check_three_P(a,c,d) ==1 ) 
){
 return 1;
 }
 else if( (c==d) && (check_three_P(a,b,e) ==1 ) 
){
 return 1;
 }
 else if( (c==e) && (check_three_P(a,b,d) ==1 ) 
){
 return 1;
 }
 else if( (d==e) && (check_three_P(a,b,c) ==1 ) 
){
 return 1;
 }
 else{
 return 0;
 }
}
else{
 int a,b,c,d,e;
 a = game_card[5].value;
 b = game_card[6].value;
 c = game_card[7].value;
 d = game_card[8].value;
 e = game_card[9].value;
 if ( (a==b) && (check_three_P(c,d,e) ==1 ) ){
 return 1;
 }
 else if( (a==c) && (check_three_P(b,d,e) ==1 ) 
){
 return 1;
 }
 else if( (a==d) && (check_three_P(c,b,e) ==1 ) 
){
 return 1;
 }
 else if( (a==e) && (check_three_P(b,c,d) ==1 ) 
){
 return 1;
 }
 else if( (b==c) && (check_three_P(a,d,e) ==1 ) 
){
 return 1;
 }
 else if( (b==d) && (check_three_P(a,c,e) ==1 ) 
){
 return 1;
 }
 else if( (b==e) && (check_three_P(a,c,d) ==1 ) 
){
 return 1;
 }
 else if( (c==d) && (check_three_P(a,b,e) ==1 ) 
){
 return 1;
 }
 else if( (c==e) && (check_three_P(a,b,d) ==1 ) 
){
 return 1;
 }
 else if( (d==e) && (check_three_P(a,b,c) ==1 ) 
){
 return 1;
 }
 else{
 return 0;
 }
}
}
int is_tok_P(int player){
 if (player == 1){
 int a,b,c,d,e;
 a = game_card[0].value;
 b = game_card[1].value;
 c = game_card[2].value;
 d = game_card[3].value;
 e = game_card[4].value;
 if ( (a==b && b==c) || (a==b && b==d) || 
(a==b && b==e) || (a==c && c==d) || (a==c 
&& c==e) || (a==d && d==e) || (b==c && 
c==d) || (b==c && c==e) || (b==d && d==e) 
||(c==d && d==e))
 {
 return 1;
 }
 else{
 return 0;
 }
}
else{
 int a,b,c,d,e;
 a = game_card[5].value;
 b = game_card[6].value;
 c = game_card[7].value;
 d = game_card[8].value;
 e = game_card[9].value;
 if ( (a==b && b==c) || (a==b && b==d) || 
(a==b && b==e) || (a==c && c==d) || (a==c 
&& c==e) || (a==d && d==e) || (b==c && 
c==d) || (b==c && c==e) || (b==d && d==e) 
||(c==d && d==e)){
 return 1;
 }
 else{
 return 0;
 }
}
}
int is_straight_P(int player){
if (player == 1){
 int a,b,c,d;
 a = game_card[0].value+4;
 b = game_card[1].value+3;
 c = game_card[2].value+2;
 d = game_card[3].value+1;
 if( a==b && b==c && c==d && 
d==game_card[4].value ){
 return 1;
 }
 else{
 return 0;
 }
}
else{
 int a,b,c,d;
 a = game_card[5].value+4;
 b = game_card[6].value+3;
 c = game_card[7].value+2;
 d = game_card[8].value+1;
 if( a==b && b==c && c==d && 
d==game_card[9].value ){
 return 1;
 }
 else{
 return 0;
 }
}
}
int is_flush_P(int player){
if(player == 1){
 int a,b,c,d;
 a = game_card[0].color;
 b = game_card[1].color;
 c = game_card[2].color;
 d = game_card[3].color;
 if( a==b && b==c && c==d && 
d==game_card[4].color ){
 return 1;
 }
 else{
 return 0;
 }
}
else{
 int a,b,c,d;
 a = game_card[5].color;
 b = game_card[6].color;
 c = game_card[7].color;
 d = game_card[8].color;
 if( a==b && b==c && c==d && 
d==game_card[9].color ){
 return 1;
 }
 else{
 return 0;
 }
}
}
int is_fullhouse_P(int player){
if(player == 1){
 if( (is_tok_P(1) == 1) && (is_onepair_P(1)==1) 
){
 return 1;
 }
 else{
 return 0;
 }
}
else{
 if( (is_tok_P(2) == 1) && (is_onepair_P(2)==1) 
){
 return 1;
 }
 else{
 return 0;
 }
}
}
int is_fourofkind_P(int player){
if(player == 1){
 int a,b,c,d,e;
 a = game_card[0].value;
 b = game_card[1].value;
 c = game_card[2].value;
 d = game_card[3].value;
 e = game_card[4].value;
 if ((a==b && b==c && c==d)||(b==c && c==d 
&& d==e)|| (c==d && d==e && e==a) || 
(d==e && e==a && a==b) || (e==a && a==b 
&& b==c)){
 return 1;
 }
 else{
 return 0;
 }
}
else{
 int a,b,c,d,e;
 a = game_card[5].value;
 b = game_card[6].value;
 c = game_card[7].value;
 d = game_card[8].value;
 e = game_card[9].value;
 if ((a==b && b==c && c==d)||(b==c && c==d 
&& d==e)|| (c==d && d==e && e==a) || 
(d==e && e==a && a==b) || (e==a && a==b 
&& b==c)){
 return 1;
 }
 else{
 return 0;
 }
}
}
int is_straight_flush_P(int player){
if(player == 1){
 if ( (is_flush_P(1) == 1)&&(is_straight_P(1) == 
1) ){
 return 1;
 }
 else{
 return 0;
 }
}
else{
 if ( (is_flush_P(2) == 1)&&(is_straight_P(2) == 
1) ){
 return 1;
 }
 else{
 return 0;
 }
}
}
int max_P(){
 for(int i=0;i<10;i++){
 if(game_card[i].value==1)
 game_card[i].value=14;
 }
 int a,b,c,d,e,p,q,r,s,t,min1,min2;
 a=game_card[0].value;
 b=game_card[1].value;
 c=game_card[2].value;
 d=game_card[3].value;
 e=game_card[4].value;
 if(a>b && a>c && a>d && a>e){
 min1 = a;
}else if(b>c && b>d && b>e){
 min1 = b;
}else if(c>d && c>e){
 min1 = c;
}else if(d>e){
 min1 = d;
}else{
 min1 = e;
}
 p=game_card[5].value;
 q=game_card[6].value;
 r=game_card[7].value;
 s=game_card[8].value;
 t=game_card[9].value;
 if(p>q && p>r && p>s && p>t){
 min2 = p;
}else if(q>r && q>s && q>t){
 min2 = q;
}else if(r>s && r>t){
 min2 = r;
}else if(s>t){
 min2 = s;
}else{
 min2 = t;
}
if(min1>min2)
 return 1;
 else if(min2>min1)
 return 2;
 else
 return 0;
}
int check_player_P(int player){
int combi = 1;
if(is_straight_flush_P(player) == 1){
 combi = 9;
}
else if(is_fourofkind_P(player) == 1){
 combi = 8;
}
else if(is_fullhouse_P(player) == 1){
 combi = 7;
}
else if(is_flush_P(player) == 1){
 combi = 6;
}
else if(is_straight_P(player) == 1){
 combi = 5;
}
else if(is_tok_P(player) == 1){
 combi = 4;
}
else if(is_twopair_P(player) == 1){
 combi = 3;
}
else if(is_onepair_P(player) == 1){
 combi = 2;
}
return combi;
}
int check_winner_P(){
if (check_player_P(1)>check_player_P(2)){
 return 1;
}
else if (check_player_P(2)>check_player_P(1)){
 return 2;
}
else{
 if(max_P()==1){
 return 1;
 }
 else if(max_P()==2){
 return 2;
 }
 else{
 return 0;
 }
 }
}
/************************/

void input_TP(){
 system("cls");
 printf("\t\tWELCOME TO TEEN PATTI\n");
 printf("Every card has a value and a color 
(Spades, Hearts, Clubs, Diamonds). The 
values are ordered as follows from the weaker 
to the stronger: from 2 to 10, then Jack, 
Queen, King, Ace (which is also 1).Five cards 
of the hand of a player form a combination. 
Here are the various combinations, classified 
in increasing order by value:\n");
 printf("1. TRIAL : All three cards having 
same numbers.\n");
 printf("2. PURE SEQUENCE : Three 
consecutive cards of the same suit.\n");
 printf("3. SEQUENCE : Three consecutive 
cards not all in the same suit.\n");
 printf("4. COLOR : A flush of 3 cards in the 
same suit, with the highest card winning in 
the case of a draw.\n");
 printf("5. PAIR : A pair of 2 cards of the 
same rank. In case of a draw, the highestranking 3rd card will denote the winner.\n");
 printf("6. HIGH CARD : When neither the 
dealer nor player has a pair, then the hand 
with the highest card wins.\n");
 printf("If a player has a better combination 
than the other player, he wins.\n");
 getch();
 system("cls");
 printf("Enter cards for player one in proper 
sequence:\n");
 for(int i=0;i<3;i++){
 scanf("%d %c", &game_card[i].value, 
&game_card[i].color);;
 }
 printf("Enter cards for player two in proper 
sequence:\n");
 for(int i=3;i<6;i++){
 scanf("%d %c", &game_card[i].value, 
&game_card[i].color);;
 }
}
int isTrial_TP(int player){
 if (player == 1){
 int a,b,c;
 a=game_card[0].value;
 b=game_card[1].value;
 c=game_card[2].value;
 if(a==b && b==c)
 return 1;
 else
 return 0;
 }
 else{
 int a,b,c;
 a=game_card[3].value;
 b=game_card[4].value;
 c=game_card[5].value;
 if(a==b && b==c)
 return 1;
 else
 return 0;
 }
}
int isPair_TP(int player){
 if (player == 1){
 int a,b,c;
 a=game_card[0].value;
 b=game_card[1].value;
 c=game_card[2].value;
 if(a==b || a==c || b==c)
 return 1;
 else
 return 0;
 }
 else{
 int a,b,c;
 a=game_card[3].value;
 b=game_card[4].value;
 c=game_card[5].value;
 if(a==b || a==c || b==c)
 return 1;
 else
 return 0;
 }
}
int isPureSequence_TP(int player){
 if(player==1){
 int a,b,c;
 char d,e,f;
 a=game_card[0].value+2;
 b=game_card[1].value+1;
 c=game_card[2].value;
 d=tolower(game_card[0].color);
 e=tolower(game_card[1].color);
 f=tolower(game_card[2].color);
 if(a==b && b==c && d==e && e==f){
 return 1;
 }
 else
 return 0;
 }
 else{
 int a,b,c;
 char d,e,f;
 a=game_card[3].value+2;
 b=game_card[4].value+1;
 c=game_card[5].value;
 d=tolower(game_card[3].color);
 e=tolower(game_card[4].color);
 f=tolower(game_card[5].color);
 if(a==b && b==c && d==e && e==f)
 return 1;
 else
 return 0;
 }
}
int isSequeunce_TP(int player){
 if (player == 1){
 int a,b,c;
 a=game_card[0].value+2;
 b=game_card[1].value+1;
 c=game_card[2].value;
 if(a==b && b==c)
 return 1;
 else
 return 0;
 }
 else{
 int a,b,c;
 a=game_card[3].value+2;
 b=game_card[4].value+1;
 c=game_card[5].value;
 if(a==b && b==c)
 return 1;
 else
 return 0;
 }
}
int isColor(int player){
 if(player==1){
 char d,e,f;
 d=tolower(game_card[0].color);
 e=tolower(game_card[1].color);
 f=tolower(game_card[2].color);
 if(d==e && e==f)
 return 1;
 else
 return 0;
 }
 else{
 char d,e,f;
 d=tolower(game_card[3].color);
 e=tolower(game_card[4].color);
 f=tolower(game_card[5].color);
 if(d==e && e==f)
 return 1;
 else
 return 0;
 }
}
int max_TP(){
 for(int i=0;i<10;i++){
 if(game_card[i].value==1)
 game_card[i].value=14;
 }
 int a,b,c,d,e,f,maxOf1,maxOf2;
 a=game_card[0].value;
 b=game_card[1].value;
 c=game_card[2].value;
 d=game_card[3].value;
 e=game_card[4].value;
 f=game_card[5].value;
 maxOf1=a>b ? (a>c ?a:c) :(b>c?b:c); 
//ternary operator
 maxOf2=d>e ? (d>f ?d:f) :(e>f?e:f);
 if(maxOf1>maxOf2)
 return 1;
 else if(maxOf2>maxOf1)
 return 2;
 else
 return 0;
}
int checkStatus_TP(int player){
 int variation=1;
 if(isTrial_TP(player)==1)
 variation=6;
 else if(isPureSequence_TP(player)==1)
 variation=5;
 else if(isSequeunce_TP(player)==1)
 variation=4;
 else if(isPair_TP(player)==1)
 variation=3;
 else if(isColor(player)==1)
 variation=2;
 return variation;
}
int checkWinner_TP(){
 if(checkStatus_TP(1)>checkStatus_TP(2)){
 return 1;
 }
 else 
if(checkStatus_TP(1)<checkStatus_TP(2)){
 return 2;
 }
 else{
 if(max_TP()==1){
 return 1;
 }
 else if(max_TP()==2){
 return 2;
 }
 else{
 return 0;
 }
 }
}

/************************/
void play(){
 printf("Lets start you off with 500 
credits.\n");
 balance = 500;
 while(balance>0){
 bet();
 initdeck();
 shuffle();
 turn();
 }
 printf("Sorry, it looks like you lost! Type 
'play' to play another game.\n");
}
void turn(){
 int inc=0;
 int d1 = hit(&inc);
 char *cn1 = csuit(d1);
 char *cf1 = cface(d1);
 int cv1 = cval(d1);
 printf("You got a %s of %s worth %d, and ", 
cf1, cn1, cv1);
 int d2 = hit(&inc);
 char *cn2 = csuit(d2);
 char *cf2 = cface(d2);
 int cv2 = cval(d2);
 printf("a %s of %s worth %d.\n", cf2, cn2, 
cv2);
 int d3 = hit(&inc);
 char *cn3 = csuit(d3);
 char *cf3 = cface(d3);
 int cv3 = cval(d3);
 printf("The dealer's face up card is a %s of 
%s worth %d.\n", cf3, cn3, cv3);
 int d4 = hit(&inc);
 char *cn4 = csuit(d4);
 char *cf4 = cface(d4);
 int cv4 = cval(d4);
 int ptotal = cv1 + cv2;
 int dtotal = cv3;
 checkAce(cv1, cv2, &ptotal);
 printf("You have a total of %d points, and 
the dealer has %d.\n", ptotal, dtotal);
 if(ptotal == 21){
 printf("Congrats! You got a blackjack!! 
Your payout is 2-to-1, %d.\n", (int)(pot*2));
 balance += (pot*2);
 }else{
 char input[6];
 scanf("%5s", input);
 while(strcmp(input,"stand")!=0){
 if(strcmp(input,"hit") == 0){
 int val = hit(&inc);
 char *ns = csuit(val);
 char *nf = cface(val);
 int nv = cval(val);
 ptotal += nv;
 printf("You got a %s of %s worth 
%d.\n", nf, ns, nv);
 if(ptotal < 21){
 if(nv==1){
 if(ptotal+10 == 21){
 ptotal += 10;
 printf("Congrats! You got 
21! Payout is 2-to-1.\n");
 balance += (pot*2);
 break;
 }else{
 int input;
 printf("You've got an ace. 
Choose whether you want to make it count as 
1 or 11.\n");
 scanf("%d",&input);
 if(input == 11)
 ptotal += 10;
 }
 }
 }else if(ptotal == 21){
 printf("Congrats! You got 
21!\n");
 break;
 }else{
 printf("Oh no, you've busted 
with %d. Try Again!\n", ptotal);
 break;
 }
 }else if(strcmp(input,"help")==0)
 printf("Type 'hit' to be dealt another 
card. Type 'stand' to hold.\n");
 else if(strcmp(input, "quit")==0){
 quit();
 printf("Enter 'hit' or 'stand'.\n");
 }else
 printf("Invalid command, try 
again.\n");
 printf("Your new total is %d.\n", 
ptotal);
 scanf("%5s", input);
 }
 }
 if(ptotal < 21){
 printf("The dealer's flips a %s of %s 
worth %d.\n", cf4, cn4, cv4);
 dtotal += cv4;
 if(cv4 == 1){
 if(dtotal+11 < 21)
 dtotal += 10;
 }
 if(dtotal >= 16){
 printf("The dealer stands with %d.\n", 
dtotal);
 }
 while(dtotal < 16){
 int val = hit(&inc);
 char *ns = csuit(val);
 char *nf = cface(val);
 int nv = cval(val);
 dtotal += nv;
 printf("The dealer got a %s of %s 
worth %d.\n", nf, ns, nv);
 if(dtotal < 16){
 if(nv==1){
 if(dtotal+11<21)
 dtotal += 10;
 }
 }else if(dtotal == 21){
 printf("The dealer just got 21.\n");
 break;
 }else if(dtotal > 21){
 printf("The dealer busted with %d! 
You win!\n", dtotal);
 break;
 }else{
 printf("The dealer stands with 
%d.\n", dtotal);
 break;
 }
 printf("The dealer's new total is 
%d.\n", dtotal);
 }
 if(dtotal<ptotal){
 printf("You beat the dealer! Your 
payout is %d.\n", (int)(pot*1.5));
 balance += (pot*1.5);
 }else if(dtotal==ptotal){
 printf("Its a tie! Push pot, 1-to-1 
payout of %d.\n", pot);
 balance += pot;
 }else if(dtotal>ptotal && dtotal <= 21){
 printf("Oh no! Looks like the dealer 
won. Try again!\n");
 }else{
 printf("You beat the dealer! Your 
payout is %d.\n", (int)(pot*1.5));
 balance += (pot*1.5);
 }
 }
 if(balance > 0)
 printf("Your new balance is %d.\n", 
balance);
}
void checkAce(int v1, int v2, int *a1){
 if(v1 == 1 || v2 == 1){
 int input;
 if(v1 == 1 && v2 == 1){
 v1 = 11;
 v2 = 1;
 *a1 = 12;
 printf("Since you got 2 Aces, we set 
one to be worth 11 and the other to be worth 
1.\n");
 }else if(v1 == 1 || v2 == 1){
 if(v1+10+v2 == 21)
 *a1 == 21;
 else{
 printf("You've got an ace. Choose 
whether you want to make it count as 1 or 
11.\n");
 scanf("%d",&input);
 if(input == 11)
 *a1 += 10;
 }
 }
 }
}
int cval(int v){
 int a;
 if(((v%13)+1)<10)
 a = v%13+1;
 else
 a = 10;
 return a;
}
char *csuit(int v){
 v = v%4;
 switch(v){
 case 0 :
 return "Hearts";
 case 1 :
 return "Clubs";
 case 2 :
 return "Diamonds";
 case 3 :
 return "Spades";
 }
}
char *cface(int v){
 v = v%13+1;
 char *output;
 switch(v){
 case 1 :
 output = "Ace";
 break;
 case 2 :
 output = "Two";
 break;
 case 3 :
 output = "Three";
 break;
 case 4 :
 output = "Four";
 break;
 case 5 :
 output = "Five";
 break;
 case 6 :
 output = "Six";
 break;
 case 7 :
 output = "Seven";
 break;
 case 8 :
 output = "Eight";
 break;
 case 9 :
 output = "Nine";
 break;
 case 10 :
 output = "Ten";
 break;
 case 11 :
 output = "Jack";
 break;
 case 12 :
 output = "Queen";
 break;
 case 13 :
 output = "King";
 }
 return output;
}
void quit(){
 int again;
 printf("Are you sure you want to quit? Type 
'y' or 'n'.\n");
 char input[6];
 scanf("%s",input);
 if(strcmp(input,"y")==0)
 {
 printf("THANK YOU FOR PLAYING THIS 
GAME\n");
 getch();
 system("cls");
 printf("If you want to play again press 1 
else 0:");
 scanf("%d",&again);
 if(again==1){
 main();
 }
 else
 {exit(0);}
}
}
int hit(int *i){
 int a = sdeck[*i];
 *i = *i + 1;
 return a;
}
void bet(){
 char input[6];
 int val;
 printf("Enter an amount you would like to 
bet.\n");
 scanf("%5s", input);
 while(strcmp(input, "bet") != 0){
 if(strcmp(input,"help") == 0)
 printf("Type 'bet' followed by a bet 
amount. For example, you could type 'bet 
50'.\n");
 else if(strcmp(input,"quit")==0){
 quit();
 printf("Enter a bet amount.\n");
 }else
 printf("You've entered an invalid 
command. Type 'help' for a list of valid 
commands.\n");
 scanf("%5s", input);
 }
 scanf("%d", &val);
 while(val > balance || (val < 10 && val > 
0) || val <=0){
 if(val > balance)
 printf("You cannot bet more than your 
balance. Your balance is: %d.\n", balance);
 else if(val <= 0)
 printf("You must make a bet. Enter a 
valid bet amount.\n");
 else
 printf("Invalid entry. Try again.\n");
 scanf("%d", &val);
 }
 balance -= val;
 printf("You've made a bet of %d. Good 
luck!\n", val);
 pot = val;
}
void initdeck(){
 int i=0;
 for(i;i<52;i++){
 deck[i] = i+1;
 }
}
void shuffle(){
 srand(time(NULL));
 int i=0;
 for(i;i<52;i++){
 sdeck[i] = deck[i];
 }
 i=0;
 for(i=CARDS-1;i>0;i--){
 int j = rand()%(i+1);
 int n = sdeck[i];
 sdeck[i] = sdeck[j];
 sdeck[j] = n;
 }
}

 
