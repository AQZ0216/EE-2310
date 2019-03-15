#include <stdio.h>
#include <stdlib.h>

int own_data[5][14];  //set a data table to store cards, the rows are S,H,D,C,total, and the columns are A(1)~K and A(14)
int player_pattern[10];  //set an array to store every player's pattern
char best_pattern[10][10];  //set an array to store every player's card

int suit_to_int(char suit)  //convert S,H,D,C to 0~4 respectively
{
    char suit_sequence[4] = {'S', 'H', 'D', 'C'};  //set an array of suits
    for(int i = 0; i < 4; i++)
    {
        if(suit_sequence[i] == suit)
        {
            return i;  //return 0~4
        }
    }
}

int number_to_int(char number)  //convert 2~K to 1~12, and A to 13
{
    char number_sequence[14] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K','A'};  //set an array of numbers
    for(int i = 1; i < 14; i++)
    {
        if(number_sequence[i] == number)
        {
            return i;  //return 1~13
        }
    }
}

char int_to_suit(int suit)  //convert 0~4 to S,H,D,C respectively
{
    char suit_sequence[4] = {'S', 'H', 'D', 'C'};  //set an array of suits
    return suit_sequence[suit];  //return S,H,D,C
}

char int_to_number(int number)  //convert 1~12 to 2~K, and 13 to A
{
    char number_sequence[14] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K','A'};  //set an array of numbers
    return number_sequence[number];  //return A~K
}

int straight_flush(int n)  //determine whether the player's pattern is Straight Flush
{
    for(int i = 13; i > 3; i--)  //check every data in first four row of the table
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 5; k++)  //check every five consecutive data in a row
            {
                if(own_data[j][i-k] == 0)  //if any of the data = 0, break
                {
                    break;
                }
                best_pattern[n][2*k] = int_to_suit(j);  //store the suit
                best_pattern[n][2*k+1] = int_to_number(i-k);  //store the number
                if(k == 4)  //if all of the data = 1
                {
                    player_pattern[n] = 1;  //set player pattern to 1
                    return 1;  //if the player pattern is Straight Flush, return 1
                }
            }
        }
    }
    return 0;  //if the player pattern isn't Straight Flush, return 0
}

int quads(int n)  //determine whether the player's pattern is Quads
{
    for(int i = 13; i > 0; i--)  //check every data in last row of the table
    {
        if(own_data[4][i] == 4)  //if there is data = 4
        {
            for(int j = 0 ; j < 4; j++)  //store four suits of the number
            {
                best_pattern[n][2*j] = int_to_suit(j);  //store the suit
                best_pattern[n][2*j+1] = int_to_number(i);  //store the number
            }
            for(int j = 13; j > 0; j--)  //find the last card of the pattern
            {
                if(j == i)  //skip the number of former card
                {
                    continue;
                }
                for(int k = 0; k < 4; k++)
                {
                    if(own_data[k][j] == 1)
                    {
                        best_pattern[n][8] = int_to_suit(k);  //store the suit
                        best_pattern[n][9] = int_to_number(j);  //store the number
                        player_pattern[n] = 2;  //set player pattern to 1
                        return 1;  //if the player pattern is Quads, return 1
                    }
                }
            }

        }
    }
    return 0;  //if the player pattern isn't Quads, return 0
}

int full_house(int n)  //determine whether the player's pattern is Full House
{
    for(int i = 13; i > 0; i--)  //check every data in last row of the table
    {
        if(own_data[4][i] == 3)  //if there is data = 3
        {
            for(int j = 0, counter = 0; j < 4; j++)  //store the trips
            {
                if(own_data[j][i] == 1)
                {
                    best_pattern[n][2*counter] = int_to_suit(j);  //store the suit
                    best_pattern[n][2*counter+1] = int_to_number(i);  //store the number
                    counter++;
                }
            }
            for(int j = 13; j > 0; j--)  //find the pair of the pattern
            {
                if(j == i)  //skip the number of former card
                {
                    continue;
                }
                if(own_data[4][j] >= 2)  //if the data of last row >=2
                {
                    for(int k = 0, counter = 3; k < 4; k++)  //store the pair
                    {
                        if(own_data[k][j] == 1)
                        {
                            best_pattern[n][2*counter] = int_to_suit(k);  //store the suit
                            best_pattern[n][2*counter+1] = int_to_number(j);  //store the number
                            counter++;
                        }
                    }
                    player_pattern[n] = 3;  //set player pattern to 1
                    return 1;  //if the player pattern is Full House, return 1
                }
            }
        }
    }
    return 0;  //if the player pattern isn't Full House, return 0
}

int flush(int n)  //determine whether the player's pattern is Flush
{
    for(int i = 0; i < 4; i++)  //check every data in first four row of the table
    {
        for(int j = 13, counter = 0; j > 0; j--)
        {
            if(own_data[i][j] == 1)
            {
                best_pattern[n][2*counter] = int_to_suit(i);  //store the suit
                best_pattern[n][2*counter+1] = int_to_number(j);  //store the number
                counter++;
            }
            if(counter == 5)  //if there is five cards in a suit
            {
                player_pattern[n] = 4;  //set player pattern to 1
                return 1;  //if the player pattern is Flush, return 1
            }
        }
    }
    return 0;  //if the player pattern isn't Flush, return 0
}

int straight(int n)  //determine whether the player's pattern is Straight
{
    for(int i = 13; i > 3; i--)  //check every data in last row of the table
    {
        for(int j = 0; j < 5; j++)  //check every five consecutive data in the last row
        {
            if(own_data[4][i-j] == 0)  //if any of the data = 0, break
            {
                break;
            }
            for(int k = 0; k < 4; k++)  //if there is data = 1, store the card
            {
                if(own_data[k][i-j] == 1)
                {
                    best_pattern[n][2*j] = int_to_suit(k);  //store the suit
                    best_pattern[n][2*j+1] = int_to_number(i-j);  //store the number
                    break;
                }
            }
            if(j == 4)  //if all of the data = 1
            {
                player_pattern[n] = 5;  //set player pattern to 1
                return 1;  //if the player pattern is Straight, return 1
            }

        }
    }
    return 0;  //if the player pattern isn't Straight, return 0
}

int trips(int n)  //determine whether the player's pattern is Trips
{
    for(int i = 13; i > 0; i--)  //check every data in last row of the table
    {
        if(own_data[4][i] == 3)  //if there is data = 3
        {
            for(int j = 0, counter = 0; j < 4; j++)  //store the trips
            {
                if(own_data[j][i] == 1)
                {
                    best_pattern[n][2*counter] = int_to_suit(j);  //store the suit
                    best_pattern[n][2*counter+1] = int_to_number(i);  //store the number
                    counter++;
                }
            }
            for(int j = 13, counter = 3; j > 0; j--)  //find the last two cards of the pattern
            {
                if(j == i)  //skip the number of former card
                {
                    continue;
                }
                for(int k = 0; k < 4; k++)  //store the last two cards
                {
                    if(own_data[k][j] == 1)
                    {
                        best_pattern[n][2*counter] = int_to_suit(k);  //store the suit
                        best_pattern[n][2*counter+1] = int_to_number(j);  //store the number
                        counter++;
                    }
                    if(counter == 5)  //if all five cards have stored
                    {
                        player_pattern[n] = 6;  //set player pattern to 1
                        return 1;  //if the player pattern is Trips, return 1
                    }
                }

            }
        }
    }
    return 0;  //if the player pattern isn't Trips, return 0
}

int two_pairs(int n)  //determine whether the player's pattern is Two Pairs
{
    int first_pair;  //set an integer to store the number of the first pair

    for(int i = 13, counter = 0; i > 0; i--)  //check every data in last row of the table
    {
        if(own_data[4][i] == 2)  //if there is data = 2
        {
            for(int j = 0; j < 4; j++)  //store the pair
            {
                if(own_data[j][i] == 1)
                {
                    best_pattern[n][2*counter] = int_to_suit(j);  //store the suit
                    best_pattern[n][2*counter+1] = int_to_number(i);  //store the number
                    counter++;
                }
                if(counter == 1)  //when the first pair has found, store the number of it
                {
                    first_pair = i;
                }
                if(counter == 4)  //if two pairs have found
                {
                    for(int k = 13; k > 0; k--)  //find the last card of the pattern
                    {
                        if(k == first_pair || k == i)  //skip the numbers of former card
                        {
                            continue;
                        }
                        for(int l = 0; l < 4; l++)
                        {
                            if(own_data[l][k] == 1)  //store the last card
                            {
                                best_pattern[n][8] = int_to_suit(l);  //store the suit
                                best_pattern[n][9] = int_to_number(k);
                                player_pattern[n] = 7;  //set player pattern to 1
                                return 1;  //if the player pattern is Two Pairs, return 1

                            }
                        }
                    }
                }
            }
        }
    }
    return 0;  //if the player pattern isn't Two Pairs, return 0
}

int pair(int n)  //determine whether the player's pattern is Pair
{
    for(int i = 13; i > 0; i--)  //check every data in last row of the table
    {
        if(own_data[4][i] == 2)  //if there is data = 2
        {
            for(int j = 0,counter = 0; j < 4; j++)  //store the pair
            {
                if(own_data[j][i] == 1)
                {
                    best_pattern[n][2*counter] = int_to_suit(j);  //store the suit
                    best_pattern[n][2*counter+1] = int_to_number(i);  //store the number
                    counter++;
                }
            }
            for(int j = 13, counter = 2; j > 0; j--)  //find the last three cards of the pattern
            {
                if(j == i)  //skip the number of former card
                {
                    continue;
                }
                for(int k = 0; k < 4; k++)  //store the last three cards
                {
                    if(own_data[k][j] == 1)
                    {
                        best_pattern[n][2*counter] = int_to_suit(k);  //store the suit
                        best_pattern[n][2*counter+1] = int_to_number(j);  //store the number
                        counter++;
                    }
                    if(counter == 5)  //if all five cards have stored
                    {
                        player_pattern[n] = 8;  //set player pattern to 1
                        return 1;  //if the player pattern is Pair, return 1
                    }
                }
            }
        }
    }
    return 0;  //if the player pattern isn't Pair, return 0
}

int high_crad(int n)  //determine whether the player's pattern is High Card
{
    for(int i = 13, counter = 0; i > 0; i--)  //check every data in first four row of the table
    {
        for(int j = 0; j < 4; j++)
        {
            if(own_data[j][i] == 1)
            {
                best_pattern[n][2*counter] = int_to_suit(j);  //store the suit
                best_pattern[n][2*counter+1] = int_to_number(i);  //store the number
                counter++;
            }
            if(counter == 5)  //if all five cards have stored
            {
                player_pattern[n] = 9;  //set player pattern to 1
                return 1;  //if the player pattern is High Card, return 1
            }
        }
    }
    return 0;  //if the player pattern isn't High Card, return 0
}

int main()
{
    int n;  //set an integer to store the number of players
    scanf("%d", &n);  //store the number of players

    //part1: store the inputs
    char public_card[10];  //set an array to store public cards
    char own_card[10][4];  //set an array to store each player's cards
    char temp;  //set an character to read
    for(int i = 0; i < 10; i+=2)//to store the public cards' suit and number
    {
        scanf("%c%c%c", &temp, &public_card[i], &public_card[i+1]);//store the card's suit and number respectively
    }
    for(int i = 0; i < n; i++)//to store the players' cards
    {
        for(int j = 0; j < 4; j+=2)//to store one of the player's cards' suit and number
        {
            scanf("%c%c%c", &temp, &own_card[i][j], &own_card[i][j+1]);//store the card's suit and number respectively
        }
    }


    for(int i = 0; i < n; i++)  //deal with each player one by one
    {

        //part2: convert inputs to data table
        for(int j = 0; j < 5; j++)  //reset the data table
        {
            for(int k = 0; k < 14; k++)
            {
                own_data[j][k] = 0;
            }
        }
        for(int j = 0; j < 10; j+=2)  //store the public cards to the data table
        {
            own_data[ suit_to_int(public_card[j]) ][ number_to_int(public_card[j+1]) ] = 1;
        }
        for(int j = 0; j < 4; j+=2)  //store the player cards to the data table
        {
            own_data[ suit_to_int(own_card[i][j]) ][ number_to_int(own_card[i][j+1]) ] = 1;
        }
        for(int j = 0; j < 4; j++)  //A refers to 1 and 14 both
        {
            own_data[j][0] = own_data[j][13];
        }
        for(int j = 0 ; j < 14; j++)  //to sum every number's total
        {
            own_data[4][j] = own_data[0][j] + own_data[1][j] + own_data[2][j] + own_data[3][j];
        }

        //part3: determine every player's pattern ,and print the  card of the pattern
        printf("%d: ", i+1);
        if(straight_flush(i) == 1)  //if player's pattern is Straight Flush
        {
            for(int j = 0; j < 10; j+=2)  //print the cards of player's pattern
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);  //print the card's suit and number respectively
            }
            printf("Straight Flush\n");
        }
        else if(quads(i) == 1)  //else if player's pattern is Quads
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("Quads\n");
        }
        else if(full_house(i) == 1)  //else if player's pattern is Full House
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("Full House\n");
        }
        else if(flush(i) == 1)  //else if player's pattern is Flush
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("Flush\n");
        }
        else if(straight(i) == 1)  //else if player's pattern is Straight
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("Straight\n");
        }
        else if(trips(i) == 1)  //else if player's pattern is Trips
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("Trips\n");
        }
        else if(two_pairs(i) == 1)  //else if player's pattern is Two Pairs
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("Two Pairs\n");
        }
        else if(pair(i) == 1)  //else if player's pattern is Pair
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("Pair\n");
        }
        else if(high_crad(i) == 1)  //else if player's pattern is High Card
        {
            for(int j = 0; j < 10; j+=2)
            {
                printf("%c%c ", best_pattern[i][j], best_pattern[i][j+1]);
            }
            printf("High Card\n");
        }
    }

    //part 3: print who is the winner
    int win_player = 0;  //set an integer to store the winner's number
    for(int i = 0; i < n; i++)  //to check whether the player's card is bigger than others
    {
        if(player_pattern[i] < player_pattern[win_player])  //if player's pattern is bigger than the temporary winner's, change the winner's number
        {
            win_player = i;
        }
        else if(player_pattern[i] == player_pattern[win_player])  //if player's pattern is bigger than the temporary winner's, compare the card
        {
            for(int j = 1; j <=5; j++)
            {
                if(number_to_int(best_pattern[i][2*j-1]) > number_to_int(best_pattern[win_player][2*j-1]))  //if player's card is bigger than the temporary winner's, change the winner's number
                {
                    win_player = i;
                    break;
                }
                if(number_to_int(best_pattern[i][2*j-1]) < number_to_int(best_pattern[win_player][2*j-1]))  //if player's card is smaller than the temporary winner's, change the winner's number
                {
                    break;
                }
            }
        }
    }

    printf("Player ");
    for(int i = 0; i < n; i++)  //print the winner's number and other players' card is as big as the winner
    {
        if(player_pattern[i] == player_pattern[win_player])
        {
            for(int j = 1; j <=5; j++)
            {
                if(best_pattern[i][2*j-1] != best_pattern[win_player][2*j-1])
                {
                    break;
                }
                if(j == 5)
                {
                    printf("%d ", i+1);
                }
            }
        }
    }
    printf("win(s) this game.\n");


    return 0;
}
